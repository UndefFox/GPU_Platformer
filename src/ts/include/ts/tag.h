#pragma once

#include <limits>

typedef unsigned int tagId;

template <int T>
struct Tag {
    const tagId id;

    Tag() : id(std::numeric_limits<tagId>::max()) {};
    Tag(tagId id) : id(id) {};

    inline bool operator==(const Tag& tag) const {
        return id == tag.id;
    }
};
