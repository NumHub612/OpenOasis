

# File ITime.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**ITime.h**](_i_time_8h.md)

[Go to the documentation of this file](_i_time_8h.md)


```C++

#pragma once


namespace OpenOasis
{
class ITime
{
public:
    virtual double GetTimeStamp() const = 0;

    virtual double GetDurationInDays() const = 0;
};

}  // namespace OpenOasis
```


