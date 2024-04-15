

# Struct OpenOasis::CommImp::Spatial::XYExtent



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Spatial**](namespace_open_oasis_1_1_comm_imp_1_1_spatial.md) **>** [**XYExtent**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_extent.md)



_Extent is a rectangle in xy-space._ 

* `#include <XYGeoStructs.h>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  double | [**xMax**](#variable-xmax)   = = 0.<br> |
|  double | [**xMin**](#variable-xmin)   = = 0.<br> |
|  double | [**yMax**](#variable-ymax)   = = 0.<br> |
|  double | [**yMin**](#variable-ymin)   = = 0.<br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**Include**](#function-include-12) (const [**XYExtent**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_extent.md) & other) <br>_Makes this extent include "other". This will grow this extent, if the "other" point is outside this extent._  |
|  void | [**Include**](#function-include-22) (double x, double y) <br>_Makes the extent include the xy-point. This will grow this extent, if the xy-point is outside this extent._  |
|  bool | [**IsContains**](#function-iscontains) (double x, double y) const<br>_Checks if this extent contains the xy-point._  |
|  bool | [**IsOverlaps**](#function-isoverlaps) (const [**XYExtent**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_extent.md) & other) const<br>_Checks if this extent overlaps this specified 'other' extent item._  |
|   | [**XYExtent**](#function-xyextent-17) () = default<br> |
|   | [**XYExtent**](#function-xyextent-27) (const [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) & point, double epsilon) <br> |
|   | [**XYExtent**](#function-xyextent-37) (const [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) & line) <br> |
|   | [**XYExtent**](#function-xyextent-47) (const [**XYPolyline**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polyline.md) & polyline) <br> |
|   | [**XYExtent**](#function-xyextent-57) (const [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) & polygon) <br> |
|   | [**XYExtent**](#function-xyextent-67) (const [**XYExtent**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_extent.md) & obj) <br> |
|   | [**XYExtent**](#function-xyextent-77) (double xmin, double xmax, double ymin, double ymax) <br> |




























## Public Attributes Documentation




### variable xMax 

```C++
double OpenOasis::CommImp::Spatial::XYExtent::xMax;
```






### variable xMin 

```C++
double OpenOasis::CommImp::Spatial::XYExtent::xMin;
```






### variable yMax 

```C++
double OpenOasis::CommImp::Spatial::XYExtent::yMax;
```






### variable yMin 

```C++
double OpenOasis::CommImp::Spatial::XYExtent::yMin;
```



## Public Functions Documentation




### function Include [1/2]

```C++
void OpenOasis::CommImp::Spatial::XYExtent::Include (
    const XYExtent & other
) 
```






### function Include [2/2]

```C++
void OpenOasis::CommImp::Spatial::XYExtent::Include (
    double x,
    double y
) 
```






### function IsContains 

```C++
bool OpenOasis::CommImp::Spatial::XYExtent::IsContains (
    double x,
    double y
) const
```






### function IsOverlaps 

```C++
bool OpenOasis::CommImp::Spatial::XYExtent::IsOverlaps (
    const XYExtent & other
) const
```






### function XYExtent [1/7]

```C++
OpenOasis::CommImp::Spatial::XYExtent::XYExtent () = default
```






### function XYExtent [2/7]

```C++
OpenOasis::CommImp::Spatial::XYExtent::XYExtent (
    const XYPoint & point,
    double epsilon
) 
```






### function XYExtent [3/7]

```C++
OpenOasis::CommImp::Spatial::XYExtent::XYExtent (
    const XYLine & line
) 
```






### function XYExtent [4/7]

```C++
OpenOasis::CommImp::Spatial::XYExtent::XYExtent (
    const XYPolyline & polyline
) 
```






### function XYExtent [5/7]

```C++
OpenOasis::CommImp::Spatial::XYExtent::XYExtent (
    const XYPolygon & polygon
) 
```






### function XYExtent [6/7]

```C++
OpenOasis::CommImp::Spatial::XYExtent::XYExtent (
    const XYExtent & obj
) 
```






### function XYExtent [7/7]

```C++
OpenOasis::CommImp::Spatial::XYExtent::XYExtent (
    double xmin,
    double xmax,
    double ymin,
    double ymax
) 
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Spatial/XYGeoStructs.h`

