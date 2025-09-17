#pragma once

#include <vector>
#include <utility>

#include "componentarray.h"
#include "ts/tag.h"



typedef Tag ArcheTypeTag;

class ArcheType {
private:
    const ArcheTypeTag tag;
    std::vector<std::pair<const ComponentArrayTag, ComponentArray>> components;
    size_t length;

public:
    void registerComponent(const ComponentArrayTag& tag, size_t length, size_t cSize, size_t cAligment);

    void resize(size_t newLength);
};
