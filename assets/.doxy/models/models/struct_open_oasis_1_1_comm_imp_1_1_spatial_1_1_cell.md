

# Struct OpenOasis::CommImp::Spatial::Cell



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Spatial**](namespace_open_oasis_1_1_comm_imp_1_1_spatial.md) **>** [**Cell**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_cell.md)



[_**Mesh**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) _cell data structure. Polygon type for 1D and 2D mesh, Polyhedron type for 3D mesh._

* `#include <MeshStructs.h>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) | [**centroid**](#variable-centroid)  <br> |
|  std::vector&lt; int &gt; | [**faceIndexes**](#variable-faceindexes)  <br> |
|  std::vector&lt; int &gt; | [**neighbors**](#variable-neighbors)  <br> |
|  std::vector&lt; int &gt; | [**subCells**](#variable-subcells)  <br> |
|  real | [**surface**](#variable-surface)   = = NAN<br> |
|  real | [**volume**](#variable-volume)   = = NAN<br> |












































## Public Attributes Documentation




### variable centroid 

```C++
Coordinate OpenOasis::CommImp::Spatial::Cell::centroid;
```






### variable faceIndexes 

```C++
std::vector<int> OpenOasis::CommImp::Spatial::Cell::faceIndexes;
```






### variable neighbors 

```C++
std::vector<int> OpenOasis::CommImp::Spatial::Cell::neighbors;
```






### variable subCells 

```C++
std::vector<int> OpenOasis::CommImp::Spatial::Cell::subCells;
```






### variable surface 

```C++
real OpenOasis::CommImp::Spatial::Cell::surface;
```






### variable volume 

```C++
real OpenOasis::CommImp::Spatial::Cell::volume;
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Spatial/MeshStructs.h`

