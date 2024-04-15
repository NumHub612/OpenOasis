

# Class OpenOasis::CommImp::Numeric::Vector

**template &lt;typename T, size\_t N&gt;**



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Numeric**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md) **>** [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|  T | [**AbsMax**](#function-absmax) () const<br>_Return the component of the vector hasing the maximum absolute value._  |
|  T | [**AbsMin**](#function-absmin) () const<br>_Return the component of the vector hasing the minimum absolute value._  |
|  void | [**Add**](#function-add-12) (T v) <br> |
|  void | [**Add**](#function-add-22) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) <br> |
|  T | [**Avg**](#function-avg) () const<br> |
|  [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) | [**Cross**](#function-cross) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) const<br> |
|  void | [**Div**](#function-div) (T v) <br> |
|  T | [**Dot**](#function-dot) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) const<br> |
|  [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md)&lt; T &gt; | [**Dyadic**](#function-dyadic) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) const<br> |
|  bool | [**IsEqual**](#function-isequal) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) const<br> |
|  T | [**Length**](#function-length) () const<br>_Return the vector's length(magnitude)._  |
|  T | [**Max**](#function-max) () const<br> |
|  T | [**Min**](#function-min) () const<br> |
|  void | [**Mul**](#function-mul) (T v) <br> |
|  void | [**Normalize**](#function-normalize) () <br> |
|  void | [**Set**](#function-set-12) (const std::initializer\_list&lt; U &gt; & lst) <br> |
|  void | [**Set**](#function-set-22) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) <br> |
|  void | [**SetAt**](#function-setat-12) (size\_t i, T v, Args... args) <br> |
|  void | [**SetAt**](#function-setat-22) (size\_t i, T v) <br> |
|  constexpr size\_t | [**Size**](#function-size) () const<br> |
|  void | [**Sub**](#function-sub-12) (T v) <br> |
|  void | [**Sub**](#function-sub-22) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) <br> |
|  T | [**Sum**](#function-sum) () const<br> |
|   | [**Vector**](#function-vector-15) () <br> |
|   | [**Vector**](#function-vector-25) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) <br> |
|   | [**Vector**](#function-vector-35) (const std::array&lt; T, N &gt; & other) <br> |
|   | [**Vector**](#function-vector-45) (Args... args) <br> |
|   | [**Vector**](#function-vector-55) (const std::initializer\_list&lt; U &gt; & lst) <br> |
|  bool | [**operator!=**](#function-operator) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) const<br> |
|  [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) | [**operator&**](#function-operator_1) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) const<br>_Override_ `&` _operator for cross product._ |
|  [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & | [**operator&=**](#function-operator_2) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) <br> |
|  T & | [**operator()**](#function-operator()-12) (size\_t i) <br> |
|  const T & | [**operator()**](#function-operator()-22) (size\_t i) const<br> |
|  [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) | [**operator\***](#function-operator_3) (T v) const<br>_Override_ `*` _operator for vector multiplication._ |
|  T | [**operator\***](#function-operator_4) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) const<br>_Override_ `*` _operator for dot product._ |
|  [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & | [**operator\*=**](#function-operator_5) (T v) <br> |
|  [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) | [**operator+**](#function-operator_6) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) const<br> |
|  [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) | [**operator+**](#function-operator_7) (T v) const<br> |
|  [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & | [**operator+=**](#function-operator_8) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) <br> |
|  [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & | [**operator+=**](#function-operator_9) (T v) <br> |
|  [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) | [**operator-**](#function-operator_10) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) const<br> |
|  [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) | [**operator-**](#function-operator_11) (T v) const<br> |
|  [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & | [**operator-=**](#function-operator_12) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) <br> |
|  [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & | [**operator-=**](#function-operator_13) (T v) <br> |
|  void | [**operator=**](#function-operator_14) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) <br> |
|  bool | [**operator==**](#function-operator_15) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) const<br> |
|  [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md)&lt; T &gt; | [**operator^**](#function-operator_16) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md) & other) const<br>_Override_ `^` _operator for dyadic product._ |
| virtual  | [**~Vector**](#function-vector) () = default<br> |




























## Public Functions Documentation




### function AbsMax 

```C++
inline T OpenOasis::CommImp::Numeric::Vector::AbsMax () const
```






### function AbsMin 

```C++
inline T OpenOasis::CommImp::Numeric::Vector::AbsMin () const
```






### function Add [1/2]

```C++
inline void OpenOasis::CommImp::Numeric::Vector::Add (
    T v
) 
```






### function Add [2/2]

```C++
inline void OpenOasis::CommImp::Numeric::Vector::Add (
    const Vector & other
) 
```






### function Avg 

```C++
inline T OpenOasis::CommImp::Numeric::Vector::Avg () const
```






### function Cross 

```C++
inline Vector OpenOasis::CommImp::Numeric::Vector::Cross (
    const Vector & other
) const
```






### function Div 

```C++
inline void OpenOasis::CommImp::Numeric::Vector::Div (
    T v
) 
```






### function Dot 

```C++
inline T OpenOasis::CommImp::Numeric::Vector::Dot (
    const Vector & other
) const
```






### function Dyadic 

```C++
inline Tensor < T > OpenOasis::CommImp::Numeric::Vector::Dyadic (
    const Vector & other
) const
```






### function IsEqual 

```C++
inline bool OpenOasis::CommImp::Numeric::Vector::IsEqual (
    const Vector & other
) const
```






### function Length 

```C++
inline T OpenOasis::CommImp::Numeric::Vector::Length () const
```






### function Max 

```C++
inline T OpenOasis::CommImp::Numeric::Vector::Max () const
```






### function Min 

```C++
inline T OpenOasis::CommImp::Numeric::Vector::Min () const
```






### function Mul 

```C++
inline void OpenOasis::CommImp::Numeric::Vector::Mul (
    T v
) 
```






### function Normalize 

```C++
inline void OpenOasis::CommImp::Numeric::Vector::Normalize () 
```






### function Set [1/2]

```C++
template<typename U>
inline void OpenOasis::CommImp::Numeric::Vector::Set (
    const std::initializer_list< U > & lst
) 
```






### function Set [2/2]

```C++
inline void OpenOasis::CommImp::Numeric::Vector::Set (
    const Vector & other
) 
```






### function SetAt [1/2]

```C++
template<typename... Args>
inline void OpenOasis::CommImp::Numeric::Vector::SetAt (
    size_t i,
    T v,
    Args... args
) 
```






### function SetAt [2/2]

```C++
inline void OpenOasis::CommImp::Numeric::Vector::SetAt (
    size_t i,
    T v
) 
```






### function Size 

```C++
inline constexpr size_t OpenOasis::CommImp::Numeric::Vector::Size () const
```






### function Sub [1/2]

```C++
inline void OpenOasis::CommImp::Numeric::Vector::Sub (
    T v
) 
```






### function Sub [2/2]

```C++
inline void OpenOasis::CommImp::Numeric::Vector::Sub (
    const Vector & other
) 
```






### function Sum 

```C++
inline T OpenOasis::CommImp::Numeric::Vector::Sum () const
```






### function Vector [1/5]

```C++
inline OpenOasis::CommImp::Numeric::Vector::Vector () 
```






### function Vector [2/5]

```C++
inline OpenOasis::CommImp::Numeric::Vector::Vector (
    const Vector & other
) 
```






### function Vector [3/5]

```C++
inline OpenOasis::CommImp::Numeric::Vector::Vector (
    const std::array< T, N > & other
) 
```






### function Vector [4/5]

```C++
template<typename... Args>
inline OpenOasis::CommImp::Numeric::Vector::Vector (
    Args... args
) 
```






### function Vector [5/5]

```C++
template<typename U>
inline OpenOasis::CommImp::Numeric::Vector::Vector (
    const std::initializer_list< U > & lst
) 
```






### function operator!= 

```C++
inline bool OpenOasis::CommImp::Numeric::Vector::operator!= (
    const Vector & other
) const
```






### function operator& 

```C++
inline Vector OpenOasis::CommImp::Numeric::Vector::operator& (
    const Vector & other
) const
```






### function operator&= 

```C++
inline Vector & OpenOasis::CommImp::Numeric::Vector::operator&= (
    const Vector & other
) 
```






### function operator() [1/2]

```C++
inline T & OpenOasis::CommImp::Numeric::Vector::operator() (
    size_t i
) 
```






### function operator() [2/2]

```C++
inline const T & OpenOasis::CommImp::Numeric::Vector::operator() (
    size_t i
) const
```






### function operator\* 

```C++
inline Vector OpenOasis::CommImp::Numeric::Vector::operator* (
    T v
) const
```






### function operator\* 

```C++
inline T OpenOasis::CommImp::Numeric::Vector::operator* (
    const Vector & other
) const
```






### function operator\*= 

```C++
inline Vector & OpenOasis::CommImp::Numeric::Vector::operator*= (
    T v
) 
```






### function operator+ 

```C++
inline Vector OpenOasis::CommImp::Numeric::Vector::operator+ (
    const Vector & other
) const
```






### function operator+ 

```C++
inline Vector OpenOasis::CommImp::Numeric::Vector::operator+ (
    T v
) const
```






### function operator+= 

```C++
inline Vector & OpenOasis::CommImp::Numeric::Vector::operator+= (
    const Vector & other
) 
```






### function operator+= 

```C++
inline Vector & OpenOasis::CommImp::Numeric::Vector::operator+= (
    T v
) 
```






### function operator- 

```C++
inline Vector OpenOasis::CommImp::Numeric::Vector::operator- (
    const Vector & other
) const
```






### function operator- 

```C++
inline Vector OpenOasis::CommImp::Numeric::Vector::operator- (
    T v
) const
```






### function operator-= 

```C++
inline Vector & OpenOasis::CommImp::Numeric::Vector::operator-= (
    const Vector & other
) 
```






### function operator-= 

```C++
inline Vector & OpenOasis::CommImp::Numeric::Vector::operator-= (
    T v
) 
```






### function operator= 

```C++
inline void OpenOasis::CommImp::Numeric::Vector::operator= (
    const Vector & other
) 
```






### function operator== 

```C++
inline bool OpenOasis::CommImp::Numeric::Vector::operator== (
    const Vector & other
) const
```






### function operator^ 

```C++
inline Tensor < T > OpenOasis::CommImp::Numeric::Vector::operator^ (
    const Vector & other
) const
```






### function ~Vector 

```C++
virtual OpenOasis::CommImp::Numeric::Vector::~Vector () = default
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Numeric/Vector.h`

