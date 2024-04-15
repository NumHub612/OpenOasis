

# File IElementSet.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IElementSet.h**](_i_element_set_8h.md)

[Go to the documentation of this file](_i_element_set_8h.md)


```C++

#pragma once
#include "ISpatialDefinition.h"
#include <vector>


namespace OpenOasis
{
enum class ElementType
{
    IdBased,    // Identifiable based
    Point,      // Points
    Polyline,   // Lines / Polylines
    Polygon,    // Polygons
    Polyhedron  // Polyhedrons
};


class IElementSet : public ISpatialDefinition
{
public:
    virtual ElementType GetElementType() const = 0;

    virtual int GetElementIndex(const std::string &elementId) = 0;

    virtual std::string GetElementId(int index) = 0;

    virtual int GetFaceCount(int elementIndex) = 0;

    virtual int GetNodeCount(int elementIndex) = 0;

    virtual std::vector<int> GetFaceNodeIndices(int elementIndex, int faceIndex) = 0;

    virtual double GetNodeXCoordinate(int elementIndex, int nodeIndex) = 0;

    virtual double GetNodeYCoordinate(int elementIndex, int nodeIndex) = 0;

    virtual double GetNodeZCoordinate(int elementIndex, int nodeIndex) = 0;
};

}  // namespace OpenOasis
```


