/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  IElementSet.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  To provide an ordered list of elements for data exchanging.
 *
 *   Data exchange between components is nearly always related to one or more elements
 *   in a space, either geo-referenced or not. An elementset can be a list of 2D or 3D
 *   spatial elements or as a special case, a list of ID based (non spatial) elements.
 *   Possible element types are defined in `ElementType`.
 *
 *   For 3D elements (i.e. polyhedron) the shape can be queried by face. When the
 *   elementset is geo-referenced co-ordinates (X,Y,Z,M) can be obtained for each
 *   vertex of an element.
 *
 *   A geo-referenced element set needs to have a valid "SpatialReferenceSystem"
 *   property set in a `ISpatialDefinition`. This is a string that specifies the OGC
 *   WKT representation of a spatial reference. An empty string indicates that there
 *   in no spatial reference, which is only valid if the `ElementType` is `IdBased`.
 *
 *   While an `IElementSet` can be used to query the geometric description of a
 *   model schematization, it does not necessarily provide all topological knowledge
 *   on inter-element connections.
 *
 ** ***********************************************************************************/
#pragma once
#include "ISpatialDefinition.h"
#include <vector>
#include <any>


namespace OpenOasis
{
/// @brief Shape Type of elements in an `IElementSet`.
enum class ElementType
{
    IdBased,    // Identifiable based
    Point,      // Points
    PolyLine,   // Lines / Polylines
    Polygon,    // Polygons
    Polyhedron  // Polyhedrons
};


/// @brief An list of elements having a common type.
/// Geometry of each element is described by an ordered list of vertices. There are
/// no restrictions to how elements are ordered.
class IElementSet : public ISpatialDefinition
{
public:
    /// @brief Gets `ElementType` of the element set.
    virtual ElementType GetElementType() const = 0;

    /// @brief Index of element with id 'elementId' in the element set.
    ///
    /// @param elementId Identification string of the element required.
    /// @return Index of the element with the specified id; return -1 if not found.
    virtual int GetElementIndex(const std::string &elementId) = 0;

    /// @brief Gets Id of the index element in the elementset.
    ///
    /// @param index The element index for which the element `Id` is requested.
    ///
    /// @return The id of the element with the specified index.
    /// If the `ElementType` of the elementset is not `IdBased`,
    /// an empty string may be returned.
    ///
    /// @throw If the index outside the range, throw an exception.
    virtual std::string GetElementId(int index) = 0;

    /// @brief Gets number of vertices for the element specified by the index.
    ///
    /// @param elementIndex The element index for the element.
    ///
    /// @return Number of vertices in element defined by the elementIndex.
    ///
    /// @throw If the index outside the range, throw an exception.
    /// @throw If the method is invoked for element sets of type `IdBased`,
    /// throw an exception.
    virtual int GetVertexCount(int elementIndex) = 0;

    /// @brief Gets the number of faces in a 3D element.
    ///
    /// @param elementIndex Index for the element.
    ///
    /// @return Number of faces.
    ///
    /// @throw If the index outside the range, throw an exception.
    virtual int GetFaceCount(int elementIndex) = 0;

    /// @brief Gets an array with the vertex indices for a face.
    ///
    /// @param elementIndex Element index.
    /// @param faceIndex Face index.
    ///
    /// @return The vertex indices for this face.
    virtual std::vector<int> GetFaceNodeIndices(int elementIndex, int faceIndex) = 0;

    /// @brief True if the element set supports Z coordinates.
    virtual bool HasZ() const = 0;

    /// @brief True if the element set supports M coordinates.
    virtual bool HasM() const = 0;

    /// @brief X coordinate for the vertex with vertexIndex of the element with
    /// elementIndex.
    ///
    /// @param elementIndex Element index.
    /// @param vertexIndex Vertex index in the element with index elementIndex.
    ///
    /// @return X coordinate for the vertex.
    virtual double GetNodeXCoordinate(int elementIndex, int vertexIndex) = 0;

    /// @brief Y coordinate for the vertex with vertexIndex of the element with
    /// elementIndex.
    ///
    /// @param elementIndex  Element index.
    /// @param vertexIndex  Vertex index in the element with index elementIndex.
    ///
    /// @return Y coordinate for the vertex.
    virtual double GetNodeYCoordinate(int elementIndex, int vertexIndex) = 0;

    /// @brief Z coordinate for the vertex with vertexIndex of the element with
    /// elementIndex.
    ///
    /// @param elementIndex Element index.
    /// @param vertexIndex Vertex index in the element with index elementIndex.
    ///
    /// @return Z coordinate for the vertex.
    virtual double GetNodeZCoordinate(int elementIndex, int vertexIndex) = 0;

    /// @brief M coordinate for the vertex with VertexIndex of the element with
    /// elementIndex.
    ///
    /// @param elementIndex Element index.
    /// @param vertexIndex Vertex index in the element with index elementIndex.
    ///
    /// @return M coordinate for the vertex.
    virtual double GetVertexMCoordinate(int elementIndex, int vertexIndex) = 0;
};

}  // namespace OpenOasis
