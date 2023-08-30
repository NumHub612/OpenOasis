/** ***********************************************************************************
 *    @File      :  Grid2D.cpp
 *    @Brief     :  Grid in 2d used for numerical calculation.
 *
 ** ***********************************************************************************/
#include "Grid2D.h"
#include "GeoCalculator.h"
#include "Cores/Utils/Exception.h"


namespace OpenOasis::CommImpl::Spatial
{
using namespace Utils;
using namespace std;

Grid2D::Grid2D(const string &meshDir) : Grid(meshDir)
{}

Grid2D::Grid2D(const shared_ptr<Grid> &grid) : Grid(grid)
{}

void Grid2D::RefineCell(int cellIndex)
{
    throw NotImplementedException("Not implemented");
}

void Grid2D::RelaxCell(int cellIndex)
{
    throw NotImplementedException("Not implemented");
}

void Grid2D::CollectCellsInZone()
{
    // Not implemented.
}

void Grid2D::CalculateFaceNormal()
{
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < mRawFacesNum; i++)
    {
        mMesh.faces[i].normal = GeoCalculator::CalculateFaceNormal(i, mMesh);
    }
}

void Grid2D::CalculateFaceArea()
{
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < mRawFacesNum; i++)
    {
        mMesh.faces[i].area = 0.0;
    }
}

void Grid2D::CalculateFacePerimeter()
{
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < mRawFacesNum; i++)
    {
        mMesh.faces[i].perimeter = GeoCalculator::CalculateFacePerimeter(i, mMesh);
    }
}

void Grid2D::CalculateCellSurface()
{
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < mRawCellsNum; i++)
    {
        mMesh.cells[i].surface = 0.0;
    }
}

void Grid2D::CalculateCellVolume()
{
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < mRawCellsNum; i++)
    {
        mMesh.cells[i].volume = 0.0;
    }
}

void Grid2D::CheckMesh() const
{
    // Not implemented.
}

}  // namespace OpenOasis::CommImpl::Spatial