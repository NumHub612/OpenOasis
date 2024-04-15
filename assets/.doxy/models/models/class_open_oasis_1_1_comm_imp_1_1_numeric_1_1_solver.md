

# Class OpenOasis::CommImp::Numeric::Solver



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Numeric**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md) **>** [**Solver**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_solver.md)



_Abstract solver class._ 

* `#include <Solver.h>`





Inherited by the following classes: [OpenOasis::CommImp::Numeric::FVM::FvmSolver](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_f_v_m_1_1_fvm_solver.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**AfterScheme**](#function-afterscheme) () <br> |
| virtual void | [**AfterSolve**](#function-aftersolve) () <br> |
| virtual void | [**BeforeScheme**](#function-beforescheme) () <br> |
| virtual void | [**BeforeSolve**](#function-beforesolve) () <br> |
|  std::optional&lt; [**LinearEqs**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md#typedef-lineareqs) &gt; | [**GetLinearEqs**](#function-getlineareqs) () const<br> |
| virtual std::optional&lt; [**ScalarFieldFp**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md) &gt; | [**GetScalarSolutions**](#function-getscalarsolutions) (const std::string & var) const<br> |
| virtual std::optional&lt; [**TensorFieldFp**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md) &gt; | [**GetTensorSolutions**](#function-gettensorsolutions) (const std::string & var) const<br> |
| virtual std::optional&lt; [**VectorFieldFp**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md) &gt; | [**GetVectorSolutions**](#function-getvectorsolutions) (const std::string & var) const<br> |
| virtual void | [**ParseConvectionTerm**](#function-parseconvectionterm) () <br> |
| virtual void | [**ParseDiffusionTerm**](#function-parsediffusionterm) () <br> |
| virtual void | [**ParseSourceTerm**](#function-parsesourceterm) () <br> |
| virtual void | [**ParseTimeDerivativeTerm**](#function-parsetimederivativeterm) () <br> |
| virtual void | [**Scheme**](#function-scheme) () <br> |
| virtual void | [**SetBoundary**](#function-setboundary) (int faceIndex, const std::shared\_ptr&lt; [**Boundary**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md) &gt; & bound) <br> |
| virtual void | [**SetCoefficient**](#function-setcoefficient-14) (const std::string & var, const std::variant&lt; real, [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; real &gt;, [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md)&lt; real &gt; &gt; & coeff) <br> |
| virtual void | [**SetCoefficient**](#function-setcoefficient-24) (const std::string & var, const [**ScalarFieldFp**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md) & coeffs) <br> |
| virtual void | [**SetCoefficient**](#function-setcoefficient-34) (const std::string & var, const [**VectorFieldFp**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md) & coeffs) <br> |
| virtual void | [**SetCoefficient**](#function-setcoefficient-44) (const std::string & var, const [**TensorFieldFp**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md) & coeffs) <br> |
| virtual void | [**SetInitialValue**](#function-setinitialvalue-14) (const std::string & var, const std::variant&lt; real, [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; real &gt;, [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md)&lt; real &gt; &gt; & value) <br> |
| virtual void | [**SetInitialValue**](#function-setinitialvalue-24) (const std::string & var, const [**ScalarFieldFp**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md) & values) <br> |
| virtual void | [**SetInitialValue**](#function-setinitialvalue-34) (const std::string & var, const [**VectorFieldFp**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md) & values) <br> |
| virtual void | [**SetInitialValue**](#function-setinitialvalue-44) (const std::string & var, const [**TensorFieldFp**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md) & values) <br> |
| virtual void | [**Solve**](#function-solve) () <br> |




























## Public Functions Documentation




### function AfterScheme 

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::AfterScheme () 
```






### function AfterSolve 

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::AfterSolve () 
```






### function BeforeScheme 

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::BeforeScheme () 
```






### function BeforeSolve 

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::BeforeSolve () 
```






### function GetLinearEqs 

```C++
inline std::optional< LinearEqs > OpenOasis::CommImp::Numeric::Solver::GetLinearEqs () const
```






### function GetScalarSolutions 

```C++
inline virtual std::optional< ScalarFieldFp > OpenOasis::CommImp::Numeric::Solver::GetScalarSolutions (
    const std::string & var
) const
```






### function GetTensorSolutions 

```C++
inline virtual std::optional< TensorFieldFp > OpenOasis::CommImp::Numeric::Solver::GetTensorSolutions (
    const std::string & var
) const
```






### function GetVectorSolutions 

```C++
inline virtual std::optional< VectorFieldFp > OpenOasis::CommImp::Numeric::Solver::GetVectorSolutions (
    const std::string & var
) const
```






### function ParseConvectionTerm 

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::ParseConvectionTerm () 
```






### function ParseDiffusionTerm 

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::ParseDiffusionTerm () 
```






### function ParseSourceTerm 

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::ParseSourceTerm () 
```






### function ParseTimeDerivativeTerm 

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::ParseTimeDerivativeTerm () 
```






### function Scheme 

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::Scheme () 
```






### function SetBoundary 

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::SetBoundary (
    int faceIndex,
    const std::shared_ptr< Boundary > & bound
) 
```






### function SetCoefficient [1/4]

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::SetCoefficient (
    const std::string & var,
    const std::variant< real, Vector < real >, Tensor < real > > & coeff
) 
```






### function SetCoefficient [2/4]

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::SetCoefficient (
    const std::string & var,
    const ScalarFieldFp & coeffs
) 
```






### function SetCoefficient [3/4]

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::SetCoefficient (
    const std::string & var,
    const VectorFieldFp & coeffs
) 
```






### function SetCoefficient [4/4]

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::SetCoefficient (
    const std::string & var,
    const TensorFieldFp & coeffs
) 
```






### function SetInitialValue [1/4]

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::SetInitialValue (
    const std::string & var,
    const std::variant< real, Vector < real >, Tensor < real > > & value
) 
```






### function SetInitialValue [2/4]

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::SetInitialValue (
    const std::string & var,
    const ScalarFieldFp & values
) 
```






### function SetInitialValue [3/4]

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::SetInitialValue (
    const std::string & var,
    const VectorFieldFp & values
) 
```






### function SetInitialValue [4/4]

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::SetInitialValue (
    const std::string & var,
    const TensorFieldFp & values
) 
```






### function Solve 

```C++
inline virtual void OpenOasis::CommImp::Numeric::Solver::Solve () 
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Numeric/Solver.h`

