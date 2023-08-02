/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  ElementMapper.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  To converts one ValueSet (inputValues) associated one ElementSet
 *    (fromElements)to a new ValueSet that corresponds to another ElementSet
 *    (toElements).
 *
 *    The conversion is a two step procedure where the first step (Initialize) is
 *    executed at initialisation time only, whereas the MapValues
 *    is executed during time stepping.
 *
 *    The Initialize method will create a conversion matrix with the same number of
 *    rows as the number of elements in the ElementSet associated to the accepting
 *    component (i.e. the toElements) and the same number of columns as the
 *    number of elements in the ElementSet associated to the providing component
 *    (i.e. the fromElements).
 *
 *   Mapping is possible for any zero-, one- and two-dimensional elemets.
 *   Zero dimensional elements will always be points, one-dimensional elements will
 *   allways be polylines and two-dimensional elements will allways be polygons.
 *
 *   The ElementMapper contains a lot of methods for mapping between the different
 *   element types. As an example polyline to polygon mapping may be done either
 *   as Weighted Mean or as Weighted Sum. Typically the method choice will
 *   depend on the quantity mapped.
 *
 *   Such that state variables such as water level will be mapped using
 *   Weighted Mean whereas flux variable such as seepage from river to groundwater
 *   will be mapped using Weighted Sum.
 *
 ** ***********************************************************************************/
#pragma once
#include "Cores/Inc/IIdentifiable.h"
#include "Cores/Inc/IElementSet.h"
#include "Cores/Inc/IValueSet.h"
#include "Cores/CommImpl/Numeric/Matrix.h"
#include "Cores/CommImpl/Spatial/XYGeoStructs.h"
#include <optional>


namespace OpenOasis
{
namespace CommImpl
{
namespace Spatial
{
using namespace Numeric;

/// @brief Predined element mapping methods.
enum class ElementMapperMethod
{
    None,
    Nearest,
    Inverse,
    Mean,
    Sum,
    WeightedMean,
    WeightedSum,
    Distribute,
    Value
};


/// @brief ElementMapper class converts one ValueSet (inputValues) associated one
/// ElementSet(fromElements) to a new ValueSet that corresponds to another
/// ElementSet(toElements).
class ElementMapper
{
private:
    std::optional<ElementMapperMethod>  mMethod;
    std::shared_ptr<DoubleSparseMatrix> mMappingMatrix;

    bool mUseSearchTree       = false;
    bool mIsInitialised       = false;
    int  mNumberOfFromColumns = 0;
    int  mNumberOfToRows      = 0;

public:
    virtual ~ElementMapper()
    {}

    ElementMapper();

    std::shared_ptr<IMatrix> GetMappingMatrix() const;

    void SetUseSearchTree(bool value);

    bool IsInitialized() const;

    bool GetUseSearchTree() const;

    ElementType GetTargetElementType();

    /// @brief Calculates for each set of timestep data a resulting IValueSet through
    /// multiplication of an inputValues IValueSet vector with the mapping matrix.
    ///
    /// @param inputValues IValueSet of values to be mapped.
    ///
    /// @return A valueset found by mapping of the inputValues on to the toElementSet.
    std::shared_ptr<IValueSet> MapValues(const std::shared_ptr<IValueSet> &inputValues);

    /// @brief Initialises the ElementMapper.
    /// The initialisation includes setting the isInitialised flag and calls
    /// UpdateMappingMatrix for calculation of the mapping matrix.
    ///
    /// @param method String description of mapping method.
    /// @param fromElements The IElementSet to map from.
    /// @param toElements The IElementSet to map to.
    void Initialise(
        const std::shared_ptr<IIdentifiable> &method,
        const std::shared_ptr<IElementSet>   &fromElements,
        const std::shared_ptr<IElementSet>   &toElements);

    /// @brief Creates a result value set of the size specified
    ///
    /// @returns An IValueSet of the correct size.
    static std::shared_ptr<IValueSet>
    CreateResultValueSet(int numtimes, int numElements);

    /// @brief Calculates for each set of timestep data a resulting IValueSet through
    /// multiplication of an inputValues IValueSet vector with the mapping matrix.
    ///
    /// This version can be used if the output value set is to be reused
    /// (performance or for adding up)
    ///
    /// @param outputValues IValueset of mapped values, of the correct size.
    /// @param inputValues IValueSet of values to be mapped.
    void MapValues(
        const std::shared_ptr<IValueSet> &outputValues,
        const std::shared_ptr<IValueSet> &inputValues);

    /// @brief Extracts the (row, column) element from the MappingMatrix.
    ///
    /// @param row Zero based row index.
    /// @param column Zero based column index.
    /// @returns Element(row, column) from the mapping matrix.
    double GetValueFromMappingMatrix(int row, int column);

    /// @brief Sets individual (row, column)element in the MappingMatrix.
    ///
    /// @param value Element value to set.
    /// @param row Zero based row index.
    /// @param column Zero based column index.
    void SetValueInMappingMatrix(double value, int row, int column);

    static XYPolygon
    CreateFromXYPolygon(const std::shared_ptr<IElementSet> &elementSet, int index);

    static XYPolygon
    CreateXYPolygon(const std::shared_ptr<IElementSet> &elementSet, int index);

    static XYPolyline
    CreateXYPolyline(const std::shared_ptr<IElementSet> &elementSet, int index);

private:
    /// @brief Calculates the mapping matrix between fromElements and toElements.
    /// The mapping method is decided from the combination of methodIdentifier,
    /// fromElements.ElementType and toElements.ElementType.
    ///
    /// UpdateMappingMatrix() is called during initialisation must be called prior
    /// to MapValues().
    ///
    /// @param methodIdentifier String identification of mapping method.
    /// @param fromElements The IElementset to map from.
    /// @param toElements The IElementset to map to.
    void UpdateMappingMatrix(
        const std::shared_ptr<IIdentifiable> &methodIdentifier,
        const std::shared_ptr<IElementSet>   &fromElements,
        const std::shared_ptr<IElementSet>   &toElements);

    void MapFromPointToPoint(
        const std::shared_ptr<IElementSet> &fromElements,
        const std::shared_ptr<IElementSet> &toElements);

    void MapFromPointToPolyline(
        const std::shared_ptr<IElementSet> &fromElements,
        const std::shared_ptr<IElementSet> &toElements);

    void MapFromPointToPolygon(
        const std::shared_ptr<IElementSet> &fromElements,
        const std::shared_ptr<IElementSet> &toElements);

    void MapFromPolylineToPoint(
        const std::shared_ptr<IElementSet> &fromElements,
        const std::shared_ptr<IElementSet> &toElements);

    void MapFromPolylineToPolygon(
        const std::shared_ptr<IElementSet> &fromElements,
        const std::shared_ptr<IElementSet> &toElements);

    void MapFromPolylineToPolyline(
        const std::shared_ptr<IElementSet> &fromElements,
        const std::shared_ptr<IElementSet> &toElements);

    void MapFromPolygonToPoint(
        const std::shared_ptr<IElementSet> &fromElements,
        const std::shared_ptr<IElementSet> &toElements);

    void MapFromPolygonToPolyline(
        const std::shared_ptr<IElementSet> &fromElements,
        const std::shared_ptr<IElementSet> &toElements);

    void MapFromPolygonToPolygon(
        const std::shared_ptr<IElementSet> &fromElements,
        const std::shared_ptr<IElementSet> &toElements);

    void ValidateIndicies(int row, int column);

    static XYPoint
    CreateXYPoint(const std::shared_ptr<IElementSet> &elementSet, int index);
};

}  // namespace Spatial
}  // namespace CommImpl
}  // namespace OpenOasis