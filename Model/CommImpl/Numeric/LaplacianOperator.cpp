/** ***********************************************************************************
 *    @File      :  LaplacianOperator.cpp
 *    @Brief     :  Laplacian Operator.
 *
 ** ***********************************************************************************/
#include "LaplacianOperator.h"
#include "Model/Utils/Exception.h"


namespace OpenOasis::CommImpl::Numeric
{
using namespace std;
using namespace Utils;


LinearEqs Laplacian::Discretize(
    const ScalarField<double> &phiCellField, const ScalarField<double> &phiFaceField)
{
    int nCells = mGrid->GetNumCells();
    int nFaces = mGrid->GetNumFaces();

    OO_ASSERT(nCells == phiCellField.Size() && nFaces == phiFaceField.Size());

    Matrix<double> coeffs(nCells);
    vector<double> rhs(nCells);

    for (int i = 0; i < mGrid->GetNumCells(); ++i)
    {
        const auto &cell = mGrid->GetCell(i);

        double coeff = 0;
        if (mCoefficient) { coeff = get<0>(mCoefficient.value()); }
        else if (mScalarCoeffs) { coeff = mScalarCoeffs.value()(i); }
        else { throw InvalidDataException("Invalid test coefficients"); }

        for (int j : cell.faceIndexes)
        {
            const auto &face = mGrid->GetFace(j);
            if (face.cellIndexes.size() != 2)
            {
                if (mboundaries.count(j) == 0 || mboundaries[j].type != "DIRICHLET")
                {
                    throw invalid_argument("Invalid boundary face.");
                }

                double boundValue = mboundaries[j].value;

                double distC2b = mGrid->GetBoundaryCenterDistance(i, j);

                double areaEb = face.area;

                double matCoeff = -coeff * areaEb / distC2b;

                double src1 = -matCoeff * boundValue;

                double src2 = 0;

                coeffs.Add(i, i, matCoeff);
                rhs[i] += src2 - src1;
            }
            else
            {
                int cIdx = (face.cellIndexes[0] == i) ? face.cellIndexes[1] :
                                                        face.cellIndexes[0];

                double distC2F = mGrid->GetCellCenterDistance(i, cIdx);

                double areaEb = face.area;

                double matCoeff = -coeff * areaEb / distC2F;

                coeffs.Add(i, i, matCoeff);
                coeffs.Add(i, cIdx, -matCoeff);

                double src1 = 0;
                double src2 = 0;

                rhs[i] += src1 + src2;
            }
        }
    }

    return LinearEqs(coeffs, rhs);
}

}  // namespace OpenOasis::CommImpl::Numeric