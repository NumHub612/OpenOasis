/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  XYGeoTools.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  The XYGeoTools class is a collection of general geometry functions.
 *
 ** ***********************************************************************************/
#pragma once
#include "XYGeoStructs.h"


namespace OpenOasis
{
namespace CommImp
{
namespace Spatial
{
/// @brief The XYGeoTools class is a collection of general geometry functions.
class XYGeoTools final
{
public:
    static constexpr double EPSILON = 1.0e-5;

    /// @brief Calculates the distance between two points.
    static double CalculatePointToPointDistance(const XYPoint &p1, const XYPoint &p2);

    /// @brief Checks if two line segments intersects.
    ///
    /// The lines are setted to intersected if the lines axctually cross or only share
    /// a point, and not if the lines are parrallel.
    static bool IsLinesIntersected(const XYLine &l1, const XYLine &l2);

    /// @brief Calculates intersection point between two line segments.
    static XYPoint CalculateIntersectionPoint(const XYLine &l1, const XYLine &l2);

    /// @brief Calculates line segment midpoint.
    static XYPoint CalculateMidpoint(const XYLine &line);

    /// @brief Calculates the distance between a point and a line segment.
    static double
    CalculateLineToPointDistance(const XYLine &line, const XYPoint &point);

    /// @brief Calculates the shortest distance between any line segment of the
    /// polyline and the point.
    static double
    CalculatePolylineToPointDistance(const XYPolyline &polyline, const XYPoint &point);

    /// @brief Determines if point is included in a line either in the interior
    /// or as one of the end points.
    static bool IsPointInLine(const XYPoint &point, const XYLine &line);

    /// @brief Calculates the shared area of two arbitrarily shaped polygons.
    static double
    CalculateSharedArea(const XYPolygon &polygonA, const XYPolygon &polygonB);

    /// @brief Determines if a point is inside or outside a polygon.
    /// Inside includes on the edge for this method.
    static bool IsPointInPolygon(const XYPoint &point, const XYPolygon &polygon);

    /// @brief Returns a list of triangles of type XYPolygon describing
    /// the triangalation of the polygon.
    static std::vector<XYPolygon> GetTriangulations(const XYPolygon &polygon);

    /// @brief Calculates length of line inside polygon. Parts of the line that
    /// is on the edge of the polygon only counts with half their length.
    static double
    CalculateLengthOfLineInsidePolygon(const XYLine &line, const XYPolygon &polygon);

    /// @brief Calculates the length of polyline inside polygon.
    /// Lines segments on the edges of polygons are included with half their length.
    static double CalculateLengthOfPolylineInsidePolygon(
        const XYPolyline &polyline, const XYPolygon &polygon);

protected:
    /// @brief Finds a set of three concecutive points that form a triangle,
    /// that is not intersected by other parts of the polygon.
    ///
    /// @returns Index for the "midlle" point of triangle that forms an ear.
    ///	The ear is formed by P(i-1), P(i) and P(i+1), where P are points
    ///	included in the polygon.
    static int FindTrianglePoints(const XYPolygon &polygon);

    /// @brief Determines if the triangle formed by  P(i-1), P(i) and P(i+1)
    /// from Polygon are intersected by any of the other points of the polygon.
    ///
    /// @param i Middle index for the three points that forms the triangle.
    ///	@returns true, If the triangle P(i-1), P(i), P(i+1) is intersected by
    /// other parts of Polygon; false, otherwise.
    static bool IsTriangleIntersected(const XYPolygon &polygon, int i);

    /// @brief Calculates the intersection area of triangle xypolygon a and b.
    static double
    CalculateTriangleSharedArea(const XYPolygon &triangleA, const XYPolygon &triangleB);

    /// @brief Calculates the length that two lines overlap.
    static double CalculateSharedLength(const XYLine &lineA, const XYLine &lineB);

    /// @brief Checks if the lines lineA and lineB shares a point either as a
    /// real crossing point or as a shared end point or a end point of
    /// the one line being in the other line.
    static bool IntersectionPoint(
        const XYLine &LineA, const XYLine &LineB, XYPoint &intersectionPoint);

    /// @brief Determines if a point is included in a lines interior
    /// and not an endpoint.
    static bool IsPointInLineInterior(const XYPoint &point, const XYLine &line);

    /// @brief Calculates the intersection points of triangle xypolygon a and b.
    ///
    /// @param  triangleA  triangle. The search is started along triangleA.
    /// @param  triangleB  triangle. Intersection with the triangle are sought.
    /// @param[out]  p  Starting point for the search.
    ///  + p must be part of triangleA.
    /// @param[out]  i
    ///  + on input: End index for the first line segment of triangleA.
    ///  + on output: End index for the last intersected line segment in triangleA.
    /// @param[out]  j
    ///  + on input: -1 if vertices before intersection isn't to be added.
    ///  + on output: End index for last intersected line of triangleB.
    /// @param[out]  intersectionPolygon  Polygon eventually describing the
    /// intersection area between triangleA and triangleB.
    ///
    ///	@returns The p, i, j and intersectionPolygon are called by
    /// reference and modified in the method.
    static void Intersect(
        const XYPolygon &triangleA, const XYPolygon &triangleB, XYPoint &p, int &i,
        int &j, XYPolygon &intersectionPolygon);

    /// @brief The method steps to the next index
    /// in a circular list {0, ..., n-1}.
    ///
    /// @param  i  Index to increase.
    /// @param  n  Modula value, one larger than largest index.
    /// @returns The increased index.
    static int IncrementModula(int i, int n);

    /// @brief The method steps to the previous index
    /// in a circular list {0, ..., n-1}.
    ///
    /// @param  i  Index to decrease..
    /// @param  n  Module value, one larger than largest index.
    /// @returns The decreased index.
    static int DecrementModula(int i, int n);
};

}  // namespace Spatial
}  // namespace CommImp
}  // namespace OpenOasis