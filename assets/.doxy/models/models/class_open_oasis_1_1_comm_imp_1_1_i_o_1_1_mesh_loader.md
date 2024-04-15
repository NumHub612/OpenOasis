

# Class OpenOasis::CommImp::IO::MeshLoader



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**IO**](namespace_open_oasis_1_1_comm_imp_1_1_i_o.md) **>** [**MeshLoader**](class_open_oasis_1_1_comm_imp_1_1_i_o_1_1_mesh_loader.md)



_Default_ `Mesh` _data loader._[More...](#detailed-description)

* `#include <MeshLoader.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual std::unordered\_map&lt; int, [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) &gt; & | [**GetCellCoordinates**](#function-getcellcoordinates) () <br> |
| virtual std::unordered\_map&lt; int, std::vector&lt; int &gt; &gt; & | [**GetCellFaces**](#function-getcellfaces) () <br> |
| virtual std::unordered\_map&lt; int, [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) &gt; & | [**GetFaceCoordinates**](#function-getfacecoordinates) () <br> |
| virtual std::unordered\_map&lt; int, std::vector&lt; int &gt; &gt; & | [**GetFaceNodes**](#function-getfacenodes) () <br> |
| virtual std::unordered\_map&lt; int, [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) &gt; & | [**GetNodeCoordinates**](#function-getnodecoordinates) () <br> |
| virtual std::unordered\_map&lt; std::string, std::vector&lt; int &gt; &gt; & | [**GetPatches**](#function-getpatches) () <br> |
| virtual std::unordered\_map&lt; std::string, std::vector&lt; int &gt; &gt; & | [**GetZones**](#function-getzones) () <br> |
| virtual void | [**Load**](#function-load) () <br> |
|   | [**MeshLoader**](#function-meshloader) (const std::string & meshDir) <br> |
|   | [**~MeshLoader**](#function-meshloader) () <br> |
























## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**CheckIds**](#function-checkids) (const std::vector&lt; std::string &gt; & ids, const std::string & meta) <br> |
|  void | [**GenerateCellCoordinates**](#function-generatecellcoordinates) () <br> |
|  void | [**GenerateFaceCoordinates**](#function-generatefacecoordinates) () <br> |
|  void | [**LoadCells**](#function-loadcells) (const std::string & file="cells.csv") <br> |
|  void | [**LoadFaces**](#function-loadfaces) (const std::string & file="faces.csv") <br> |
|  void | [**LoadNodes**](#function-loadnodes) (const std::string & file="nodes.csv") <br> |
|  void | [**LoadPatches**](#function-loadpatches) (const std::string & file="patches.csv") <br> |
|  void | [**LoadZones**](#function-loadzones) (const std::string & file="zones.csv") <br> |




# Detailed Description


In default mode, coordinates are defined on nodes. 


    
## Public Functions Documentation




### function GetCellCoordinates 

```C++
virtual std::unordered_map< int, Coordinate > & OpenOasis::CommImp::IO::MeshLoader::GetCellCoordinates () 
```






### function GetCellFaces 

```C++
virtual std::unordered_map< int, std::vector< int > > & OpenOasis::CommImp::IO::MeshLoader::GetCellFaces () 
```






### function GetFaceCoordinates 

```C++
virtual std::unordered_map< int, Coordinate > & OpenOasis::CommImp::IO::MeshLoader::GetFaceCoordinates () 
```






### function GetFaceNodes 

```C++
virtual std::unordered_map< int, std::vector< int > > & OpenOasis::CommImp::IO::MeshLoader::GetFaceNodes () 
```






### function GetNodeCoordinates 

```C++
virtual std::unordered_map< int, Coordinate > & OpenOasis::CommImp::IO::MeshLoader::GetNodeCoordinates () 
```






### function GetPatches 

```C++
virtual std::unordered_map< std::string, std::vector< int > > & OpenOasis::CommImp::IO::MeshLoader::GetPatches () 
```






### function GetZones 

```C++
virtual std::unordered_map< std::string, std::vector< int > > & OpenOasis::CommImp::IO::MeshLoader::GetZones () 
```






### function Load 

```C++
virtual void OpenOasis::CommImp::IO::MeshLoader::Load () 
```






### function MeshLoader 

```C++
OpenOasis::CommImp::IO::MeshLoader::MeshLoader (
    const std::string & meshDir
) 
```






### function ~MeshLoader 

```C++
inline OpenOasis::CommImp::IO::MeshLoader::~MeshLoader () 
```



## Protected Functions Documentation




### function CheckIds 

```C++
void OpenOasis::CommImp::IO::MeshLoader::CheckIds (
    const std::vector< std::string > & ids,
    const std::string & meta
) 
```






### function GenerateCellCoordinates 

```C++
void OpenOasis::CommImp::IO::MeshLoader::GenerateCellCoordinates () 
```






### function GenerateFaceCoordinates 

```C++
void OpenOasis::CommImp::IO::MeshLoader::GenerateFaceCoordinates () 
```






### function LoadCells 

```C++
void OpenOasis::CommImp::IO::MeshLoader::LoadCells (
    const std::string & file="cells.csv"
) 
```






### function LoadFaces 

```C++
void OpenOasis::CommImp::IO::MeshLoader::LoadFaces (
    const std::string & file="faces.csv"
) 
```






### function LoadNodes 

```C++
void OpenOasis::CommImp::IO::MeshLoader::LoadNodes (
    const std::string & file="nodes.csv"
) 
```






### function LoadPatches 

```C++
void OpenOasis::CommImp::IO::MeshLoader::LoadPatches (
    const std::string & file="patches.csv"
) 
```






### function LoadZones 

```C++
void OpenOasis::CommImp::IO::MeshLoader::LoadZones (
    const std::string & file="zones.csv"
) 
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/IO/MeshLoader.h`

