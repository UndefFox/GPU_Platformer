#pragma once

#include <vector>
#include <utility>

#include "ts/tag.h"
#include "tagtypes.h"
#include "executionrestraints.h"
#include "archetype.h"


class System {
public:
    const Tag<TagType::System> tag;
    const std::vector<std::pair<ExecutionRestraintType, const ExecutionRestraint<ExecutionRestraintType::None> *const>> restrains;
    const std::vector<Tag<TagType::Component>> processedComponents;

public:
    void (*preExecute)();
    void (*iteration)(const ArcheType& archetype);
    void (*postExecute)();
};
