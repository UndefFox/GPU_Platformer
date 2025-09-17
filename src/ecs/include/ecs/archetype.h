#pragma once

#include <vector>
#include <utility>

#include "componentarray.h"
#include "tagtypes.h"
#include "ts/tag.h"

class ArcheType {
private:
    const Tag<TagType::Archetype> tag;
    std::vector<std::pair<const Tag<TagType::Component>, ComponentArray>> components;
    size_t length;

public:
    template <typename T>
    inline void registerComponent(const Tag<TagType::Component>& tag) {
        components.insert(std::pair{tag, ComponentArray::createInstance<T>(length)});
    };



    void resize(size_t newLength);
};
