/** ***********************************************************************************
 *    @File      :  XYGeoTools.cpp
 *    @Brief     :  The XYGeoTools class is a collection of general geometry functions.
 *
 ** ***********************************************************************************/
#include "XYGeoTools.h"
#include "Models/Utils/Exception.h"
#include <algorithm>
#include <cmath>


namespace OpenOasis::CommImp::Spatial
{
using namespace Utils;
using namespace std;


// struct XYGeoTools ------------------------------------------------------------------

double XYGeoTools::CalculatePointToPointDistance(const XYPoint &p1, const XYPoint &p2)
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

bool XYGeoTools::IsLinesIntersected(const XYLine &l1, const XYLine &l2)
{
    // Vector A × B (× is the cross product):
    // if the result is less than 0,  then vector B is in the clockwise direction of A;
    // if result is greater than 0, vector B is in the counterclockwise direction of A;
    // if it's 0, that means that vector A is parallel to vector B.
    //
    // A(a1, b1), B(a2, b2), then: A × B = |a1 b1| = a1*b2 - a2*b1 = |A| * |B| * sin(θ).
    //                                     |a2 b2|
    //

    // 1. Fast Rejection Test,
    //    whether the projection of two line segments overlaps in x and y coordinates;
    // 2. Straddle Test,
    //    the cross product is used to judge the intersection of line segments.
    //

    const XYPoint &l1p1 = l1.point1, &l1p2 = l1.point2;
    const XYPoint &l2p1 = l2.point1, &l2p2 = l2.point2;

    // Fast rejection test.
    if (max(l1p1.x, l1p2.x) <= min(l2p1.x, l2p2.x)
        || max(l2p1.y, l2p2.y) <= min(l1p1.y, l1p2.y)
        || max(l2p1.x, l2p2.x) <= min(l1p1.x, l1p2.x)
        || max(l1p1.y, l1p2.y) <= min(l2p1.y, l2p2.y))
    {
        return false;  // line segment extents have no overlap.
    }

    // Straddle test.
    double l1det1 =
        (l1p1.x - l2p2.x) * (l2p1.y - l2p2.y) - (l1p1.y - l2p2.y) * (l2p1.x - l2p2.x);
    double l1det2 =
        (l1p2.x - l2p2.x) * (l2p1.y - l2p2.y) - (l1p2.y - l2p2.y) * (l2p1.x - l2p2.x);
    double l2det1 =
        (l2p1.x - l1p2.x) * (l1p1.y - l1p2.y) - (l2p1.y - l1p2.y) * (l1p1.x - l1p2.x);
    double l2det2 =
        (l2p2.x - l1p2.x) * (l1p1.y - l1p2.y) - (l2p2.y - l1p2.y) * (l1p1.x - l1p2.x);

    if (l1det1 * l1det2 >= EPSILON || l2det1 * l2det2 >= EPSILON)
    {
        return false;  // line segments not cross.
    }
    if (abs(l1det1 * l1det2) <= EPSILON && abs(l2det1 * l2det2) <= EPSILON)
    {
        return false;  // line segments are parrallel.
    }

    return true;
}

XYPoint XYGeoTools::CalculateIntersectionPoint(const XYLine &l1, const XYLine &l2)
{
    // Using the cross product to calculate the area and according to the ratio of
    // areas, calculate the proportional position of the intersection point `O` on
    // the line segment.
    // Then, using this scale to interpolate the coordinates.
    //

    if (!IsLinesIntersected(l1, l2))
    {
        throw runtime_error("Line segments have no intersection point.");
    }

    const XYPoint &l1p1 = l1.point1, &l1p2 = l1.point2;
    const XYPoint &l2p1 = l2.point1, &l2p2 = l2.point2;

    double area1 =
        (l1p2.x - l1p1.x) * (l2p1.y - l1p1.y) - (l1p2.y - l1p1.y) * (l2p1.x - l1p1.x);
    double area2 =
        (l1p2.x - l1p1.x) * (l2p2.y - l1p1.y) - (l1p2.y - l1p1.y) * (l2p2.x - l1p1.x);

    double lambda = abs(area1) / abs(area2);
    double x      = l2p1.x + lambda / (lambda + 1) * (l2p2.x - l2p1.x);
    double y      = l2p1.y + lambda / (lambda + 1) * (l2p2.y - l2p1.y);

    return XYPoint(x, y);
}

XYPoint XYGeoTools::CalculateMidpoint(const XYLine &line)
{
    double x = (line.point1.x + line.point2.x) / 2.;
    double y = (line.point1.y + line.point2.y) / 2.;
    return XYPoint(x, y);
}

double
XYGeoTools::CalculateLineToPointDistance(const XYLine &line, const XYPoint &point)
{
    const XYPoint &p1 = line.point1, &p2 = line.point2;

    // check if the line is a point actually.
    if (abs(line.GetLength()) <= EPSILON)  // p1 == p2.
    {
        return CalculatePointToPointDistance(point, p1);
    }

    // Point projected on line before P1, use distance to P1.
    double p2p1dotpp1 =
        (p2.x - p1.x) * (point.x - p1.x) + (p2.y - p1.y) * (point.y - p1.y);
    if (p2p1dotpp1 <= EPSILON)
    {
        return CalculatePointToPointDistance(point, p1);
    }

    // Point projected on line after P2, use distance to P2.
    double p2p1dotpp2 =
        (p2.x - p1.x) * (point.x - p2.x) + (p2.y - p1.y) * (point.y - p2.y);
    if (p2p1dotpp2 >= EPSILON)
    {
        return CalculatePointToPointDistance(point, p2);
    }

    // Point projected between P1 and P2, calculate distance to projection point.
    double p2p1crosspp1 =
        (p2.x - p1.x) * (point.y - p1.y) - (p2.y - p1.y) * (point.x - p1.x);
    return abs(p2p1crosspp1 / line.GetLength());
}

double XYGeoTools::CalculatePolylineToPointDistance(
    const XYPolyline &polyline, const XYPoint &point)
{
    if (polyline.points.empty())
    {
        return 0;
    }

    int    i    = 1;
    double dist = CalculateLineToPointDistance(polyline.GetLine(0), point);

    while (i < (int)polyline.points.size() - 1)
    {
        dist = min(dist, CalculateLineToPointDistance(polyline.GetLine(i++), point));
    }

    return dist;
}

double XYGeoTools::CalculateLengthOfPolylineInsidePolygon(
    const XYPolyline &polyline, const XYPolygon &polygon)
{
    double lengthInside         = 0;
    int    numberOfLineSegments = polyline.points.size() - 1;
    for (int i = 0; i < numberOfLineSegments; i++)
    {
        auto line = polyline.GetLine(i);
        lengthInside += CalculateLengthOfLineInsidePolygon(line, polygon);
    }
    return lengthInside;
}

bool XYGeoTools::IsPointInLine(const XYPoint &point, const XYLine &line)
{
    return (abs(CalculateLineToPointDistance(line, point)) <= EPSILON) ? true : false;
}

bool XYGeoTools::IsPointInPolygon(const XYPoint &point, const XYPolygon &polygon)
{
    // PNPoly algorithm (by W. Randolph Franklin), in general:
    //
    // For a polygon and a given point, draw a line horizontally through that point,
    // count how many times the line is compared to the edge of the polygon,
    // and then count the number of times the line crosses the polygon.
    //
    // If it's odd, the point is inside the polygon, otherwise it's outside polygon.
    //

    if (!polygon.Validate())
    {
        return false;
    }

    bool isInside = false;
    auto size     = (int)polygon.points.size();

    double x1, y1, x2, y2;
    for (int i = 0; i < size; i++)
    {
        if (i < size - 1)
        {
            x1 = polygon.points[i].x;
            y1 = polygon.points[i].y;
            x2 = polygon.points[i + 1].x;
            y2 = polygon.points[i + 1].y;
        }
        else
        {
            x1 = polygon.points[i].x;
            y1 = polygon.points[i].y;
            x2 = polygon.points[0].x;
            y2 = polygon.points[0].y;
        }

        if (point.y - min(y1, y2) >= EPSILON)
        {
            if (max(y1, y2) - point.y >= EPSILON)
            {
                if (max(x1, x2) - point.x >= EPSILON)
                {
                    if (abs(y1 - y2) > EPSILON)
                    {
                        double xinter = (point.y - y1) * (x2 - x1) / (y2 - y1) + x1;
                        if (abs(x1 - x2) <= EPSILON || xinter - point.x >= EPSILON)
                        {
                            isInside = !isInside;
                        }
                    }
                }
            }
        }
    }

    return isInside;
}

double
XYGeoTools::CalculateSharedArea(const XYPolygon &polygonA, const XYPolygon &polygonB)
{
    const auto &triangleListA = GetTriangulations(polygonA);
    const auto &triangleListB = GetTriangulations(polygonB);

    double area = 0;
    for (int ia = 0; ia < (int)triangleListA.size(); ia++)
    {
        const auto &triangleA = triangleListA[ia];

        for (int ib = 0; ib < (int)triangleListB.size(); ib++)
        {
            const auto &triangleB = triangleListB[ib];
            area = area + CalculateTriangleSharedArea(triangleA, triangleB);
        }
    }

    return area;
}

double XYGeoTools::CalculateTriangleSharedArea(
    const XYPolygon &triangleA, const XYPolygon &triangleB)
{
    try
    {
        if (triangleA.points.size() != 3 || triangleB.points.size() != 3)
        {
            throw runtime_error("Argument must be a polygon with 3 points");
        }

        int i = 1;  // Index for "next" node in polygon a.

        // Index for "next" node in polygon b.
        // -1 indicates that the first has not yet been found.
        int j = -1;

        double    area = 0;             // Intersection area.
        XYPolygon intersectionPolygon;  // Intersection polygon.

        // Latest intersection node found.
        XYPoint pIntersect(triangleA.points[0]);
        Intersect(triangleA, triangleB, pIntersect, i, j, intersectionPolygon);

        // First intersection point between triangles.
        XYPoint pFirst = pIntersect;

        if (j != -1)
        {
            // int  jStop    = IncrementModula(j, 3);
            bool complete = false;
            int  count    = 0;
            while (!complete)
            {
                // coordinates for vectors pointing to next triangleA and triangleB
                // point respectively.
                double vax = triangleA.points[i].x - pIntersect.x;
                double vay = triangleA.points[i].y - pIntersect.y;
                double vbx = triangleB.points[j].x - pIntersect.x;
                double vby = triangleB.points[j].y - pIntersect.y;

                // The sideOf tells if the vb vector or the va vector is the one
                // pointing "left" If sideOf is positive, vb is pointing left, otherwise
                // va is pointing left The "left" vector is the one that is inside the
                // polygon.
                double sideOf = vax * vby - vay * vbx;

                // Make sure to get out of EPSILON reach from the original point, hence
                // 2*EPSILON
                if (sideOf < 0
                    && IsPointInPolygon(
                        XYPoint(
                            pIntersect.x + 2 * EPSILON * vax,
                            pIntersect.y + 2 * EPSILON * vay),
                        triangleB))
                {
                    Intersect(
                        triangleA, triangleB, pIntersect, i, j, intersectionPolygon);
                }
                else if (
                    sideOf > 0
                    && IsPointInPolygon(
                        XYPoint(
                            pIntersect.x + 2 * EPSILON * vbx,
                            pIntersect.y + 2 * EPSILON * vby),
                        triangleA))
                {
                    Intersect(
                        triangleB, triangleA, pIntersect, j, i, intersectionPolygon);
                }
                // can be true if the point is on the edge of the triangleB.
                // TODO: Replace with IsPointOnEdge of triangleB.
                else if (IsPointInPolygon(
                             XYPoint(
                                 pIntersect.x + 2 * EPSILON * vax,
                                 pIntersect.y + 2 * EPSILON * vay),
                             triangleB))
                {
                    Intersect(
                        triangleA, triangleB, pIntersect, i, j, intersectionPolygon);
                }
                // can be true if the point is on the edge of the triangleA
                // Should never happen, since above test basically does the same.
                // TODO: Replace with IsPointOnEdge of triangleA
                else if (IsPointInPolygon(
                             XYPoint(
                                 pIntersect.x + 2 * EPSILON * vbx,
                                 pIntersect.y + 2 * EPSILON * vby),
                             triangleA))
                {
                    Intersect(
                        triangleB, triangleA, pIntersect, j, i, intersectionPolygon);
                }
                // triangleA and triangleB only touches one another but do not
                // intersect
                else
                {
                    area = 0;
                    return area;
                }
                if (!intersectionPolygon.points.empty())
                {
                    complete =
                        (CalculatePointToPointDistance(pIntersect, pFirst) < EPSILON);
                }
                count++;
                if (count > 20)
                {
                    throw runtime_error("Failed to find intersection polygon");
                }
            }
            area = intersectionPolygon.GetArea();
        }
        else
        {
            // internal point in triangle a
            const auto &pointsA = triangleA.points;
            double      xPa     = (pointsA[0].x + pointsA[1].x + pointsA[2].x) / 3.0;
            double      yPa     = (pointsA[0].y + pointsA[1].y + pointsA[2].y) / 3.0;

            XYPoint pa(xPa, yPa);

            // internal point in triangle b
            const auto &pointsB = triangleB.points;
            double      xPb     = (pointsB[0].x + pointsB[1].x + pointsB[2].x) / 3.0;
            double      yPb     = (pointsB[0].y + pointsB[1].y + pointsB[2].y) / 3.0;

            XYPoint pb(xPb, yPb);

            if (IsPointInPolygon(pa, triangleB)
                || IsPointInPolygon(
                    pb, triangleA))  // triangleA is completely inside triangleB
            {
                area = min(triangleA.GetArea(), triangleB.GetArea());
            }
            else  // triangleA and triangleB do dot intersect
            {
                area = 0;
            }
        }

        return area;
    }
    catch (const runtime_error &e)
    {
        throw runtime_error("GetTriangleSharedArea failed");
    }
}

vector<XYPolygon> XYGeoTools::GetTriangulations(const XYPolygon &polygon)
{
    if (!polygon.Validate())
    {
        throw runtime_error("Invalid Polygon object.");
    }

    XYPolygon         localPolygon(polygon);
    vector<XYPolygon> triangleList;

    while (localPolygon.points.size() > 3)
    {
        int  i    = FindTrianglePoints(localPolygon);
        auto n    = (int)localPolygon.points.size();
        auto prev = (i == 0) ? n - 1 : i - 1;
        auto next = (i == n - 1) ? 0 : i + 1;

        XYPolygon triangle;
        triangle.points.push_back(localPolygon.points[prev]);
        triangle.points.push_back(localPolygon.points[i]);
        triangle.points.push_back(localPolygon.points[next]);

        triangleList.push_back(triangle);
        localPolygon.points.erase(localPolygon.points.begin() + i);
    }

    triangleList.push_back(localPolygon);
    return triangleList;
}

int XYGeoTools::FindTrianglePoints(const XYPolygon &polygon)
{
    bool found = false;
    int  i     = 0;

    while (i < (int)polygon.points.size() && !found)
    {
        if (polygon.IsConvex(i) && !IsTriangleIntersected(polygon, i))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }

    return i;
}

bool XYGeoTools::IsTriangleIntersected(const XYPolygon &polygon, int index)
{
    const auto &points    = polygon.points;
    auto        prevIndex = (index - 1 < 0) ? (int)points.size() - 1 : index - 1;
    auto        nextIndex = (index + 1 > (int)points.size() - 1) ? 0 : index + 1;

    const XYPoint &p1 = points[prevIndex], &p = points[index], &p2 = points[nextIndex];

    XYPolygon triangulation;
    triangulation.points.push_back(p1);
    triangulation.points.push_back(p);
    triangulation.points.push_back(p2);

    int  i           = 0;
    bool insertected = false;
    while (i < (int)points.size() - 1 && !insertected)
    {
        bool skip = (i == index || i == prevIndex || i == nextIndex);
        if (!skip && IsPointInPolygon(points[i], triangulation))
        {
            return true;
        }
        else
        {
            i++;
        }
    }

    return insertected;
}

double XYGeoTools::CalculateSharedLength(const XYLine &lineA, const XYLine &lineB)
{
    if (abs(lineA.point2.x - lineA.point1.x) < EPSILON
        && abs(lineB.point2.x - lineB.point1.x) < EPSILON
        && abs(lineA.point1.x - lineB.point1.x) < EPSILON)
    {
        double YP1A = min(lineA.point1.y, lineA.point2.y);
        double YP2A = max(lineA.point1.y, lineA.point2.y);
        double YP1B = min(lineB.point1.y, lineB.point2.y);
        double YP2B = max(lineB.point1.y, lineB.point2.y);

        double YP1 = max(YP1A, YP1B);
        double YP2 = min(YP2A, YP2B);
        if (YP1 < YP2)
        {
            return YP2 - YP1;
        }
        else
        {
            return 0;
        }
    }
    else if (
        abs(lineA.point2.x - lineA.point1.x) < EPSILON
        || abs(lineB.point2.x - lineB.point1.x) < EPSILON)
    {
        return 0;
    }
    else
    {
        XYPoint P1A, P2A;
        if (lineA.point1.x < lineA.point2.x)
        {
            P1A = lineA.point1;
            P2A = lineA.point2;
        }
        else
        {
            P1A = lineA.point2;
            P2A = lineA.point1;
        }
        XYPoint P1B, P2B;
        if (lineB.point1.x < lineB.point2.x)
        {
            P1B = lineB.point1;
            P2B = lineB.point2;
        }
        else
        {
            P1B = lineB.point2;
            P2B = lineB.point1;
        }

        double alphaA = (P2A.y - P1A.y) / (P2A.x - P1A.x);
        double betaA  = -alphaA * P2A.x + P2A.y;
        double alphaB = (P2B.y - P1B.y) / (P2B.x - P1B.x);
        double betaB  = -alphaA * P2B.x + P2B.y;
        if (abs(alphaA - alphaB) < EPSILON && abs(betaA - betaB) < EPSILON)
        {
            double x1 = max(P1A.x, P1B.x);
            double x2 = min(P2A.x, P2B.x);
            if (x1 < x2)
            {
                XYLine line(x1, alphaA * x1 + betaA, x2, alphaA * x2 + betaA);

                return line.GetLength();
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
}

double XYGeoTools::CalculateLengthOfLineInsidePolygon(
    const XYLine &line, const XYPolygon &polygon)
{
    vector<XYLine> lineList{line};

    for (int i = 0; i < (int)polygon.points.size(); i++)  // All lines in the polygon
    {
        for (int n = 0; n < (int)lineList.size(); n++)
        {
            if (lineList.size() > 1000)
            {
                throw runtime_error("Line has been cut in more than 1000 pieces.");
            }

            if (IsLinesIntersected(lineList[n], polygon.GetLine(i)))
            {
                // Split the intersecting line into two lines
                XYPoint IntersectionPoint(
                    CalculateIntersectionPoint(lineList[n], polygon.GetLine(i)));

                XYLine tempVar(IntersectionPoint, lineList[n].point2);
                lineList.push_back(tempVar);
                lineList[n].point2.x = IntersectionPoint.x;
                lineList[n].point2.y = IntersectionPoint.y;

                break;
            }
        }
    }

    for (int i = 0; i < (int)lineList.size(); i++)
    {
        if (lineList.size() > 1000)
        {
            throw runtime_error("Line has been cuttes in more than 100 pieces.");
        }
        for (int j = 0; j < (int)polygon.points.size(); j++)
        {
            if (IsPointInLineInterior(polygon.GetLine(j).point1, lineList[i]))
            {
                XYLine tempVar2(polygon.GetLine(j).point1, lineList[i].point2);
                lineList.push_back(tempVar2);
                lineList[i].point2.x = polygon.GetLine(j).point1.x;
                lineList[i].point2.y = polygon.GetLine(j).point1.y;
            }
        }
    }

    double lengthInside = 0;
    for (int i = 0; i < (int)lineList.size(); i++)
    {
        double sharedLength = 0;
        for (int j = 0; j < (int)polygon.points.size(); j++)
        {
            sharedLength += CalculateSharedLength(lineList[i], polygon.GetLine(j));
        }
        if (sharedLength > EPSILON)
        {
            lengthInside += sharedLength / 2;
        }
        else if (IsPointInPolygon(CalculateMidpoint(lineList[i]), polygon))
        {
            lengthInside += lineList[i].GetLength();
        }
    }
    return lengthInside;
}

bool XYGeoTools::IntersectionPoint(
    const XYLine &LineA, const XYLine &LineB, XYPoint &intersectionPoint)
{
    if (IsLinesIntersected(LineA, LineB))
    {
        intersectionPoint = CalculateIntersectionPoint(LineA, LineB);
        return true;
    }
    if (IsPointInLine(LineA.point2, LineB))
    {
        intersectionPoint = LineA.point2;
        return true;
    }
    if (IsPointInLine(LineB.point2, LineA))
    {
        intersectionPoint = LineB.point2;
        return true;
    }
    if (IsPointInLine(LineB.point1, LineA))
    {
        intersectionPoint = LineB.point1;
        return true;
    }
    if (IsPointInLine(LineA.point1, LineB))
    {
        intersectionPoint = LineA.point1;
        return true;
    }

    return false;
}

bool XYGeoTools::IsPointInLineInterior(const XYPoint &point, const XYLine &line)
{
    // TODO: Update to use projection method instead, see IsPointInLine.

    bool result = false;
    if (line.point1.x - line.point2.x != 0)  // line is not vertical
    {
        if ((point.x > min(line.point1.x, line.point2.x))
            && (point.x < max(line.point1.x, line.point2.x)))
        {
            if (abs(point.y - line.point1.y
                    - (line.point2.y - line.point1.y) / (line.point1.x - line.point2.x)
                          * (line.point1.x - point.x))
                < EPSILON * EPSILON)
            {
                result = true;
            }
        }
    }
    else  // line is vertical
    {
        if (line.point1.x == point.x)
        {
            if ((point.y > min(line.point1.y, line.point2.y))
                && (point.y < max(line.point1.y, line.point2.y)))
            {
                result = true;
            }
        }
    }
    return result;
}

void XYGeoTools::Intersect(
    const XYPolygon &triangleA, const XYPolygon &triangleB, XYPoint &p, int &i, int &j,
    XYPolygon &intersectionPolygon)
{
    XYLine lineA;
    XYLine lineB;

    int  im1    = DecrementModula(i, 3);  // "i-1"
    int  count1 = 0;
    bool found  = false;

    while ((count1 < 3) && (!found))
    {
        lineA = triangleA.GetLine(im1);
        if (count1 == 0)
        {
            lineA        = XYLine(lineA);
            lineA.point1 = p;
        }

        double MinDist  = -1;  // Distance used when a line is crossed more than once.
        int    jm1      = 0;   // "j-1"
        int    jm1Store = -1;
        while (jm1 < 3)
        {
            lineB       = triangleB.GetLine(jm1);
            found       = IntersectionPoint(lineA, lineB, p);
            double Dist = CalculatePointToPointDistance(lineA.point1, p);
            if (Dist < EPSILON)
            {
                found = false;
            }
            if (found)
            {
                if ((MinDist < 0) || (Dist < MinDist))
                {
                    MinDist  = Dist;
                    jm1Store = jm1;
                }
            }
            jm1++;
        }

        if (jm1Store > -1)
        {
            lineB = triangleB.GetLine(jm1Store);
            found = IntersectionPoint(lineA, lineB, p);

            XYPoint HelpCoordinate(p);
            XYPoint HelpNode(HelpCoordinate);
            intersectionPolygon.points.push_back(HelpNode);

            j = IncrementModula(jm1Store, 3);
        }

        if (!found)
        {
            count1++;
            im1 = IncrementModula(im1, 3);
            i   = IncrementModula(i, 3);
            if (j != -1)
            {
                XYPoint HelpCoordinate(lineA.point2);
                XYPoint HelpNode(HelpCoordinate);
                intersectionPolygon.points.push_back(HelpNode);
            }
        }
    }

    lineA = triangleA.GetLine(DecrementModula(i, 3));
    if (CalculatePointToPointDistance(p, lineA.point2) < EPSILON)
    {
        i = IncrementModula(i, 3);
    }

    lineB = triangleB.GetLine(DecrementModula(j, 3));
    if (CalculatePointToPointDistance(p, lineB.point2) < EPSILON)
    {
        j = IncrementModula(j, 3);
    }
}

int XYGeoTools::IncrementModula(int i, int n)
{
    i++;
    i %= n;
    return i;
}

int XYGeoTools::DecrementModula(int i, int n)
{
    i--;
    if (i < 0)
    {
        i = n - 1;
    }
    return i;
}

}  // namespace OpenOasis::CommImp::Spatial