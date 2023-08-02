/** ***********************************************************************************
 *    @File      :  XYGeoStructs.cpp
 *    @Brief     :  To provide basic plane geometry data structures (no z coordinate).
 *
 ** ***********************************************************************************/
#include "XYGeoStructs.h"
#include "XYGeoTools.h"
#include "Cores/Utils/CommConstants.h"
#include "Cores/Utils/StringHelper.h"
#include "Cores/Utils/Exception.h"


namespace OpenOasis::CommImpl::Spatial
{
using namespace Utils;
using namespace std;


// struct XYPoint ---------------------------------------------------------------------

XYPoint::XYPoint(double coorX, double coorY)
{
    x = coorX;
    y = coorY;
}

XYPoint::XYPoint(const Coordinate &coor)
{
    x = coor.x;
    y = coor.y;
}

XYPoint::XYPoint(const XYPoint &point)
{
    x = point.x;
    y = point.y;
}


// struct XYLine ----------------------------------------------------------------------

XYLine::XYLine(double x1, double y1, double x2, double y2)
{
    point1 = XYPoint(x1, y1);
    point2 = XYPoint(x2, y2);
}

XYLine::XYLine(const XYPoint &p1, const XYPoint &p2)
{
    point1 = p1;
    point2 = p2;
}

XYLine::XYLine(const XYLine &line)
{
    point1 = line.point1;
    point2 = line.point2;
}

double XYLine::GetLength() const
{
    double dx = point2.x - point1.x;
    double dy = point2.y - point1.y;
    return sqrt(dx * dx + dy * dy);
}


// struct XYPolyline ------------------------------------------------------------------

XYPolyline::XYPolyline(const vector<XYPoint> &xyPoints)
{
    points = xyPoints;
}

XYPolyline::XYPolyline(const XYPolyline &pline)
{
    points = pline.points;
}

bool XYPolyline::Validate() const
{
    if (points.empty() || points.size() < 2)
    {
        throw runtime_error("Number of vertices in polyline element is less than 2.");
    }

    for (int i = 0; i < points.size() - 1; i++)
    {
        if (GetLine(i).GetLength() <= 0.0)
        {
            throw runtime_error(StringHelper::FormatSimple(
                "Length of line segment no: {} (0-based) of XYPolyline is zero.", i));
        }
    }

    return true;
}

XYLine XYPolyline::GetLine(int lineNumber) const
{
    if (points.empty() || lineNumber >= points.size())
    {
        throw runtime_error("The line segment index exceeds the XYPolyLine size.");
    }

    return XYLine(points[lineNumber - 1], points[lineNumber]);
}

double XYPolyline::GetLength() const
{
    if (points.empty())
        return 0.0;

    double len = 0.0;
    for (int i = 0; i < points.size() - 1; ++i)
    {
        len += GetLine(i).GetLength();
    }

    return len;
}


// struct XYPolygon -------------------------------------------------------------------

XYPolygon::XYPolygon(const vector<XYPoint> &xypoints)
{
    points = xypoints;
}

XYPolygon::XYPolygon(const XYPolygon &polygon)
{
    points = polygon.points;
}

bool XYPolygon::Validate() const
{
    if (points.empty() || points.size() < 3)
    {
        throw runtime_error("Number of vertices in polygon element is less than 3.");
    }

    if (GetArea() <= 0.0)
    {
        throw runtime_error("Area of polygon is negative or zero.");
    }

    for (int i = 0; i < points.size() - 1; i++)
    {
        if (GetLine(i).GetLength() <= 0.0)
        {
            throw runtime_error(StringHelper::FormatSimple(
                "Length of line segment no: {} (0-based) of XYPolyon is zero.", i));
        }

        for (int j = 0; j < i; ++j)
        {
            if (XYGeoTools::IsLinesIntersected(GetLine(j), GetLine(i)))
            {
                throw runtime_error(StringHelper::FormatSimple(
                    "Line no: {} and line no: {} of XYPolygon crosses.", j, i));
            }
        }
    }

    return true;
}

double XYPolygon::GetArea() const
{
    // For a polygon, Assuming the coordinates of each vertice are known:
    //  A1(x1, y1), A2(x2, y2), A3(x3, y3), ..., An(xn, yn),
    //
    // then, the area of the polygon is:
    //  S = 0.5 * |∑(x_i * y_i+1 - x_i+1 * y_i)|, for i = 0, ...n
    //
    // Among them, x_n+1 = x_1, y_n+1 = y_1.
    //

    if (points.empty() || points.size() < 3)
        return 0.0;

    auto   size = points.size();
    double area = 0.0;
    for (int i = 0; i < size - 1; ++i)
    {
        area += points[i].x * points[i + 1].y - points[i + 1].x * points[i].y;
    }

    area += points[size - 1].x * points[0].y - points[0].x * points[size - 1].y;
    area *= 0.5;
    return abs(area);
}

XYLine XYPolygon::GetLine(int lineNumber) const
{
    if (points.empty() || lineNumber >= points.size())
    {
        throw runtime_error("The line segment index exceeds the XYPolygon size.");
    }

    int index2 = (lineNumber == points.size() - 1) ? 0 : lineNumber + 1;
    return XYLine(points[lineNumber], points[index2]);
}

bool XYPolygon::IsConvex(int index) const
{
    // Acute angles are convex.

    if (points.empty())
    {
        return false;
    }

    auto prevIndex = (index - 1 < 0) ? points.size() - 1 : index - 1;
    auto nextIndex = (index + 1 > points.size() - 1) ? 0 : index + 1;

    const XYPoint &p1 = points[prevIndex], &p2 = points[nextIndex], &p = points[index];
    double         dot = (p1.x - p.x) * (p2.x - p.x) + (p1.y - p.y) * (p2.y - p.y);

    return (IsBigger(dot, 0.0)) ? true : false;
}


// struct XYExtent --------------------------------------------------------------------

XYExtent::XYExtent(const XYExtent &obj)
{
    xMin = obj.xMin;
    xMax = obj.xMax;
    yMin = obj.yMin;
    yMax = obj.yMax;
}

XYExtent::XYExtent(const XYPoint &point, double epsilon)
{
    xMin = point.x - epsilon;
    xMax = point.x + epsilon;
    yMin = point.y - epsilon;
    yMax = point.y + epsilon;
}

XYExtent::XYExtent(const XYLine &line)
{
    xMin = std::min(line.point1.x, line.point2.x);
    xMax = std::max(line.point1.x, line.point2.x);
    yMin = std::min(line.point1.y, line.point2.y);
    yMax = std::max(line.point1.y, line.point2.y);
}

XYExtent::XYExtent(const XYPolyline &polyline)
{
    for (const auto &p : polyline.points)
    {
        Include(p.x, p.y);
    }
}

XYExtent::XYExtent(const XYPolygon &polygon)
{
    for (const auto &p : polygon.points)
    {
        Include(p.x, p.y);
    }
}

XYExtent::XYExtent(double xmin, double xmax, double ymin, double ymax)
{
    xMin = xmin;
    xMax = xmax;
    yMin = ymin;
    yMax = ymax;
}

void XYExtent::Include(const XYExtent &other)
{
    if (other.xMin < xMin)
    {
        xMin = other.xMin;
    }
    if (other.xMax > xMax)
    {
        xMax = other.xMax;
    }
    if (other.yMin < yMin)
    {
        yMin = other.yMin;
    }
    if (other.yMax > yMax)
    {
        yMax = other.yMax;
    }
}

void XYExtent::Include(double x, double y)
{
    if (x < xMin)
    {
        xMin = x;
    }
    if (x > xMax)
    {
        xMax = x;
    }
    if (y < yMin)
    {
        yMin = y;
    }
    if (y > yMax)
    {
        yMax = y;
    }
}

bool XYExtent::IsContains(double x, double y) const
{
    return xMin <= x && x <= xMax && yMin <= y && y <= yMax;
}

bool XYExtent::IsOverlaps(const XYExtent &other) const
{
    return xMin <= other.xMax && xMax >= other.xMin && yMin <= other.yMax
           && yMax >= other.yMin;
}

}  // namespace OpenOasis::CommImpl::Spatial