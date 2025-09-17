#include "archetype.h"



void ArcheType::registerComponent(const ComponentArrayTag &tag, size_t length, size_t cSize, size_t cAligment)
{
    components.push_back(std::pair<const ComponentArrayTag, ComponentArray>{tag, ComponentArray(length, cSize, cAligment)});
}

void ArcheType::resize(size_t newLength)
{
    for (auto& c : components) {
        c.second.resize(newLength);
    }

    length = newLength;
}
