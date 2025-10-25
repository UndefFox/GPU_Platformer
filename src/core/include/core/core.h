#pragma once

#include "modman/modman.h"
#include "parsers/fon.h"



struct Core {
public:
    ModuleManager moduleManager;


public:
    Core() = default;
    Core(const FONEntry& params);

    ~Core() = default;

    Core& operator=(Core&) = delete;

    void serialize(FONEntry& save) const;
};
