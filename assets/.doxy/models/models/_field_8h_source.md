

# File Field.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Numeric**](dir_a0ece07902893bffce0f747cc8ee06c8.md) **>** [**Field.h**](_field_8h.md)

[Go to the documentation of this file](_field_8h.md)


```C++

#pragma once
#include "Models/Utils/CommMacros.h"
#include "Vector.h"
#include "Tensor.h"
#include <vector>
#include <algorithm>


namespace OpenOasis::CommImp::Numeric
{
enum class FieldType
{
    SCALAR,
    VECTOR,
    TENSOR,
    NONE,
};


enum class FieldDomain
{
    NODE,
    FACE,
    CELL,
    NONE,
};


template <typename T>
class Field
{
protected:
    FieldDomain    mDomain = FieldDomain::NONE;
    FieldType      mType   = FieldType::NONE;
    std::vector<T> mData;
    T              mDefault;

protected:
    virtual ~Field() = default;

    Field() = default;
    Field(std::size_t size, T value) : mData(size, value){};

public:
    // Methods for field manipulation.
    //

    void Initialize(T value)
    {
        std::fill(mData.begin(), mData.end(), value);
    }

    void Resize(std::size_t size)
    {
        mData.resize(size);
        mData.shrink_to_fit();
    }

    void Clean()
    {
        std::fill(mData.begin(), mData.end(), mDefault);
    }

    void Clear()
    {
        mData.clear();
    }

    template <typename Callback>
    void ForEach(Callback func)
    {
        for (auto &elem : mData)
        {
            func(elem);
        }
    }

    std::size_t Size() const
    {
        return mData.size();
    }

    void SetAt(std::size_t i, T value)
    {
        mData.at(i) = value;
    }

    void SetAt(
        std::size_t startIndex, std::size_t endIndex, const Field<T> &other,
        std::size_t offset = 0)
    {
        std::size_t j = offset;
        for (std::size_t i = startIndex; i < endIndex; ++i)
            mData.at(i) = other(j++);
    }

    const std::vector<T> &Data() const
    {
        return mData;
    }

    FieldType Type() const
    {
        return mType;
    }

    FieldDomain Range() const
    {
        return mDomain;
    }

    // Operators overrided for field manipulation.
    //

    const T &operator()(int i) const
    {
        return mData.at(i);
    }

    T &operator()(int i)
    {
        return mData.at(i);
    }

    void operator=(const Field<T> &other)
    {
        mData = other.mData;
    }

    void operator=(const T &value)
    {
        Initialize(value);
    }

    Field<T> operator+(const Field<T> &other) const
    {
        OO_ASSERT(other.Size() == Size());

        auto datas = mData;
        for (int i = 0; i < Size(); ++i)
        {
            datas[i] += other(i);
        }

        return datas;
    }

    void operator+=(const Field<T> &other)
    {
        OO_ASSERT(other.Size() == Size());

        for (int i = 0; i < Size(); ++i)
            mData[i] += other(i);
    }

    Field<T> operator-(const Field<T> &other) const
    {
        OO_ASSERT(other.Size() == Size());

        auto datas = mData;
        for (int i = 0; i < Size(); ++i)
        {
            datas[i] -= other(i);
        }

        return datas;
    }

    void operator-=(const Field<T> &other)
    {
        OO_ASSERT(other.Size() == Size());

        for (int i = 0; i < Size(); ++i)
            mData[i] -= other(i);
    }

    Field<T> operator*(double k) const
    {
        auto datas = mData;
        std::for_each(datas.begin(), datas.end(), [&k](auto &d) { d *= k; });

        return datas;
    }

    void operator*=(double k)
    {
        std::for_each(mData.begin(), mData.end(), [&k](auto &d) { d *= k; });
    }
};


template <typename T>
class ScalarField : public Field<T>
{
public:
    static_assert(
        std::is_arithmetic<T>::value,
        "ScalarField only can be instantiated with arithmetic types");

    virtual ~ScalarField() = default;

    ScalarField(std::size_t size, T val = 0, FieldDomain domain = FieldDomain::CELL) :
        Field<T>(size, val)
    {
        this->mDomain = domain;
        this->mType   = FieldType::SCALAR;
    }

    ScalarField(FieldDomain domain = FieldDomain::CELL)
    {
        this->mDomain = domain;
        this->mType   = FieldType::SCALAR;
    }
};


template <typename T, std::size_t N = 3>
class VectorField : public Field<Vector<T, N>>
{
public:
    virtual ~VectorField() = default;

    VectorField(FieldDomain domain = FieldDomain::CELL)
    {
        this->mDomain = domain;
        this->mType   = FieldType::VECTOR;
    }

    VectorField(
        std::size_t size, const Vector<T, N> &val = {},
        FieldDomain domain = FieldDomain::CELL) :
        Field<Vector<T, N>>(size, val)
    {
        this->mDomain = domain;
        this->mType   = FieldType::VECTOR;
    }
};


template <typename T>
class TensorField : public Field<Tensor<T>>
{
public:
    virtual ~TensorField() = default;

    TensorField(FieldDomain domain = FieldDomain::CELL)
    {
        this->mDomain = domain;
        this->mType   = FieldType::TENSOR;
    }

    TensorField(
        std::size_t size, const Tensor<T> &val = {},
        FieldDomain domain = FieldDomain::CELL) :
        Field<Tensor<T>>(size, val)
    {
        this->mDomain = domain;
        this->mType   = FieldType::TENSOR;
    }
};


// Commonly used fields.

using ScalarFieldFp = ScalarField<Utils::real>;
using VectorFieldFp = VectorField<Utils::real>;
using TensorFieldFp = TensorField<Utils::real>;

}  // namespace OpenOasis::CommImp::Numeric
```


