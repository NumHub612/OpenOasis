/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Element.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  To describe a spatial element.
 *
 ** ***********************************************************************************/
#pragma once
#include "Cores/Inc/IIdentifiable.h"
#include "Cores/CommImpl/Spatial/Coordinate.h"
#include <vector>


namespace OpenOasis::CommImpl::DevSupports
{
using namespace Spatial;

/// @brief The Element class contains a spatial element.
class Element : public IIdentifiable
{
private:
    std::string mId          = "";
    std::string mCaption     = "";
    std::string mDescription = "";

    std::vector<Coordinate>       mVertices;           // points.
    std::vector<std::vector<int>> mFaceVertexIndices;  // faces consisted of vertices.

public:
    virtual ~Element() = default;

    Element(const Element &elem);
    Element(
        const std::string &id, const std::string &caption,
        const std::string &description, const std::vector<Coordinate> &vertices,
        const std::vector<std::vector<int>> &faces = {});
    Element(const std::string &id);

    ///////////////////////////////////////////////////////////////////////////////////
    // Implement methods inherited from `IDescribable`.
    //

    std::string GetDescription() const override;

    void SetDescription(const std::string &value) override;

    std::string GetCaption() const override;

    void SetCaption(const std::string &value) override;

    ///////////////////////////////////////////////////////////////////////////////////
    // Implement methods inherited from `IIdentifiable`.
    //

    std::string GetId() const override;

    ///////////////////////////////////////////////////////////////////////////////////
    // Additional methods for the vertex operations.
    //

    std::vector<Coordinate> GetVertices() const;

    void SetVertices(const std::vector<Coordinate> &value);

    int GetVertexCount() const;

    Coordinate GetVertex(int Index) const;

    void AddVertex(const Coordinate &vertex);

    ///////////////////////////////////////////////////////////////////////////////////
    // Additional methods for the face operations.
    //

    int GetFaceCount() const;

    void AddFace(const std::vector<int> &vertexIndices);

    std::vector<int> GetFaceVertexIndices(int faceIndex) const;
};

}  // namespace OpenOasis::CommImpl::DevSupports