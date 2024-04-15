

# File TimeBuffer.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Temporal**](dir_ffb56fa5fbb3b89fb2d1e87d90c0c2f7.md) **>** [**TimeBuffer.h**](_time_buffer_8h.md)

[Go to the documentation of this file](_time_buffer_8h.md)


```C++

#pragma once
#include "Models/CommImp/TimeSet.h"
#include "Models/CommImp/ValueSet2D.h"


namespace OpenOasis
{
namespace CommImp
{
namespace Temporal
{
using Utils::real;

class TimeBuffer
{
protected:
    bool mDoExtrapolate = true;

    std::shared_ptr<ValueSet2D> mValues = nullptr;

    std::shared_ptr<TimeSet> mTimes = nullptr;

    real mRelaxationFactor = 0;

    int mLastBufferSizeMessageCounter = 0;

    bool mDoExtendedDataVerification = false;

public:
    virtual ~TimeBuffer()
    {}

    TimeBuffer();
    TimeBuffer(const TimeBuffer &TimeBuffer);

    // Methods for getting and setting the buffer extrapolation flag.
    //
    // Default is true. If false and a requested time is outside the available spans,
    // an exception is thrown.

    void SetDoExtrapolate(bool value);

    bool GetDoExtrapolate() const;

    void AddValues(const std::shared_ptr<ITime> &time, const std::vector<real> &values);

    // Methods for getting and setting the relaxation factor(must be in [0, 1]).
    //
    // Relaxation parameter is used when doing extrapolation.
    // A value of 1 results in nearest extrapolation whereas
    // a value 0 results in linear extrapolation.

    std::vector<real> GetValues(const std::shared_ptr<ITime> &requestedTime);

    void SetRelaxationFactor(real value);

    real GetRelaxationFactor() const;

    std::shared_ptr<ITime> GetTimeAt(int timeStep) const;

    std::vector<real> GetValuesAt(int timeStep) const;

    std::shared_ptr<TimeSet> GetTimeSet() const;

    std::shared_ptr<ValueSet2D> GetValueSet() const;

    // Methods for getting and setting the data extension flag.
    //

    bool GetDoExtendedDataVerification() const;

    void SetDoExtendedDataVerification(bool value);

    void CheckBuffer() const;

    void ClearBefore(std::shared_ptr<ITime> time);

    void ClearAfter(std::shared_ptr<ITime> time);

    void Reset();

    std::vector<std::vector<real>> GetAllValues();

    void SetOrAddValues(std::shared_ptr<ITime> time, std::vector<real> values);

    int GetTimesCount() const;

    int GetValuesCount() const;

protected:
    void AddValuesToBuffer(
        const std::shared_ptr<ITime> &time, const std::vector<real> &values);

    void Create();

    std::vector<real>
    MapFromTimeStampsToTimeSpan(const std::shared_ptr<ITime> &requestedTime);

    std::vector<real>
    MapFromTimeSpansToTimeStamp(const std::shared_ptr<ITime> &requestedTimeStamp);

    std::vector<real>
    MapFromTimeSpansToTimeSpan(const std::shared_ptr<ITime> &requestedTime);

    std::vector<real>
    MapFromTimeStampsToTimeStamp(const std::shared_ptr<ITime> &requestedTimeStamp);
};

}  // namespace Temporal
}  // namespace CommImp
}  // namespace OpenOasis
```


