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

double DoubleSparseMatrix::operator()(int row, int column)
{
    auto index = Index(row, column);

    const auto &iterator = mValues.find(index);
    if (iterator == mValues.end()) throw runtime_error("Matrxi index out of range");

    return iterator->second;
}

double DoubleSparseMatrix::At(int row, int column)
{
    auto index = Index(row, column);

    const auto &iterator = mValues.find(index);
    if (iterator == mValues.end()) throw runtime_error("Matrxi index out of range");

    return iterator->second;
}

void DoubleSparseMatrix::SetValue(int row, int column, double value)
{
    auto index     = Index(row, column);
    mValues[index] = value;
}

vector<double> DoubleSparseMatrix::Product(const vector<double> &vector2)
{
    auto outputValues = vector<double>(mRowCount);
    Product(outputValues, vector2);
    return outputValues;
}

void DoubleSparseMatrix::Product(vector<double> &res, const vector<double> &vector2)
{
    if (vector2.empty()) return;

    for (auto &entry : mValues)
    {
        res[entry.first.mRow] += entry.second * vector2[entry.first.mCol];
    }
}

}  // namespace OpenOasis::CommImpl::Numeric