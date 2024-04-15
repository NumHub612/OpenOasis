

# Struct OpenOasis::CommImp::Spatial::XYPolyline



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Spatial**](namespace_open_oasis_1_1_comm_imp_1_1_spatial.md) **>** [**XYPolyline**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polyline.md)



[_**XYPolyline**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polyline.md) _is a collection of points (at least 2) connected with straigth lines. XYPolylines are typically used for presentation of 1D data, river network._

* `#include <XYGeoStructs.h>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  std::vector&lt; [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) &gt; | [**points**](#variable-points)  <br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  double | [**GetLength**](#function-getlength) () const<br>_Returns the cumulative calculating length of current line._  |
|  [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) | [**GetLine**](#function-getline) (int lineNumber) const<br>_Retrieves the lineNumber line segment of the polyline. The index list is zero based._  |
|  bool | [**Validate**](#function-validate) () const<br>_The validate method check if the_ [_**XYPolyline**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polyline.md) _is valid. The checks made are:_ |
|   | [**XYPolyline**](#function-xypolyline-13) () = default<br> |
|   | [**XYPolyline**](#function-xypolyline-23) (const std::vector&lt; [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) &gt; & points) <br> |
|   | [**XYPolyline**](#function-xypolyline-33) (const [**XYPolyline**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polyline.md) & pline) <br> |




























## Public Attributes Documentation




### variable points 

```C++
std::vector<XYPoint> OpenOasis::CommImp::Spatial::XYPolyline::points;
```



## Public Functions Documentation




### function GetLength 

```C++
double OpenOasis::CommImp::Spatial::XYPolyline::GetLength () const
```






### function GetLine 

```C++
XYLine OpenOasis::CommImp::Spatial::XYPolyline::GetLine (
    int lineNumber
) const
```






### function Validate 

_The validate method check if the_ [_**XYPolyline**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polyline.md) _is valid. The checks made are:_
```C++
bool OpenOasis::CommImp::Spatial::XYPolyline::Validate () const
```




* is number of points &gt;= 2
* is the length of all line segments positive






**Exception:**


* `Exception` is raised if these above constraints aren't met. 




        



### function XYPolyline [1/3]

```C++
OpenOasis::CommImp::Spatial::XYPolyline::XYPolyline () = default
```






### function XYPolyline [2/3]

```C++
OpenOasis::CommImp::Spatial::XYPolyline::XYPolyline (
    const std::vector< XYPoint > & points
) 
```






### function XYPolyline [3/3]

```C++
OpenOasis::CommImp::Spatial::XYPolyline::XYPolyline (
    const XYPolyline & pline
) 
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Spatial/XYGeoStructs.h`

