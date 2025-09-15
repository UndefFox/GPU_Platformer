#include "archetype.h"

void ArcheType::resize(size_t newLength)
{
    for (auto& c : components) {
        c.second.resize(newLength);
    }

    length = newLength;
}
