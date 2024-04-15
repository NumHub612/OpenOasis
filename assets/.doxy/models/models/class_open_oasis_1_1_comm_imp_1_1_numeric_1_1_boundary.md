

# Class OpenOasis::CommImp::Numeric::Boundary



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Numeric**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md) **>** [**Boundary**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md)



_Abstract boundary class._ 

* `#include <Boundary.h>`





Inherited by the following classes: [OpenOasis::CommImp::Numeric::DirichletBoundary](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_dirichlet_boundary.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual [**BoundaryCondition**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary_condition.md) | [**GetBoundaryCondition**](#function-getboundarycondition) () = 0<br> |
| virtual std::string | [**GetType**](#function-gettype) () const = 0<br> |
| virtual void | [**SetBoundaryFlux**](#function-setboundaryflux) (real flux) = 0<br> |
| virtual void | [**SetBoundaryValue**](#function-setboundaryvalue) (real value) = 0<br> |




























## Public Functions Documentation




### function GetBoundaryCondition 

```C++
virtual BoundaryCondition OpenOasis::CommImp::Numeric::Boundary::GetBoundaryCondition () = 0
```






### function GetType 

```C++
virtual std::string OpenOasis::CommImp::Numeric::Boundary::GetType () const = 0
```






### function SetBoundaryFlux 

```C++
virtual void OpenOasis::CommImp::Numeric::Boundary::SetBoundaryFlux (
    real flux
) = 0
```






### function SetBoundaryValue 

```C++
virtual void OpenOasis::CommImp::Numeric::Boundary::SetBoundaryValue (
    real value
) = 0
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Numeric/Boundary.h`

