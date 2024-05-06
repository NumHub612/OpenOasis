
# Class Hierarchy

This inheritance list is sorted roughly, but not completely, alphabetically:


* **class** [**OpenOasis::AdditionalControl::IComparable**](class_open_oasis_1_1_additional_control_1_1_i_comparable.md) _Interface class provides a unified interface for object comparison._ 
* **class** [**OpenOasis::AdditionalControl::ISpaceExtension**](class_open_oasis_1_1_additional_control_1_1_i_space_extension.md) 
* **class** [**OpenOasis::AdditionalControl::ITimeExtension**](class_open_oasis_1_1_additional_control_1_1_i_time_extension.md) _Methods that are specific for a time-space component._ 
* **class** [**OpenOasis::CommImp::IO::LinkLoader**](class_open_oasis_1_1_comm_imp_1_1_i_o_1_1_link_loader.md) _Class forLoading components coupling configurations json file._ 
* **class** [**OpenOasis::CommImp::IO::MeshLoader**](class_open_oasis_1_1_comm_imp_1_1_i_o_1_1_mesh_loader.md) _Default_ `Mesh` _data loader._
* **class** [**OpenOasis::CommImp::IO::TaskLoader**](class_open_oasis_1_1_comm_imp_1_1_i_o_1_1_task_loader.md) _Loading components task configurations yaml file._ 
* **class** [**OpenOasis::CommImp::Numeric::Boundary**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md) _Abstract boundary class._     
    * **class** [**OpenOasis::CommImp::Numeric::FVM::DirichletBoundary**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_f_v_m_1_1_dirichlet_boundary.md) _Dirichlet boundary._ 
* **class** [**OpenOasis::CommImp::Numeric::DoubleSparseMatrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_double_sparse_matrix.md) _Sparse matrix having double elements._ 
* **class** [**OpenOasis::CommImp::Numeric::DoubleSparseMatrix::Index**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_double_sparse_matrix_1_1_index.md) 
* **class** [**OpenOasis::CommImp::Numeric::Solver**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_solver.md) _Abstract solver class._     
    * **class** [**OpenOasis::CommImp::Numeric::FVM::FvmSolver**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_f_v_m_1_1_fvm_solver.md) 
* **class** [**OpenOasis::CommImp::Numeric::Operator**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_operator.md) _Abstract operator class._     
    * **class** [**OpenOasis::CommImp::Numeric::FVM::Laplacian**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_f_v_m_1_1_laplacian.md) [_**Laplacian**_](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_f_v_m_1_1_laplacian.md) _operator for the divergence of the gradient of a scalar field._
* **class** [**OpenOasis::CommImp::Numeric::Field**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md) _The abstract field class used to represent numeric field, such as scalar, vector or tensor data._     
    * **class** [**OpenOasis::CommImp::Numeric::ScalarField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md) _Scaler field._ 
    * **class** [**OpenOasis::CommImp::Numeric::ScalarField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md) _Scaler field._ 
    * **class** [**OpenOasis::CommImp::Numeric::VectorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md) [_**Vector**_](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) _field._
* **class** [**OpenOasis::CommImp::Numeric::Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) 
* **class** [**OpenOasis::CommImp::Numeric::Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) 
* **class** [**OpenOasis::CommImp::Numeric::Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) 
* **class** [**OpenOasis::CommImp::Spatial::GeoCalculator**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_geo_calculator.md) _The_ [_**GeoCalculator**_](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_geo_calculator.md) _is a collection of general geometry functions._
* **class** [**OpenOasis::CommImp::Spatial::Grid**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md) [_**Grid**_](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md) _encapsulate the mesh data for numerical calculation._    
    * **class** [**OpenOasis::CommImp::Spatial::Grid1D**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid1_d.md) 
    * **class** [**OpenOasis::CommImp::Spatial::Grid2D**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid2_d.md) [_**Grid**_](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md) _formed by flat cells in 2d._
    * **class** [**OpenOasis::CommImp::Spatial::Grid3D**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid3_d.md) 
* **class** [**OpenOasis::CommImp::Spatial::XYGeoTools**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_geo_tools.md) _The_ [_**XYGeoTools**_](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_geo_tools.md) _class is a collection of general geometry functions._
* **class** [**OpenOasis::CommImp::Temporal::TimeBuffer**](class_open_oasis_1_1_comm_imp_1_1_temporal_1_1_time_buffer.md) _The_ [_**TimeBuffer**_](class_open_oasis_1_1_comm_imp_1_1_temporal_1_1_time_buffer.md) _class provides temporal buffering functionality._
* **class** [**OpenOasis::ExchangeItemChangeEventArgs**](class_open_oasis_1_1_exchange_item_change_event_args.md) _Class containing the information that will be passed when firing an_ `ExchangeItemValueChanged` _event._
* **class** [**OpenOasis::IDescribable**](class_open_oasis_1_1_i_describable.md) _An entity that is describable has a caption (title or heading) and a description. These are not to be used for identification._     
    * **class** [**OpenOasis::ICategory**](class_open_oasis_1_1_i_category.md) _Class describes one item of a possible categorization._ 
    * **class** [**OpenOasis::IIdentifiable**](class_open_oasis_1_1_i_identifiable.md) _To define a method to get the Id of an_ [_**OpenOasis**_](namespace_open_oasis.md) _entity._    
        * **class** [**OpenOasis::IAdaptedOutputFactory**](class_open_oasis_1_1_i_adapted_output_factory.md) _Factory class for creating instances of_ `IAdaptedOutput` _items._
        * **class** [**OpenOasis::IArgument**](class_open_oasis_1_1_i_argument.md) _Class for providing arguments for an_ `ILinkableComponent` _and others._
        * **class** [**OpenOasis::IBaseExchangeItem**](class_open_oasis_1_1_i_base_exchange_item.md) _Class presenting a item that can be exchanged, either as an input or output._     
            * **class** [**OpenOasis::IInput**](class_open_oasis_1_1_i_input.md) _An input item that can accept values for an_ `ILinkableComponent` _. The input item may have multiple providers._
            * **class** [**OpenOasis::IOutput**](class_open_oasis_1_1_i_output.md) _Output exchange item that can deliver values from an_ `ILinkableComponent` _._    
                * **class** [**OpenOasis::IAdaptedOutput**](class_open_oasis_1_1_i_adapted_output.md) _Extension class for adding data operations on top of an output item._ 
        * **class** [**OpenOasis::ILinkableComponent**](class_open_oasis_1_1_i_linkable_component.md) _The key interface class for linkable modules connection and data transfer._ 
    * **class** [**OpenOasis::ISpatialDefinition**](class_open_oasis_1_1_i_spatial_definition.md) _General spatial construct that all other spatial constructions extend from._     
        * **class** [**OpenOasis::IElementSet**](class_open_oasis_1_1_i_element_set.md) _An list of elements having a common type._ 
    * **class** [**OpenOasis::IUnit**](class_open_oasis_1_1_i_unit.md) _Unit interface describes the physical unit._ 
    * **class** [**OpenOasis::IValueDefinition**](class_open_oasis_1_1_i_value_definition.md) _Class describes value definition._     
        * **class** [**OpenOasis::IQuality**](class_open_oasis_1_1_i_quality.md) _Class describes qualitative data, where a value is specified as one category within a number of predefined (possible) categories._ 
        * **class** [**OpenOasis::IQuantity**](class_open_oasis_1_1_i_quantity.md) _Class specifies values as an amount of some unit._ 
* **class** [**OpenOasis::IByteStateConverter**](class_open_oasis_1_1_i_byte_state_converter.md) _An optional interface to save and transform the model state._ 
* **class** [**OpenOasis::IDimension**](class_open_oasis_1_1_i_dimension.md) _Define the order of each dimension in_ `DimensionBase` _for a unit._
* **class** [**OpenOasis::IManageState**](class_open_oasis_1_1_i_manage_state.md) _It provides additional methods for handling component state so it can be saved, restored and cleared._ 
* **class** [**OpenOasis::ITime**](class_open_oasis_1_1_i_time.md) _Time interface to support a time stamp as well as a time interval._ 
* **class** [**OpenOasis::ITimeSet**](class_open_oasis_1_1_i_time_set.md) _Set of time stamps or time intervals, used to indicate when an output has and can provide values, and when an input item does or may require values._ 
* **class** [**OpenOasis::IValueSet**](class_open_oasis_1_1_i_value_set.md) _Class represents a general(ordered) multi-dimensional set of values._ 
* **class** [**OpenOasis::LinkableComponentStatusChangeEventArgs**](class_open_oasis_1_1_linkable_component_status_change_event_args.md) _Class contains the information that will be passed when the_ `ILinkableComponent` _fires the_`StatusChanged` _event._
* **struct** [**OpenOasis::CommImp::Numeric::BoundaryCondition**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary_condition.md) [_**Boundary**_](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md) _condition struct._
* **struct** [**OpenOasis::CommImp::Numeric::DoubleSparseMatrix::EqualFunc**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_double_sparse_matrix_1_1_equal_func.md) 
* **struct** [**OpenOasis::CommImp::Numeric::DoubleSparseMatrix::HashFunc**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_double_sparse_matrix_1_1_hash_func.md) 
* **struct** [**OpenOasis::CommImp::Spatial::Cell**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_cell.md) [_**Mesh**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) _cell data structure. Polygon type for 1D and 2D mesh, Polyhedron type for 3D mesh._
* **struct** [**OpenOasis::CommImp::Spatial::Coordinate**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) _The_ [_**Coordinate**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_coordinate.md) _struct contains a (x, y, z) coordinate._
* **struct** [**OpenOasis::CommImp::Spatial::Face**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_face.md) [_**Mesh**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) _face data structure. Polyline type for 1D or 2D mesh, Polygon type for 3D mesh._
* **struct** [**OpenOasis::CommImp::Spatial::Mesh**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) [_**Mesh**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) _structure._
* **struct** [**OpenOasis::CommImp::Spatial::Node**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_node.md) [_**Mesh**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_mesh.md) _node data structure. (Point type)._
* **struct** [**OpenOasis::CommImp::Spatial::XYExtent**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_extent.md) _Extent is a rectangle in xy-space._ 
* **struct** [**OpenOasis::CommImp::Spatial::XYLine**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_line.md) _The XYline struct is used for representing a line segment._ 
* **struct** [**OpenOasis::CommImp::Spatial::XYPoint**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) [_**XYPoint**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_point.md) _is simply a x and y coordinate point (has no z coordinate)._
* **struct** [**OpenOasis::CommImp::Spatial::XYPolygon**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) _The_ [_**XYPolygon**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polygon.md) _struct defines a polygon in the XY plane (no z coordinate)._
* **struct** [**OpenOasis::CommImp::Spatial::XYPolyline**](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polyline.md) [_**XYPolyline**_](struct_open_oasis_1_1_comm_imp_1_1_spatial_1_1_x_y_polyline.md) _is a collection of points (at least 2) connected with straigth lines. XYPolylines are typically used for presentation of 1D data, river network._
* **class** **LinkableComponent**    
    * **class** [**OpenOasis::SystHeats::HeatConductionModel**](class_open_oasis_1_1_syst_heats_1_1_heat_conduction_model.md) 

