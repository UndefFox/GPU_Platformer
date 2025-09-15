#pragma once

#include <string_view>
#include <string>

struct Tagabable {
    static inline constexpr std::string_view getTagName() {
        static const std::string tagName = "NULL";

        return std::string_view(tagName);
    }
};
