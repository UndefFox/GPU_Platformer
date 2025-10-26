#pragma once

#include <string_view>

#include "module.h"
#include "graphs/directedacyclicgraph.hpp"
#include "parsers/fon.h"



class ModuleManager {
private:
    DirectedAcyclicGraph<Module> modules;
    std::string modFolder;

public:
    ModuleManager() noexcept;
    ModuleManager(const FONEntry& object);
    ModuleManager(ModuleManager&) = delete;

    ~ModuleManager() = default;

    ModuleManager& operator=(ModuleManager&) = delete;

    void reset() noexcept;
    void reset(const FONEntry& object);

    void loadAll();

    void serialize(FONEntry& save) const;

private:
    void preReset() noexcept;
    void postReset() noexcept;
    void postReset(const FONEntry& object);
};
