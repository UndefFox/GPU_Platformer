#pragma once

#include <string_view>
#include <string>
#include <vector>
#include <optional>



struct FONEntry {
    std::string name;
    std::string value;
    std::vector<FONEntry> children;
};

/** @brief .fon file parser.
 *
 *  FON file format:
 *    - each line represents one value
 *    - line format:
 *      1. '-' * the level of nesting
 *      2. mandatorry space, even when no nesting is pressent
 *      3. value name
 *      4. value after one space
 *    - order of values is preserved
 *    - line can be valueless, nameless or both
 *
 *    Example1:
 *    root
 *    | testValue
 *    |- child1 12
 *    |- child2 even long text
 *    | antoherValue X
 *    |- child3
 *    |-- child31
 *    |
 *    |
 */
namespace FONParser {

std::optional<FONEntry> readFromFile(const std::string_view path);
void saveToFile(const FONEntry& fon, const std::string_view path);

}
