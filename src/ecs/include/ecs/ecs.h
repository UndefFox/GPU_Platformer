#pragma once

#include <vector>

#include "ts/tagsystem.h"
#include "ts/tag.h"
#include "tagtypes.h"
#include "archetype.h"


class ECS {
public:

private:
    TagSystem<TagType::Component> componentsTags;
    TagSystem<TagType::Archetype> archeTypesTags;
    TagSystem<TagType::System>    systemsTags;

    std::vector<ArcheType> archetypes;

public:
    template <class T>
    inline Tag<TagType::Component> registerComponent() { componentsTags.getId(T::getTagName()); }

    template <class T>
    inline Tag<TagType::Archetype> registerArcheType() { archeTypesTags.getId(T::getTagName()); }

    template <class T>
    inline Tag<TagType::System> registerSystem() { systemsTags.getId(T::getTagName()); }
};
