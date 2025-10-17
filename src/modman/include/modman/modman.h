#pragma once

#include <string>

#include "module.h"
#include "graphs/directedacyclicgraph.hpp"



class ModuleManager {
private:
    DirectedAcyclicGraph<Module> modules;

public:
    void loadModule(const std::string& path);
};
