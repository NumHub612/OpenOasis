

# Class OpenOasis::ISpatialDefinition



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**ISpatialDefinition**](class_open_oasis_1_1_i_spatial_definition.md)



_General spatial construct that all other spatial constructions extend from._ 

* `#include <ISpatialDefinition.h>`



Inherits the following classes: [OpenOasis::IDescribable](class_open_oasis_1_1_i_describable.md)


Inherited by the following classes: [OpenOasis::IElementSet](class_open_oasis_1_1_i_element_set.md)




















































## Public Functions

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




### function GetElementCount 

```C++
virtual int OpenOasis::ISpatialDefinition::GetElementCount () const = 0
```






### function GetSpatialReferenceSystem 

```C++
virtual std::string OpenOasis::ISpatialDefinition::GetSpatialReferenceSystem () const = 0
```






### function GetVersion 

_Gets the version number for the spatial axis._ 
```C++
virtual int OpenOasis::ISpatialDefinition::GetVersion () const = 0
```



The version must be incremented if anything inside the spatial axis is changed, or if an entirely new spatial axis is provided. 


        

------------------------------
The documentation for this class was generated from the following file `Models/Inc/ISpatialDefinition.h`

