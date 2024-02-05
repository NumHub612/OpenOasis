/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  XYGeoStructs.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  To provide basic plane geometry data structures (no z coordinate).
 *
 ** ***********************************************************************************/
#pragma once
#include "Coordinate.h"
#include <vector>


namespace OpenOasis
{
namespace CommImp
{
namespace Spatial
{
/// @brief XYPoint is simply a x and y coordinate point (has no z coordinate).
struct XYPoint
{
    double x = 0.;
    double y = 0.;

    XYPoint() = default;
    XYPoint(const XYPoint &obj);
    XYPoint(const Coordinate &coor);
    XYPoint(double coorX, double coorY);
};


/// @brief The XYline struct is used for representing a line segment.
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


/// @brief XYPolyline is a collection of points (at least 2) connected with straigth
/// lines. XYPolylines are typically used for presentation of 1D data, river network.
struct XYPolyline
{
    std::vector<XYPoint> points;

    XYPolyline() = default;
    XYPolyline(const std::vector<XYPoint> &points);
    XYPolyline(const XYPolyline &pline);

    /// @brief The validate method check if the XYPolyline is valid. The checks
    /// made are:
    ///   - is number of points >= 2
    ///   - is the length of all line segments positive
    ///
    /// @throw Exception is raised if these above constraints aren't met.
    bool Validate() const;

    /// @brief Returns the cumulative calculating length of current line.
    double GetLength() const;

    /// @brief Retrieves the lineNumber line segment of the polyline. The index
    /// list is zero based.
    XYLine GetLine(int lineNumber) const;
};


/// @brief The XYPolygon struct defines a polygon in the XY plane (no z coordinate).
struct XYPolygon
{
    std::vector<XYPoint> points;

    XYPolygon() = default;
    XYPolygon(const std::vector<XYPoint> &points);
    XYPolygon(const XYPolygon &polygon);

    /// @brief Checks if the XYPolygon item is valid. The check made are:
    ///   - is number of points >= 3
    ///   - is the length of all line segments positive
    ///   - is any lines cross
    ///   - is the area positive
    ///
    /// @throw Exception is raised if these above constraints aren't met.
    bool Validate() const;

    /// @brief Calculates area of the polygon.
    double GetArea() const;

    /// @brief Returns the XYLine that connects XYPoint "LineNumber" and the next
    /// number (i.e. LineNumber+1 or 0).
    XYLine GetLine(int lineNumber) const;

    /// @brief Decides if the angle at index point is convex or concave.
    bool IsConvex(int index) const;
};


/// @brief Extent is a rectangle in xy-space.
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

    /// @brief Makes this extent include "other". This will grow this extent, if
    /// the "other" point is outside this extent.
    void Include(const XYExtent &other);

    /// @brief Makes the extent include the xy-point. This will grow this extent,
    /// if the xy-point is outside this extent.
    void Include(double x, double y);

    /// @brief Checks if this extent contains the xy-point.
    bool IsContains(double x, double y) const;

    /// @brief Checks if this extent overlaps this specified 'other' extent item.
    bool IsOverlaps(const XYExtent &other) const;
};

}  // namespace Spatial
}  // namespace CommImp
}  // namespace OpenOasis