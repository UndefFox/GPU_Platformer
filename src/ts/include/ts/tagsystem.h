#pragma once

#include <map>
#include <string_view>

#include "tag.h"



class TagSystem {
public:

private:
    tagId lastId;
    std::map<const std::string_view, const Tag> registeredTags;


public:
    TagSystem() : registeredTags(){};

    const Tag getId(const std::string_view& name) {
        auto tagItter = registeredTags.find(name);

        if (tagItter == registeredTags.end()) {
            const Tag newTag(lastId++);

            registeredTags.insert(std::pair{name, newTag});

            return newTag;
        }

        return tagItter->second;
    }
};
