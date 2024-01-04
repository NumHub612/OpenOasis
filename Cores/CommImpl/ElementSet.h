/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  ElementSet.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  To describe a collection of spatial elements.
 *
 ** ***********************************************************************************/
#pragma once
#include "Cores/Inc/IElementSet.h"
#include "Cores/CommImpl/DevSupports/Element.h"
#include <memory>


namespace OpenOasis
{
namespace CommImpl
{
using Spatial::Coordinate;
using DevSupports::Element;

/// @brief The ElementSet class describes a collection of spatial elements.
///
/// In general, spatial objects are fixed. Based on this consideration, the elements are
/// required to be specified when elementset is initialized, meanwhile only the fetch
/// interfaces is provided.
///
/// For changing spatial objects, such as an adaptive dynamic grid, the elementset is
/// recreated each time.
class ElementSet : public IElementSet
{
private:
    std::string mSpatialReference;
    std::string mCaption;
    std::string mDescription;

    std::vector<Element> mElements;

    ElementType mElementType = ElementType::IdBased;
    int         mVersion     = 0;

public:
    virtual ~ElementSet()
    {}

    ElementSet(const std::shared_ptr<IElementSet> &source);
    ElementSet(
        const std::string &caption, const std::string &description, ElementType type,
        const std::vector<Element> &elements, const std::string &spatialRef = "",
        int version = 0);

    ///////////////////////////////////////////////////////////////////////////////////
    // Implement methods inherited from `IDescribable`.
    //

    std::string GetDescription() const override;

    void SetDescription(const std::string &value) override;

    std::string GetCaption() const override;

    void SetCaption(const std::string &value) override;

    ///////////////////////////////////////////////////////////////////////////////////
    // Implement methods inherited from `ISpatialDefinition`.
    //

    std::string GetSpatialReferenceSystem() const override;

    int GetElementCount() const override;

    int GetVersion() const override;

    ///////////////////////////////////////////////////////////////////////////////////
    // Implement methods inherited from `IElementSet`.
    //

    ElementType GetElementType() const override;

    int GetElementIndex(const std::string &elementId) override;

    std::string GetElementId(int index) override;

    int GetFaceCount(int elementIndex) override;

    int GetVertexCount(int elementIndex) override;

    std::vector<int> GetFaceVertexIndices(int elementIndex, int faceIndex) override;

    double GetVertexXCoordinate(int elementIndex, int vertexIndex) override;

    double GetVertexYCoordinate(int elementIndex, int vertexIndex) override;

    double GetVertexZCoordinate(int elementIndex, int vertexIndex) override;

protected:
    void CheckElementIndex(int elemIndex) const;
    void CheckVertexIndex(int elemIndex, int vertIndex) const;
    void CheckFaceIndex(int elemIndex, int faceIndex) const;
};

}  // namespace CommImpl
}  // namespace OpenOasis