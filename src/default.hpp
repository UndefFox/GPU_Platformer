#pragma once

#include <filesystem>

#include "core/core.h"
#include "parsers/fon.h"



void run() {
    FONEntry parametrs = []() -> FONEntry {
        if (auto a = FONParser::readFromFile("./save.fon")) {
            return *a;
        }
        else {
            return {};
        }
    }();

    Core core(parametrs);

    parametrs.clear();
    core.serialize(parametrs);

    FONParser::saveToFile(parametrs, "./save.fon");
}
