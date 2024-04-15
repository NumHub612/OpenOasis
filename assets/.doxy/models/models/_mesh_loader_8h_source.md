

# File MeshLoader.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**IO**](dir_3b1940e7bde9c1f91eabae8dc723b4f2.md) **>** [**MeshLoader.h**](_mesh_loader_8h.md)

[Go to the documentation of this file](_mesh_loader_8h.md)


```C++

#pragma once
#include "Models/CommImp/Spatial/Coordinate.h"
#include <string>
#include <vector>
#include <unordered_map>


namespace OpenOasis::CommImp::IO
{
using Spatial::Coordinate;

class MeshLoader
{
private:
    std::string mMeshDir;

    std::unordered_map<std::string, std::vector<int>> mPatchFaces;
    std::unordered_map<std::string, std::vector<int>> mZoneFaces;

    std::unordered_map<int, Coordinate> mNodeCoords;
    std::unordered_map<int, Coordinate> mFaceCoords;
    std::unordered_map<int, Coordinate> mCellCoords;

    std::unordered_map<int, std::vector<int>> mFaceNodes;
    std::unordered_map<int, std::vector<int>> mCellFaces;

public:
    MeshLoader(const std::string &meshDir);
    ~MeshLoader()
    {}

    virtual void Load();

    virtual std::unordered_map<std::string, std::vector<int>> &GetPatches();
    virtual std::unordered_map<std::string, std::vector<int>> &GetZones();

    virtual std::unordered_map<int, Coordinate> &GetNodeCoordinates();
    virtual std::unordered_map<int, Coordinate> &GetFaceCoordinates();
    virtual std::unordered_map<int, Coordinate> &GetCellCoordinates();

    virtual std::unordered_map<int, std::vector<int>> &GetFaceNodes();
    virtual std::unordered_map<int, std::vector<int>> &GetCellFaces();

protected:
    void LoadNodes(const std::string &file = "nodes.csv");
    void LoadFaces(const std::string &file = "faces.csv");
    void LoadCells(const std::string &file = "cells.csv");
    void LoadZones(const std::string &file = "zones.csv");
    void LoadPatches(const std::string &file = "patches.csv");

    void CheckIds(const std::vector<std::string> &ids, const std::string &meta);

    void GenerateFaceCoordinates();
    void GenerateCellCoordinates();
};
}  // namespace OpenOasis::CommImp::IO
```


