

# Class OpenOasis::IValueSet



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IValueSet**](class_open_oasis_1_1_i_value_set.md)



_Class represents a general(ordered) multi-dimensional set of values._ [More...](#detailed-description)

* `#include <IValueSet.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual std::vector&lt; std::any &gt; | [**GetElementValuesForTime**](#function-getelementvaluesfortime) (int timeIndex) const = 0<br>_Gets the values, for all elements, for the given timeIndex. If data is time independent,_ `timeIndex` _must be specified as 0._ |
| virtual int | [**GetIndexCount**](#function-getindexcount) (const std::vector&lt; int &gt; & indices) const = 0<br>_Returns the length of the dimension specified._  |
| virtual int | [**GetNumberOfIndices**](#function-getnumberofindices) () const = 0<br>_Returns the number of possible indices (dimensions)._  |
| virtual std::vector&lt; std::any &gt; | [**GetTimeSeriesValuesForElement**](#function-gettimeseriesvaluesforelement) (int elementIndex) const = 0<br>_Gets the values, for all times, for the given elementIndex. If the data is spatial independent,_ `elementIndex` _must be specified as 0._ |
| virtual std::any | [**GetValue**](#function-getvalue) (const std::vector&lt; int &gt; & indices) const = 0<br>_Returns the value object specified by the given indices array._  |
| virtual std::shared\_ptr&lt; [**IValueDefinition**](class_open_oasis_1_1_i_value_definition.md) &gt; | [**GetValueDefinition**](#function-getvaluedefinition) () const = 0<br>_Definition of the values in the value set._  |
| virtual bool | [**IsValues2D**](#function-isvalues2d) () const = 0<br>_Whether this value set is a specified two-dimensional type._  |
| virtual void | [**RemoveValue**](#function-removevalue) (const std::vector&lt; int &gt; & indices) = 0<br>_Removes the values specified by the given indices._  |
| virtual void | [**SetElementValuesForTime**](#function-setelementvaluesfortime) (int timeIndex, const std::vector&lt; std::any &gt; & values) = 0<br>_Sets the values, for all elements, for the given timeIndex. If data is time independent,_ `timeIndex` _must be specified as 0._ |
| virtual void | [**SetOrAddValue**](#function-setoraddvalue) (const std::vector&lt; int &gt; & indices, const std::any & value) = 0<br>_Sets or adds the value object specified by the given indices._  |
| virtual void | [**SetTimeSeriesValuesForElement**](#function-settimeseriesvaluesforelement) (int elementIndex, const std::vector&lt; std::any &gt; & values) = 0<br>_Sets the values, for all times, for the given elementIndex. If the data is spatial independent,_ `elementIndex` _must be specified as 0._ |




























# Detailed Description


The size of each dimension can vary, depending on the indices provided, e.g. In a 2D matrix, each row can have different lengths. For example, assuming the data is stored as a double[][] matrix, then matrix[1].Size need not equal to matrix[2].Size. 


    
## Public Functions Documentation




### function GetElementValuesForTime 

_Gets the values, for all elements, for the given timeIndex. If data is time independent,_ `timeIndex` _must be specified as 0._
```C++
virtual std::vector< std::any > OpenOasis::IValueSet::GetElementValuesForTime (
    int timeIndex
) const = 0
```





**Parameters:**


* `timeIndex` Index of time in `ITimeSet`. 



**Returns:**

Element valueset at given time. 




**Exception:**


* `If` `timeIndex` is out of range, throw an exception. 




        



### function GetIndexCount 

_Returns the length of the dimension specified._ 
```C++
virtual int OpenOasis::IValueSet::GetIndexCount (
    const std::vector< int > & indices
) const = 0
```



To get the size of the specified dimension, use zero-length int array as input argument. Length of indice must be a least one smaller than the `GetNumberOfIndices()`.




**Parameters:**


* `indices` Indices of the dimension to get the size of. 



**Returns:**

Length of the specified dimension. 





        



### function GetNumberOfIndices 

_Returns the number of possible indices (dimensions)._ 
```C++
virtual int OpenOasis::IValueSet::GetNumberOfIndices () const = 0
```





**Returns:**

number of indices, zero based. 





        



### function GetTimeSeriesValuesForElement 

_Gets the values, for all times, for the given elementIndex. If the data is spatial independent,_ `elementIndex` _must be specified as 0._
```C++
virtual std::vector< std::any > OpenOasis::IValueSet::GetTimeSeriesValuesForElement (
    int elementIndex
) const = 0
```





**Parameters:**


* `elementIndex` Index of element in `IElementSet`. 



**Returns:**

The timeseries values. 




**Exception:**


* `If` the `elementIndex` is out of range, throw an exception. 




        



### function GetValue 

_Returns the value object specified by the given indices array._ 
```C++
virtual std::any OpenOasis::IValueSet::GetValue (
    const std::vector< int > & indices
) const = 0
```





**Parameters:**


* `indices` Indices of each dimension. 



**Returns:**

The value object for the given indices. 




**Exception:**


* `The` length of the array of indices is N, so that the index for each dimension is specified. Otherwise throw an exception. 




        



### function GetValueDefinition 

_Definition of the values in the value set._ 
```C++
virtual std::shared_ptr< IValueDefinition > OpenOasis::IValueSet::GetValueDefinition () const = 0
```



The "IValueDefinition" should never be returned directly; The all implementing classes should return either an `IQuality`, an `IQuantity`, or a custom derived value definition interface. 


        



### function IsValues2D 

```C++
virtual bool OpenOasis::IValueSet::IsValues2D () const = 0
```






### function RemoveValue 

_Removes the values specified by the given indices._ 
```C++
virtual void OpenOasis::IValueSet::RemoveValue (
    const std::vector< int > & indices
) = 0
```



It is possible to remove not just a single value item, but also the whole set of values for the given indices.




**Parameters:**


* `indices` Indices of specified dimension. 




        



### function SetElementValuesForTime 

_Sets the values, for all elements, for the given timeIndex. If data is time independent,_ `timeIndex` _must be specified as 0._
```C++
virtual void OpenOasis::IValueSet::SetElementValuesForTime (
    int timeIndex,
    const std::vector< std::any > & values
) = 0
```





**Parameters:**


* `timeIndex` Index of time in `ITimeSet`. 
* `values` Element valueset at given time. 



**Exception:**


* `If` `timeIndex` is out of range, throw an exception. 




        



### function SetOrAddValue 

_Sets or adds the value object specified by the given indices._ 
```C++
virtual void OpenOasis::IValueSet::SetOrAddValue (
    const std::vector< int > & indices,
    const std::any & value
) = 0
```





**Parameters:**


* `indices` Indices of each dimension. 
* `value` Value object to be set or added. 



**Exception:**


* `The` length of the array of indices is N, so that the index for each dimension is specified. Otherwise throw an exception. 




        



### function SetTimeSeriesValuesForElement 

_Sets the values, for all times, for the given elementIndex. If the data is spatial independent,_ `elementIndex` _must be specified as 0._
```C++
virtual void OpenOasis::IValueSet::SetTimeSeriesValuesForElement (
    int elementIndex,
    const std::vector< std::any > & values
) = 0
```





**Parameters:**


* `elementIndex` Index of element in `IElementSet`. 
* `values` Timeseries values for given element. 



**Exception:**


* `If` the `elementIndex` is out of range, throw an exception. 




        

------------------------------
The documentation for this class was generated from the following file `Models/Inc/IValueSet.h`

