

# Namespace OpenOasis::CommImp::Numeric



[**Namespace List**](namespaces.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Numeric**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md)



[More...](#detailed-description)














## Namespaces

| Type | Name |
| ---: | :--- |
| namespace | [**FVM**](namespace_open_oasis_1_1_comm_imp_1_1_numeric_1_1_f_v_m.md) <br> |


## Classes

| Type | Name |
| ---: | :--- |
| class | [**Boundary**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md) <br>_Abstract boundary class._  |
| struct | [**BoundaryCondition**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary_condition.md) <br>[_**Boundary**_](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md) _condition struct._ |
| class | [**DirichletBoundary**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_dirichlet_boundary.md) <br>_Dirichlet boundary._  |
| class | [**DoubleSparseMatrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_double_sparse_matrix.md) <br>_Sparse matrix having double elements._  |
| class | [**Field**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md) &lt;typename T&gt;<br>_The abstract field class used to represent numeric field, such as scalar, vector or tensor data._  |
| class | [**Laplacian**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_laplacian.md) <br>[_**Laplacian**_](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_laplacian.md) _operator for the divergence of the gradient of a scalar field._ |
| class | [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) &lt;typename T&gt;<br> |
| class | [**Operator**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_operator.md) <br>_Abstract operator class._  |
| class | [**ScalarField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md) &lt;typename T&gt;<br>_Scaler field._  |
| class | [**Solver**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_solver.md) <br>_Abstract solver class._  |
| class | [**Source**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_source.md) <br> |
| class | [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) &lt;typename T&gt;<br> |
| class | [**TensorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md) &lt;typename T&gt;<br>[_**Tensor**_](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) _field._ |
| class | [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) &lt;typename T, N&gt;<br> |
| class | [**VectorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md) &lt;typename T, N&gt;<br>[_**Vector**_](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) _field with default zero vector in 2D or 3D space._ |


## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**FieldDomain**](#enum-fielddomain)  <br> |
| enum  | [**FieldType**](#enum-fieldtype)  <br> |
| typedef std::tuple&lt; [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md)&lt; real &gt;, std::vector&lt; real &gt; &gt; | [**LinearEqs**](#typedef-lineareqs)  <br>_Linear equations consisting of coefficient matrix and source term vector._  |
| typedef [**ScalarField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md)&lt; double &gt; | [**ScalarFieldDbl**](#typedef-scalarfielddbl)  <br> |
| typedef [**ScalarField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md)&lt; Utils::real &gt; | [**ScalarFieldFp**](#typedef-scalarfieldfp)  <br> |
| typedef [**ScalarField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md)&lt; int &gt; | [**ScalarFieldInt**](#typedef-scalarfieldint)  <br> |
| enum  | [**SolverStatus**](#enum-solverstatus)  <br> |
| typedef [**TensorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md)&lt; double &gt; | [**TensorFieldDbl**](#typedef-tensorfielddbl)  <br> |
| typedef [**TensorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md)&lt; Utils::real &gt; | [**TensorFieldFp**](#typedef-tensorfieldfp)  <br> |
| typedef [**TensorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md)&lt; int &gt; | [**TensorFieldInt**](#typedef-tensorfieldint)  <br> |
| typedef [**VectorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md)&lt; double, 2 &gt; | [**VectorFieldDbl2D**](#typedef-vectorfielddbl2d)  <br> |
| typedef [**VectorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md)&lt; double, 3 &gt; | [**VectorFieldDbl3D**](#typedef-vectorfielddbl3d)  <br> |
| typedef [**VectorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md)&lt; Utils::real, 3 &gt; | [**VectorFieldFp**](#typedef-vectorfieldfp)  <br> |
| typedef [**VectorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md)&lt; int, 2 &gt; | [**VectorFieldInt2D**](#typedef-vectorfieldint2d)  <br> |
| typedef [**VectorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md)&lt; int, 3 &gt; | [**VectorFieldInt3D**](#typedef-vectorfieldint3d)  <br> |
















































# Detailed Description



 Copyright (C) 2023, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Boundary.h @License : Apache-2.0


@Desc : Abstract boundary class.



 @File : DirichletBoundary.cpp @Brief : Dirichlet boundary.



 Copyright (C) 2023, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : DirichletBoundary.h @License : Apache-2.0


@Desc : Dirichlet boundary.



 Copyright (C) 2023, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Field.h @License : Apache-2.0


@Desc : Abstract field class.



 @File : LaplacianOperator.cpp @Brief : [**Laplacian**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_laplacian.md) [**Operator**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_operator.md).



 Copyright (C) 2023, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : LaplacianOperator.h @License : Apache-2.0


@Desc : [**Laplacian**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_laplacian.md) [**Operator**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_operator.md).



 @File : Matrix.cpp @Brief : To provide matrix interface and a common implementation.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Matrix.h @License : Apache-2.0


@Desc : Define [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) template class for numerical calculation.



 Copyright (C) 2023, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Operator.h @License : Apache-2.0


@Desc : Abstract operator class.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : ScalarField.h @License : Apache-2.0


@Desc : [**ScalarField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md) for the definition and calculation of scalar fields.



 Copyright (C) 2023, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Solver.h @License : Apache-2.0


@Desc : Abstract solver class to provide unified interfaces. [**Solver**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_solver.md)'s responsible for parsing the equation expression to be solved, and discretizing the equation items in the computational domain, combining them into a matrix, and solving it.


[**Solver**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_solver.md) is also responsible for initializing the relevant field quantities, and providing specific discrete and stepping scheme.



 Copyright (C) 2023, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Source.h @License : Apache-2.0


@Desc : Abstract [**Source**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_source.md) class for definition of source vector.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : TensorField.h @License : Apache-2.0


@Desc : [**TensorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md) for the definition and calculation of tensor fields.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : VectorField.h @License : Apache-2.0


@Desc : [**VectorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md) for the definition and calculation of vector fields. 


    
## Public Types Documentation




### enum FieldDomain 

```C++
enum OpenOasis::CommImp::Numeric::FieldDomain {
    NONE,
    NODE,
    FACE,
    CELL
};
```






### enum FieldType 

```C++
enum OpenOasis::CommImp::Numeric::FieldType {
    NONE,
    SCALAR,
    VECTOR,
    TENSOR
};
```






### typedef LinearEqs 

```C++
using OpenOasis::CommImp::Numeric::LinearEqs = typedef std::tuple<Matrix<real>, std::vector<real> >;
```






### typedef ScalarFieldDbl 

```C++
using OpenOasis::CommImp::Numeric::ScalarFieldDbl = typedef ScalarField<double>;
```






### typedef ScalarFieldFp 

```C++
using OpenOasis::CommImp::Numeric::ScalarFieldFp = typedef ScalarField<Utils::real>;
```






### typedef ScalarFieldInt 

```C++
using OpenOasis::CommImp::Numeric::ScalarFieldInt = typedef ScalarField<int>;
```






### enum SolverStatus 

```C++
enum OpenOasis::CommImp::Numeric::SolverStatus {
    Created,
    Initialized,
    Parsed,
    Discretized,
    Updated,
    Solved,
    Failed
};
```






### typedef TensorFieldDbl 

```C++
using OpenOasis::CommImp::Numeric::TensorFieldDbl = typedef TensorField<double>;
```






### typedef TensorFieldFp 

```C++
using OpenOasis::CommImp::Numeric::TensorFieldFp = typedef TensorField<Utils::real>;
```






### typedef TensorFieldInt 

```C++
using OpenOasis::CommImp::Numeric::TensorFieldInt = typedef TensorField<int>;
```






### typedef VectorFieldDbl2D 

```C++
using OpenOasis::CommImp::Numeric::VectorFieldDbl2D = typedef VectorField<double, 2>;
```






### typedef VectorFieldDbl3D 

```C++
using OpenOasis::CommImp::Numeric::VectorFieldDbl3D = typedef VectorField<double, 3>;
```






### typedef VectorFieldFp 

```C++
using OpenOasis::CommImp::Numeric::VectorFieldFp = typedef VectorField<Utils::real, 3>;
```






### typedef VectorFieldInt2D 

```C++
using OpenOasis::CommImp::Numeric::VectorFieldInt2D = typedef VectorField<int, 2>;
```






### typedef VectorFieldInt3D 

```C++
using OpenOasis::CommImp::Numeric::VectorFieldInt3D = typedef VectorField<int, 3>;
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Numeric/Boundary.h`

