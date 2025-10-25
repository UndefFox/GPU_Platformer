#pragma once

#include <string_view>
#include <string>
#include <vector>
#include <optional>



struct FONEntry {
public:
    std::string name;
    std::string value;
    std::vector<FONEntry> children;

public:
    void clear();
    std::optional<FONEntry*> getEntryByName(std::string_view name);
    std::optional<const FONEntry*> getEntryByName(std::string_view name) const;

    bool loadParamIfExits(std::string& value, const std::string_view name) const;
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
