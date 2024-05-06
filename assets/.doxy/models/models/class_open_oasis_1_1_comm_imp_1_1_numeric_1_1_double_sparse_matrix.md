

# Class OpenOasis::CommImp::Numeric::DoubleSparseMatrix



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Numeric**](namespace_open_oasis_1_1_comm_imp_1_1_numeric.md) **>** [**DoubleSparseMatrix**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_double_sparse_matrix.md)



_Sparse matrix having double elements._ 

* `#include <Matrix.h>`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**EqualFunc**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_double_sparse_matrix_1_1_equal_func.md) <br> |
| struct | [**HashFunc**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_double_sparse_matrix_1_1_hash_func.md) <br> |
| class | [**Index**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_double_sparse_matrix_1_1_index.md) <br> |






## Public Attributes

| Type | Name |
| ---: | :--- |
|  std::unordered\_map&lt; [**Index**](class_open_oasis_1_1_comm_imp_1_1_numeric_1_1_double_sparse_matrix_1_1_index.md), Utils::real, [**HashFunc**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_double_sparse_matrix_1_1_hash_func.md), [**EqualFunc**](struct_open_oasis_1_1_comm_imp_1_1_numeric_1_1_double_sparse_matrix_1_1_equal_func.md) &gt; | [**mValues**](#variable-mvalues)  <br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  Utils::real | [**At**](#function-at) (int row, int column) <br> |
|   | [**DoubleSparseMatrix**](#function-doublesparsematrix) (int rowCount, int columnCount) <br> |
|  int | [**GetColumnCount**](#function-getcolumncount) () const<br> |
|  int | [**GetRowCount**](#function-getrowcount) () const<br> |
|  bool | [**IsCellEmpty**](#function-iscellempty) (int row, int column) <br> |
|  std::vector&lt; Utils::real &gt; | [**Product**](#function-product-12) (const std::vector&lt; Utils::real &gt; & vector2) <br> |
|  void | [**Product**](#function-product-22) (std::vector&lt; Utils::real &gt; & res, const std::vector&lt; Utils::real &gt; & vector2) <br> |
|  void | [**SetColumnCount**](#function-setcolumncount) (int value) <br> |
|  void | [**SetRowCount**](#function-setrowcount) (int value) <br> |
|  void | [**SetValue**](#function-setvalue) (int row, int column, Utils::real value) <br> |
|  Utils::real | [**operator()**](#function-operator()) (int row, int column) <br> |




























## Public Attributes Documentation




### variable mValues 

```C++
std::unordered_map<Index, Utils::real, HashFunc, EqualFunc> OpenOasis::CommImp::Numeric::DoubleSparseMatrix::mValues;
```



## Public Functions Documentation




### function At 

```C++
inline Utils::real OpenOasis::CommImp::Numeric::DoubleSparseMatrix::At (
    int row,
    int column
) 
```






### function DoubleSparseMatrix 

```C++
inline OpenOasis::CommImp::Numeric::DoubleSparseMatrix::DoubleSparseMatrix (
    int rowCount,
    int columnCount
) 
```






### function GetColumnCount 

```C++
inline int OpenOasis::CommImp::Numeric::DoubleSparseMatrix::GetColumnCount () const
```






### function GetRowCount 

```C++
inline int OpenOasis::CommImp::Numeric::DoubleSparseMatrix::GetRowCount () const
```






### function IsCellEmpty 

```C++
inline bool OpenOasis::CommImp::Numeric::DoubleSparseMatrix::IsCellEmpty (
    int row,
    int column
) 
```






### function Product [1/2]

```C++
inline std::vector< Utils::real > OpenOasis::CommImp::Numeric::DoubleSparseMatrix::Product (
    const std::vector< Utils::real > & vector2
) 
```






### function Product [2/2]

```C++
inline void OpenOasis::CommImp::Numeric::DoubleSparseMatrix::Product (
    std::vector< Utils::real > & res,
    const std::vector< Utils::real > & vector2
) 
```






### function SetColumnCount 

```C++
inline void OpenOasis::CommImp::Numeric::DoubleSparseMatrix::SetColumnCount (
    int value
) 
```






### function SetRowCount 

```C++
inline void OpenOasis::CommImp::Numeric::DoubleSparseMatrix::SetRowCount (
    int value
) 
```






### function SetValue 

```C++
inline void OpenOasis::CommImp::Numeric::DoubleSparseMatrix::SetValue (
    int row,
    int column,
    Utils::real value
) 
```






### function operator() 

```C++
inline Utils::real OpenOasis::CommImp::Numeric::DoubleSparseMatrix::operator() (
    int row,
    int column
) 
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Numeric/Matrix.h`

