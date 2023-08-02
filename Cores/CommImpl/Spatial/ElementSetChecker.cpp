/** ***********************************************************************************
 *    @File      :  ElementSetChecker.cpp
 *    @Brief     :  None.
 *
 ** ***********************************************************************************/
#include "ElementSetChecker.h"
#include "XYGeoStructs.h"
#include "Cores/Utils/StringHelper.h"


namespace OpenOasis::CommImpl::Spatial
{
using namespace Utils;
using namespace std;

void ElementSetChecker::CheckElementSet(const shared_ptr<IElementSet> &elementSet)
{
    try
    {
        switch (elementSet->GetElementType())
        {
        case ElementType::Point:
            for (int i = 0; i < elementSet->GetElementCount(); ++i)
            {
                try
                {
                    if (elementSet->GetVertexCount(i) != 1)
                    {
                        throw runtime_error(
                            "Number of vertices in point element is different from 1.");
                    }
                }
                catch (const runtime_error &e)
                {
                    throw runtime_error(StringHelper::FormatSimple(
                        "{} ElementID = {}.", e.what(), elementSet->GetElementId(i)));
                }
            }
            break;
        case ElementType::Polyline:
            for (int i = 0; i < elementSet->GetElementCount(); ++i)
            {
                try
                {
                    XYPolyline polyline;
                    for (int j = 0; j < elementSet->GetVertexCount(i); j++)
                    {
                        polyline.points.emplace_back(XYPoint(
                            elementSet->GetVertexXCoordinate(i, j),
                            elementSet->GetVertexYCoordinate(i, j)));
                    }

                    if (!polyline.Validate())
                    {
                        throw runtime_error("Invalid polyline.");
                    }
                }
                catch (const runtime_error &e)
                {
                    throw runtime_error(StringHelper::FormatSimple(
                        "{} ElementID = {}.", e.what(), elementSet->GetElementId(i)));
                }
            }
            break;
        case ElementType::Polygon:
            for (int i = 0; i < elementSet->GetElementCount(); ++i)
            {
                try
                {
                    XYPolygon polygon;
                    for (int j = 0; j < elementSet->GetVertexCount(i); j++)
                    {
                        polygon.points.emplace_back(
                            elementSet->GetVertexXCoordinate(i, j),
                            elementSet->GetVertexYCoordinate(i, j));
                    }

                    if (!polygon.Validate())
                    {
                        throw runtime_error("Invalid polygon.");
                    }
                }
                catch (const runtime_error &e)
                {
                    throw runtime_error(StringHelper::FormatSimple(
                        "{} ElementID = {}.", e.what(), elementSet->GetElementId(i)));
                }
            }
            break;
        default: throw runtime_error("Invalid ElementType.");
        }
    }
    catch (const runtime_error &)
    {
        throw runtime_error(StringHelper::FormatSimple(
            "ElementSet with Caption = {} is invalid.", elementSet->GetCaption()));
    }
}

}  // namespace OpenOasis::CommImpl::Spatial