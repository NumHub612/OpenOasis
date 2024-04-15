

# Class OpenOasis::AdditionalControl::IComparable



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**AdditionalControl**](namespace_open_oasis_1_1_additional_control.md) **>** [**IComparable**](class_open_oasis_1_1_additional_control_1_1_i_comparable.md)



_Interface class provides a unified interface for object comparison._ 

* `#include <IComparable.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual int | [**CompareTo**](#function-compareto) (const std::shared\_ptr&lt; [**IComparable**](class_open_oasis_1_1_additional_control_1_1_i_comparable.md) &gt; & obj) const = 0<br>_Compare the two comparable objections._  |




























## Public Functions Documentation




### function CompareTo 

_Compare the two comparable objections._ 
```C++
virtual int OpenOasis::AdditionalControl::IComparable::CompareTo (
    const std::shared_ptr< IComparable > & obj
) const = 0
```



if this &gt; obj, return +1; if this = obj, return 0; if this &lt; obj, return -1;




**Parameters:**


* `obj` A comparable object.



**Returns:**

The comparison result.




**Exception:**


* `If` the two objects were not comparable, an exception thrown. 




        

------------------------------
The documentation for this class was generated from the following file `Models/Inc/AdditionalControl/IComparable.h`

