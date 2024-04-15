

# Class OpenOasis::CommImp::Spatial::GeoCalculator



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Spatial**](namespace_open_oasis_1_1_comm_imp_1_1_spatial.md) **>** [**GeoCalculator**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_geo_calculator.md)



_The_ [_**GeoCalculator**_](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_geo_calculator.md) _is a collection of general geometry functions._

* `#include <GeoCalculator.h>`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr real | [**EPSILON**](#variable-epsilon)   = = 1.0e-5<br> |
















## Public Static Functions

| Type | Name |
| ---: | :--- |
|  real | [**CalculateArea**](#function-calculatearea) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; real, 3 &gt; & normal, const std::vector&lt; int &gt; & nodeIdxs, const std::unordered\_map&lt; int, [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) &gt; & nodes) <br>_Calculates the plane(2d or 3d) area._  |
|  [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) | [**CalculateCellCentroid**](#function-calculatecellcentroid) (int cellIdx, const [**Mesh**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) & mesh) <br> |
|  real | [**CalculateCellVolume**](#function-calculatecellvolume) (int cellIdx, const [**Mesh**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) & mesh) <br> |
|  [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) | [**CalculateCentroid**](#function-calculatecentroid) (const std::vector&lt; int &gt; & nodeIdxs, const std::unordered\_map&lt; int, [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) &gt; & nodes) <br>_Calculates the centroid._  |
|  real | [**CalculateFaceArea**](#function-calculatefacearea) (int faceIdx, const [**Mesh**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) & mesh) <br> |
|  [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) | [**CalculateFaceCentroid**](#function-calculatefacecentroid) (int faceIdx, const [**Mesh**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) & mesh) <br> |
|  std::array&lt; real, 3 &gt; | [**CalculateFaceNormal**](#function-calculatefacenormal) (int faceIdx, const [**Mesh**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) & mesh) <br> |
|  real | [**CalculateFacePerimeter**](#function-calculatefaceperimeter) (int faceIdx, const [**Mesh**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) & mesh) <br> |
|  real | [**CalculateLength**](#function-calculatelength) (const [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) & node0, const [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) & node1) <br>_Calculates the distance between two Nodes._  |
|  std::array&lt; real, 3 &gt; | [**CalculateNormal**](#function-calculatenormal) (const std::vector&lt; int &gt; & nodeIdxs, const std::unordered\_map&lt; int, [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) &gt; & nodes) <br>_Calculates the plane(2d or 3d) unit normal vector._  |
|  real | [**CalculateVolume**](#function-calculatevolume) (const std::vector&lt; int &gt; & nodeIdxs, const std::unordered\_map&lt; int, [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) &gt; & nodes) <br>_Calculates the volume of a polygon pyramid._  |
|  std::vector&lt; int &gt; | [**GetCellNodeIndexes**](#function-getcellnodeindexes) (int cellIdx, const [**Mesh**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) & mesh) <br> |
|  std::vector&lt; int &gt; | [**SortFaceNodes**](#function-sortfacenodes) (int faceIndex, const [**Mesh**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) & mesh) <br> |
|  std::vector&lt; int &gt; | [**SortNodes**](#function-sortnodes) (const std::vector&lt; int &gt; & nodeIdxs, const std::unordered\_map&lt; int, [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) &gt; & nodes) <br>_Sortes the specified Nodes counterclockwise._  |


























## Public Static Attributes Documentation




### variable EPSILON 

```C++
constexpr real OpenOasis::CommImp::Spatial::GeoCalculator::EPSILON;
```



## Public Static Functions Documentation




### function CalculateArea 

_Calculates the plane(2d or 3d) area._ 
```C++
static real OpenOasis::CommImp::Spatial::GeoCalculator::CalculateArea (
    const Vector < real, 3 > & normal,
    const std::vector< int > & nodeIdxs,
    const std::unordered_map< int, Node > & nodes
) 
```





**Parameters:**


* `normal` The unit normal vector of the plane. 
* `nodeIdxs` The clock- or counter- clockwise ordered [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) indexes. 
* `nodes` The [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) map. 



**Returns:**

Area of the plane. 





        



### function CalculateCellCentroid 

```C++
static Coordinate OpenOasis::CommImp::Spatial::GeoCalculator::CalculateCellCentroid (
    int cellIdx,
    const Mesh & mesh
) 
```






### function CalculateCellVolume 

```C++
static real OpenOasis::CommImp::Spatial::GeoCalculator::CalculateCellVolume (
    int cellIdx,
    const Mesh & mesh
) 
```






### function CalculateCentroid 

_Calculates the centroid._ 
```C++
static Coordinate OpenOasis::CommImp::Spatial::GeoCalculator::CalculateCentroid (
    const std::vector< int > & nodeIdxs,
    const std::unordered_map< int, Node > & nodes
) 
```





**Parameters:**


* `nodeIdxs` [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) indexes. 
* `nodes` The Nodes map. 



**Returns:**

Centroid. 





        



### function CalculateFaceArea 

```C++
static real OpenOasis::CommImp::Spatial::GeoCalculator::CalculateFaceArea (
    int faceIdx,
    const Mesh & mesh
) 
```






### function CalculateFaceCentroid 

```C++
static Coordinate OpenOasis::CommImp::Spatial::GeoCalculator::CalculateFaceCentroid (
    int faceIdx,
    const Mesh & mesh
) 
```






### function CalculateFaceNormal 

```C++
static std::array< real, 3 > OpenOasis::CommImp::Spatial::GeoCalculator::CalculateFaceNormal (
    int faceIdx,
    const Mesh & mesh
) 
```






### function CalculateFacePerimeter 

```C++
static real OpenOasis::CommImp::Spatial::GeoCalculator::CalculateFacePerimeter (
    int faceIdx,
    const Mesh & mesh
) 
```






### function CalculateLength 

_Calculates the distance between two Nodes._ 
```C++
static real OpenOasis::CommImp::Spatial::GeoCalculator::CalculateLength (
    const Node & node0,
    const Node & node1
) 
```





**Parameters:**


* `node0` The endpoint. 
* `node1` The endpoint. 



**Returns:**

The length. 





        



### function CalculateNormal 

_Calculates the plane(2d or 3d) unit normal vector._ 
```C++
static std::array< real, 3 > OpenOasis::CommImp::Spatial::GeoCalculator::CalculateNormal (
    const std::vector< int > & nodeIdxs,
    const std::unordered_map< int, Node > & nodes
) 
```





**Parameters:**


* `nodeIdxs` The clock- or counter- clockwise ordered [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) indexes. 
* `nodes` The Nodes map. 



**Returns:**

Unit normal vector. 





        



### function CalculateVolume 

_Calculates the volume of a polygon pyramid._ 
```C++
static real OpenOasis::CommImp::Spatial::GeoCalculator::CalculateVolume (
    const std::vector< int > & nodeIdxs,
    const std::unordered_map< int, Node > & nodes
) 
```





**Parameters:**


* `nodeIdxs` The [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) indexes. 
* `nodes` The [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) map. 



**Returns:**

Volume. 





        



### function GetCellNodeIndexes 

```C++
static std::vector< int > OpenOasis::CommImp::Spatial::GeoCalculator::GetCellNodeIndexes (
    int cellIdx,
    const Mesh & mesh
) 
```






### function SortFaceNodes 

```C++
static std::vector< int > OpenOasis::CommImp::Spatial::GeoCalculator::SortFaceNodes (
    int faceIndex,
    const Mesh & mesh
) 
```






### function SortNodes 

_Sortes the specified Nodes counterclockwise._ 
```C++
static std::vector< int > OpenOasis::CommImp::Spatial::GeoCalculator::SortNodes (
    const std::vector< int > & nodeIdxs,
    const std::unordered_map< int, Node > & nodes
) 
```





**Parameters:**


* `nodeIdxs` The [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) indexes. 
* `nodes` The Nodes map. 



**Returns:**

The sorted [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) indexes. 





        

------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Spatial/GeoCalculator.h`

