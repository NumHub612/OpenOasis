

# File XYGeoTools.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Spatial**](dir_47a0bcc12c466f07097ed8db741700fa.md) **>** [**XYGeoTools.h**](_x_y_geo_tools_8h.md)

[Go to the documentation of this file](_x_y_geo_tools_8h.md)


```C++

#pragma once
#include "XYGeoStructs.h"


namespace OpenOasis
{
namespace CommImp
{
namespace Spatial
{
class XYGeoTools final
{
public:
    static constexpr double EPSILON = 1.0e-5;

    static double CalculatePointToPointDistance(const XYPoint &p1, const XYPoint &p2);

    static bool IsLinesIntersected(const XYLine &l1, const XYLine &l2);

    static XYPoint CalculateIntersectionPoint(const XYLine &l1, const XYLine &l2);

    static XYPoint CalculateMidpoint(const XYLine &line);

    static double
    CalculateLineToPointDistance(const XYLine &line, const XYPoint &point);

    static double
    CalculatePolylineToPointDistance(const XYPolyline &polyline, const XYPoint &point);

    static bool IsPointInLine(const XYPoint &point, const XYLine &line);

    static double
    CalculateSharedArea(const XYPolygon &polygonA, const XYPolygon &polygonB);

    static bool IsPointInPolygon(const XYPoint &point, const XYPolygon &polygon);

    static std::vector<XYPolygon> GetTriangulations(const XYPolygon &polygon);

    static double
    CalculateLengthOfLineInsidePolygon(const XYLine &line, const XYPolygon &polygon);

    static double CalculateLengthOfPolylineInsidePolygon(
        const XYPolyline &polyline, const XYPolygon &polygon);

protected:
    static int FindTrianglePoints(const XYPolygon &polygon);

    static bool IsTriangleIntersected(const XYPolygon &polygon, int i);

    static double
    CalculateTriangleSharedArea(const XYPolygon &triangleA, const XYPolygon &triangleB);

    static double CalculateSharedLength(const XYLine &lineA, const XYLine &lineB);

    static bool IntersectionPoint(
        const XYLine &LineA, const XYLine &LineB, XYPoint &intersectionPoint);

    static bool IsPointInLineInterior(const XYPoint &point, const XYLine &line);

    static void Intersect(
        const XYPolygon &triangleA, const XYPolygon &triangleB, XYPoint &p, int &i,
        int &j, XYPolygon &intersectionPolygon);

    static int IncrementModula(int i, int n);

    static int DecrementModula(int i, int n);
};

}  // namespace Spatial
}  // namespace CommImp
}  // namespace OpenOasis
```


