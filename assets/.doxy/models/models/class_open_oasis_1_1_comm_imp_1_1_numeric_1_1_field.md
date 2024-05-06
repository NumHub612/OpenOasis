

# Class OpenOasis::CommImp::Numeric::Field

**template &lt;typename T&gt;**



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Numeric**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md) **>** [**Field**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md)



_The abstract field class used to represent numeric field, such as scalar, vector or tensor data._ 

* `#include <Field.h>`





Inherited by the following classes: [OpenOasis::CommImp::Numeric::ScalarField](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md),  [OpenOasis::CommImp::Numeric::ScalarField](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_scalar_field.md),  [OpenOasis::CommImp::Numeric::VectorField](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector_field.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**Clean**](#function-clean) () <br>_Cleans the field data to the default value._  |
|  void | [**Clear**](#function-clear) () <br>_Clears the field._  |
|  const std::vector&lt; T &gt; & | [**Data**](#function-data) () const<br>_Returns constant refrence to the field data._  |
|  void | [**ForEach**](#function-foreach) (Callback func) <br>_Iterates the field and invoke given_ `func` _for each element._ |
|  void | [**Initialize**](#function-initialize) (T value) <br>_Initializes the vector field with specified value._  |
|  [**FieldDomain**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md#enum-fielddomain) | [**Range**](#function-range) () const<br> |
|  void | [**Resize**](#function-resize) (std::size\_t size) <br>_Resizes the field._  |
|  void | [**SetAt**](#function-setat-12) (std::size\_t i, T value) <br>_Sets the field data._  |
|  void | [**SetAt**](#function-setat-22) (std::size\_t startIndex, std::size\_t endIndex, const [**Field**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_field.md)&lt; T &gt; & other, std::size\_t offset=0) <br>_Sets the field data from the specified range._  |
|  std::size\_t | [**Size**](#function-size) () const<br>_Returns the field size._  |
|  [**FieldType**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md#enum-fieldtype) | [**Type**](#function-type) () const<br> |
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








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  std::vector&lt; T &gt; | [**mData**](#variable-mdata)  <br> |
|  T | [**mDefault**](#variable-mdefault)  <br> |
|  [**FieldDomain**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md#enum-fielddomain) | [**mDomain**](#variable-mdomain)   = = FieldDomain::NONE<br> |
|  [**FieldType**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md#enum-fieldtype) | [**mType**](#variable-mtype)   = = FieldType::NONE<br> |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**Field**](#function-field-12) () = default<br> |
|   | [**Field**](#function-field-22) (std::size\_t size, T value) <br> |
| virtual  | [**~Field**](#function-field) () = default<br> |




## Public Functions Documentation




### function Clean 

```C++
inline void OpenOasis::CommImp::Numeric::Field::Clean () 
```






### function Clear 

```C++
inline void OpenOasis::CommImp::Numeric::Field::Clear () 
```






### function Data 

```C++
inline const std::vector< T > & OpenOasis::CommImp::Numeric::Field::Data () const
```






### function ForEach 

_Iterates the field and invoke given_ `func` _for each element._
```C++
template<typename Callback>
inline void OpenOasis::CommImp::Numeric::Field::ForEach (
    Callback func
) 
```



This function iterates the field elements and invoke the callback function `func`. The callback function takes field's element as its input. 


        



### function Initialize 

_Initializes the vector field with specified value._ 
```C++
inline void OpenOasis::CommImp::Numeric::Field::Initialize (
    T value
) 
```





**Parameters:**


* `value` The initial value. 




        



### function Range 

```C++
inline FieldDomain OpenOasis::CommImp::Numeric::Field::Range () const
```






### function Resize 

_Resizes the field._ 
```C++
inline void OpenOasis::CommImp::Numeric::Field::Resize (
    std::size_t size
) 
```





**Parameters:**


* `size` New size. 




        



### function SetAt [1/2]

```C++
inline void OpenOasis::CommImp::Numeric::Field::SetAt (
    std::size_t i,
    T value
) 
```






### function SetAt [2/2]

_Sets the field data from the specified range._ 
```C++
inline void OpenOasis::CommImp::Numeric::Field::SetAt (
    std::size_t startIndex,
    std::size_t endIndex,
    const Field < T > & other,
    std::size_t offset=0
) 
```





**Parameters:**


* `startIndex` Start index of the range. 
* `endIndex` End index of the range. 
* `other` Source field. 
* `offset` Index offset of the source field. 




        



### function Size 

```C++
inline std::size_t OpenOasis::CommImp::Numeric::Field::Size () const
```






### function Type 

```C++
inline FieldType OpenOasis::CommImp::Numeric::Field::Type () const
```






### function operator() [1/2]

```C++
inline const T & OpenOasis::CommImp::Numeric::Field::operator() (
    int i
) const
```






### function operator() [2/2]

```C++
inline T & OpenOasis::CommImp::Numeric::Field::operator() (
    int i
) 
```






### function operator\* 

```C++
inline Field < T > OpenOasis::CommImp::Numeric::Field::operator* (
    double k
) const
```






### function operator\*= 

```C++
inline void OpenOasis::CommImp::Numeric::Field::operator*= (
    double k
) 
```






### function operator+ 

```C++
inline Field < T > OpenOasis::CommImp::Numeric::Field::operator+ (
    const Field < T > & other
) const
```






### function operator+= 

```C++
inline void OpenOasis::CommImp::Numeric::Field::operator+= (
    const Field < T > & other
) 
```






### function operator- 

```C++
inline Field < T > OpenOasis::CommImp::Numeric::Field::operator- (
    const Field < T > & other
) const
```






### function operator-= 

```C++
inline void OpenOasis::CommImp::Numeric::Field::operator-= (
    const Field < T > & other
) 
```






### function operator= 

```C++
inline void OpenOasis::CommImp::Numeric::Field::operator= (
    const Field < T > & other
) 
```






### function operator= 

```C++
inline void OpenOasis::CommImp::Numeric::Field::operator= (
    const T & value
) 
```



## Protected Attributes Documentation




### variable mData 

```C++
std::vector<T> OpenOasis::CommImp::Numeric::Field< T >::mData;
```






### variable mDefault 

```C++
T OpenOasis::CommImp::Numeric::Field< T >::mDefault;
```






### variable mDomain 

```C++
FieldDomain OpenOasis::CommImp::Numeric::Field< T >::mDomain;
```






### variable mType 

```C++
FieldType OpenOasis::CommImp::Numeric::Field< T >::mType;
```



## Protected Functions Documentation




### function Field [1/2]

```C++
OpenOasis::CommImp::Numeric::Field::Field () = default
```






### function Field [2/2]

```C++
inline OpenOasis::CommImp::Numeric::Field::Field (
    std::size_t size,
    T value
) 
```






### function ~Field 

```C++
virtual OpenOasis::CommImp::Numeric::Field::~Field () = default
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Numeric/Field.h`

