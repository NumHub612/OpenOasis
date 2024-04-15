

# Class OpenOasis::IElementSet



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IElementSet**](class_open_oasis_1_1_i_element_set.md)



_An list of elements having a common type._ 

* `#include <IElementSet.h>`



Inherits the following classes: [OpenOasis::ISpatialDefinition](class_open_oasis_1_1_i_spatial_definition.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual std::string | [**GetElementId**](#function-getelementid) (int index) = 0<br>_Gets Id of the index element in the element set._  |
| virtual int | [**GetElementIndex**](#function-getelementindex) (const std::string & elementId) = 0<br>_Index of element with id 'elementId' in the element set._  |
| virtual [**ElementType**](namespace_open_oasis.md#enum-elementtype) | [**GetElementType**](#function-getelementtype) () const = 0<br>_Gets_ `ElementType` _of the elementset._ |
| virtual int | [**GetFaceCount**](#function-getfacecount) (int elementIndex) = 0<br>_Gets the number of faces in a element._  |
| virtual std::vector&lt; int &gt; | [**GetFaceNodeIndices**](#function-getfacenodeindices) (int elementIndex, int faceIndex) = 0<br>_Gets an array with the node indices for a face._  |
| virtual int | [**GetNodeCount**](#function-getnodecount) (int elementIndex) = 0<br>_Gets number of nodes for the element specified by the index._  |
| virtual double | [**GetNodeXCoordinate**](#function-getnodexcoordinate) (int elementIndex, int nodeIndex) = 0<br>_X coordinate for the node with nodeIndex of the element with elementIndex._  |
| virtual double | [**GetNodeYCoordinate**](#function-getnodeycoordinate) (int elementIndex, int nodeIndex) = 0<br>_Y coordinate for the node with nodeIndex of the element with elementIndex._  |
| virtual double | [**GetNodeZCoordinate**](#function-getnodezcoordinate) (int elementIndex, int nodeIndex) = 0<br>_Z coordinate for the node with nodeIndex of the element with elementIndex._  |


## Public Functions inherited from OpenOasis::ISpatialDefinition

See [OpenOasis::ISpatialDefinition](class_open_oasis_1_1_i_spatial_definition.md)

| Type | Name |
| ---: | :--- |
| virtual int | [**GetElementCount**](#function-getelementcount) () const = 0<br>_Gets number of data elements in the spatial axis._  |
| virtual std::string | [**GetSpatialReferenceSystem**](#function-getspatialreferencesystem) () const = 0<br>_Specifies the OGC Well-Known Text(WKT) representation of spatial reference system to be used in association with the coordinates in the_ `ISpatialDefinition` _._ |
| virtual int | [**GetVersion**](#function-getversion) () const = 0<br>_Gets the version number for the spatial axis._  |


## Public Functions inherited from OpenOasis::IDescribable

See [OpenOasis::IDescribable](class_open_oasis_1_1_i_describable.md)

| Type | Name |
| ---: | :--- |
| virtual std::string | [**GetCaption**](#function-getcaption) () const = 0<br> |
| virtual std::string | [**GetDescription**](#function-getdescription) () const = 0<br> |
| virtual void | [**SetCaption**](#function-setcaption) (const std::string & value) = 0<br> |
| virtual void | [**SetDescription**](#function-setdescription) (const std::string & value) = 0<br> |
















































































## Public Functions Documentation




### function GetElementId 

_Gets Id of the index element in the element set._ 
```C++
virtual std::string OpenOasis::IElementSet::GetElementId (
    int index
) = 0
```





**Parameters:**


* `index` The element index for which the element `Id` is requested.



**Returns:**

The id of the element with the specified index. If the `ElementType` of the elementset is not `IdBased`, an empty string may be returned.




**Exception:**


* `If` the index outside the range, throw an exception. 




        



### function GetElementIndex 

_Index of element with id 'elementId' in the element set._ 
```C++
virtual int OpenOasis::IElementSet::GetElementIndex (
    const std::string & elementId
) = 0
```





**Parameters:**


* `elementId` Identification string of the element required. 



**Returns:**

Index of the element with the specified id; return -1 if not found. 





        



### function GetElementType 

```C++
virtual ElementType OpenOasis::IElementSet::GetElementType () const = 0
```






### function GetFaceCount 

_Gets the number of faces in a element._ 
```C++
virtual int OpenOasis::IElementSet::GetFaceCount (
    int elementIndex
) = 0
```





**Parameters:**


* `elementIndex` Index for the element. 



**Returns:**

Number of faces. 




**Exception:**


* `If` the index outside the range, throw an exception. 




        



### function GetFaceNodeIndices 

_Gets an array with the node indices for a face._ 
```C++
virtual std::vector< int > OpenOasis::IElementSet::GetFaceNodeIndices (
    int elementIndex,
    int faceIndex
) = 0
```





**Parameters:**


* `elementIndex` Element index. 
* `faceIndex` Face index. 



**Returns:**

The node indices for this face. 





        



### function GetNodeCount 

_Gets number of nodes for the element specified by the index._ 
```C++
virtual int OpenOasis::IElementSet::GetNodeCount (
    int elementIndex
) = 0
```





**Parameters:**


* `elementIndex` The element index for the element.



**Returns:**

Number of nodes in element defined by the elementIndex.




**Exception:**


* `If` the index outside the range, throw an exception. 
* `If` the method is invoked with type `IdBased`, throw an exception. 




        



### function GetNodeXCoordinate 

_X coordinate for the node with nodeIndex of the element with elementIndex._ 
```C++
virtual double OpenOasis::IElementSet::GetNodeXCoordinate (
    int elementIndex,
    int nodeIndex
) = 0
```





**Parameters:**


* `elementIndex` Element index. 
* `nodeIndex` Node index in the element with index elementIndex.



**Returns:**

X coordinate for the node. 





        



### function GetNodeYCoordinate 

_Y coordinate for the node with nodeIndex of the element with elementIndex._ 
```C++
virtual double OpenOasis::IElementSet::GetNodeYCoordinate (
    int elementIndex,
    int nodeIndex
) = 0
```





**Parameters:**


* `elementIndex` Element index. 
* `nodeIndex` Node index in the element with index elementIndex.



**Returns:**

Y coordinate for the node. 





        



### function GetNodeZCoordinate 

_Z coordinate for the node with nodeIndex of the element with elementIndex._ 
```C++
virtual double OpenOasis::IElementSet::GetNodeZCoordinate (
    int elementIndex,
    int nodeIndex
) = 0
```





**Parameters:**


* `elementIndex` Element index. 
* `nodeIndex` Node index in the element with index elementIndex.



**Returns:**

Z coordinate for the node. 





        

------------------------------
The documentation for this class was generated from the following file `Models/Inc/IElementSet.h`

