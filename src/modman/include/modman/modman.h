#pragma once

#include <vector>
#include <string_view>

#include "module.h"



class ModuleManager {
private:
    std::vector<Module> modules;

public:
    void loadModule(const std::string_view& path);
};
