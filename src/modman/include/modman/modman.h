#pragma once

#include <string_view>

#include "module.h"
#include "graphs/directedacyclicgraph.hpp"



class ModuleManager {
private:
    DirectedAcyclicGraph<Module> modules;

public:
    ModuleManager() noexcept;
    ModuleManager(const std::string_view modFolder);
    ModuleManager(ModuleManager&) = delete;

    ~ModuleManager() = default;

    ModuleManager& operator=(ModuleManager&) = delete;

    void reset() noexcept;
    void reset(const std::string_view modFolder);

    void loadAll();
};
