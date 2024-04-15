

# Class OpenOasis::LinkableComponentStatusChangeEventArgs



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**LinkableComponentStatusChangeEventArgs**](class_open_oasis_1_1_linkable_component_status_change_event_args.md)



_Class contains the information that will be passed when the_ `ILinkableComponent` _fires the_`StatusChanged` _event._

* `#include <LinkableComponentStatusChangeEventArgs.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual std::shared\_ptr&lt; [**ILinkableComponent**](class_open_oasis_1_1_i_linkable_component.md) &gt; | [**GetLinkableComponent**](#function-getlinkablecomponent) () const = 0<br> |
| virtual std::string | [**GetMessages**](#function-getmessages) () const = 0<br> |
| virtual [**LinkableComponentStatus**](namespace_open_oasis.md#enum-linkablecomponentstatus) | [**GetNewStatus**](#function-getnewstatus) () const = 0<br> |
| virtual [**LinkableComponentStatus**](namespace_open_oasis.md#enum-linkablecomponentstatus) | [**GetOldStatus**](#function-getoldstatus) () const = 0<br> |
| virtual void | [**SetLinkableComponent**](#function-setlinkablecomponent) (std::shared\_ptr&lt; [**ILinkableComponent**](class_open_oasis_1_1_i_linkable_component.md) &gt; obj) = 0<br> |
| virtual void | [**SetMessages**](#function-setmessages) (const std::string & msg) = 0<br> |
| virtual void | [**SetNewStatus**](#function-setnewstatus) ([**LinkableComponentStatus**](namespace_open_oasis.md#enum-linkablecomponentstatus) value) = 0<br> |
| virtual void | [**SetOldStatus**](#function-setoldstatus) ([**LinkableComponentStatus**](namespace_open_oasis.md#enum-linkablecomponentstatus) value) = 0<br> |




























## Public Functions Documentation




### function GetLinkableComponent 

```C++
virtual std::shared_ptr< ILinkableComponent > OpenOasis::LinkableComponentStatusChangeEventArgs::GetLinkableComponent () const = 0
```






### function GetMessages 

```C++
virtual std::string OpenOasis::LinkableComponentStatusChangeEventArgs::GetMessages () const = 0
```






### function GetNewStatus 

```C++
virtual LinkableComponentStatus OpenOasis::LinkableComponentStatusChangeEventArgs::GetNewStatus () const = 0
```






### function GetOldStatus 

```C++
virtual LinkableComponentStatus OpenOasis::LinkableComponentStatusChangeEventArgs::GetOldStatus () const = 0
```






### function SetLinkableComponent 

```C++
virtual void OpenOasis::LinkableComponentStatusChangeEventArgs::SetLinkableComponent (
    std::shared_ptr< ILinkableComponent > obj
) = 0
```






### function SetMessages 

```C++
virtual void OpenOasis::LinkableComponentStatusChangeEventArgs::SetMessages (
    const std::string & msg
) = 0
```






### function SetNewStatus 

```C++
virtual void OpenOasis::LinkableComponentStatusChangeEventArgs::SetNewStatus (
    LinkableComponentStatus value
) = 0
```






### function SetOldStatus 

```C++
virtual void OpenOasis::LinkableComponentStatusChangeEventArgs::SetOldStatus (
    LinkableComponentStatus value
) = 0
```




------------------------------
The documentation for this class was generated from the following file `Models/Inc/LinkableComponentStatusChangeEventArgs.h`

