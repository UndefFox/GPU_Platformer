#pragma once

#include <vector>
#include <utility>

#include "ts/tag.h"
#include "executionrestraints.h"
#include "archetype.h"
#include "componentarray.h"



typedef Tag SystemTag;

class System {
public:
    const std::vector<std::pair<ExecutionRestraintType, const ExecutionRestraint<ExecutionRestraintType::None> *const>> restrains;
    const std::vector<ComponentArrayTag> processedComponents;

public:
    void (*preExecute)();
    void (*iteration)(const ArcheType& archetype);
    void (*postExecute)();
};
