/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Matrix.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  To provide matrix interface and a common implementation.
 *
 ** ***********************************************************************************/
#pragma once
#include "Tools/Eigen/Sparse"
#include <vector>
#include <unordered_map>


namespace OpenOasis::CommImpl::Numeric
{

template <typename T>
class SparseMatrix
{
private:
    int                    mRows;
    int                    mCols;
    Eigen::SparseMatrix<T> mData;

public:
    SparseMatrix(int rows, int cols) : mRows(rows), mCols(cols), mData(rows, cols)
    {}
    SparseMatrix(int size) : mRows(size), mCols(size), mData(size, size)
    {}

    void Insert(int i, int j, const T &value)
    {
        mData.insert(i, j) = value;
    }

    void Reset(int i, int j, const T &value)
    {
        mData.coeffRef(i, j) = value;
    }

    void SetZero()
    {
        mData.setZero();
    }

    int Rows() const
    {
        return mRows;
    }

    int Cols() const
    {
        return mCols;
    }

    const T &operator()(int i, int j) const
    {
        return mData(i, j);
    }

    T &operator()(int i, int j)
    {
        return mData(i, j);
    }

    operator Eigen::SparseMatrix<T>() const
    {
        return mData;
    }
};

using DblSparseMatrix = SparseMatrix<double>;


///////////////////////////////////////////////////////////////////////////////////
// Legacy code below.
//


/// @brief Base matrix interface.
class IMatrix
{
public:
    virtual int  GetRowCount() const       = 0;
    virtual void SetRowCount(int value)    = 0;
    virtual int  GetColumnCount() const    = 0;
    virtual void SetColumnCount(int value) = 0;

    /// @brief Does a matrix-vector product.
    ///
    /// @param vector Vector b in res = A*b.
    /// @return Vector res in res = A*b.
    virtual std::vector<double> Product(const std::vector<double> &vector2) = 0;

    /// @brief Does a matrix-vector product.
    ///
    /// @param[out] res Vector res in res = A*b.
    /// @param vector Vector b in res = A*b.
    virtual void
    Product(std::vector<double> &res, const std::vector<double> &vector2) = 0;
};


/// @brief Sparse matrix having double elements.
class DoubleSparseMatrix : public IMatrix
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
        std::size_t operator()(const Index &key) const;
    };

    std::unordered_map<Index, double, HashFunc, EqualFunc> mValues;

public:
    DoubleSparseMatrix(int rowCount, int columnCount);

    ///////////////////////////////////////////////////////////////////////////////////
    // Implement methods inherited from `IMatrix`.
    //

    int  GetRowCount() const override;
    void SetRowCount(int value) override;
    int  GetColumnCount() const override;
    void SetColumnCount(int value) override;

    std::vector<double> Product(const std::vector<double> &vector2) override;

    void Product(std::vector<double> &res, const std::vector<double> &vector2) override;

    ///////////////////////////////////////////////////////////////////////////////////
    // Local methods.
    //

    bool IsCellEmpty(int row, int column);

    double operator()(int row, int column);

    double At(int row, int column);

    void SetValue(int row, int column, double value);
};

}  // namespace OpenOasis::CommImpl::Numeric