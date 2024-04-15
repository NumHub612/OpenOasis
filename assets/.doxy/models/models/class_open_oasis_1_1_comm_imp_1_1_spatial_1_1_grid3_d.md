

# Class OpenOasis::CommImp::Spatial::Grid3D



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Spatial**](namespace_open_oasis_1_1_comm_imp_1_1_spatial.md) **>** [**Grid3D**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid3_d.md)








Inherits the following classes: [OpenOasis::CommImp::Spatial::Grid](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Grid3D**](#function-grid3d-12) (const std::shared\_ptr&lt; [**Grid**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md) &gt; & grid) <br> |
|   | [**Grid3D**](#function-grid3d-22) (std::unordered\_map&lt; int, [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) &gt; & nodeCoords, std::unordered\_map&lt; int, [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) &gt; & faceCoords, std::unordered\_map&lt; int, [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) &gt; & cellCoords, std::unordered\_map&lt; int, std::vector&lt; int &gt; &gt; & faceNodes, std::unordered\_map&lt; int, std::vector&lt; int &gt; &gt; & cellFaces, std::unordered\_map&lt; std::string, std::vector&lt; int &gt; &gt; & patches, std::unordered\_map&lt; std::string, std::vector&lt; int &gt; &gt; & zones) <br> |
| virtual void | [**RefineCell**](#function-refinecell) (int cellIndex) override<br>_Refine the cell at the given index for adaptive grid._  |
| virtual void | [**RelaxCell**](#function-relaxcell) (int cellIndex) override<br>_Relax the cell at the given index for adaptive grid._  |
| virtual int | [**Type**](#function-type) () override const<br>_Get the grid type._  |
| virtual  | [**~Grid3D**](#function-grid3d) () = default<br> |


## Public Functions inherited from OpenOasis::CommImp::Spatial::Grid

See [OpenOasis::CommImp::Spatial::Grid](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md)

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
| virtual void | [**RelaxCell**](#function-relaxcell) (int cellIndex) = 0<br>_Relax the cell at the given index for adaptive grid._  |
| virtual int | [**Type**](#function-type) () const = 0<br>_Get the grid type._  |
| virtual  | [**~Grid**](#function-grid) () = default<br> |
















## Protected Attributes inherited from OpenOasis::CommImp::Spatial::Grid

See [OpenOasis::CommImp::Spatial::Grid](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md)

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
|  std::unordered\_map&lt; std::string, std::vector&lt; int &gt; &gt; | [**mZoneCells**](#variable-mzonecells)  <br> |
|  std::unordered\_map&lt; std::string, std::vector&lt; int &gt; &gt; | [**mZones**](#variable-mzones)  <br> |
































## Protected Functions inherited from OpenOasis::CommImp::Spatial::Grid

See [OpenOasis::CommImp::Spatial::Grid](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md)

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




### function Grid3D [1/2]

```C++
OpenOasis::CommImp::Spatial::Grid3D::Grid3D (
    const std::shared_ptr< Grid > & grid
) 
```






### function Grid3D [2/2]

```C++
OpenOasis::CommImp::Spatial::Grid3D::Grid3D (
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
virtual void OpenOasis::CommImp::Spatial::Grid3D::RefineCell (
    int cellIndex
) override
```





**Note:**

The refining wouldn't change the origin nodes. 





        
Implements [*OpenOasis::CommImp::Spatial::Grid::RefineCell*](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md#function-refinecell)




### function RelaxCell 

_Relax the cell at the given index for adaptive grid._ 
```C++
virtual void OpenOasis::CommImp::Spatial::Grid3D::RelaxCell (
    int cellIndex
) override
```





**Note:**

The coarsening wouldn't change the origin nodes. 





        
Implements [*OpenOasis::CommImp::Spatial::Grid::RelaxCell*](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md#function-relaxcell)




### function Type 

_Get the grid type._ 
```C++
virtual int OpenOasis::CommImp::Spatial::Grid3D::Type () override const
```





**Returns:**

Return 1, for 1d grid; 2, for 2d; 3, for 3d; others, for invalid type. 





        
Implements [*OpenOasis::CommImp::Spatial::Grid::Type*](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md#function-type)




### function ~Grid3D 

```C++
virtual OpenOasis::CommImp::Spatial::Grid3D::~Grid3D () = default
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Spatial/Grid3D.h`

