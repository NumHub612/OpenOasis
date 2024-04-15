

# Class OpenOasis::ExchangeItemChangeEventArgs



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**ExchangeItemChangeEventArgs**](class_open_oasis_1_1_exchange_item_change_event_args.md)



_Class containing the information that will be passed when firing an_ `ExchangeItemValueChanged` _event._[More...](#detailed-description)

* `#include <ExchangeItemChangeEventArgs.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual std::shared\_ptr&lt; [**IBaseExchangeItem**](class_open_oasis_1_1_i_base_exchange_item.md) &gt; | [**GetExchangeItem**](#function-getexchangeitem) () const = 0<br> |
| virtual std::string | [**GetMessages**](#function-getmessages) () const = 0<br> |
| virtual void | [**SetExchangeItem**](#function-setexchangeitem) (std::shared\_ptr&lt; [**IBaseExchangeItem**](class_open_oasis_1_1_i_base_exchange_item.md) &gt; obj) = 0<br> |
| virtual void | [**SetMessages**](#function-setmessages) (const std::string & value) = 0<br> |




























# Detailed Description


Sending exchange item events is optional, so it should not be used as a mechanism to build critical functionality upon. 


    
## Public Functions Documentation




### function GetExchangeItem 

```C++
virtual std::shared_ptr< IBaseExchangeItem > OpenOasis::ExchangeItemChangeEventArgs::GetExchangeItem () const = 0
```






### function GetMessages 

```C++
virtual std::string OpenOasis::ExchangeItemChangeEventArgs::GetMessages () const = 0
```






### function SetExchangeItem 

```C++
virtual void OpenOasis::ExchangeItemChangeEventArgs::SetExchangeItem (
    std::shared_ptr< IBaseExchangeItem > obj
) = 0
```






### function SetMessages 

```C++
virtual void OpenOasis::ExchangeItemChangeEventArgs::SetMessages (
    const std::string & value
) = 0
```




------------------------------
The documentation for this class was generated from the following file `Models/Inc/ExchangeItemChangeEventArgs.h`

