

# Class OpenOasis::CommImp::IO::LinkLoader



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**IO**](namespace_open_oasis_1_1_comm_imp_1_1_i_o.md) **>** [**LinkLoader**](class_open_oasis_1_1_comm_imp_1_1_i_o_1_1_link_loader.md)



_Class forLoading components coupling configurations json file._ 

* `#include <LinkLoader.h>`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::array&lt; std::string, 3 &gt; | [**ComponentInfo**](#typedef-componentinfo)  <br> |
| typedef std::array&lt; std::string, 5 &gt; | [**ElementInfo**](#typedef-elementinfo)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  std::vector&lt; std::string &gt; | [**GetComponentIds**](#function-getcomponentids) () const<br> |
|  ComponentInfo | [**GetComponentInfo**](#function-getcomponentinfo) (const std::string & compId) const<br> |
|  std::vector&lt; ElementInfo &gt; | [**GetComponentInputs**](#function-getcomponentinputs) (const std::string & compId) const<br> |
|  std::vector&lt; ElementInfo &gt; | [**GetComponentOutputs**](#function-getcomponentoutputs) (const std::string & compId) const<br> |
|  std::unordered\_map&lt; std::string, std::vector&lt; ElementInfo &gt; &gt; | [**GetInputProviders**](#function-getinputproviders) (const std::string & compId, const ElementInfo & input) const<br> |
|  std::multimap&lt; std::string, std::string &gt; | [**GetIteratorConfigs**](#function-getiteratorconfigs) (const std::string & iterId) const<br>_Gets the iterator configurations of specified iterator group._  |
|  std::unordered\_map&lt; std::string, std::vector&lt; std::string &gt; &gt; | [**GetIteratorGroups**](#function-getiteratorgroups) () const<br>_Gets iterator groups consisted of components._  |
|  std::unordered\_map&lt; std::string, std::vector&lt; ElementInfo &gt; &gt; | [**GetOutputConsumers**](#function-getoutputconsumers) (const std::string & compId, const ElementInfo & output) const<br> |
|   | [**LinkLoader**](#function-linkloader) (const std::string & json) <br> |
|  void | [**Load**](#function-load) () <br> |




























## Public Types Documentation




### typedef ComponentInfo 

```C++
using OpenOasis::CommImp::IO::LinkLoader::ComponentInfo =  std::array<std::string, 3>;
```






### typedef ElementInfo 

```C++
using OpenOasis::CommImp::IO::LinkLoader::ElementInfo =  std::array<std::string, 5>;
```



## Public Functions Documentation




### function GetComponentIds 

```C++
std::vector< std::string > OpenOasis::CommImp::IO::LinkLoader::GetComponentIds () const
```






### function GetComponentInfo 

```C++
ComponentInfo OpenOasis::CommImp::IO::LinkLoader::GetComponentInfo (
    const std::string & compId
) const
```






### function GetComponentInputs 

```C++
std::vector< ElementInfo > OpenOasis::CommImp::IO::LinkLoader::GetComponentInputs (
    const std::string & compId
) const
```






### function GetComponentOutputs 

```C++
std::vector< ElementInfo > OpenOasis::CommImp::IO::LinkLoader::GetComponentOutputs (
    const std::string & compId
) const
```






### function GetInputProviders 

```C++
std::unordered_map< std::string, std::vector< ElementInfo > > OpenOasis::CommImp::IO::LinkLoader::GetInputProviders (
    const std::string & compId,
    const ElementInfo & input
) const
```






### function GetIteratorConfigs 

```C++
std::multimap< std::string, std::string > OpenOasis::CommImp::IO::LinkLoader::GetIteratorConfigs (
    const std::string & iterId
) const
```






### function GetIteratorGroups 

_Gets iterator groups consisted of components._ 
```C++
std::unordered_map< std::string, std::vector< std::string > > OpenOasis::CommImp::IO::LinkLoader::GetIteratorGroups () const
```





**Returns:**

The iterator groups, where each group contains a set of components. 





        



### function GetOutputConsumers 

```C++
std::unordered_map< std::string, std::vector< ElementInfo > > OpenOasis::CommImp::IO::LinkLoader::GetOutputConsumers (
    const std::string & compId,
    const ElementInfo & output
) const
```






### function LinkLoader 

```C++
inline OpenOasis::CommImp::IO::LinkLoader::LinkLoader (
    const std::string & json
) 
```






### function Load 

```C++
void OpenOasis::CommImp::IO::LinkLoader::Load () 
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/IO/LinkLoader.h`

