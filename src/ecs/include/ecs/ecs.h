#pragma once

#include <vector>
#include <utility>

#include "ts/tagsystem.h"
#include "ts/tag.h"
#include "archetype.h"
#include "system.h"



class ECS {
public:

private:
    TagSystem componentsTS;
    TagSystem archeTypesTS;
    TagSystem systemsTS;

    std::vector<std::pair<ArcheTypeTag, ArcheType>> archetypes;
    std::vector<std::pair<SystemTag, System>> systems;

public:
    template <class T>
    inline Tag registerComponent() { componentsTS.getId(T::getTagName()); }

    template <class T>
    inline Tag registerArcheType() { archeTypesTS.getId(T::getTagName()); }

    template <class T>
    inline Tag registerSystem() { systemsTS.getId(T::getTagName()); }
};
