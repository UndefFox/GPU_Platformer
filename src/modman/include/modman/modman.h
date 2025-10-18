#pragma once

#include <string>

#include "module.h"
#include "graphs/directedacyclicgraph.hpp"



class ModuleManager {
private:
    DirectedAcyclicGraph<Module> modules;

public:
    ModuleManager() noexcept;
    ModuleManager(const std::string& modFolder);
    ModuleManager(ModuleManager&) = delete;

    ~ModuleManager() = default;

    ModuleManager& operator=(ModuleManager&) = delete;

    void reset() noexcept;
    void reset(const std::string& modFolder);

    void loadAll();
};
