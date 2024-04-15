

# File IDimension.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IDimension.h**](_i_dimension_8h.md)

[Go to the documentation of this file](_i_dimension_8h.md)


```C++

#pragma once


namespace OpenOasis
{
enum class DimensionBase
{
    Length,             // Base dimension length.
    Mass,               // Base dimension mass.
    Time,               // Base dimension time.
    ElectricCurrent,    // Base dimension electric current.
    Temperature,        // Base dimension temperature.
    AmountOfSubstance,  // Base dimension amount of substance.
    LuminousIntensity,  // Base dimension luminous intensity.
    Currency            // Base dimension currency.
};


class IDimension
{
public:
    virtual double GetPower(DimensionBase baseQuantity) const = 0;

    virtual void SetPower(DimensionBase baseQuantity, double power) = 0;
};

}  // namespace OpenOasis
```


