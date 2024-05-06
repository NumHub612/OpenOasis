

# Class OpenOasis::CommImp::Numeric::FVM::DirichletBoundary



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Numeric**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md) **>** [**FVM**](namespace_open_oasis_1_1_comm_imp_1_1_numeric_1_1_f_v_m.md) **>** [**DirichletBoundary**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_f_v_m_1_1_dirichlet_boundary.md)



_Dirichlet boundary._ 

* `#include <DirichletBoundary.h>`



Inherits the following classes: [OpenOasis::CommImp::Numeric::Boundary](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DirichletBoundary**](#function-dirichletboundary-13) () <br> |
|   | [**DirichletBoundary**](#function-dirichletboundary-23) (real value) <br> |
|   | [**DirichletBoundary**](#function-dirichletboundary-33) (const [**DirichletBoundary**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_f_v_m_1_1_dirichlet_boundary.md) & other) <br> |
|  [**BoundaryCondition**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary_condition.md) | [**GetBoundaryCondition**](#function-getboundarycondition) () override<br> |
|  std::string | [**GetType**](#function-gettype) () override const<br> |
|  void | [**SetBoundaryFlux**](#function-setboundaryflux) (real flux) override<br> |
|  void | [**SetBoundaryValue**](#function-setboundaryvalue) (real value) override<br> |


## Public Functions inherited from OpenOasis::CommImp::Numeric::Boundary

See [OpenOasis::CommImp::Numeric::Boundary](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**AddBoundaryCondition**](#function-addboundarycondition) (double time, const [**BoundaryCondition**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary_condition.md) & bc) = 0<br> |
| virtual [**BoundaryCondition**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary_condition.md) | [**GetBoundaryCondition**](#function-getboundarycondition) (double time) = 0<br> |






















































## Public Functions Documentation




### function DirichletBoundary [1/3]

```C++
OpenOasis::CommImp::Numeric::FVM::DirichletBoundary::DirichletBoundary () 
```






### function DirichletBoundary [2/3]

```C++
OpenOasis::CommImp::Numeric::FVM::DirichletBoundary::DirichletBoundary (
    real value
) 
```






### function DirichletBoundary [3/3]

```C++
OpenOasis::CommImp::Numeric::FVM::DirichletBoundary::DirichletBoundary (
    const DirichletBoundary & other
) 
```






### function GetBoundaryCondition 

```C++
BoundaryCondition OpenOasis::CommImp::Numeric::FVM::DirichletBoundary::GetBoundaryCondition () override
```






### function GetType 

```C++
std::string OpenOasis::CommImp::Numeric::FVM::DirichletBoundary::GetType () override const
```






### function SetBoundaryFlux 

```C++
void OpenOasis::CommImp::Numeric::FVM::DirichletBoundary::SetBoundaryFlux (
    real flux
) override
```






### function SetBoundaryValue 

```C++
void OpenOasis::CommImp::Numeric::FVM::DirichletBoundary::SetBoundaryValue (
    real value
) override
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Numeric/FVM/DirichletBoundary.h`

