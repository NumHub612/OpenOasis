

# Struct OpenOasis::CommImp::Spatial::XYPoint



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Spatial**](namespace_open_oasis_1_1_comm_imp_1_1_spatial.md) **>** [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md)



[_**XYPoint**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) _is simply a x and y coordinate point (has no z coordinate)._

* `#include <XYGeoStructs.h>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  double | [**x**](#variable-x)   = = 0.<br> |
|  double | [**y**](#variable-y)   = = 0.<br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**XYPoint**](#function-xypoint-14) () = default<br> |
|   | [**XYPoint**](#function-xypoint-24) (const [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) & obj) <br> |
|   | [**XYPoint**](#function-xypoint-34) (const [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) & coor) <br> |
|   | [**XYPoint**](#function-xypoint-44) (double coorX, double coorY) <br> |




























## Public Attributes Documentation




### variable x 

```C++
double OpenOasis::CommImp::Spatial::XYPoint::x;
```






### variable y 

```C++
double OpenOasis::CommImp::Spatial::XYPoint::y;
```



## Public Functions Documentation




### function XYPoint [1/4]

```C++
OpenOasis::CommImp::Spatial::XYPoint::XYPoint () = default
```






### function XYPoint [2/4]

```C++
OpenOasis::CommImp::Spatial::XYPoint::XYPoint (
    const XYPoint & obj
) 
```






### function XYPoint [3/4]

```C++
OpenOasis::CommImp::Spatial::XYPoint::XYPoint (
    const Coordinate & coor
) 
```






### function XYPoint [4/4]

```C++
OpenOasis::CommImp::Spatial::XYPoint::XYPoint (
    double coorX,
    double coorY
) 
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Spatial/XYGeoStructs.h`

