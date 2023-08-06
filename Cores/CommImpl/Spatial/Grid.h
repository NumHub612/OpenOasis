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
/// @brief Grid encapsulate the mesh data for numerical calculation.
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

    std::size_t GetNumCells() const;
    std::size_t GetNumFaces() const;
    std::size_t GetNumNodes() const;

    const Cell &GetCell(int cellIndex) const;
    const Face &GetFace(int faceIndex) const;
    const Node &GetNode(int nodeIndex) const;

    std::vector<std::size_t> GetBoundaryFaceIdexes() const;

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
    void CollectCellNeighbors();

    bool CheckMeshValid() const;

private:
    Mesh mMesh;

    bool mMeshHasZ;
};

}  // namespace Spatial
}  // namespace CommImpl
}  // namespace OpenOasis