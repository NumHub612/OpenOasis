

# File LinkLoader.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**IO**](dir_3b1940e7bde9c1f91eabae8dc723b4f2.md) **>** [**LinkLoader.h**](_link_loader_8h.md)

[Go to the documentation of this file](_link_loader_8h.md)


```C++

#pragma once
#include "Models/Utils/JsonHandler.h"


namespace OpenOasis::CommImp::IO
{
using Utils::JsonLoader;

class LinkLoader
{
public:
    // Component information, contains:
    // - type
    // - task file path
    // - dll path
    using ComponentInfo = std::array<std::string, 3>;

    // Element(input/output) information, contains:
    // - id in component
    // - object type
    // - state
    // - temporal operator
    // - spatial operator
    using ElementInfo = std::array<std::string, 5>;

private:
    std::string mLinkFile;
    JsonLoader  mLoader;

    std::unordered_map<std::string, std::vector<std::string>> mOutputConsumers;
    std::unordered_map<std::string, std::vector<std::string>> mInputProviders;

    std::unordered_map<std::string, ComponentInfo>            mComps;
    std::unordered_map<std::string, std::vector<ElementInfo>> mInps;
    std::unordered_map<std::string, std::vector<ElementInfo>> mOuts;

    // Iterator groups, contains:
    // - iterator group id
    // - component ids
    std::unordered_map<std::string, std::vector<std::string>> mIterGroups;

    // Iterator configurations, contains:
    // - iterator group id
    // - iterator configurations
    std::unordered_map<std::string, std::multimap<std::string, std::string>>
        mIterConfigs;

public:
    LinkLoader(const std::string &json) : mLinkFile(json), mLoader(json)
    {}

    void Load();

    std::vector<std::string> GetComponentIds() const;

    ComponentInfo GetComponentInfo(const std::string &compId) const;

    std::vector<ElementInfo> GetComponentOutputs(const std::string &compId) const;

    std::unordered_map<std::string, std::vector<ElementInfo>>
    GetOutputConsumers(const std::string &compId, const ElementInfo &output) const;

    std::vector<ElementInfo> GetComponentInputs(const std::string &compId) const;

    std::unordered_map<std::string, std::vector<ElementInfo>>
    GetInputProviders(const std::string &compId, const ElementInfo &input) const;

    std::unordered_map<std::string, std::vector<std::string>> GetIteratorGroups() const;

    std::multimap<std::string, std::string>
    GetIteratorConfigs(const std::string &iterId) const;

private:
    void LoadComponents();
    void LoadLinks();
    void LoadPipeline(
        const std::string &linkId, const nlohmann::json &json, int index,
        std::unordered_map<std::string, std::vector<std::string>> &linkGroups);

    void CollectExchangeItemMap(
        const std::string &srcCompId, const ElementInfo &output,
        const std::string &tarCompId, const ElementInfo &input);

    void CollectIteratorGroups(
        const std::unordered_map<std::string, std::vector<std::string>> &linkGroups,
        const std::unordered_map<std::string, std::string>              &linkModes,
        const std::unordered_map<
            std::string, std::unordered_map<std::string, std::string>> &linkConfs);

    std::string GenerateUniqueElementId(
        const std::string &compId, const ElementInfo &element) const;

    std::vector<std::string> SplitUniqueElementId(const std::string &uniqueId) const;
};

}  // namespace OpenOasis::CommImp::IO
```


