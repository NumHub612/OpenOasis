

# Class OpenOasis::CommImp::Spatial::XYGeoTools



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Spatial**](namespace_open_oasis_1_1_comm_imp_1_1_spatial.md) **>** [**XYGeoTools**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_geo_tools.md)



_The_ [_**XYGeoTools**_](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_geo_tools.md) _class is a collection of general geometry functions._

* `#include <XYGeoTools.h>`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr double | [**EPSILON**](#variable-epsilon)   = = 1.0e-5<br> |
















## Public Static Functions

| Type | Name |
| ---: | :--- |
|  [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) | [**CalculateIntersectionPoint**](#function-calculateintersectionpoint) (const [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) & l1, const [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) & l2) <br>_Calculates intersection point between two line segments._  |
|  double | [**CalculateLengthOfLineInsidePolygon**](#function-calculatelengthoflineinsidepolygon) (const [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) & line, const [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) & polygon) <br>_Calculates length of line inside polygon. Parts of the line that is on the edge of the polygon only counts with half their length._  |
|  double | [**CalculateLengthOfPolylineInsidePolygon**](#function-calculatelengthofpolylineinsidepolygon) (const [**XYPolyline**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polyline.md) & polyline, const [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) & polygon) <br>_Calculates the length of polyline inside polygon. Lines segments on the edges of polygons are included with half their length._  |
|  double | [**CalculateLineToPointDistance**](#function-calculatelinetopointdistance) (const [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) & line, const [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) & point) <br>_Calculates the distance between a point and a line segment._  |
|  [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) | [**CalculateMidpoint**](#function-calculatemidpoint) (const [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) & line) <br>_Calculates line segment midpoint._  |
|  double | [**CalculatePointToPointDistance**](#function-calculatepointtopointdistance) (const [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) & p1, const [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) & p2) <br>_Calculates the distance between two points._  |
|  double | [**CalculatePolylineToPointDistance**](#function-calculatepolylinetopointdistance) (const [**XYPolyline**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polyline.md) & polyline, const [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) & point) <br>_Calculates the shortest distance between any line segment of the polyline and the point._  |
|  double | [**CalculateSharedArea**](#function-calculatesharedarea) (const [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) & polygonA, const [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) & polygonB) <br>_Calculates the shared area of two arbitrarily shaped polygons._  |
|  std::vector&lt; [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) &gt; | [**GetTriangulations**](#function-gettriangulations) (const [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) & polygon) <br>_Returns a list of triangles of type_ [_**XYPolygon**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) _describing the triangalation of the polygon._ |
|  bool | [**IsLinesIntersected**](#function-islinesintersected) (const [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) & l1, const [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) & l2) <br>_Checks if two line segments intersects._  |
|  bool | [**IsPointInLine**](#function-ispointinline) (const [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) & point, const [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) & line) <br>_Determines if point is included in a line either in the interior or as one of the end points._  |
|  bool | [**IsPointInPolygon**](#function-ispointinpolygon) (const [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) & point, const [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) & polygon) <br>_Determines if a point is inside or outside a polygon. Inside includes on the edge for this method._  |
























## Protected Static Functions

| Type | Name |
| ---: | :--- |
|  double | [**CalculateSharedLength**](#function-calculatesharedlength) (const [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) & lineA, const [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) & lineB) <br>_Calculates the length that two lines overlap._  |
|  double | [**CalculateTriangleSharedArea**](#function-calculatetrianglesharedarea) (const [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) & triangleA, const [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) & triangleB) <br>_Calculates the intersection area of triangle xypolygon a and b._  |
|  int | [**DecrementModula**](#function-decrementmodula) (int i, int n) <br>_The method steps to the previous index in a circular list {0, ..., n-1}._  |
|  int | [**FindTrianglePoints**](#function-findtrianglepoints) (const [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) & polygon) <br>_Finds a set of three concecutive points that form a triangle, that is not intersected by other parts of the polygon._  |
|  int | [**IncrementModula**](#function-incrementmodula) (int i, int n) <br>_The method steps to the next index in a circular list {0, ..., n-1}._  |
|  void | [**Intersect**](#function-intersect) (const [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) & triangleA, const [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) & triangleB, [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) & p, int & i, int & j, [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) & intersectionPolygon) <br>_Calculates the intersection points of triangle xypolygon a and b._  |
|  bool | [**IntersectionPoint**](#function-intersectionpoint) (const [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) & LineA, const [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) & LineB, [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) & intersectionPoint) <br>_Checks if the lines lineA and lineB shares a point either as a real crossing point or as a shared end point or a end point of the one line being in the other line._  |
|  bool | [**IsPointInLineInterior**](#function-ispointinlineinterior) (const [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) & point, const [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) & line) <br>_Determines if a point is included in a lines interior and not an endpoint._  |
|  bool | [**IsTriangleIntersected**](#function-istriangleintersected) (const [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) & polygon, int i) <br>_Determines if the triangle formed by P(i-1), P(i) and P(i+1) from Polygon are intersected by any of the other points of the polygon._  |


## Public Static Attributes Documentation




### variable EPSILON 

```C++
constexpr double OpenOasis::CommImp::Spatial::XYGeoTools::EPSILON;
```



## Public Static Functions Documentation




### function CalculateIntersectionPoint 

```C++
static XYPoint OpenOasis::CommImp::Spatial::XYGeoTools::CalculateIntersectionPoint (
    const XYLine & l1,
    const XYLine & l2
) 
```






### function CalculateLengthOfLineInsidePolygon 

```C++
static double OpenOasis::CommImp::Spatial::XYGeoTools::CalculateLengthOfLineInsidePolygon (
    const XYLine & line,
    const XYPolygon & polygon
) 
```






### function CalculateLengthOfPolylineInsidePolygon 

```C++
static double OpenOasis::CommImp::Spatial::XYGeoTools::CalculateLengthOfPolylineInsidePolygon (
    const XYPolyline & polyline,
    const XYPolygon & polygon
) 
```






### function CalculateLineToPointDistance 

```C++
static double OpenOasis::CommImp::Spatial::XYGeoTools::CalculateLineToPointDistance (
    const XYLine & line,
    const XYPoint & point
) 
```






### function CalculateMidpoint 

```C++
static XYPoint OpenOasis::CommImp::Spatial::XYGeoTools::CalculateMidpoint (
    const XYLine & line
) 
```






### function CalculatePointToPointDistance 

```C++
static double OpenOasis::CommImp::Spatial::XYGeoTools::CalculatePointToPointDistance (
    const XYPoint & p1,
    const XYPoint & p2
) 
```






### function CalculatePolylineToPointDistance 

```C++
static double OpenOasis::CommImp::Spatial::XYGeoTools::CalculatePolylineToPointDistance (
    const XYPolyline & polyline,
    const XYPoint & point
) 
```






### function CalculateSharedArea 

```C++
static double OpenOasis::CommImp::Spatial::XYGeoTools::CalculateSharedArea (
    const XYPolygon & polygonA,
    const XYPolygon & polygonB
) 
```






### function GetTriangulations 

```C++
static std::vector< XYPolygon > OpenOasis::CommImp::Spatial::XYGeoTools::GetTriangulations (
    const XYPolygon & polygon
) 
```






### function IsLinesIntersected 

_Checks if two line segments intersects._ 
```C++
static bool OpenOasis::CommImp::Spatial::XYGeoTools::IsLinesIntersected (
    const XYLine & l1,
    const XYLine & l2
) 
```



The lines are setted to intersected if the lines axctually cross or only share a point, and not if the lines are parrallel. 


        



### function IsPointInLine 

```C++
static bool OpenOasis::CommImp::Spatial::XYGeoTools::IsPointInLine (
    const XYPoint & point,
    const XYLine & line
) 
```






### function IsPointInPolygon 

```C++
static bool OpenOasis::CommImp::Spatial::XYGeoTools::IsPointInPolygon (
    const XYPoint & point,
    const XYPolygon & polygon
) 
```



## Protected Static Functions Documentation




### function CalculateSharedLength 

```C++
static double OpenOasis::CommImp::Spatial::XYGeoTools::CalculateSharedLength (
    const XYLine & lineA,
    const XYLine & lineB
) 
```






### function CalculateTriangleSharedArea 

```C++
static double OpenOasis::CommImp::Spatial::XYGeoTools::CalculateTriangleSharedArea (
    const XYPolygon & triangleA,
    const XYPolygon & triangleB
) 
```






### function DecrementModula 

_The method steps to the previous index in a circular list {0, ..., n-1}._ 
```C++
static int OpenOasis::CommImp::Spatial::XYGeoTools::DecrementModula (
    int i,
    int n
) 
```





**Parameters:**


* `i` Index to decrease.. 
* `n` Module value, one larger than largest index. 



**Returns:**

The decreased index. 





        



### function FindTrianglePoints 

_Finds a set of three concecutive points that form a triangle, that is not intersected by other parts of the polygon._ 
```C++
static int OpenOasis::CommImp::Spatial::XYGeoTools::FindTrianglePoints (
    const XYPolygon & polygon
) 
```





**Returns:**

Index for the "midlle" point of triangle that forms an ear. The ear is formed by P(i-1), P(i) and P(i+1), where P are points included in the polygon. 





        



### function IncrementModula 

_The method steps to the next index in a circular list {0, ..., n-1}._ 
```C++
static int OpenOasis::CommImp::Spatial::XYGeoTools::IncrementModula (
    int i,
    int n
) 
```





**Parameters:**


* `i` Index to increase. 
* `n` Modula value, one larger than largest index. 



**Returns:**

The increased index. 





        



### function Intersect 

_Calculates the intersection points of triangle xypolygon a and b._ 
```C++
static void OpenOasis::CommImp::Spatial::XYGeoTools::Intersect (
    const XYPolygon & triangleA,
    const XYPolygon & triangleB,
    XYPoint & p,
    int & i,
    int & j,
    XYPolygon & intersectionPolygon
) 
```





**Parameters:**


* `triangleA` triangle. The search is started along triangleA. 
* `triangleB` triangle. Intersection with the triangle are sought. 
* `p` Starting point for the search.
  * p must be part of triangleA. 


* `i` 
  * on input: End index for the first line segment of triangleA.
  * on output: End index for the last intersected line segment in triangleA. 


* `j` 
  * on input: -1 if vertices before intersection isn't to be added.
  * on output: End index for last intersected line of triangleB. 


* `intersectionPolygon` Polygon eventually describing the intersection area between triangleA and triangleB.



**Returns:**

The p, i, j and intersectionPolygon are called by reference and modified in the method. 





        



### function IntersectionPoint 

```C++
static bool OpenOasis::CommImp::Spatial::XYGeoTools::IntersectionPoint (
    const XYLine & LineA,
    const XYLine & LineB,
    XYPoint & intersectionPoint
) 
```






### function IsPointInLineInterior 

```C++
static bool OpenOasis::CommImp::Spatial::XYGeoTools::IsPointInLineInterior (
    const XYPoint & point,
    const XYLine & line
) 
```






### function IsTriangleIntersected 

_Determines if the triangle formed by P(i-1), P(i) and P(i+1) from Polygon are intersected by any of the other points of the polygon._ 
```C++
static bool OpenOasis::CommImp::Spatial::XYGeoTools::IsTriangleIntersected (
    const XYPolygon & polygon,
    int i
) 
```





**Parameters:**


* `i` Middle index for the three points that forms the triangle. 



**Returns:**

true, If the triangle P(i-1), P(i), P(i+1) is intersected by other parts of Polygon; false, otherwise. 





        

------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Spatial/XYGeoTools.h`

