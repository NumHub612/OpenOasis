/** ***********************************************************************************
 *    Copyright (C) 2024, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  MeshProcessor.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Mesh processors.
 *
 ** ***********************************************************************************/
#pragma once
#include "Mesh.h"
#include "GeoCalculator.h"
#include "Models/Utils/MultiIndexMapper.h"


namespace OpenOasis::CommImp::Spatial
{
using namespace Utils;


/// @brief Class for mesh refining and relaxing manipulations.
class MeshAdapter
{
public:
    virtual std::vector<int> Refine(Mesh &mesh, int cellIndex);
    virtual std::vector<int> Relax(Mesh &mesh, int cellIndex);
};


/// @brief Class for mesh filtering manipulations.
class MeshFilter
{
public:
    virtual std::vector<int> GetBoundaryCells(const Mesh &mesh) const;
    virtual std::vector<int> GetBoundaryFaces(const Mesh &mesh) const;
    virtual std::vector<int> GetBoundaryNodes(const Mesh &mesh) const;

    virtual std::vector<int>
    GetZoneCells(const Mesh &mesh, std::vector<int> &zone) const;
};


/// @brief Class for extracting mesh features.
class MeshFeaturer
{
public:
    virtual TupleIndexMap<real> CalcInteriorCellCenterDists(const Mesh &mesh) const;
    virtual MultiIndexMap<real> CalcBoundaryCellCenterDists(const Mesh &mesh) const;

    virtual std::unordered_map<int, Coordinate> CalcFacePoints(const Mesh &mesh) const;
    virtual std::unordered_map<int, std::array<real, 3>> CalcFacePointVectors(
        const Mesh &mesh, const std::unordered_map<int, Coordinate> &facePoints) const;

    virtual MultiIndexMap<real> CalcCellWeights(const Mesh &mesh) const;
};


}  // namespace OpenOasis::CommImp::Spatial
