#include "fon.h"

#include <fstream>
#include <stack>
#include <utility>



std::optional<FONEntry> FONParser::readFromFile(const std::string_view path)
{
    FONEntry root;

    std::ifstream file((std::string)path);

    if (!file.is_open()) return {};

    std::stack<FONEntry*> nesting;
    nesting.push(&root);

    try {
        std::string line;
        std::getline(file, line);

        if (line[0] == '-') return {};

        while (line.size()) {
            size_t nest = 0;
            while (true) {
                if (line.at(nest) == '-') nest++;
                else break;
            }

            std::string name;
            std::string value{};

            auto f = line.find(' ', 0);
            auto s = line.find(' ', f + 1);

            if (f == std::string::npos) return {};
            else name = line.substr(f + 1, s - f - 1);

            if (s != std::string::npos) value = line.substr(s + 1);


            if (nesting.size() - 1 == nest - 1) {
                nesting.push(&nesting.top()->children.back());
            }
            else if (nesting.size() - 1 > nest) {
                const size_t s = nesting.size();
                for (size_t i = 0; i < s - 1 - nest; i++) nesting.pop();
            }
            else if (nesting.size() - 1 != nest) {
                return {};
            }

            nesting.top()->children.push_back({
                .name = name,
                .value = value,
                .children = {}
            });

            std::getline(file, line);
        }
    }
    catch (...) {
        return {};
    }


    return root;
}

void FONParser::saveToFile(const FONEntry& root, const std::string_view path)
{
    std::ofstream file((std::string)path);

    if (root.children.size() == 0) return;

    std::stack<std::pair<std::span<const FONEntry>, size_t>> nesting;
    nesting.push(std::make_pair(std::span{root.children}, 0));
    while (true) {
        auto& [currentSpan, currentPos] = nesting.top();

        if (currentSpan.size() <= currentPos) {
            nesting.pop();

            if (nesting.empty()) return;

            nesting.top().second += 1;
            continue;
        }

        const auto& currentElement = currentSpan[currentPos];

        for (size_t i = 0; i < nesting.size() - 1; i++) file << '-';
        file << ' ' << currentElement.name << ' ' << currentElement.value << '\n';
        file.flush();

        if (currentElement.children.size() != 0) {
            nesting.push({currentElement.children, 0});
        }
        else {
            currentPos += 1;
        }
    }
}

void FONEntry::clear()
{
    name = "";
    value = "";
    children.clear();
    children.shrink_to_fit();
}

std::optional<FONEntry*> FONEntry::getEntryByName(std::string_view name)
{
    if (auto result = std::ranges::find_if(children, [&name](FONEntry i) { return i.name == name; }); result != children.end()) {
        return &(*result);
    }
    else {
        return {};
    }
}
std::optional<const FONEntry*> FONEntry::getEntryByName(std::string_view name) const
{
    if (auto result = std::ranges::find_if(children, [&name](FONEntry i) { return i.name == name; });
        result != children.end()) {
        return &(*result);
    }
    else {
        return {};
    }
}

bool FONEntry::loadParamIfExits(std::string& value, const std::string_view name) const
{
    if (auto result = getEntryByName(name))
        value = (*result)->value;
    else
        return false;

    return true;
}
