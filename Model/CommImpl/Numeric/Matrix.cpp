/** ***********************************************************************************
 *    @File      :  Matrix.cpp
 *    @Brief     :  To provide matrix interface and a common implementation.
 *
 ** ***********************************************************************************/
#include "Matrix.h"
#include <stdexcept>


namespace OpenOasis::CommImpl::Numeric
{
using namespace std;

DoubleSparseMatrix::Index::Index(int row, int column)
{
    mRow = row;
    mCol = column;
}

size_t DoubleSparseMatrix::HashFunc::operator()(const Index &key) const
{
    using std::hash;
    using std::size_t;

    return ((hash<int>()(key.mRow) ^ (hash<int>()(key.mCol) << 1)) >> 1);
}

bool DoubleSparseMatrix::EqualFunc::operator()(const Index &lhs, const Index &rhs) const
{
    return lhs.mRow == rhs.mRow && lhs.mCol == rhs.mCol;
}

DoubleSparseMatrix::DoubleSparseMatrix(int rowCount, int columnCount)
{
    SetRowCount(rowCount);
    SetColumnCount(columnCount);
}

int DoubleSparseMatrix::GetRowCount() const
{
    return mRowCount;
}

void DoubleSparseMatrix::SetRowCount(int value)
{
    mRowCount = value;
}

int DoubleSparseMatrix::GetColumnCount() const
{
    return mColumnCount;
}

void DoubleSparseMatrix::SetColumnCount(int value)
{
    mColumnCount = value;
}

bool DoubleSparseMatrix::IsCellEmpty(int row, int column)
{
    auto index = Index(row, column);
    return mValues.find(index) == mValues.end();
}

Utils::real DoubleSparseMatrix::operator()(int row, int column)
{
    auto index = Index(row, column);

    const auto &iterator = mValues.find(index);
    if (iterator == mValues.end())
        throw runtime_error("Matrxi index out of range");

    return iterator->second;
}

Utils::real DoubleSparseMatrix::At(int row, int column)
{
    auto index = Index(row, column);

    const auto &iterator = mValues.find(index);
    if (iterator == mValues.end())
        throw runtime_error("Matrxi index out of range");

    return iterator->second;
}

void DoubleSparseMatrix::SetValue(int row, int column, Utils::real value)
{
    auto index     = Index(row, column);
    mValues[index] = value;
}

vector<Utils::real> DoubleSparseMatrix::Product(const vector<Utils::real> &vector2)
{
    auto outputValues = vector<Utils::real>(mRowCount);
    Product(outputValues, vector2);
    return outputValues;
}

void DoubleSparseMatrix::Product(
    vector<Utils::real> &res, const vector<Utils::real> &vector2)
{
    if (vector2.empty())
        return;

    for (auto &entry : mValues)
    {
        res[entry.first.mRow] += entry.second * vector2[entry.first.mCol];
    }
}

}  // namespace OpenOasis::CommImpl::Numeric