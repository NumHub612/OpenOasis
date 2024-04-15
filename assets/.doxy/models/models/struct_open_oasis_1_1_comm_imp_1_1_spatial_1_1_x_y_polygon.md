

# Struct OpenOasis::CommImp::Spatial::XYPolygon



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Spatial**](namespace_open_oasis_1_1_comm_imp_1_1_spatial.md) **>** [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md)



_The_ [_**XYPolygon**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) _struct defines a polygon in the XY plane (no z coordinate)._

* `#include <XYGeoStructs.h>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  std::vector&lt; [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) &gt; | [**points**](#variable-points)  <br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  double | [**GetArea**](#function-getarea) () const<br>_Calculates area of the polygon._  |
|  [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) | [**GetLine**](#function-getline) (int lineNumber) const<br>_Returns the_ [_**XYLine**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) _that connects_[_**XYPoint**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) _"LineNumber" and the next number (i.e. LineNumber+1 or 0)._ |
|  bool | [**IsConvex**](#function-isconvex) (int index) const<br>_Decides if the angle at index point is convex or concave._  |
|  bool | [**Validate**](#function-validate) () const<br>_Checks if the_ [_**XYPolygon**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) _item is valid. The check made are:_ |
|   | [**XYPolygon**](#function-xypolygon-13) () = default<br> |
|   | [**XYPolygon**](#function-xypolygon-23) (const std::vector&lt; [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) &gt; & points) <br> |
|   | [**XYPolygon**](#function-xypolygon-33) (const [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) & polygon) <br> |




























## Public Attributes Documentation




### variable points 

```C++
std::vector<XYPoint> OpenOasis::CommImp::Spatial::XYPolygon::points;
```



## Public Functions Documentation




### function GetArea 

```C++
double OpenOasis::CommImp::Spatial::XYPolygon::GetArea () const
```






### function GetLine 

```C++
XYLine OpenOasis::CommImp::Spatial::XYPolygon::GetLine (
    int lineNumber
) const
```






### function IsConvex 

```C++
bool OpenOasis::CommImp::Spatial::XYPolygon::IsConvex (
    int index
) const
```






### function Validate 

_Checks if the_ [_**XYPolygon**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) _item is valid. The check made are:_
```C++
bool OpenOasis::CommImp::Spatial::XYPolygon::Validate () const
```




* is number of points &gt;= 3
* is the length of all line segments positive
* is any lines cross
* is the area positive






**Exception:**


* `Exception` is raised if these above constraints aren't met. 




        



### function XYPolygon [1/3]

```C++
OpenOasis::CommImp::Spatial::XYPolygon::XYPolygon () = default
```






### function XYPolygon [2/3]

```C++
OpenOasis::CommImp::Spatial::XYPolygon::XYPolygon (
    const std::vector< XYPoint > & points
) 
```






### function XYPolygon [3/3]

```C++
OpenOasis::CommImp::Spatial::XYPolygon::XYPolygon (
    const XYPolygon & polygon
) 
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Spatial/XYGeoStructs.h`

