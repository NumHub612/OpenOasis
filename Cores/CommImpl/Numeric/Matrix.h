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
#include "Cores/Inc/AdditionalControl/IComparable.h"
#include <type_traits>
#include <vector>
#include <unordered_map>


namespace OpenOasis
{
namespace CommImpl
{
namespace Numeric
{
using namespace AdditionalControl;

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

        int mRow = 0;

        int mColumn = 0;

        Index() = default;
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

}  // namespace Numeric
}  // namespace CommImpl
}  // namespace OpenOasis