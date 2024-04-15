

# Class OpenOasis::CommImp::Numeric::Laplacian



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Numeric**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md) **>** [**Laplacian**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_laplacian.md)



[_**Laplacian**_](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_laplacian.md) _operator for the divergence of the gradient of a scalar field._[More...](#detailed-description)

* `#include <LaplacianOperator.h>`



Inherits the following classes: [OpenOasis::CommImp::Numeric::Operator](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_operator.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual [**LinearEqs**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md#typedef-lineareqs) | [**Discretize**](#function-discretize) (const [**ScalarField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md)&lt; real &gt; & phiCellField, const [**ScalarField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md)&lt; real &gt; & phiFaceField) override<br> |
|   | [**Laplacian**](#function-laplacian) (const std::shared\_ptr&lt; [**Grid**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md) &gt; & grid) <br> |
| virtual  | [**~Laplacian**](#function-laplacian) () = default<br> |


## Public Functions inherited from OpenOasis::CommImp::Numeric::Operator

See [OpenOasis::CommImp::Numeric::Operator](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_operator.md)

| Type | Name |
| ---: | :--- |
| virtual [**LinearEqs**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md#typedef-lineareqs) | [**Discretize**](#function-discretize-13) (const [**ScalarField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md)&lt; real &gt; & phiCellField, const [**ScalarField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md)&lt; real &gt; & phiFaceField) <br> |
| virtual [**LinearEqs**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md#typedef-lineareqs) | [**Discretize**](#function-discretize-23) (const [**VectorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md)&lt; real &gt; & phiCellField, const [**VectorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md)&lt; real &gt; & phiFaceField) <br> |
| virtual [**LinearEqs**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md#typedef-lineareqs) | [**Discretize**](#function-discretize-33) (const [**TensorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md)&lt; real &gt; & phiCellField, const [**TensorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md)&lt; real &gt; & phiFaceField) <br> |
| virtual void | [**SetBoundaryCondition**](#function-setboundarycondition) (int faceIndex, const [**BoundaryCondition**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary_condition.md) & boundary) <br> |
| virtual void | [**SetCoefficient**](#function-setcoefficient-14) (const std::variant&lt; real, [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; real &gt;, [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md)&lt; real &gt; &gt; & coeff) <br> |
| virtual void | [**SetCoefficient**](#function-setcoefficient-24) (const [**ScalarField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md)&lt; real &gt; & coefficients) <br> |
| virtual void | [**SetCoefficient**](#function-setcoefficient-34) (const [**VectorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md)&lt; real &gt; & coefficients) <br> |
| virtual void | [**SetCoefficient**](#function-setcoefficient-44) (const [**TensorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md)&lt; real &gt; & coefficients) <br> |
| virtual  | [**~Operator**](#function-operator) () = default<br> |
















## Protected Attributes inherited from OpenOasis::CommImp::Numeric::Operator

See [OpenOasis::CommImp::Numeric::Operator](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_operator.md)

| Type | Name |
| ---: | :--- |
|  std::optional&lt; std::variant&lt; real, [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; real &gt;, [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md)&lt; real &gt; &gt; &gt; | [**mCoefficient**](#variable-mcoefficient)  <br> |
|  std::optional&lt; [**ScalarField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md)&lt; real &gt; &gt; | [**mScalarCoeffs**](#variable-mscalarcoeffs)  <br> |
|  std::optional&lt; [**TensorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md)&lt; real &gt; &gt; | [**mTensorCoeffs**](#variable-mtensorcoeffs)  <br> |
|  std::optional&lt; [**VectorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md)&lt; real &gt; &gt; | [**mVectorCoeffs**](#variable-mvectorcoeffs)  <br> |
|  std::unordered\_map&lt; int, [**BoundaryCondition**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary_condition.md) &gt; | [**mboundaries**](#variable-mboundaries)  <br> |






































# Detailed Description


First, calculate the gradient of the scalar field. Then, calculate the divergence of the gradient. 


    
## Public Functions Documentation




### function Discretize 

```C++
virtual LinearEqs OpenOasis::CommImp::Numeric::Laplacian::Discretize (
    const ScalarField < real > & phiCellField,
    const ScalarField < real > & phiFaceField
) override
```



Implements [*OpenOasis::CommImp::Numeric::Operator::Discretize*](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_operator.md#function-discretize-13)




### function Laplacian 

```C++
inline OpenOasis::CommImp::Numeric::Laplacian::Laplacian (
    const std::shared_ptr< Grid > & grid
) 
```






### function ~Laplacian 

```C++
virtual OpenOasis::CommImp::Numeric::Laplacian::~Laplacian () = default
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Numeric/LaplacianOperator.h`

