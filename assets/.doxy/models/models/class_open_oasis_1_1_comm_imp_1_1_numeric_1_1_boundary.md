

# Class OpenOasis::CommImp::Numeric::Boundary



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Numeric**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md) **>** [**Boundary**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md)



_Abstract boundary class._ 

* `#include <Boundary.h>`





Inherited by the following classes: [OpenOasis::CommImp::Numeric::FVM::DirichletBoundary](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_f_v_m_1_1_dirichlet_boundary.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**AddBoundaryCondition**](#function-addboundarycondition) (double time, const [**BoundaryCondition**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary_condition.md) & bc) = 0<br> |
| virtual [**BoundaryCondition**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary_condition.md) | [**GetBoundaryCondition**](#function-getboundarycondition) (double time) = 0<br> |




























## Public Functions Documentation




### function AddBoundaryCondition 

```C++
virtual void OpenOasis::CommImp::Numeric::Boundary::AddBoundaryCondition (
    double time,
    const BoundaryCondition & bc
) = 0
```






### function GetBoundaryCondition 

```C++
virtual BoundaryCondition OpenOasis::CommImp::Numeric::Boundary::GetBoundaryCondition (
    double time
) = 0
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Numeric/Boundary.h`

