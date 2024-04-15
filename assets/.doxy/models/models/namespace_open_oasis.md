

# Namespace OpenOasis



[**Namespace List**](namespaces.md) **>** [**OpenOasis**](namespace_open_oasis.md)



[More...](#detailed-description)














## Namespaces

| Type | Name |
| ---: | :--- |
| namespace | [**AdditionalControl**](namespace_open_oasis_1_1_additional_control.md) <br> |
| namespace | [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) <br> |
| namespace | [**SystHeats**](namespace_open_oasis_1_1_syst_heats.md) <br> |


## Classes

| Type | Name |
| ---: | :--- |
| class | [**ExchangeItemChangeEventArgs**](class_open_oasis_1_1_exchange_item_change_event_args.md) <br>_Class containing the information that will be passed when firing an_ `ExchangeItemValueChanged` _event._ |
| class | [**IAdaptedOutput**](class_open_oasis_1_1_i_adapted_output.md) <br>_Extension class for adding data operations on top of an output item._  |
| class | [**IAdaptedOutputFactory**](class_open_oasis_1_1_i_adapted_output_factory.md) <br>_Factory class for creating instances of_ `IAdaptedOutput` _items._ |
| class | [**IArgument**](class_open_oasis_1_1_i_argument.md) <br>_Class for providing arguments for an_ `ILinkableComponent` _and others._ |
| class | [**IBaseExchangeItem**](class_open_oasis_1_1_i_base_exchange_item.md) <br>_Class presenting a item that can be exchanged, either as an input or output._  |
| class | [**IByteStateConverter**](class_open_oasis_1_1_i_byte_state_converter.md) <br>_An optional interface to save and transform the model state._  |
| class | [**ICategory**](class_open_oasis_1_1_i_category.md) <br>_Class describes one item of a possible categorization._  |
| class | [**IDescribable**](class_open_oasis_1_1_i_describable.md) <br>_An entity that is describable has a caption (title or heading) and a description. These are not to be used for identification._  |
| class | [**IDimension**](class_open_oasis_1_1_i_dimension.md) <br>_Define the order of each dimension in_ `DimensionBase` _for a unit._ |
| class | [**IElementSet**](class_open_oasis_1_1_i_element_set.md) <br>_An list of elements having a common type._  |
| class | [**IIdentifiable**](class_open_oasis_1_1_i_identifiable.md) <br>_To define a method to get the Id of an_ [_**OpenOasis**_](namespace_open_oasis.md) _entity._ |
| class | [**IInput**](class_open_oasis_1_1_i_input.md) <br>_An input item that can accept values for an_ `ILinkableComponent` _. The input item may have multiple providers._ |
| class | [**ILinkableComponent**](class_open_oasis_1_1_i_linkable_component.md) <br>_The key interface class for linkable modules connection and data transfer._  |
| class | [**IManageState**](class_open_oasis_1_1_i_manage_state.md) <br>_It provides additional methods for handling component state so it can be saved, restored and cleared._  |
| class | [**IOutput**](class_open_oasis_1_1_i_output.md) <br>_Output exchange item that can deliver values from an_ `ILinkableComponent` _._ |
| class | [**IQuality**](class_open_oasis_1_1_i_quality.md) <br>_Class describes qualitative data, where a value is specified as one category within a number of predefined (possible) categories._  |
| class | [**IQuantity**](class_open_oasis_1_1_i_quantity.md) <br>_Class specifies values as an amount of some unit._  |
| class | [**ISpatialDefinition**](class_open_oasis_1_1_i_spatial_definition.md) <br>_General spatial construct that all other spatial constructions extend from._  |
| class | [**ITime**](class_open_oasis_1_1_i_time.md) <br>_Time interface to support a time stamp as well as a time interval._  |
| class | [**ITimeSet**](class_open_oasis_1_1_i_time_set.md) <br>_Set of time stamps or time intervals, used to indicate when an output has and can provide values, and when an input item does or may require values._  |
| class | [**IUnit**](class_open_oasis_1_1_i_unit.md) <br>_Unit interface describes the physical unit._  |
| class | [**IValueDefinition**](class_open_oasis_1_1_i_value_definition.md) <br>_Class describes value definition._  |
| class | [**IValueSet**](class_open_oasis_1_1_i_value_set.md) <br>_Class represents a general(ordered) multi-dimensional set of values._  |
| class | [**LinkableComponentStatusChangeEventArgs**](class_open_oasis_1_1_linkable_component_status_change_event_args.md) <br>_Class contains the information that will be passed when the_ `ILinkableComponent` _fires the_`StatusChanged` _event._ |


## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**DimensionBase**](#enum-dimensionbase)  <br>_Enumeration for base dimensions._  |
| enum  | [**ElementType**](#enum-elementtype)  <br>_Shape Type of elements in an_ `IElementSet` _._ |
| enum  | [**LinkableComponentStatus**](#enum-linkablecomponentstatus)  <br>_Class enumerates the possible statuses that a linkable component can be in._  |
















































# Detailed Description



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IComparable.h @License : Apache-2.0


@Desc : To provide a unified interface for object comparison.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : ISpaceExtension.h @License : Apache-2.0


@Desc : Spatial information (usually an element set) on the values.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : ITimeExtension.h @License : Apache-2.0


@Desc : Methods that are specific for an time-space component.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : ExchangeItemChangeEventArgs.h @License : Apache-2.0


@Desc : To contain the information that will be passed when the `IBaseExchangeItem` fires the `ExchangeItemValueChanged` event.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IAdaptedOutput.h @License : Apache-2.0


@Desc : To adds one or more data operations on top of an output item.


`IAdaptedOutput` objects are created by means of an `IAdaptedOutputFactory`. It is based on the adaptor design pattern.It adapts an `IOutput` or another `IAdaptedOutput` to make it suitable for new use or purpose.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IAdaptedOutputFactory.h @License : Apache-2.0


@Desc : Factory to create instance of `IAdaptedOutput`.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IArgument.h @License : Apache-2.0


@Desc : To provide an argument interface.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IBaseExchangeItem.h @License : Apache-2.0


@Desc : To provide an item that can be exchanged, either as input or output.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IByteStateConverter.h @License : Apache-2.0


@Desc : An optional complement to support state management.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : ICategory.h @License : Apache-2.0


@Desc : To describe one item of a possible categorization.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IDescribable.h @License : Apache-2.0


@Desc : To provide descriptive information on an [**OpenOasis**](namespace_open_oasis.md) entity.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IDimension.h @License : Apache-2.0


@Desc : To define the order of dimension in each `DimensionBase` for a unit.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IElementSet.h @License : Apache-2.0


@Desc : To provide an ordered list of elements for data exchanging.


Data exchange between components is nearly always related to one or more elements in a space, either geo-referenced or not. An elementset can be a list of 2D or 3D spatial elements or as a special case, a list of ID based (non spatial) elements. Possible element types are defined in `ElementType`.


For 3D elements (i.e. polyhedron) the shape can be queried by face. When the elementset is geo-referenced, coordinates (X, Y, Z) can be obtained for each node of an element.


A geo-referenced elementset needs to have a valid "SpatialReferenceSystem" property set in a `ISpatialDefinition`. This is a string that specifies the OGC WKT representation of a spatial reference. An empty string indicates that there in no spatial reference, which is only valid if the `ElementType` is `IdBased`.


While an `IElementSet` can be used to query the geometric description of a model schematization, it does not necessarily provide all topological knowledge on inter-element connections.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IIdentifiable.h @License : Apache-2.0


@Desc : To provide the id of an [**OpenOasis**](namespace_open_oasis.md) entity.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IInput.h @License : Apache-2.0


@Desc : To provide an input item that can accept values for an `ILinkableComponent` object.


This item is a combination of an `IValueDefinition`, an `IElementSet`, and an `ITimeSet`. This combination specifies which type of data is required, where and when, as input for an `ILinkableComponent`.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : ILinkableComponent.h @License : Apache-2.0


@Desc : To provide key interface for module connection and data transfer.



* An [**OpenOasis**](namespace_open_oasis.md) compliant component must implement the `ILinkableComponent` interface according to specifications provided from [**OpenOasis**](namespace_open_oasis.md) docs;
* An [**OpenOasis**](namespace_open_oasis.md) compliant component can also comply to one ore more extensions, by implementing the `ILinkableComponent` interface and the extension interfaces, according to the specifications;





 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IManageState.h @License : Apache-2.0


@Desc : To provide an optional interface to handling component state so it can be saved, restored and cleared.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IOutput.h @License : Apache-2.0


@Desc : To provide an output exchange item that can deliver values from an `ILinkableComponent`.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IQuality.h @License : Apache-2.0


@Desc : To describe qualitative data, where a value is specified as one category within a number of predefined (possible) categories.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IQuantity.h @License : Apache-2.0


@Desc : Specify values as an amount of some unit.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : ISpatialDefinition.h @License : Apache-2.0


@Desc : To provide a general spatial construct that all other spatial constructions extend from.


Data in component is often related to spatial coordinates, either georeferenced or not. Although most models encapsulate data with a static spatial definition, some advanced models might contain dynamic spatial definitions (e.g. waves, moving grids). A `Version` number has been introduced to enable tracking of spatial changes over time. If the version changes, the spatial definition might need to be queried again during the computation process.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : ITime.h @License : Apache-2.0


@Desc : Time interface to support a time stamp as well as a time interval.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : ITimeSet.h @License : Apache-2.0


@Desc : A set of time stamps or time intervals, used to indicate when an output item has values and can provide values, and when an input item does or may require values.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IUnit.h @License : Apache-2.0


@Desc : To describe the physical unit of `IQuantity`.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IValueDefinition.h @License : Apache-2.0


@Desc : To provide value definition description of an [**OpenOasis**](namespace_open_oasis.md) entity.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : IValueSet.h @License : Apache-2.0


@Desc : To represent a general multi-dimensional set of values.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : LinkableComponentStatus.h @License : Apache-2.0


@Desc : To enumerate the possible statuses that a linkable component can be.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : LinkableComponentStatusChangeEventArgs.h @License : Apache-2.0


@Desc : To contain the information that will be passed when the `ILinkableComponent` fires the `StatusChanged` event.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : HeatConductionModel.h @License : Apache-2.0


@Desc : A dummy heat conduction model used for example purposes.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Logger.h @License : Apache-2.0


@Desc : Provide logger.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Tensor.h @License : Apache-2.0


@Desc : Define Tensor template class for numerical calculation.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Vector.h @License : Apache-2.0


@Desc : Define Vector template class for numerical calculation.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : TimeBuffer.h @License : Apache-2.0


@Desc : To provide temporal buffering functionalities.


The TimeBuffer class provides buffering functionalities that will store values needed for a particular output item in memory and functionality that will interpolate, extrapolate and aggregate values from these values.


The content of the TimeBuffer is lists of corresponding times and ValueSets, where times can be TimeStamps or TimeSpans and the ValueSets are double[].


TimeBuffer objects may not contain mixtures of TimeSpans and TimeStamps. The number of Times (TimeSpans or TimeStamps) must equal the number of value sets (double[]) in the TimeBuffer.


When time spans are put in the buffer, it is assumed that there aren't holes between the spans, i.e. a time setup of:


\|-\|-\| \|-\|-\| a b c d e f


where data is missing between c and d isn't allowed (a value of 0 is assumed in such an interval).



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : GeoCalculator.h @License : Apache-2.0


@Desc : A collection of general geometry functions.



 Copyright (C) 2023, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Grid1D.h @License : Apache-2.0


@Desc : Grid in river net used for numerical calculation.



 Copyright (C) 2023, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Grid2D.h @License : Apache-2.0


@Desc : Grid formed by flat cells in 2d used for numerical calculation.



 Copyright (C) 2023, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Grid3D.h @License : Apache-2.0


@Desc : Grid in 3d used for numerical calculation.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : MeshStructs.h @License : Apache-2.0


@Desc : Definitions of mesh related structures.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : XYGeoStructs.h @License : Apache-2.0


@Desc : To provide basic plane geometry data structures (no z coordinate).



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : XYGeoTools.h @License : Apache-2.0


@Desc : The XYGeoTools class is a collection of general geometry functions. 


    
## Public Types Documentation




### enum DimensionBase 

```C++
enum OpenOasis::DimensionBase {
    Length,
    Mass,
    Time,
    ElectricCurrent,
    Temperature,
    AmountOfSubstance,
    LuminousIntensity,
    Currency
};
```






### enum ElementType 

```C++
enum OpenOasis::ElementType {
    IdBased,
    Point,
    Polyline,
    Polygon,
    Polyhedron
};
```






### enum LinkableComponentStatus 

```C++
enum OpenOasis::LinkableComponentStatus {
    Created,
    Initializing,
    Initialized,
    Validating,
    Valid,
    WaitingForData,
    Invalid,
    Preparing,
    Updating,
    Updated,
    Done,
    Finishing,
    Finished,
    Failed
};
```




------------------------------
The documentation for this class was generated from the following file `Models/Inc/AdditionalControl/IComparable.h`

