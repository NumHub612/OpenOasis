

# Class OpenOasis::CommImp::Numeric::TensorField

**template &lt;typename T&gt;**



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Numeric**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md) **>** [**TensorField**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor_field.md)



[_**Tensor**_](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) _field._

* `#include <TensorField.h>`



Inherits the following classes: [OpenOasis::CommImp::Numeric::Field](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**TensorField**](#function-tensorfield-12) (FieldDomain domain=FieldDomain::CELL) <br> |
|   | [**TensorField**](#function-tensorfield-22) (std::size\_t size, const [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md)&lt; T &gt; & val={}, FieldDomain domain=FieldDomain::CELL) <br> |
| virtual  | [**~TensorField**](#function-tensorfield) () = default<br> |


## Public Functions inherited from OpenOasis::CommImp::Numeric::Field

See [OpenOasis::CommImp::Numeric::Field](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md)

| Type | Name |
| ---: | :--- |
|  void | [**Clean**](#function-clean) () <br>_Cleans the field data to the default value._  |
|  void | [**Clear**](#function-clear) () <br>_Clears the field._  |
|  const std::vector&lt; T &gt; & | [**Data**](#function-data) () const<br>_Returns constant refrence to the field data._  |
|  void | [**ForEach**](#function-foreach) (Callback func) <br>_Iterates the field and invoke given_ `func` _for each element._ |
|  void | [**Initialize**](#function-initialize) (T value) <br>_Initializes the vector field with specified value._  |
|  FieldDomain | [**Range**](#function-range) () const<br> |
|  void | [**Resize**](#function-resize) (std::size\_t size) <br>_Resizes the field._  |
|  void | [**SetAt**](#function-setat-12) (std::size\_t i, T value) <br>_Sets the field data._  |
|  void | [**SetAt**](#function-setat-22) (std::size\_t startIndex, std::size\_t endIndex, const [**Field**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md)&lt; T &gt; & other, std::size\_t offset=0) <br>_Sets the field data from the specified range._  |
|  std::size\_t | [**Size**](#function-size) () const<br>_Returns the field size._  |
|  FieldType | [**Type**](#function-type) () const<br> |
|  const T & | [**operator()**](#function-operator()-12) (int i) const<br> |
|  T & | [**operator()**](#function-operator()-22) (int i) <br> |
|  [**Field**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md)&lt; T &gt; | [**operator\***](#function-operator) (double k) const<br> |
|  void | [**operator\*=**](#function-operator_1) (double k) <br> |
|  [**Field**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md)&lt; T &gt; | [**operator+**](#function-operator_2) (const [**Field**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md)&lt; T &gt; & other) const<br> |
|  void | [**operator+=**](#function-operator_3) (const [**Field**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md)&lt; T &gt; & other) <br> |
|  [**Field**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md)&lt; T &gt; | [**operator-**](#function-operator_4) (const [**Field**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md)&lt; T &gt; & other) const<br> |
|  void | [**operator-=**](#function-operator_5) (const [**Field**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md)&lt; T &gt; & other) <br> |
|  void | [**operator=**](#function-operator_6) (const [**Field**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md)&lt; T &gt; & other) <br> |
|  void | [**operator=**](#function-operator_7) (const T & value) <br> |
















## Protected Attributes inherited from OpenOasis::CommImp::Numeric::Field

See [OpenOasis::CommImp::Numeric::Field](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md)

| Type | Name |
| ---: | :--- |
|  std::vector&lt; T &gt; | [**mData**](#variable-mdata)  <br> |
|  T | [**mDefault**](#variable-mdefault)  <br> |
|  FieldDomain | [**mDomain**](#variable-mdomain)   = = FieldDomain::NONE<br> |
|  FieldType | [**mType**](#variable-mtype)   = = FieldType::NONE<br> |
































## Protected Functions inherited from OpenOasis::CommImp::Numeric::Field

See [OpenOasis::CommImp::Numeric::Field](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md)

| Type | Name |
| ---: | :--- |
|   | [**Field**](#function-field-12) () = default<br> |
|   | [**Field**](#function-field-22) (std::size\_t size, T value) <br> |
| virtual  | [**~Field**](#function-field) () = default<br> |






## Public Functions Documentation




### function TensorField [1/2]

```C++
inline OpenOasis::CommImp::Numeric::TensorField::TensorField (
    FieldDomain domain=FieldDomain::CELL
) 
```






### function TensorField [2/2]

```C++
inline OpenOasis::CommImp::Numeric::TensorField::TensorField (
    std::size_t size,
    const Tensor < T > & val={},
    FieldDomain domain=FieldDomain::CELL
) 
```






### function ~TensorField 

```C++
virtual OpenOasis::CommImp::Numeric::TensorField::~TensorField () = default
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Numeric/TensorField.h`

