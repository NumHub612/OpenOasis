

# File XYGeoStructs.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Spatial**](dir_47a0bcc12c466f07097ed8db741700fa.md) **>** [**XYGeoStructs.h**](_x_y_geo_structs_8h.md)

[Go to the documentation of this file](_x_y_geo_structs_8h.md)


```C++

#pragma once
#include "Coordinate.h"
#include <vector>


namespace OpenOasis
{
namespace CommImp
{
namespace Spatial
{
struct XYPoint
{
    double x = 0.;
    double y = 0.;

    XYPoint() = default;
    XYPoint(const XYPoint &obj);
    XYPoint(const Coordinate &coor);
    XYPoint(double coorX, double coorY);
};


struct XYLine
{
    XYPoint point1;  // The start XYPoint.
    XYPoint point2;  // The end XYPoint.

    XYLine() = default;
    XYLine(double x1, double y1, double x2, double y2);
    XYLine(const XYPoint &p1, const XYPoint &p2);
    XYLine(const XYLine &line);

    double GetLength() const;
};


struct XYPolyline
{
    std::vector<XYPoint> points;

    XYPolyline() = default;
    XYPolyline(const std::vector<XYPoint> &points);
    XYPolyline(const XYPolyline &pline);

    bool Validate() const;

    double GetLength() const;

    XYLine GetLine(int lineNumber) const;
};


struct XYPolygon
{
    std::vector<XYPoint> points;

    XYPolygon() = default;
    XYPolygon(const std::vector<XYPoint> &points);
    XYPolygon(const XYPolygon &polygon);

    bool Validate() const;

    double GetArea() const;

    XYLine GetLine(int lineNumber) const;

    bool IsConvex(int index) const;
};


struct XYExtent
{
    double xMin = 0.;
    double xMax = 0.;
    double yMin = 0.;
    double yMax = 0.;

    XYExtent() = default;
    XYExtent(const XYPoint &point, double epsilon);
    XYExtent(const XYLine &line);
    XYExtent(const XYPolyline &polyline);
    XYExtent(const XYPolygon &polygon);
    XYExtent(const XYExtent &obj);
    XYExtent(double xmin, double xmax, double ymin, double ymax);

    void Include(const XYExtent &other);

    void Include(double x, double y);

    bool IsContains(double x, double y) const;

    bool IsOverlaps(const XYExtent &other) const;
};

}  // namespace Spatial
}  // namespace CommImp
}  // namespace OpenOasis
```


