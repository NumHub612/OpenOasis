

# Class OpenOasis::CommImp::Numeric::Tensor

**template &lt;typename T&gt;**



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Numeric**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md) **>** [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|  T | [**AbsMax**](#function-absmax) () const<br>_Return the component of the tensor hasing the maximum absolute value._  |
|  T | [**AbsMin**](#function-absmin) () const<br>_Return the component of the tensor hasing the minimum absolute value._  |
|  void | [**Add**](#function-add-12) (T v) <br> |
|  void | [**Add**](#function-add-22) (const [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) & other) <br> |
|  T | [**Avg**](#function-avg) () const<br> |
|  T | [**DDot**](#function-ddot) (const [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) & other) const<br> |
|  void | [**Div**](#function-div) (T v) <br> |
|  [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; T, 3 &gt; | [**Dot**](#function-dot) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; T, 3 &gt; & other) const<br> |
|  bool | [**IsEqual**](#function-isequal) (const [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) & other) const<br> |
|  T | [**Length**](#function-length) () const<br>_Return the tensor's length(magnitude)._  |
|  T | [**Max**](#function-max) () const<br> |
|  T | [**Min**](#function-min) () const<br> |
|  void | [**Mul**](#function-mul) (T v) <br> |
|  void | [**Normalize**](#function-normalize) () <br> |
|  void | [**Set**](#function-set-12) (const [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) & other) <br> |
|  void | [**Set**](#function-set-22) (const std::initializer\_list&lt; U &gt; & lst) <br> |
|  void | [**SetAt**](#function-setat-14) (std::size\_t i, T v, Args... args) <br> |
|  void | [**SetAt**](#function-setat-24) (std::size\_t i, T v) <br> |
|  void | [**SetAt**](#function-setat-34) (std::size\_t i, std::size\_t j, T v) <br> |
|  void | [**SetAt**](#function-setat-44) (std::size\_t i, const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; T, 3 &gt; & vec) <br> |
|  constexpr std::size\_t | [**Size**](#function-size) () const<br> |
|  void | [**Sub**](#function-sub-12) (T v) <br> |
|  void | [**Sub**](#function-sub-22) (const [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) & other) <br> |
|  T | [**Sum**](#function-sum) () const<br> |
|   | [**Tensor**](#function-tensor-14) () <br> |
|   | [**Tensor**](#function-tensor-24) (const [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) & other) <br> |
|   | [**Tensor**](#function-tensor-34) (Args... args) <br> |
|   | [**Tensor**](#function-tensor-44) (const std::initializer\_list&lt; U &gt; & lst) <br> |
|  T & | [**operator()**](#function-operator()-12) (std::size\_t i, std::size\_t j) <br> |
|  const T & | [**operator()**](#function-operator()-22) (std::size\_t i, std::size\_t j) const<br> |
|  [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; T, 3 &gt; | [**operator\***](#function-operator) (const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; T, 3 &gt; & other) const<br> |
|  T | [**operator\***](#function-operator_1) (const [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) & other) const<br> |
|  [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) | [**operator+**](#function-operator_2) (const [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) & other) const<br> |
|  [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) | [**operator+**](#function-operator_3) (T v) const<br> |
|  [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) & | [**operator+=**](#function-operator_4) (const [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) & other) <br> |
|  [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) & | [**operator+=**](#function-operator_5) (T v) <br> |
|  [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) | [**operator-**](#function-operator_6) (const [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) & other) const<br> |
|  [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) | [**operator-**](#function-operator_7) (T v) const<br> |
|  [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) & | [**operator-=**](#function-operator_8) (const [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) & other) <br> |
|  [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) & | [**operator-=**](#function-operator_9) (T v) <br> |
|  void | [**operator=**](#function-operator_10) (const [**Tensor**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_tensor.md) & other) <br> |




























## Public Functions Documentation




### function AbsMax 

```C++
inline T OpenOasis::CommImp::Numeric::Tensor::AbsMax () const
```






### function AbsMin 

```C++
inline T OpenOasis::CommImp::Numeric::Tensor::AbsMin () const
```






### function Add [1/2]

```C++
inline void OpenOasis::CommImp::Numeric::Tensor::Add (
    T v
) 
```






### function Add [2/2]

```C++
inline void OpenOasis::CommImp::Numeric::Tensor::Add (
    const Tensor & other
) 
```






### function Avg 

```C++
inline T OpenOasis::CommImp::Numeric::Tensor::Avg () const
```






### function DDot 

```C++
inline T OpenOasis::CommImp::Numeric::Tensor::DDot (
    const Tensor & other
) const
```






### function Div 

```C++
inline void OpenOasis::CommImp::Numeric::Tensor::Div (
    T v
) 
```






### function Dot 

```C++
inline Vector < T, 3 > OpenOasis::CommImp::Numeric::Tensor::Dot (
    const Vector < T, 3 > & other
) const
```






### function IsEqual 

```C++
inline bool OpenOasis::CommImp::Numeric::Tensor::IsEqual (
    const Tensor & other
) const
```






### function Length 

```C++
inline T OpenOasis::CommImp::Numeric::Tensor::Length () const
```






### function Max 

```C++
inline T OpenOasis::CommImp::Numeric::Tensor::Max () const
```






### function Min 

```C++
inline T OpenOasis::CommImp::Numeric::Tensor::Min () const
```






### function Mul 

```C++
inline void OpenOasis::CommImp::Numeric::Tensor::Mul (
    T v
) 
```






### function Normalize 

```C++
inline void OpenOasis::CommImp::Numeric::Tensor::Normalize () 
```






### function Set [1/2]

```C++
inline void OpenOasis::CommImp::Numeric::Tensor::Set (
    const Tensor & other
) 
```






### function Set [2/2]

```C++
template<typename U>
inline void OpenOasis::CommImp::Numeric::Tensor::Set (
    const std::initializer_list< U > & lst
) 
```






### function SetAt [1/4]

```C++
template<typename... Args>
inline void OpenOasis::CommImp::Numeric::Tensor::SetAt (
    std::size_t i,
    T v,
    Args... args
) 
```






### function SetAt [2/4]

```C++
inline void OpenOasis::CommImp::Numeric::Tensor::SetAt (
    std::size_t i,
    T v
) 
```






### function SetAt [3/4]

```C++
inline void OpenOasis::CommImp::Numeric::Tensor::SetAt (
    std::size_t i,
    std::size_t j,
    T v
) 
```






### function SetAt [4/4]

```C++
inline void OpenOasis::CommImp::Numeric::Tensor::SetAt (
    std::size_t i,
    const Vector < T, 3 > & vec
) 
```






### function Size 

```C++
inline constexpr std::size_t OpenOasis::CommImp::Numeric::Tensor::Size () const
```






### function Sub [1/2]

```C++
inline void OpenOasis::CommImp::Numeric::Tensor::Sub (
    T v
) 
```






### function Sub [2/2]

```C++
inline void OpenOasis::CommImp::Numeric::Tensor::Sub (
    const Tensor & other
) 
```






### function Sum 

```C++
inline T OpenOasis::CommImp::Numeric::Tensor::Sum () const
```






### function Tensor [1/4]

```C++
inline OpenOasis::CommImp::Numeric::Tensor::Tensor () 
```






### function Tensor [2/4]

```C++
inline OpenOasis::CommImp::Numeric::Tensor::Tensor (
    const Tensor & other
) 
```






### function Tensor [3/4]

```C++
template<typename... Args>
inline OpenOasis::CommImp::Numeric::Tensor::Tensor (
    Args... args
) 
```






### function Tensor [4/4]

```C++
template<typename U>
inline OpenOasis::CommImp::Numeric::Tensor::Tensor (
    const std::initializer_list< U > & lst
) 
```






### function operator() [1/2]

```C++
inline T & OpenOasis::CommImp::Numeric::Tensor::operator() (
    std::size_t i,
    std::size_t j
) 
```






### function operator() [2/2]

```C++
inline const T & OpenOasis::CommImp::Numeric::Tensor::operator() (
    std::size_t i,
    std::size_t j
) const
```






### function operator\* 

```C++
inline Vector < T, 3 > OpenOasis::CommImp::Numeric::Tensor::operator* (
    const Vector < T, 3 > & other
) const
```






### function operator\* 

```C++
inline T OpenOasis::CommImp::Numeric::Tensor::operator* (
    const Tensor & other
) const
```






### function operator+ 

```C++
inline Tensor OpenOasis::CommImp::Numeric::Tensor::operator+ (
    const Tensor & other
) const
```






### function operator+ 

```C++
inline Tensor OpenOasis::CommImp::Numeric::Tensor::operator+ (
    T v
) const
```






### function operator+= 

```C++
inline Tensor & OpenOasis::CommImp::Numeric::Tensor::operator+= (
    const Tensor & other
) 
```






### function operator+= 

```C++
inline Tensor & OpenOasis::CommImp::Numeric::Tensor::operator+= (
    T v
) 
```






### function operator- 

```C++
inline Tensor OpenOasis::CommImp::Numeric::Tensor::operator- (
    const Tensor & other
) const
```






### function operator- 

```C++
inline Tensor OpenOasis::CommImp::Numeric::Tensor::operator- (
    T v
) const
```






### function operator-= 

```C++
inline Tensor & OpenOasis::CommImp::Numeric::Tensor::operator-= (
    const Tensor & other
) 
```






### function operator-= 

```C++
inline Tensor & OpenOasis::CommImp::Numeric::Tensor::operator-= (
    T v
) 
```






### function operator= 

```C++
inline void OpenOasis::CommImp::Numeric::Tensor::operator= (
    const Tensor & other
) 
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Numeric/Tensor.h`

