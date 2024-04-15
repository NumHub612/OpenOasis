

# File LaplacianOperator.cpp

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Numeric**](dir_a0ece07902893bffce0f747cc8ee06c8.md) **>** [**LaplacianOperator.cpp**](_laplacian_operator_8cpp.md)

[Go to the documentation of this file](_laplacian_operator_8cpp.md)


```C++

#include "LaplacianOperator.h"
#include "Models/Utils/Exception.h"


namespace OpenOasis::CommImp::Numeric
{
using namespace std;
using namespace Utils;


LinearEqs Laplacian::Discretize(
    const ScalarField<real> &phiCellField, const ScalarField<real> &phiFaceField)
{
    int nCells = mGrid->GetNumCells();
    int nFaces = mGrid->GetNumFaces();

    OO_ASSERT(nCells == phiCellField.Size());

    Matrix<real> coeffs(nCells);
    vector<real> rhs(nCells);

    for (int i = 0; i < mGrid->GetNumCells(); ++i)
    {
        const auto &cell = mGrid->GetCell(i);

        real coeff = 0;
        if (mCoefficient)
        {
            coeff = get<0>(mCoefficient.value());
        }
        else if (mScalarCoeffs)
        {
            coeff = mScalarCoeffs.value()(i);
        }
        else
        {
            throw InvalidDataException("Invalid test coefficients");
        }

        for (int j : cell.faceIndexes)
        {
            const auto &face = mGrid->GetFace(j);
            if (face.cellIndexes.size() != 2)
            {
                if (mboundaries.count(j) == 0 || mboundaries[j].type != "DIRICHLET")
                {
                    throw invalid_argument("Invalid boundary face.");
                }

                real boundValue = mboundaries[j].value;

                real distC2b = mGrid->GetBoundaryCenterDistance(i, j);

                real areaEb = face.area;

                real matCoeff = -coeff * areaEb / distC2b;

                real src1 = -matCoeff * boundValue;

                real src2 = 0;

                coeffs.Add(i, i, matCoeff);
                rhs[i] += src2 - src1;
            }
            else
            {
                int cIdx = (face.cellIndexes[0] == i) ? face.cellIndexes[1] :
                                                        face.cellIndexes[0];

                real distC2F = mGrid->GetCellCenterDistance(i, cIdx);

                real areaEb = face.area;

                real matCoeff = -coeff * areaEb / distC2F;

                coeffs.Add(i, i, matCoeff);
                coeffs.Add(i, cIdx, -matCoeff);

                real src1 = 0;
                real src2 = 0;

                rhs[i] += src1 + src2;
            }
        }
    }

    return LinearEqs(coeffs, rhs);
}

}  // namespace OpenOasis::CommImp::Numeric
```


