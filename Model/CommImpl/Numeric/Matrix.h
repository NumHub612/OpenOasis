/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Matrix.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Define Matrix template class for numerical calculation.
 *
 ** ***********************************************************************************/
#pragma once
#include "ThirdPart/Eigen/Sparse"
#include "Vector.h"
#include <vector>
#include <unordered_map>
#include "Model/Utils/CommConstants.h"


namespace OpenOasis::CommImpl::Numeric
{
template <typename T>
class Matrix
{
private:
    int                    mRows;
    int                    mCols;
    Eigen::SparseMatrix<T> mData;

public:
    Matrix(int rows, int cols) : mRows(rows), mCols(cols), mData(rows, cols){};
    Matrix(int size) : mRows(size), mCols(size), mData(size, size){};

    Matrix(const Matrix &other)
    {
        Set(other);
    }

    Matrix(const std::initializer_list<std::initializer_list<T>> &lst)
    {
        Set(lst);
    }

    Matrix(const Eigen::SparseMatrix<T> &mat)
    {
        mData = mat;
        mRows = mat.rows();
        mCols = mat.cols();
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Static methods for matrix creation.
    //

    /// @brief Makes a sparse matrix with zeros.
    static Matrix Zero(int rows, int cols)
    {
        return Matrix(rows, cols);
    }

    /// Makes a sparse matrix with all diagonal elements to 1, and other elements to 0.
    static Matrix Unit(int rows, int cols)
    {
        Matrix mat(rows, cols);
        mat.SetUnit();
        return mat;
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for matrix data setting.
    //

    void Set(const Matrix &other)
    {
        mData = other.mData;
        mRows = other.mRows;
        mCols = other.mCols;
    }

    void Set(const std::initializer_list<std::initializer_list<T>> &lst)
    {
        size_t rows = lst.size();
        size_t cols = (rows > 0) ? lst.begin()->size() : 0;

        OO_ASSERT((rows == mRows) && (cols == mCols));

        std::vector<Eigen::Triplet<T>> triplets;

        auto rowIter = lst.begin();
        for (size_t i = 0; i < rows; ++i, ++rowIter)
        {
            OO_ASSERT(cols == rowIter->size());

            auto colIter = rowIter->begin();
            for (size_t j = 0; j < cols; ++j, ++colIter)
                triplets.emplace_back({i, j, *colIter});
        }

        mData.setZero();
        mData.setFromTriplets(triplets.begin(), triplets.end());
    }

    void SetAt(size_t i, size_t j, const T &val)
    {
        mData.coeffRef(i, j) = val;
    }

    void SetDiagonal(const T &s)
    {
        for (size_t i = 0; i < mRows; i++)
        {
            SetAt(i, i, s);
        }
    }

    template <size_t N>
    void SetRow(size_t i, const Vector<T, N> &vec)
    {
        OO_ASSERT(i < mRows);
        OO_ASSERT(N == mCols);

        for (size_t j = 0; j < mCols; ++j)
        {
            SetAt(i, j, vec(j));
        }
    }

    template <size_t N>
    void SetCol(size_t j, const Vector<T, N> &vec)
    {
        OO_ASSERT(j < mCols);
        OO_ASSERT(N == mRows);

        for (size_t i = 0; i < mRows; ++i)
        {
            SetAt(i, j, vec(i));
        }
    }

    void SetZero()
    {
        mData.setZero();
    }

    void SetUnit()
    {
        mData.setIdentity();
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for matrix attributes query.
    //

    /// @brief Returns the trace of this matrix.
    /// @warning Should be a square matrix.
    T Trace() const
    {
        OO_ASSERT(mRows == mCols);

        T res = 0;
        for (size_t i = 0; i < mRows; ++i)
            res += mData.coeffRef(i, i);

        return res;
    }

    /// @brief Returns the determinant of this matrix.
    /// @warning Should be a square matrix.
    T Determinant() const
    {
        T res = 1;
        for (size_t i = 0; i < mRows; ++i)
            res *= mData.coeffRef(i, i);

        return res;
    }

    /// @brief Returns diagonal vector of this matrix.
    /// @warning Should be a square matrix.
    template <std::size_t N>
    Vector<T, N> Diagonal() const
    {
        OO_ASSERT(N == mRows);

        std::array<T, N> diags;
        for (std::size_t i = 0; i < N; ++i)
            diags[i] = mData.coeffRef(i, i);

        return diags;
    }

    Eigen::SparseMatrix<T> &Data()
    {
        return mData;
    }

    const Eigen::SparseMatrix<T> &Data() const
    {
        return mData;
    }

    T Max() const
    {
        return mData.maxCoeff();
    }

    T Min() const
    {
        return mData.minCoeff();
    }

    size_t Rows() const
    {
        return mRows;
    }

    size_t Cols() const
    {
        return mCols;
    }

    T Sum() const
    {
        return mData.sum();
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for matrix operations.
    //

    /// @brief Add input scalar @p s to specified element.
    void Add(std::size_t i, std::size_t j, const T &s)
    {
        OO_ASSERT((i < mRows) && (j < mCols));
        mData.coeffRef(i, j) += s;
    }

    /// @brief Adds input matrix @p m (element-wise).
    void Add(const Matrix &m)
    {
        OO_ASSERT((mRows == m.mRows) && (mCols == m.mCols));
        mData += m.mData;
    }

    /// @brief Subtracts scalar @p s to specified element.
    void Sub(std::size_t i, std::size_t j, const T &s)
    {
        OO_ASSERT((i < mRows) && (j < mCols));
        mData.coeffRef(i, j) -= s;
    }

    /// @brief Subtracts input matrix @p m (element-wise).
    void Sub(const Matrix &m)
    {
        OO_ASSERT((mRows == m.mRows) && (mCols == m.mCols));
        mData -= m.mData;
    }

    /// @brief Multiplies scalar @p s to the whole matrix.
    void Mul(const T &s)
    {
        mData *= s;
    }

    /// @brief Returns this matrix * input matrix @p m.
    Matrix Mul(const Matrix &m) const
    {
        OO_ASSERT(mCols == m.mRows);
        return mData * m.mData;
    }

    /// @brief Returns transpose matrix.
    Matrix Transpose() const
    {
        return mData.transpose();
    }

    /// @brief Returns inverse matrix.
    Matrix Invert() const
    {
        return mData.inverse();
    }

    /// @brief Returns adjoint matrix.
    Matrix Adjoint() const
    {
        return mData.adjoint();
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Override operators for matrix.
    //

    T &operator()(size_t i, size_t j)
    {
        return mData.coeffRef(i, j);
    }

    const T &operator()(size_t i, size_t j) const
    {
        return mData.coeffRef(i, j);
    }

    Matrix operator+(const Matrix &m) const
    {
        Matrix res = *this;
        res.Add(m);
        return res;
    }

    Matrix operator-(const Matrix &m) const
    {
        Matrix res = *this;
        res.Sub(m);
        return res;
    }

    Matrix operator*(const Matrix &m) const
    {
        Matrix res = *this;
        res.Mul(m);
        return res;
    }

    Matrix operator*(const T &s) const
    {
        Matrix res = *this;
        res.Mul(s);
        return res;
    }

    Matrix &operator=(const Matrix &other)
    {
        Set(other);
        return *this;
    }

    Matrix &operator+=(const Matrix &m)
    {
        Add(m);
        return *this;
    }

    Matrix &operator-=(const Matrix &m)
    {
        Sub(m);
        return *this;
    }

    Matrix &operator*=(const T &s)
    {
        Mul(s);
        return *this;
    }

    Matrix &operator*=(const Matrix &m)
    {
        Mul(m);
        return *this;
    }
};


///////////////////////////////////////////////////////////////////////////////////
// Legacy code below.
//

/// @brief Sparse matrix having double elements.
class DoubleSparseMatrix
{
private:
    int mRowCount    = 0;
    int mColumnCount = 0;

public:
    class Index
    {
    public:
        Index(int row, int column);
        Index() = default;

        int mRow = 0;
        int mCol = 0;
    };

    struct EqualFunc
    {
        bool operator()(const Index &lhs, const Index &rhs) const;
    };

    struct HashFunc
    {
        size_t operator()(const Index &key) const;
    };

    std::unordered_map<Index, Utils::real, HashFunc, EqualFunc> mValues;

public:
    DoubleSparseMatrix(int rowCount, int columnCount);

    int  GetRowCount() const;
    void SetRowCount(int value);
    int  GetColumnCount() const;
    void SetColumnCount(int value);

    std::vector<Utils::real> Product(const std::vector<Utils::real> &vector2);

    void
    Product(std::vector<Utils::real> &res, const std::vector<Utils::real> &vector2);

    ///////////////////////////////////////////////////////////////////////////////////
    // Local methods.
    //

    bool IsCellEmpty(int row, int column);

    Utils::real operator()(int row, int column);

    Utils::real At(int row, int column);

    void SetValue(int row, int column, Utils::real value);
};

}  // namespace OpenOasis::CommImpl::Numeric