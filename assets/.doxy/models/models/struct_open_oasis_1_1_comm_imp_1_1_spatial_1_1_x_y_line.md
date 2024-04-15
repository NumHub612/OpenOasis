

# Struct OpenOasis::CommImp::Spatial::XYLine



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Spatial**](namespace_open_oasis_1_1_comm_imp_1_1_spatial.md) **>** [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md)



_The XYline struct is used for representing a line segment._ 

* `#include <XYGeoStructs.h>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) | [**point1**](#variable-point1)  <br> |
|  [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) | [**point2**](#variable-point2)  <br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  double | [**GetLength**](#function-getlength) () const<br> |
|   | [**XYLine**](#function-xyline-14) () = default<br> |
|   | [**XYLine**](#function-xyline-24) (double x1, double y1, double x2, double y2) <br> |
|   | [**XYLine**](#function-xyline-34) (const [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) & p1, const [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) & p2) <br> |
|   | [**XYLine**](#function-xyline-44) (const [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) & line) <br> |




























## Public Attributes Documentation




### variable point1 

```C++
XYPoint OpenOasis::CommImp::Spatial::XYLine::point1;
```






### variable point2 

```C++
XYPoint OpenOasis::CommImp::Spatial::XYLine::point2;
```



## Public Functions Documentation




### function GetLength 

```C++
double OpenOasis::CommImp::Spatial::XYLine::GetLength () const
```






### function XYLine [1/4]

```C++
OpenOasis::CommImp::Spatial::XYLine::XYLine () = default
```






### function XYLine [2/4]

```C++
OpenOasis::CommImp::Spatial::XYLine::XYLine (
    double x1,
    double y1,
    double x2,
    double y2
) 
```






### function XYLine [3/4]

```C++
OpenOasis::CommImp::Spatial::XYLine::XYLine (
    const XYPoint & p1,
    const XYPoint & p2
) 
```






### function XYLine [4/4]

```C++
OpenOasis::CommImp::Spatial::XYLine::XYLine (
    const XYLine & line
) 
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Spatial/XYGeoStructs.h`

