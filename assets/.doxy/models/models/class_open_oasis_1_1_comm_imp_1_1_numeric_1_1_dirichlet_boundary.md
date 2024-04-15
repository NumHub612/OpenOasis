

# Class OpenOasis::CommImp::Numeric::DirichletBoundary



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Numeric**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md) **>** [**DirichletBoundary**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_dirichlet_boundary.md)



_Dirichlet boundary._ 

* `#include <DirichletBoundary.h>`



Inherits the following classes: [OpenOasis::CommImp::Numeric::Boundary](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DirichletBoundary**](#function-dirichletboundary-13) () <br> |
|   | [**DirichletBoundary**](#function-dirichletboundary-23) (real value) <br> |
|   | [**DirichletBoundary**](#function-dirichletboundary-33) (const [**DirichletBoundary**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_dirichlet_boundary.md) & other) <br> |
| virtual [**BoundaryCondition**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary_condition.md) | [**GetBoundaryCondition**](#function-getboundarycondition) () override<br> |
| virtual std::string | [**GetType**](#function-gettype) () override const<br> |
| virtual void | [**SetBoundaryFlux**](#function-setboundaryflux) (real flux) override<br> |
| virtual void | [**SetBoundaryValue**](#function-setboundaryvalue) (real value) override<br> |


## Public Functions inherited from OpenOasis::CommImp::Numeric::Boundary

See [OpenOasis::CommImp::Numeric::Boundary](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md)

| Type | Name |
| ---: | :--- |
| virtual [**BoundaryCondition**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary_condition.md) | [**GetBoundaryCondition**](#function-getboundarycondition) () = 0<br> |
| virtual std::string | [**GetType**](#function-gettype) () const = 0<br> |
| virtual void | [**SetBoundaryFlux**](#function-setboundaryflux) (real flux) = 0<br> |
| virtual void | [**SetBoundaryValue**](#function-setboundaryvalue) (real value) = 0<br> |






















































## Public Functions Documentation




### function DirichletBoundary [1/3]

```C++
OpenOasis::CommImp::Numeric::DirichletBoundary::DirichletBoundary () 
```






### function DirichletBoundary [2/3]

```C++
OpenOasis::CommImp::Numeric::DirichletBoundary::DirichletBoundary (
    real value
) 
```






### function DirichletBoundary [3/3]

```C++
OpenOasis::CommImp::Numeric::DirichletBoundary::DirichletBoundary (
    const DirichletBoundary & other
) 
```






### function GetBoundaryCondition 

```C++
virtual BoundaryCondition OpenOasis::CommImp::Numeric::DirichletBoundary::GetBoundaryCondition () override
```



Implements [*OpenOasis::CommImp::Numeric::Boundary::GetBoundaryCondition*](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md#function-getboundarycondition)




### function GetType 

```C++
virtual std::string OpenOasis::CommImp::Numeric::DirichletBoundary::GetType () override const
```



Implements [*OpenOasis::CommImp::Numeric::Boundary::GetType*](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md#function-gettype)




### function SetBoundaryFlux 

```C++
virtual void OpenOasis::CommImp::Numeric::DirichletBoundary::SetBoundaryFlux (
    real flux
) override
```



Implements [*OpenOasis::CommImp::Numeric::Boundary::SetBoundaryFlux*](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md#function-setboundaryflux)




### function SetBoundaryValue 

```C++
virtual void OpenOasis::CommImp::Numeric::DirichletBoundary::SetBoundaryValue (
    real value
) override
```



Implements [*OpenOasis::CommImp::Numeric::Boundary::SetBoundaryValue*](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_boundary.md#function-setboundaryvalue)


------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Numeric/DirichletBoundary.h`

