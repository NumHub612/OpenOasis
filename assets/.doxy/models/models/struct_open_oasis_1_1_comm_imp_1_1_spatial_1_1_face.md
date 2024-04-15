

# Struct OpenOasis::CommImp::Spatial::Face



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Spatial**](namespace_open_oasis_1_1_comm_imp_1_1_spatial.md) **>** [**Face**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_face.md)



[_**Mesh**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) _face data structure. Polyline type for 1D or 2D mesh, Polygon type for 3D mesh._

* `#include <MeshStructs.h>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  real | [**area**](#variable-area)   = = NAN<br> |
|  std::vector&lt; int &gt; | [**cellIndexes**](#variable-cellindexes)  <br> |
|  std::vector&lt; int &gt; | [**cellSides**](#variable-cellsides)  <br> |
|  [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) | [**centroid**](#variable-centroid)  <br> |
|  std::vector&lt; int &gt; | [**nodeIndexes**](#variable-nodeindexes)  <br> |
|  std::array&lt; real, 3 &gt; | [**normal**](#variable-normal)  <br> |
|  real | [**perimeter**](#variable-perimeter)   = = NAN<br> |












































## Public Attributes Documentation




### variable area 

```C++
real OpenOasis::CommImp::Spatial::Face::area;
```






### variable cellIndexes 

```C++
std::vector<int> OpenOasis::CommImp::Spatial::Face::cellIndexes;
```






### variable cellSides 

```C++
std::vector<int> OpenOasis::CommImp::Spatial::Face::cellSides;
```






### variable centroid 

```C++
Coordinate OpenOasis::CommImp::Spatial::Face::centroid;
```






### variable nodeIndexes 

```C++
std::vector<int> OpenOasis::CommImp::Spatial::Face::nodeIndexes;
```






### variable normal 

```C++
std::array<real, 3> OpenOasis::CommImp::Spatial::Face::normal;
```






### variable perimeter 

```C++
real OpenOasis::CommImp::Spatial::Face::perimeter;
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Spatial/MeshStructs.h`

