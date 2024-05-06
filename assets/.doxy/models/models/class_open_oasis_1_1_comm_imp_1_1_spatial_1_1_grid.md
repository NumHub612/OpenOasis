

# Class OpenOasis::CommImp::Spatial::Grid



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Spatial**](namespace_open_oasis_1_1_comm_imp_1_1_spatial.md) **>** [**Grid**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md)



[_**Grid**_](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md) _encapsulate the mesh data for numerical calculation._

* `#include <Grid.h>`





Inherited by the following classes: [OpenOasis::CommImp::Spatial::Grid1D](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid1_d.md),  [OpenOasis::CommImp::Spatial::Grid2D](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid2_d.md),  [OpenOasis::CommImp::Spatial::Grid3D](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid3_d.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Activate**](#function-activate) () <br>_Activate the mesh to extract topological information needed for various numerical calculations._  |
|  const std::vector&lt; int &gt; & | [**GetBoundaryCellIndexes**](#function-getboundarycellindexes) () const<br> |
|  double | [**GetBoundaryCenterDistance**](#function-getboundarycenterdistance) (int cellIdx, int boundaryFaceIdx) const<br> |
|  const MultiIndexMap&lt; double &gt; & | [**GetBoundaryCenterDistances**](#function-getboundarycenterdistances) () const<br> |
|  const std::vector&lt; int &gt; & | [**GetBoundaryFaceIndexes**](#function-getboundaryfaceindexes) () const<br> |
|  const [**Cell**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_cell.md) & | [**GetCell**](#function-getcell) (int cellIndex) const<br> |
|  double | [**GetCellCenterDistance**](#function-getcellcenterdistance) (int cellIdx, int neighborCellIdx) const<br> |
|  const MultiIndexMap&lt; double &gt; & | [**GetCellCenterDistances**](#function-getcellcenterdistances) () const<br> |
|  const MultiIndexMap&lt; double &gt; & | [**GetCellWeightAtFace**](#function-getcellweightatface-12) () const<br> |
|  double | [**GetCellWeightAtFace**](#function-getcellweightatface-22) (int cellIdx, int faceIdx) const<br> |
|  const [**Face**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_face.md) & | [**GetFace**](#function-getface) (int faceIndex) const<br> |
|  const std::unordered\_map&lt; int, [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; double &gt; &gt; & | [**GetFaceCorrectionVector**](#function-getfacecorrectionvector-12) () const<br> |
|  const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; double &gt; & | [**GetFaceCorrectionVector**](#function-getfacecorrectionvector-22) (int faceIdx) const<br> |
|  const [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) & | [**GetNode**](#function-getnode) (int nodeIndex) const<br> |
|  int | [**GetNumCells**](#function-getnumcells) () const<br> |
|  int | [**GetNumFaces**](#function-getnumfaces) () const<br> |
|  int | [**GetNumNodes**](#function-getnumnodes) () const<br> |
|  std::vector&lt; int &gt; | [**GetPatchFaceIndexes**](#function-getpatchfaceindexes) (const std::string & patchId) const<br> |
|  std::vector&lt; std::string &gt; | [**GetPatchIds**](#function-getpatchids) () const<br> |
|  int | [**GetRawNumCells**](#function-getrawnumcells) () const<br> |
|  int | [**GetRawNumFaces**](#function-getrawnumfaces) () const<br> |
|  int | [**GetRawNumNodes**](#function-getrawnumnodes) () const<br> |
|  std::vector&lt; int &gt; | [**GetZoneCellIndexes**](#function-getzonecellindexes) (const std::string & zoneId) const<br> |
|  std::vector&lt; std::string &gt; | [**GetZoneIds**](#function-getzoneids) () const<br> |
|   | [**Grid**](#function-grid-12) (const std::shared\_ptr&lt; [**Grid**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md) &gt; & grid) <br> |
|   | [**Grid**](#function-grid-22) (std::unordered\_map&lt; int, [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) &gt; & nodeCoords, std::unordered\_map&lt; int, [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) &gt; & faceCoords, std::unordered\_map&lt; int, [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) &gt; & cellCoords, std::unordered\_map&lt; int, std::vector&lt; int &gt; &gt; & faceNodes, std::unordered\_map&lt; int, std::vector&lt; int &gt; &gt; & cellFaces, std::unordered\_map&lt; std::string, std::vector&lt; int &gt; &gt; & patches, std::unordered\_map&lt; std::string, std::vector&lt; int &gt; &gt; & zones) <br> |
| virtual void | [**RefineCell**](#function-refinecell) (int cellIndex) = 0<br>_Refine the cell at the given index for adaptive grid._  |
| virtual void | [**RelaxCell**](#function-relaxcell) (int cellIndex) = 0<br>_Relax the cell at given index for adaptive grid._  |
| virtual int | [**Type**](#function-type) () const = 0<br>_Get the grid type._  |
| virtual int | [**Version**](#function-version) () const = 0<br>_Get the version of the current grid._  |
| virtual  | [**~Grid**](#function-grid) () = default<br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  std::vector&lt; int &gt; | [**mBoundaryCells**](#variable-mboundarycells)  <br> |
|  MultiIndexMap&lt; double &gt; | [**mBoundaryCenterDists**](#variable-mboundarycenterdists)  <br> |
|  std::vector&lt; int &gt; | [**mBoundaryFaces**](#variable-mboundaryfaces)  <br> |
|  MultiIndexMap&lt; double &gt; | [**mCellFaceWeight**](#variable-mcellfaceweight)  <br> |
|  MultiIndexMap&lt; double &gt; | [**mCenterDists**](#variable-mcenterdists)  <br> |
|  std::unordered\_map&lt; int, [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; double &gt; &gt; | [**mFaceCorrVecs**](#variable-mfacecorrvecs)  <br> |
|  std::unordered\_map&lt; int, [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) &gt; | [**mFaceIntersection**](#variable-mfaceintersection)  <br> |
|  [**Mesh**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) | [**mMesh**](#variable-mmesh)  <br> |
|  std::unordered\_map&lt; std::string, std::vector&lt; int &gt; &gt; | [**mPatches**](#variable-mpatches)  <br> |
|  int | [**mRawCellsNum**](#variable-mrawcellsnum)  <br> |
|  int | [**mRawFacesNum**](#variable-mrawfacesnum)  <br> |
|  int | [**mRawNodesNum**](#variable-mrawnodesnum)  <br> |
|  int | [**mVersion**](#variable-mversion)   = = 0<br> |
|  std::unordered\_map&lt; std::string, std::vector&lt; int &gt; &gt; | [**mZoneCells**](#variable-mzonecells)  <br> |
|  std::unordered\_map&lt; std::string, std::vector&lt; int &gt; &gt; | [**mZones**](#variable-mzones)  <br> |
















## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**CalculateBoundaryCenterDistances**](#function-calculateboundarycenterdistances) () <br> |
| virtual void | [**CalculateCellDistances**](#function-calculatecelldistances) () <br> |
| virtual void | [**CalculateCellSurface**](#function-calculatecellsurface) () <br> |
| virtual void | [**CalculateCellVolume**](#function-calculatecellvolume) () <br> |
|  double | [**CalculateDistance**](#function-calculatedistance) (const [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) & n1, const [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) & n2) const<br> |
| virtual void | [**CalculateFaceArea**](#function-calculatefacearea) () <br> |
| virtual void | [**CalculateFaceCorrectionVector**](#function-calculatefacecorrectionvector) () <br> |
| virtual void | [**CalculateFaceDirector**](#function-calculatefacedirector) () <br> |
| virtual void | [**CalculateFaceIntersections**](#function-calculatefaceintersections) () <br> |
| virtual void | [**CalculateFaceNormal**](#function-calculatefacenormal) () <br> |
| virtual void | [**CalculateFacePerimeter**](#function-calculatefaceperimeter) () <br> |
| virtual void | [**CalculateFaceWeights**](#function-calculatefaceweights) () <br> |
| virtual void | [**CheckMesh**](#function-checkmesh) () const<br> |
| virtual void | [**CollectBoundaryFacesAndCells**](#function-collectboundaryfacesandcells) () <br> |
| virtual void | [**CollectCellNeighbors**](#function-collectcellneighbors) () <br> |
| virtual void | [**CollectCellsInZone**](#function-collectcellsinzone) () <br> |
| virtual void | [**CollectCellsSharedFace**](#function-collectcellssharedface) () <br> |
| virtual void | [**CollectCellsSharedNode**](#function-collectcellssharednode) () <br> |
| virtual void | [**CollectFacesSharedNode**](#function-collectfacessharednode) () <br> |
| virtual void | [**SortNodes**](#function-sortnodes) () <br> |




## Public Functions Documentation




### function Activate 

```C++
virtual void OpenOasis::CommImp::Spatial::Grid::Activate () 
```






### function GetBoundaryCellIndexes 

```C++
const std::vector< int > & OpenOasis::CommImp::Spatial::Grid::GetBoundaryCellIndexes () const
```






### function GetBoundaryCenterDistance 

```C++
double OpenOasis::CommImp::Spatial::Grid::GetBoundaryCenterDistance (
    int cellIdx,
    int boundaryFaceIdx
) const
```






### function GetBoundaryCenterDistances 

```C++
const MultiIndexMap< double > & OpenOasis::CommImp::Spatial::Grid::GetBoundaryCenterDistances () const
```






### function GetBoundaryFaceIndexes 

```C++
const std::vector< int > & OpenOasis::CommImp::Spatial::Grid::GetBoundaryFaceIndexes () const
```






### function GetCell 

```C++
const Cell & OpenOasis::CommImp::Spatial::Grid::GetCell (
    int cellIndex
) const
```






### function GetCellCenterDistance 

```C++
double OpenOasis::CommImp::Spatial::Grid::GetCellCenterDistance (
    int cellIdx,
    int neighborCellIdx
) const
```






### function GetCellCenterDistances 

```C++
const MultiIndexMap< double > & OpenOasis::CommImp::Spatial::Grid::GetCellCenterDistances () const
```






### function GetCellWeightAtFace [1/2]

```C++
const MultiIndexMap< double > & OpenOasis::CommImp::Spatial::Grid::GetCellWeightAtFace () const
```






### function GetCellWeightAtFace [2/2]

```C++
double OpenOasis::CommImp::Spatial::Grid::GetCellWeightAtFace (
    int cellIdx,
    int faceIdx
) const
```






### function GetFace 

```C++
const Face & OpenOasis::CommImp::Spatial::Grid::GetFace (
    int faceIndex
) const
```






### function GetFaceCorrectionVector [1/2]

```C++
const std::unordered_map< int, Vector < double > > & OpenOasis::CommImp::Spatial::Grid::GetFaceCorrectionVector () const
```






### function GetFaceCorrectionVector [2/2]

```C++
const Vector < double > & OpenOasis::CommImp::Spatial::Grid::GetFaceCorrectionVector (
    int faceIdx
) const
```






### function GetNode 

```C++
const Node & OpenOasis::CommImp::Spatial::Grid::GetNode (
    int nodeIndex
) const
```






### function GetNumCells 

```C++
int OpenOasis::CommImp::Spatial::Grid::GetNumCells () const
```






### function GetNumFaces 

```C++
int OpenOasis::CommImp::Spatial::Grid::GetNumFaces () const
```






### function GetNumNodes 

```C++
int OpenOasis::CommImp::Spatial::Grid::GetNumNodes () const
```






### function GetPatchFaceIndexes 

```C++
std::vector< int > OpenOasis::CommImp::Spatial::Grid::GetPatchFaceIndexes (
    const std::string & patchId
) const
```






### function GetPatchIds 

```C++
std::vector< std::string > OpenOasis::CommImp::Spatial::Grid::GetPatchIds () const
```






### function GetRawNumCells 

```C++
int OpenOasis::CommImp::Spatial::Grid::GetRawNumCells () const
```






### function GetRawNumFaces 

```C++
int OpenOasis::CommImp::Spatial::Grid::GetRawNumFaces () const
```






### function GetRawNumNodes 

```C++
int OpenOasis::CommImp::Spatial::Grid::GetRawNumNodes () const
```






### function GetZoneCellIndexes 

```C++
std::vector< int > OpenOasis::CommImp::Spatial::Grid::GetZoneCellIndexes (
    const std::string & zoneId
) const
```






### function GetZoneIds 

```C++
std::vector< std::string > OpenOasis::CommImp::Spatial::Grid::GetZoneIds () const
```






### function Grid [1/2]

```C++
OpenOasis::CommImp::Spatial::Grid::Grid (
    const std::shared_ptr< Grid > & grid
) 
```






### function Grid [2/2]

```C++
OpenOasis::CommImp::Spatial::Grid::Grid (
    std::unordered_map< int, Coordinate > & nodeCoords,
    std::unordered_map< int, Coordinate > & faceCoords,
    std::unordered_map< int, Coordinate > & cellCoords,
    std::unordered_map< int, std::vector< int > > & faceNodes,
    std::unordered_map< int, std::vector< int > > & cellFaces,
    std::unordered_map< std::string, std::vector< int > > & patches,
    std::unordered_map< std::string, std::vector< int > > & zones
) 
```






### function RefineCell 

_Refine the cell at the given index for adaptive grid._ 
```C++
virtual void OpenOasis::CommImp::Spatial::Grid::RefineCell (
    int cellIndex
) = 0
```





**Note:**

This wouldn't change the origin nodes. 





        



### function RelaxCell 

_Relax the cell at given index for adaptive grid._ 
```C++
virtual void OpenOasis::CommImp::Spatial::Grid::RelaxCell (
    int cellIndex
) = 0
```





**Note:**

This wouldn't change the origin nodes. 





        



### function Type 

_Get the grid type._ 
```C++
virtual int OpenOasis::CommImp::Spatial::Grid::Type () const = 0
```





**Returns:**

Return 1, for 1d grid; 2, for 2d; 3, for 3d; others, for invalid type. 





        



### function Version 

```C++
virtual int OpenOasis::CommImp::Spatial::Grid::Version () const = 0
```






### function ~Grid 

```C++
virtual OpenOasis::CommImp::Spatial::Grid::~Grid () = default
```



## Protected Attributes Documentation




### variable mBoundaryCells 

```C++
std::vector<int> OpenOasis::CommImp::Spatial::Grid::mBoundaryCells;
```






### variable mBoundaryCenterDists 

```C++
MultiIndexMap<double> OpenOasis::CommImp::Spatial::Grid::mBoundaryCenterDists;
```






### variable mBoundaryFaces 

```C++
std::vector<int> OpenOasis::CommImp::Spatial::Grid::mBoundaryFaces;
```






### variable mCellFaceWeight 

```C++
MultiIndexMap<double> OpenOasis::CommImp::Spatial::Grid::mCellFaceWeight;
```






### variable mCenterDists 

```C++
MultiIndexMap<double> OpenOasis::CommImp::Spatial::Grid::mCenterDists;
```






### variable mFaceCorrVecs 

```C++
std::unordered_map<int, Vector<double> > OpenOasis::CommImp::Spatial::Grid::mFaceCorrVecs;
```






### variable mFaceIntersection 

```C++
std::unordered_map<int, Coordinate> OpenOasis::CommImp::Spatial::Grid::mFaceIntersection;
```






### variable mMesh 

```C++
Mesh OpenOasis::CommImp::Spatial::Grid::mMesh;
```






### variable mPatches 

```C++
std::unordered_map<std::string, std::vector<int> > OpenOasis::CommImp::Spatial::Grid::mPatches;
```






### variable mRawCellsNum 

```C++
int OpenOasis::CommImp::Spatial::Grid::mRawCellsNum;
```






### variable mRawFacesNum 

```C++
int OpenOasis::CommImp::Spatial::Grid::mRawFacesNum;
```






### variable mRawNodesNum 

```C++
int OpenOasis::CommImp::Spatial::Grid::mRawNodesNum;
```






### variable mVersion 

```C++
int OpenOasis::CommImp::Spatial::Grid::mVersion;
```






### variable mZoneCells 

```C++
std::unordered_map<std::string, std::vector<int> > OpenOasis::CommImp::Spatial::Grid::mZoneCells;
```






### variable mZones 

```C++
std::unordered_map<std::string, std::vector<int> > OpenOasis::CommImp::Spatial::Grid::mZones;
```



## Protected Functions Documentation




### function CalculateBoundaryCenterDistances 

```C++
virtual void OpenOasis::CommImp::Spatial::Grid::CalculateBoundaryCenterDistances () 
```






### function CalculateCellDistances 

```C++
virtual void OpenOasis::CommImp::Spatial::Grid::CalculateCellDistances () 
```






### function CalculateCellSurface 

```C++
inline virtual void OpenOasis::CommImp::Spatial::Grid::CalculateCellSurface () 
```






### function CalculateCellVolume 

```C++
inline virtual void OpenOasis::CommImp::Spatial::Grid::CalculateCellVolume () 
```






### function CalculateDistance 

```C++
inline double OpenOasis::CommImp::Spatial::Grid::CalculateDistance (
    const Coordinate & n1,
    const Coordinate & n2
) const
```






### function CalculateFaceArea 

```C++
inline virtual void OpenOasis::CommImp::Spatial::Grid::CalculateFaceArea () 
```






### function CalculateFaceCorrectionVector 

```C++
virtual void OpenOasis::CommImp::Spatial::Grid::CalculateFaceCorrectionVector () 
```






### function CalculateFaceDirector 

```C++
virtual void OpenOasis::CommImp::Spatial::Grid::CalculateFaceDirector () 
```






### function CalculateFaceIntersections 

```C++
virtual void OpenOasis::CommImp::Spatial::Grid::CalculateFaceIntersections () 
```






### function CalculateFaceNormal 

```C++
inline virtual void OpenOasis::CommImp::Spatial::Grid::CalculateFaceNormal () 
```






### function CalculateFacePerimeter 

```C++
inline virtual void OpenOasis::CommImp::Spatial::Grid::CalculateFacePerimeter () 
```






### function CalculateFaceWeights 

```C++
virtual void OpenOasis::CommImp::Spatial::Grid::CalculateFaceWeights () 
```






### function CheckMesh 

```C++
virtual void OpenOasis::CommImp::Spatial::Grid::CheckMesh () const
```






### function CollectBoundaryFacesAndCells 

```C++
virtual void OpenOasis::CommImp::Spatial::Grid::CollectBoundaryFacesAndCells () 
```






### function CollectCellNeighbors 

```C++
virtual void OpenOasis::CommImp::Spatial::Grid::CollectCellNeighbors () 
```






### function CollectCellsInZone 

```C++
inline virtual void OpenOasis::CommImp::Spatial::Grid::CollectCellsInZone () 
```






### function CollectCellsSharedFace 

```C++
virtual void OpenOasis::CommImp::Spatial::Grid::CollectCellsSharedFace () 
```






### function CollectCellsSharedNode 

```C++
virtual void OpenOasis::CommImp::Spatial::Grid::CollectCellsSharedNode () 
```






### function CollectFacesSharedNode 

```C++
virtual void OpenOasis::CommImp::Spatial::Grid::CollectFacesSharedNode () 
```






### function SortNodes 

```C++
virtual void OpenOasis::CommImp::Spatial::Grid::SortNodes () 
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Spatial/Grid.h`

