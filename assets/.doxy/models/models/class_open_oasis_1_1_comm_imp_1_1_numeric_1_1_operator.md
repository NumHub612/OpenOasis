

# Class OpenOasis::CommImp::Numeric::Operator



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Numeric**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md) **>** [**Operator**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_operator.md)



_Abstract operator class._ [More...](#detailed-description)

* `#include <Operator.h>`





Inherited by the following classes: [OpenOasis::CommImp::Numeric::FVM::Laplacian](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_f_v_m_1_1_laplacian.md)
































## Public Functions

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








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  std::optional&lt; std::variant&lt; real, [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; real &gt;, [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md)&lt; real &gt; &gt; &gt; | [**mCoefficient**](#variable-mcoefficient)  <br> |
|  std::optional&lt; [**ScalarField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md)&lt; real &gt; &gt; | [**mScalarCoeffs**](#variable-mscalarcoeffs)  <br> |
|  std::optional&lt; [**TensorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md)&lt; real &gt; &gt; | [**mTensorCoeffs**](#variable-mtensorcoeffs)  <br> |
|  std::optional&lt; [**VectorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md)&lt; real &gt; &gt; | [**mVectorCoeffs**](#variable-mvectorcoeffs)  <br> |
|  std::unordered\_map&lt; int, [**BoundaryCondition**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary_condition.md) &gt; | [**mboundaries**](#variable-mboundaries)  <br> |




















# Detailed Description


Each numerical operator can discretize specific equation terms, or say carry out specific operations on field quantities, and return corresponding coefficient matrix and source term vector. 


    
## Public Functions Documentation




### function Discretize [1/3]

```C++
inline virtual LinearEqs OpenOasis::CommImp::Numeric::Operator::Discretize (
    const ScalarField < real > & phiCellField,
    const ScalarField < real > & phiFaceField
) 
```






### function Discretize [2/3]

```C++
inline virtual LinearEqs OpenOasis::CommImp::Numeric::Operator::Discretize (
    const VectorField < real > & phiCellField,
    const VectorField < real > & phiFaceField
) 
```






### function Discretize [3/3]

```C++
inline virtual LinearEqs OpenOasis::CommImp::Numeric::Operator::Discretize (
    const TensorField < real > & phiCellField,
    const TensorField < real > & phiFaceField
) 
```






### function SetBoundaryCondition 

```C++
inline virtual void OpenOasis::CommImp::Numeric::Operator::SetBoundaryCondition (
    int faceIndex,
    const BoundaryCondition & boundary
) 
```






### function SetCoefficient [1/4]

```C++
inline virtual void OpenOasis::CommImp::Numeric::Operator::SetCoefficient (
    const std::variant< real, Vector < real >, Tensor < real > > & coeff
) 
```






### function SetCoefficient [2/4]

```C++
inline virtual void OpenOasis::CommImp::Numeric::Operator::SetCoefficient (
    const ScalarField < real > & coefficients
) 
```






### function SetCoefficient [3/4]

```C++
inline virtual void OpenOasis::CommImp::Numeric::Operator::SetCoefficient (
    const VectorField < real > & coefficients
) 
```






### function SetCoefficient [4/4]

```C++
inline virtual void OpenOasis::CommImp::Numeric::Operator::SetCoefficient (
    const TensorField < real > & coefficients
) 
```






### function ~Operator 

```C++
virtual OpenOasis::CommImp::Numeric::Operator::~Operator () = default
```



## Protected Attributes Documentation




### variable mCoefficient 

```C++
std::optional<std::variant<real, Vector<real>, Tensor<real> > > OpenOasis::CommImp::Numeric::Operator::mCoefficient;
```






### variable mScalarCoeffs 

```C++
std::optional<ScalarField<real> > OpenOasis::CommImp::Numeric::Operator::mScalarCoeffs;
```






### variable mTensorCoeffs 

```C++
std::optional<TensorField<real> > OpenOasis::CommImp::Numeric::Operator::mTensorCoeffs;
```






### variable mVectorCoeffs 

```C++
std::optional<VectorField<real> > OpenOasis::CommImp::Numeric::Operator::mVectorCoeffs;
```






### variable mboundaries 

```C++
std::unordered_map<int, BoundaryCondition> OpenOasis::CommImp::Numeric::Operator::mboundaries;
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Numeric/Operator.h`

