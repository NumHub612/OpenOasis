

# Class OpenOasis::CommImp::Numeric::FVM::FvmSolver



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Numeric**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md) **>** [**FVM**](namespace_open_oasis_1_1_comm_imp_1_1_numeric_1_1_f_v_m.md) **>** [**FvmSolver**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_f_v_m_1_1_fvm_solver.md)








Inherits the following classes: [OpenOasis::CommImp::Numeric::Solver](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_solver.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**FvmSolver**](#function-fvmsolver) (const std::shared\_ptr&lt; [**Grid**](class_open_oasis_1_1_comm_imp_1_1_spatial_1_1_grid.md) &gt; & grid) <br> |
| virtual std::optional&lt; [**ScalarFieldFp**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md) &gt; | [**GetScalarSolutions**](#function-getscalarsolutions) (const std::string & var) override const<br> |
|  void | [**ParseDiffusionTerm**](#function-parsediffusionterm) () override<br> |
| virtual void | [**SetBoundary**](#function-setboundary) (int faceIndex, const std::shared\_ptr&lt; [**Boundary**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md) &gt; & bound) override<br> |
| virtual void | [**SetCoefficient**](#function-setcoefficient) (const std::string & var, const std::variant&lt; real, [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; real &gt;, [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md)&lt; real &gt; &gt; & coeff) override<br> |
| virtual void | [**SetInitialValue**](#function-setinitialvalue) (const std::string & var, const std::variant&lt; real, [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; real &gt;, [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md)&lt; real &gt; &gt; & value) override<br> |
| virtual void | [**Solve**](#function-solve) () override<br> |
|   | [**~FvmSolver**](#function-fvmsolver) () = default<br> |


## Public Functions inherited from OpenOasis::CommImp::Numeric::Solver

See [OpenOasis::CommImp::Numeric::Solver](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_solver.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**AfterScheme**](#function-afterscheme) () <br> |
| virtual void | [**AfterSolve**](#function-aftersolve) () <br> |
| virtual void | [**BeforeScheme**](#function-beforescheme) () <br> |
| virtual void | [**BeforeSolve**](#function-beforesolve) () <br> |
| virtual void | [**DiscretizeEquation**](#function-discretizeequation) () <br> |
|  std::optional&lt; [**LinearEqs**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md#typedef-lineareqs) &gt; | [**GetLinearEqs**](#function-getlineareqs) () const<br> |
| virtual std::optional&lt; [**ScalarFieldFp**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md) &gt; | [**GetScalarSolutions**](#function-getscalarsolutions) (const std::string & var) const<br> |
| virtual std::optional&lt; [**TensorFieldFp**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md) &gt; | [**GetTensorSolutions**](#function-gettensorsolutions) (const std::string & var) const<br> |
| virtual std::optional&lt; [**VectorFieldFp**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md) &gt; | [**GetVectorSolutions**](#function-getvectorsolutions) (const std::string & var) const<br> |
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




### function FvmSolver 

```C++
OpenOasis::CommImp::Numeric::FVM::FvmSolver::FvmSolver (
    const std::shared_ptr< Grid > & grid
) 
```






### function GetScalarSolutions 

```C++
virtual std::optional< ScalarFieldFp > OpenOasis::CommImp::Numeric::FVM::FvmSolver::GetScalarSolutions (
    const std::string & var
) override const
```



Implements [*OpenOasis::CommImp::Numeric::Solver::GetScalarSolutions*](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_solver.md#function-getscalarsolutions)




### function ParseDiffusionTerm 

```C++
void OpenOasis::CommImp::Numeric::FVM::FvmSolver::ParseDiffusionTerm () override
```






### function SetBoundary 

```C++
virtual void OpenOasis::CommImp::Numeric::FVM::FvmSolver::SetBoundary (
    int faceIndex,
    const std::shared_ptr< Boundary > & bound
) override
```



Implements [*OpenOasis::CommImp::Numeric::Solver::SetBoundary*](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_solver.md#function-setboundary)




### function SetCoefficient 

```C++
virtual void OpenOasis::CommImp::Numeric::FVM::FvmSolver::SetCoefficient (
    const std::string & var,
    const std::variant< real, Vector < real >, Tensor < real > > & coeff
) override
```



Implements [*OpenOasis::CommImp::Numeric::Solver::SetCoefficient*](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_solver.md#function-setcoefficient-14)




### function SetInitialValue 

```C++
virtual void OpenOasis::CommImp::Numeric::FVM::FvmSolver::SetInitialValue (
    const std::string & var,
    const std::variant< real, Vector < real >, Tensor < real > > & value
) override
```



Implements [*OpenOasis::CommImp::Numeric::Solver::SetInitialValue*](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_solver.md#function-setinitialvalue-14)




### function Solve 

```C++
virtual void OpenOasis::CommImp::Numeric::FVM::FvmSolver::Solve () override
```



Implements [*OpenOasis::CommImp::Numeric::Solver::Solve*](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_solver.md#function-solve)




### function ~FvmSolver 

```C++
OpenOasis::CommImp::Numeric::FVM::FvmSolver::~FvmSolver () = default
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Numeric/FVM/FvmSolver.h`

