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
#include "Mesh.h"
#include <string>


namespace OpenOasis::CommImp::Spatial
{
/// @brief Grid encapsulate the mesh data for various numerical calculations.
/// @note The Grid garuntees the mesh indexes is valid and continuous.
class Grid
{
protected:
    int  mVersion = 0;
    Mesh mMesh;

public:
    virtual ~Grid() = default;
    Grid(const Mesh &mesh);
    Grid(Mesh &&mesh);
    Grid(
        const std::unordered_map<size_t, Coordinate>          &nodeCoords,
        const std::unordered_map<size_t, Coordinate>          &faceCoords,
        const std::unordered_map<size_t, Coordinate>          &cellCoords,
        const std::unordered_map<size_t, std::vector<size_t>> &faceNodes,
        const std::unordered_map<size_t, std::vector<size_t>> &cellFaces);


    ///////////////////////////////////////////////////////////////////////////////////
    // Methods used for mesh activation and manipulations.
    //

    /// @brief Extract topology and geometry data.
    virtual void Activate();

    /// @brief Refine the mesh cell of a given index @p cellIndex for adaptive mesh.
    virtual void RefineCell(size_t cellIndex);

    /// @brief Relax the mesh cell of a given index @p cellIndex .
    virtual void RelaxCell(size_t cellIndex);

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods used for mesh query.
    //

    int Version() const;

    const Cell &GetCell(size_t cellIndex) const;
    const Face &GetFace(size_t faceIndex) const;
    const Node &GetNode(size_t nodeIndex) const;
    const Mesh &GetMesh() const;

    size_t GetNumCells() const;
    size_t GetNumFaces() const;
    size_t GetNumNodes() const;

protected:
    ///////////////////////////////////////////////////////////////////////////////////
    // Methods used for activating mesh data.
    //

    virtual void CollectCellsSharedNode();
    virtual void CollectFacesSharedNode();
    virtual void CollectCellsSharedFace();
    virtual void CollectCellNeighbors();
    virtual void CollectFaceCellSides();

    virtual void SortNodes();
    virtual void CheckMesh();

    virtual void CalculateFaceNormal();
    virtual void CalculateFaceArea();
    virtual void CalculateFacePerimeter();
    virtual void CalculateCellSurface();
    virtual void CalculateCellVolume();
};

}  // namespace OpenOasis::CommImp::Spatial