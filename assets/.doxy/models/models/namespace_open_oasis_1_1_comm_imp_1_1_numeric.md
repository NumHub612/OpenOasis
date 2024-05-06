

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
| class | [**DoubleSparseMatrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_double_sparse_matrix.md) <br>_Sparse matrix having double elements._  |
| class | [**Field**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md) &lt;typename T&gt;<br>_The abstract field class used to represent numeric field, such as scalar, vector or tensor data._  |
| class | [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) &lt;typename T&gt;<br> |
| class | [**Operator**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_operator.md) <br>_Abstract operator class._  |
| class | [**ScalarField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md) &lt;typename T&gt;<br>_Scaler field._  |
| class | [**Solver**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_solver.md) <br>_Abstract solver class._  |
| class | [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) &lt;typename T&gt;<br> |
| class | [**TensorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md) &lt;typename T&gt;<br>[_**Tensor**_](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) _field._ |
| class | [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) &lt;typename T, N&gt;<br> |
| class | [**VectorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md) &lt;typename T, N&gt;<br>[_**Vector**_](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) _field._ |


## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**BoundaryType**](#enum-boundarytype)  <br>[_**Boundary**_](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md) _type enum._ |
| typedef [**Operator**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_operator.md) | [**CurlOperator**](#typedef-curloperator)  <br>_Commomly used operators._  |
| typedef [**Operator**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_operator.md) | [**DdtOperator**](#typedef-ddtoperator)  <br> |
| typedef [**Boundary**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md) | [**DirichletBoundary**](#typedef-dirichletboundary)  <br> |
| typedef [**Operator**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_operator.md) | [**DivOperator**](#typedef-divoperator)  <br> |
| enum  | [**FieldDomain**](#enum-fielddomain)  <br>_The field domain enum._  |
| enum  | [**FieldType**](#enum-fieldtype)  <br>_The field type enum._  |
| typedef [**Operator**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_operator.md) | [**GradOperator**](#typedef-gradoperator)  <br> |
| typedef [**Operator**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_operator.md) | [**LaplacianOperator**](#typedef-laplacianoperator)  <br> |
| typedef std::tuple&lt; [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md)&lt; real &gt;, std::vector&lt; real &gt; &gt; | [**LinearEqs**](#typedef-lineareqs)  <br>_Linear equations consisting of coefficient matrix and source term vector._  |
| typedef [**Boundary**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md) | [**NeumannBoundary**](#typedef-neumannboundary)  <br> |
| typedef [**Boundary**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md) | [**RobinBoundary**](#typedef-robinboundary)  <br> |
| typedef [**ScalarField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md)&lt; Utils::real &gt; | [**ScalarFieldFp**](#typedef-scalarfieldfp)  <br> |
| typedef [**TensorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md)&lt; Utils::real &gt; | [**TensorFieldFp**](#typedef-tensorfieldfp)  <br> |
| typedef [**VectorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md)&lt; Utils::real &gt; | [**VectorFieldFp**](#typedef-vectorfieldfp)  <br> |
















































# Detailed Description



 Copyright (C) 2023, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Boundary.h @License : Apache-2.0


@Desc : Abstract boundary class.



 Copyright (C) 2023, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Field.h @License : Apache-2.0


@Desc : Abstract field class.



 Copyright (C) 2022, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Matrix.h @License : Apache-2.0


@Desc : Define [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) template class for numerical calculation.



 Copyright (C) 2023, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Operator.h @License : Apache-2.0


@Desc : Abstract operator class.



 Copyright (C) 2023, The [**OpenOasis**](namespace_open_oasis.md) Contributors. Join us in the Oasis!


@File : Solver.h @License : Apache-2.0


@Desc : Abstract solver class to provide unified interfaces. [**Solver**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_solver.md)'s responsible for parsing the equation expression to be solved, and discretizing the equation items in the computational domain, combining them into a matrix, and solving it.


[**Solver**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_solver.md) is also responsible for initializing the relevant field quantities, and providing specific discrete and stepping scheme. 


    
## Public Types Documentation




### enum BoundaryType 

```C++
enum OpenOasis::CommImp::Numeric::BoundaryType {
    ValueBound,
    FluxBound,
    MixedBound
};
```






### typedef CurlOperator 

```C++
using OpenOasis::CommImp::Numeric::CurlOperator = typedef Operator;
```






### typedef DdtOperator 

```C++
using OpenOasis::CommImp::Numeric::DdtOperator = typedef Operator;
```






### typedef DirichletBoundary 

```C++
using OpenOasis::CommImp::Numeric::DirichletBoundary = typedef Boundary;
```






### typedef DivOperator 

```C++
using OpenOasis::CommImp::Numeric::DivOperator = typedef Operator;
```






### enum FieldDomain 

```C++
enum OpenOasis::CommImp::Numeric::FieldDomain {
    NODE,
    FACE,
    CELL,
    NONE
};
```






### enum FieldType 

```C++
enum OpenOasis::CommImp::Numeric::FieldType {
    SCALAR,
    VECTOR,
    TENSOR,
    NONE
};
```






### typedef GradOperator 

```C++
using OpenOasis::CommImp::Numeric::GradOperator = typedef Operator;
```






### typedef LaplacianOperator 

```C++
using OpenOasis::CommImp::Numeric::LaplacianOperator = typedef Operator;
```






### typedef LinearEqs 

```C++
using OpenOasis::CommImp::Numeric::LinearEqs = typedef std::tuple<Matrix<real>, std::vector<real> >;
```






### typedef NeumannBoundary 

```C++
using OpenOasis::CommImp::Numeric::NeumannBoundary = typedef Boundary;
```






### typedef RobinBoundary 

```C++
using OpenOasis::CommImp::Numeric::RobinBoundary = typedef Boundary;
```






### typedef ScalarFieldFp 

```C++
using OpenOasis::CommImp::Numeric::ScalarFieldFp = typedef ScalarField<Utils::real>;
```






### typedef TensorFieldFp 

```C++
using OpenOasis::CommImp::Numeric::TensorFieldFp = typedef TensorField<Utils::real>;
```






### typedef VectorFieldFp 

```C++
using OpenOasis::CommImp::Numeric::VectorFieldFp = typedef VectorField<Utils::real>;
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Numeric/Boundary.h`

