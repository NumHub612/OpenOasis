

# Namespace OpenOasis::CommImp::Spatial



[**Namespace List**](namespaces.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Spatial**](namespace_open_oasis_1_1_comm_imp_1_1_spatial.md)



[More...](#detailed-description)
















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**Cell**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_cell.md) <br>[_**Mesh**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) _cell data structure. Polygon type for 1D and 2D mesh, Polyhedron type for 3D mesh._ |
| struct | [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) <br>_The_ [_**Coordinate**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) _struct contains a (x, y, z) coordinate._ |
| struct | [**Face**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_face.md) <br>[_**Mesh**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) _face data structure. Polyline type for 1D or 2D mesh, Polygon type for 3D mesh._ |
| class | [**GeoCalculator**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_geo_calculator.md) <br>_The_ [_**GeoCalculator**_](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_geo_calculator.md) _is a collection of general geometry functions._ |
| class | [**Grid**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md) <br>[_**Grid**_](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md) _encapsulate the mesh data for numerical calculation._ |
| class | [**Grid1D**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid1_d.md) <br> |
| class | [**Grid2D**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid2_d.md) <br>[_**Grid**_](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md) _formed by flat cells in 2d._ |
| class | [**Grid3D**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid3_d.md) <br> |
| struct | [**Mesh**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) <br>[_**Mesh**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) _structure._ |
| struct | [**Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) <br>[_**Mesh**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) _node data structure. (Point type)._ |
| struct | [**XYExtent**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_extent.md) <br>_Extent is a rectangle in xy-space._  |
| class | [**XYGeoTools**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_geo_tools.md) <br>_The_ [_**XYGeoTools**_](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_geo_tools.md) _class is a collection of general geometry functions._ |
| struct | [**XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) <br>_The XYline struct is used for representing a line segment._  |
| struct | [**XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) <br>[_**XYPoint**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) _is simply a x and y coordinate point (has no z coordinate)._ |
| struct | [**XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) <br>_The_ [_**XYPolygon**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) _struct defines a polygon in the XY plane (no z coordinate)._ |
| struct | [**XYPolyline**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polyline.md) <br>[_**XYPolyline**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polyline.md) _is a collection of points (at least 2) connected with straigth lines. XYPolylines are typically used for presentation of 1D data, river network._ |


















































# Detailed Description



 @File : Coordinate.cpp @Brief : None.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Coordinate.h @License : Apache-2.0


@Desc : The [**Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) struct contains a (x, y, z) coordinate.



 @File : GeoCalculator.cpp @Brief : A collection of general geometry functions.



 @File : Grid.cpp @Brief : [**Grid**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md) used for numerical calculation.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Grid.h @License : Apache-2.0


@Desc : [**Grid**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md) used for numerical calculation.



 @File : Grid1D.cpp @Brief : [**Grid**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md) in river net used for numerical calculation.



 @File : Grid2D.cpp @Brief : [**Grid**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md) in 2d used for numerical calculation.



 @File : Grid3D.cpp @Brief : [**Grid**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md) in 3d used for numerical calculation.



 @File : XYGeoStructs.cpp @Brief : To provide basic plane geometry data structures (no z coordinate).



 @File : XYGeoTools.cpp @Brief : The [**XYGeoTools**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_geo_tools.md) class is a collection of general geometry functions. 


    

------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Spatial/Coordinate.cpp`

