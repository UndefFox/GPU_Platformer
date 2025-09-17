#pragma once

#include <vector>
#include <utility>

#include "ts/tagsystem.h"
#include "ts/tag.h"
#include "tagtypes.h"
#include "archetype.h"


class ECS {
public:

private:
    TagSystem<TagType::Component> componentsTS;
    TagSystem<TagType::Archetype> archeTypesTS;
    TagSystem<TagType::System>    systemsTS;

    std::vector<std::pair<Tag<TagType::Archetype>, ArcheType>> archetypes;


public:
    template <class T>
    inline Tag<TagType::Component> registerComponent() { componentsTS.getId(T::getTagName()); }

    template <class T>
    inline Tag<TagType::Archetype> registerArcheType() { archeTypesTS.getId(T::getTagName()); }

    template <class T>
    inline Tag<TagType::System> registerSystem() { systemsTS.getId(T::getTagName()); }
};
