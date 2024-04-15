

# File ExchangeItemChangeEventArgs.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**ExchangeItemChangeEventArgs.h**](_exchange_item_change_event_args_8h.md)

[Go to the documentation of this file](_exchange_item_change_event_args_8h.md)


```C++

#pragma once
#include <memory>
#include <string>


namespace OpenOasis
{
class IBaseExchangeItem;

class ExchangeItemChangeEventArgs
{
public:
    // To deal with the exchange item of which the status has been changed.
    //

    virtual std::shared_ptr<IBaseExchangeItem> GetExchangeItem() const = 0;

    virtual void SetExchangeItem(std::shared_ptr<IBaseExchangeItem> obj) = 0;

    // To deal with the message that describes the way in which the status
    // of the exchange item has been changed.
    //

    virtual std::string GetMessages() const = 0;

    virtual void SetMessages(const std::string &value) = 0;
};

}  // namespace OpenOasis
```


