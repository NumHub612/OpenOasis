

# File IBaseExchangeItem.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IBaseExchangeItem.h**](_i_base_exchange_item_8h.md)

[Go to the documentation of this file](_i_base_exchange_item_8h.md)


```C++

#pragma once
#include "IValueDefinition.h"
#include "IValueSet.h"
#include "IIdentifiable.h"
#include "ITimeSet.h"
#include "IElementSet.h"
#include "ExchangeItemChangeEventArgs.h"
#include <functional>


namespace OpenOasis
{
class ILinkableComponent;

class IBaseExchangeItem : public IIdentifiable
{
public:
    using ListenFunc =
        std::function<void(std::shared_ptr<ExchangeItemChangeEventArgs>)>;

public:
    virtual std::shared_ptr<IValueDefinition> GetValueDefinition() const = 0;

    virtual void Reset() = 0;

    virtual std::shared_ptr<IValueSet> GetValues() = 0;

    virtual std::shared_ptr<IElementSet> GetElementSet() const = 0;

    virtual void SetValues(std::shared_ptr<IValueSet> value) = 0;

    virtual std::shared_ptr<ITimeSet> GetTimeSet() const = 0;

    virtual void SetTimeSet(std::shared_ptr<ITimeSet> times) = 0;

    virtual void SetElementSet(std::shared_ptr<IElementSet> elements) = 0;

    virtual std::weak_ptr<ILinkableComponent> GetComponent() const = 0;

    virtual void AddListener(const ListenFunc &func) = 0;

    virtual void RemoveListener(const ListenFunc &func) = 0;
};

}  // namespace OpenOasis
```


