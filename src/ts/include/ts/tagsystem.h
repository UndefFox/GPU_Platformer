#pragma once

#include <map>
#include <string_view>

#include "tag.h"

template <int T>
class TagSystem {
public:

private:
    tagId lastId;
    std::map<const std::string_view, const Tag<T>> registeredTags;


public:
    TagSystem() : registeredTags(0) {};

    const Tag<T> getId(const std::string_view& name) {
        auto tagItter = registeredTags.find(name);

        if (tagItter == registeredTags.end()) {
            const Tag<T> newTag(lastId++);

            registeredTags.insert(std::pair{name, newTag});

            return newTag;
        }

        return tagItter.right;
    }
};
