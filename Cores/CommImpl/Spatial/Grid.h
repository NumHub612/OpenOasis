/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Grid.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Grid used for numerical calculation.
 *
 ** ***********************************************************************************/
#pragma once
#include "MeshStructs.h"


namespace OpenOasis
{
namespace CommImpl
{
namespace Spatial
{
/// @brief Grid used for numerical calculation.
class Grid
{
public:
    virtual ~Grid() = default;
    Grid(Mesh &&mesh);
    Grid(const Mesh &mesh);
    Grid(const Grid &grid);

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods used for mesh operations.
    //

    /// @brief Activate the mesh to extract topological information needed for various
    /// numerical calculations.
    void ActivateMesh();

    /// @brief Refine the cell at the given index for a adaptive grid.
    /// @note  The refining wouldn't change the origin nodes.
    void RefineCell(int cellIndex);

    /// @brief Coarsen the cell at the given index for adaptive grid.
    /// @note  The coarsening wouldn't change the origin nodes.
    void CoarsenCell(int cellIndex);

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods used for mesh query.
    //

    size_t GetNumCells() const;
    size_t GetNumFaces() const;
    size_t GetNumNodes() const;

    const Cell &GetCell(int cellIndex) const;
    const Face &GetFace(int faceIndex) const;
    const Node &GetNode(int nodeIndex) const;

private:
    void CalculateFaceCentroid();
    void CalculateFaceNormal();
    void CalculateFaceArea();
    void CalculateFacePerimeter();

    void CalculateCellCentroid();
    void CalculateCellSurface();
    void CalculateCellVolume();

    void CollectCellsSharedNode();
    void CollectFacesSharedNode();
    void CollectCellsSharedFace();
    void CollectCellNeighbors();

private:
    Mesh mMesh;
};

}  // namespace Spatial
}  // namespace CommImpl
}  // namespace OpenOasis