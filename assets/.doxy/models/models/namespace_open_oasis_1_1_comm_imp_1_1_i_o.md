

# Namespace OpenOasis::CommImp::IO



[**Namespace List**](namespaces.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**IO**](namespace_open_oasis_1_1_comm_imp_1_1_i_o.md)



[More...](#detailed-description)
















## Classes

| Type | Name |
| ---: | :--- |
| class | [**LinkLoader**](class_open_oasis_1_1_comm_imp_1_1_i_o_1_1_link_loader.md) <br>_Class forLoading components coupling configurations json file._  |
| class | [**MeshLoader**](class_open_oasis_1_1_comm_imp_1_1_i_o_1_1_mesh_loader.md) <br>_Default_ `Mesh` _data loader._ |
| class | [**TaskLoader**](class_open_oasis_1_1_comm_imp_1_1_i_o_1_1_task_loader.md) <br>_Loading components task configurations yaml file._  |








## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  int | [**DEFAULT\_FILE\_NUM**](#variable-default_file_num)   = = 9<br> |
|  const string | [**DEFAULT\_LOGGER\_ID**](#variable-default_logger_id)   = = "OasisLog"<br> |
|  int | [**DEFAULT\_LOGGER\_SIZE**](#variable-default_logger_size)   = = 1024 \* 1024 \* 5<br> |
|  unordered\_map&lt; string, shared\_ptr&lt; spdlog::logger &gt; &gt; | [**OasisLoggers**](#variable-oasisloggers)   = = {
    {DEFAULT\_LOGGER\_ID,
     spdlog::rotating\_logger\_mt(
         DEFAULT\_LOGGER\_ID, DEFAULT\_LOGGER\_ID, DEFAULT\_LOGGER\_SIZE, DEFAULT\_FILE\_NUM)}}<br> |
|  shared\_ptr&lt; spdlog::logger &gt; | [**logger**](#variable-logger)   = = GetLogger()<br> |
|  mutex | [**mtx**](#variable-mtx)  <br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  shared\_ptr&lt; spdlog::logger &gt; | [**GetLogger**](#function-getlogger) (const string & loggerId) <br> |
|  std::shared\_ptr&lt; spdlog::logger &gt; | [**GetLogger**](#function-getlogger) (const std::string & loggerId="OasisLog") <br>_To get rotating logger with specified id._  |




























# Detailed Description



 @File : LinkLoader.cpp @Brief : To provide unified interfaces for loading coupling configurations.



 Copyright (C) 2024, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : LinkLoader.h @License : Apache-2.0


@Desc : To provide unified interfaces for loading coupling configurations.


Coupling between components requires clarification of several issues, including:
* Which coupling mode is used, i.e., loop-mode or pull-mode?
* Which two components are coupled?
* Which component objects are coupled?
* Which object states are coupled?
* During which period of coupling?
* What coupling adaptation operations are used?




A component connection configuration needs to describe the above issues clearly, which is designed in the following format:



```C++
{
    "comps": {
        "comp1": {
            "description": "{some description about comp1}",
            "type": "{component type of comp1}",
            "task": "{path_to_taskfile}/task.yaml",
            "dll": "{path_to_dllfile}/OasisFlows.dll",
            "link": false
        },
        "comp2": {
            "description": "{some description about comp2}",
            "type": "{component type of comp2}",
            "task": "{path_to_taskfile}/task.yaml",
            "dll": "{path_to_dllfile}/OasisFlows.dll",
            "link": false
        },
        ...
    },
    "links": {
        "link_comp1_to_comp2": {
            "description": "{some description about the coupling link}",
            "pipelines": [
                {
                    "src_component": "{name of the source component}",
                    "src_state": "{state of the source element}",
                    "src_elements": [
                        {
                            "id": "c1_e1",
                            "type": "{type of the specified element}"
                        },
                        {
                            "id": "c1_e2",
                            "type": "{type of the specified element}"
                        },
                        ...
                    ],
                    "tar_component": "{name of the target component}",
                    "tar_element": {
                        "id": "c2_e1",
                        "type": "{type of the specified element}"
                    },
                    "temporal_operators": "accumulate",
                    "spatial_operators": "average"
                }
                ...
            ],
            "link_mode": "pull",
            "params":{
                "max_iter_steps": "25",
                "tolerance": "0.001",
                ...
            }
        },
        ...
    }
}
```




 @File : Logger.cpp @Brief : Provide logger.



 @File : MeshLoader.cpp @Brief : Loading mesh data from files.



 Copyright (C) 2023, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : MeshLoader.h @License : Apache-2.0


@Desc : Loading mesh data from files. The default mesh loader predefined a fixed set of csv files for storing mesh data, including :


nodes.csv, used for storing node coordinates data, formated as : "nId, x, y, z" faces.csv, used for storing face nodes index data, formated as : "fId, nId1, nId2" cells.csv, used for storing cell faces index data, formated as : "cId, fId1, fId2, fId3, ..."


And more :


zones.csv, used for storing zone faces index data, formated as : "zId, fId1, fId2, fId3, ..." patches.csv, used for storing patch faces indexes, formated as : "pId, fId1, fId2, fId3, ..."



 Copyright (C) 2023, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : NetworkLoader.h @License : Apache-2.0


@Desc : Loading river, pipe or mixed network data from files.



 Copyright (C) 2024, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : OutputCsv.h @License : Apache-2.0


@Desc : To provide unified output interface for the csv format.



 Copyright (C) 2024, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : TaskLoader.h @License : Apache-2.0


@Desc : To provide a unified interface for loading model tasks. 


    
## Public Static Attributes Documentation




### variable DEFAULT\_FILE\_NUM 

```C++
int OpenOasis::CommImp::IO::DEFAULT_FILE_NUM;
```






### variable DEFAULT\_LOGGER\_ID 

```C++
const string OpenOasis::CommImp::IO::DEFAULT_LOGGER_ID;
```






### variable DEFAULT\_LOGGER\_SIZE 

```C++
int OpenOasis::CommImp::IO::DEFAULT_LOGGER_SIZE;
```






### variable OasisLoggers 

```C++
unordered_map<string, shared_ptr<spdlog::logger> > OpenOasis::CommImp::IO::OasisLoggers;
```






### variable logger 

```C++
shared_ptr<spdlog::logger> OpenOasis::CommImp::IO::logger;
```






### variable mtx 

```C++
mutex OpenOasis::CommImp::IO::mtx;
```



## Public Functions Documentation




### function GetLogger 

```C++
shared_ptr< spdlog::logger > OpenOasis::CommImp::IO::GetLogger (
    const string & loggerId
) 
```






### function GetLogger 

```C++
std::shared_ptr< spdlog::logger > OpenOasis::CommImp::IO::GetLogger (
    const std::string & loggerId="OasisLog"
) 
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/IO/LinkLoader.cpp`

