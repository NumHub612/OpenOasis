

# Class OpenOasis::CommImp::Numeric::Matrix

**template &lt;typename T&gt;**



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Numeric**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md) **>** [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**Add**](#function-add-12) (std::size\_t i, std::size\_t j, const T & s) <br>_Add input scalar_ `s` _to specified element._ |
|  void | [**Add**](#function-add-22) (const [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & m) <br>_Adds input matrix_ `m` _(element-wise)._ |
|  [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) | [**Adjoint**](#function-adjoint) () const<br>_Returns adjoint matrix._  |
|  size\_t | [**Cols**](#function-cols) () const<br> |
|  Eigen::SparseMatrix&lt; T &gt; & | [**Data**](#function-data-12) () <br> |
|  const Eigen::SparseMatrix&lt; T &gt; & | [**Data**](#function-data-22) () const<br> |
|  T | [**Determinant**](#function-determinant) () const<br>_Returns the determinant of this matrix._  |
|  [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; T, N &gt; | [**Diagonal**](#function-diagonal) () const<br>_Returns diagonal vector of this matrix._  |
|  [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) | [**Invert**](#function-invert) () const<br>_Returns inverse matrix._  |
|   | [**Matrix**](#function-matrix-15) (int rows, int cols) <br> |
|   | [**Matrix**](#function-matrix-25) (int size) <br> |
|   | [**Matrix**](#function-matrix-35) (const [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & other) <br> |
|   | [**Matrix**](#function-matrix-45) (const std::initializer\_list&lt; std::initializer\_list&lt; T &gt; &gt; & lst) <br> |
|   | [**Matrix**](#function-matrix-55) (const Eigen::SparseMatrix&lt; T &gt; & mat) <br> |
|  T | [**Max**](#function-max) () const<br> |
|  T | [**Min**](#function-min) () const<br> |
|  void | [**Mul**](#function-mul-12) (const T & s) <br>_Multiplies scalar_ `s` _to the whole matrix._ |
|  [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) | [**Mul**](#function-mul-22) (const [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & m) const<br>_Returns this matrix \* input matrix_ `m` _._ |
|  size\_t | [**Rows**](#function-rows) () const<br> |
|  void | [**Set**](#function-set-12) (const [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & other) <br> |
|  void | [**Set**](#function-set-22) (const std::initializer\_list&lt; std::initializer\_list&lt; T &gt; &gt; & lst) <br> |
|  void | [**SetAt**](#function-setat) (size\_t i, size\_t j, const T & val) <br> |
|  void | [**SetCol**](#function-setcol) (size\_t j, const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; T, N &gt; & vec) <br> |
|  void | [**SetDiagonal**](#function-setdiagonal) (const T & s) <br> |
|  void | [**SetRow**](#function-setrow) (size\_t i, const [**Vector**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_vector.md)&lt; T, N &gt; & vec) <br> |
|  void | [**SetUnit**](#function-setunit) () <br> |
|  void | [**SetZero**](#function-setzero) () <br> |
|  void | [**Sub**](#function-sub-12) (std::size\_t i, std::size\_t j, const T & s) <br>_Subtracts scalar_ `s` _to specified element._ |
|  void | [**Sub**](#function-sub-22) (const [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & m) <br>_Subtracts input matrix_ `m` _(element-wise)._ |
|  T | [**Sum**](#function-sum) () const<br> |
|  T | [**Trace**](#function-trace) () const<br>_Returns the trace of this matrix._  |
|  [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) | [**Transpose**](#function-transpose) () const<br>_Returns transpose matrix._  |
|  T & | [**operator()**](#function-operator()-12) (size\_t i, size\_t j) <br> |
|  const T & | [**operator()**](#function-operator()-22) (size\_t i, size\_t j) const<br> |
|  [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) | [**operator\***](#function-operator) (const [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & m) const<br> |
|  [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) | [**operator\***](#function-operator_1) (const T & s) const<br> |
|  [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & | [**operator\*=**](#function-operator_2) (const T & s) <br> |
|  [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & | [**operator\*=**](#function-operator_3) (const [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & m) <br> |
|  [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) | [**operator+**](#function-operator_4) (const [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & m) const<br> |
|  [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & | [**operator+=**](#function-operator_5) (const [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & m) <br> |
|  [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) | [**operator-**](#function-operator_6) (const [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & m) const<br> |
|  [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & | [**operator-=**](#function-operator_7) (const [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & m) <br> |
|  [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & | [**operator=**](#function-operator_8) (const [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) & other) <br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) | [**Unit**](#function-unit) (int rows, int cols) <br>_Makes a sparse matrix with all diagonal elements to 1, and other elements to 0._  |
|  [**Matrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_matrix.md) | [**Zero**](#function-zero) (int rows, int cols) <br>_Makes a sparse matrix with zeros._  |


























## Public Functions Documentation




### function Add [1/2]

```C++
inline void OpenOasis::CommImp::Numeric::Matrix::Add (
    std::size_t i,
    std::size_t j,
    const T & s
) 
```






### function Add [2/2]

```C++
inline void OpenOasis::CommImp::Numeric::Matrix::Add (
    const Matrix & m
) 
```






### function Adjoint 

```C++
inline Matrix OpenOasis::CommImp::Numeric::Matrix::Adjoint () const
```






### function Cols 

```C++
inline size_t OpenOasis::CommImp::Numeric::Matrix::Cols () const
```






### function Data [1/2]

```C++
inline Eigen::SparseMatrix< T > & OpenOasis::CommImp::Numeric::Matrix::Data () 
```






### function Data [2/2]

```C++
inline const Eigen::SparseMatrix< T > & OpenOasis::CommImp::Numeric::Matrix::Data () const
```






### function Determinant 

_Returns the determinant of this matrix._ 
```C++
inline T OpenOasis::CommImp::Numeric::Matrix::Determinant () const
```





**Warning:**

Should be a square matrix. 





        



### function Diagonal 

_Returns diagonal vector of this matrix._ 
```C++
template<std::size_t N>
inline Vector < T, N > OpenOasis::CommImp::Numeric::Matrix::Diagonal () const
```





**Warning:**

Should be a square matrix. 





        



### function Invert 

```C++
inline Matrix OpenOasis::CommImp::Numeric::Matrix::Invert () const
```






### function Matrix [1/5]

```C++
inline OpenOasis::CommImp::Numeric::Matrix::Matrix (
    int rows,
    int cols
) 
```






### function Matrix [2/5]

```C++
inline OpenOasis::CommImp::Numeric::Matrix::Matrix (
    int size
) 
```






### function Matrix [3/5]

```C++
inline OpenOasis::CommImp::Numeric::Matrix::Matrix (
    const Matrix & other
) 
```






### function Matrix [4/5]

```C++
inline OpenOasis::CommImp::Numeric::Matrix::Matrix (
    const std::initializer_list< std::initializer_list< T > > & lst
) 
```






### function Matrix [5/5]

```C++
inline OpenOasis::CommImp::Numeric::Matrix::Matrix (
    const Eigen::SparseMatrix< T > & mat
) 
```






### function Max 

```C++
inline T OpenOasis::CommImp::Numeric::Matrix::Max () const
```






### function Min 

```C++
inline T OpenOasis::CommImp::Numeric::Matrix::Min () const
```






### function Mul [1/2]

```C++
inline void OpenOasis::CommImp::Numeric::Matrix::Mul (
    const T & s
) 
```






### function Mul [2/2]

```C++
inline Matrix OpenOasis::CommImp::Numeric::Matrix::Mul (
    const Matrix & m
) const
```






### function Rows 

```C++
inline size_t OpenOasis::CommImp::Numeric::Matrix::Rows () const
```






### function Set [1/2]

```C++
inline void OpenOasis::CommImp::Numeric::Matrix::Set (
    const Matrix & other
) 
```






### function Set [2/2]

```C++
inline void OpenOasis::CommImp::Numeric::Matrix::Set (
    const std::initializer_list< std::initializer_list< T > > & lst
) 
```






### function SetAt 

```C++
inline void OpenOasis::CommImp::Numeric::Matrix::SetAt (
    size_t i,
    size_t j,
    const T & val
) 
```






### function SetCol 

```C++
template<size_t N>
inline void OpenOasis::CommImp::Numeric::Matrix::SetCol (
    size_t j,
    const Vector < T, N > & vec
) 
```






### function SetDiagonal 

```C++
inline void OpenOasis::CommImp::Numeric::Matrix::SetDiagonal (
    const T & s
) 
```






### function SetRow 

```C++
template<size_t N>
inline void OpenOasis::CommImp::Numeric::Matrix::SetRow (
    size_t i,
    const Vector < T, N > & vec
) 
```






### function SetUnit 

```C++
inline void OpenOasis::CommImp::Numeric::Matrix::SetUnit () 
```






### function SetZero 

```C++
inline void OpenOasis::CommImp::Numeric::Matrix::SetZero () 
```






### function Sub [1/2]

```C++
inline void OpenOasis::CommImp::Numeric::Matrix::Sub (
    std::size_t i,
    std::size_t j,
    const T & s
) 
```






### function Sub [2/2]

```C++
inline void OpenOasis::CommImp::Numeric::Matrix::Sub (
    const Matrix & m
) 
```






### function Sum 

```C++
inline T OpenOasis::CommImp::Numeric::Matrix::Sum () const
```






### function Trace 

_Returns the trace of this matrix._ 
```C++
inline T OpenOasis::CommImp::Numeric::Matrix::Trace () const
```





**Warning:**

Should be a square matrix. 





        



### function Transpose 

```C++
inline Matrix OpenOasis::CommImp::Numeric::Matrix::Transpose () const
```






### function operator() [1/2]

```C++
inline T & OpenOasis::CommImp::Numeric::Matrix::operator() (
    size_t i,
    size_t j
) 
```






### function operator() [2/2]

```C++
inline const T & OpenOasis::CommImp::Numeric::Matrix::operator() (
    size_t i,
    size_t j
) const
```






### function operator\* 

```C++
inline Matrix OpenOasis::CommImp::Numeric::Matrix::operator* (
    const Matrix & m
) const
```






### function operator\* 

```C++
inline Matrix OpenOasis::CommImp::Numeric::Matrix::operator* (
    const T & s
) const
```






### function operator\*= 

```C++
inline Matrix & OpenOasis::CommImp::Numeric::Matrix::operator*= (
    const T & s
) 
```






### function operator\*= 

```C++
inline Matrix & OpenOasis::CommImp::Numeric::Matrix::operator*= (
    const Matrix & m
) 
```






### function operator+ 

```C++
inline Matrix OpenOasis::CommImp::Numeric::Matrix::operator+ (
    const Matrix & m
) const
```






### function operator+= 

```C++
inline Matrix & OpenOasis::CommImp::Numeric::Matrix::operator+= (
    const Matrix & m
) 
```






### function operator- 

```C++
inline Matrix OpenOasis::CommImp::Numeric::Matrix::operator- (
    const Matrix & m
) const
```






### function operator-= 

```C++
inline Matrix & OpenOasis::CommImp::Numeric::Matrix::operator-= (
    const Matrix & m
) 
```






### function operator= 

```C++
inline Matrix & OpenOasis::CommImp::Numeric::Matrix::operator= (
    const Matrix & other
) 
```



## Public Static Functions Documentation




### function Unit 

```C++
static inline Matrix OpenOasis::CommImp::Numeric::Matrix::Unit (
    int rows,
    int cols
) 
```






### function Zero 

```C++
static inline Matrix OpenOasis::CommImp::Numeric::Matrix::Zero (
    int rows,
    int cols
) 
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Numeric/Matrix.h`

