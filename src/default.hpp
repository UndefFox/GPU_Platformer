#pragma once

#include "modman/modman.h"



void run() {
    ModuleManager man("mods");
    man.loadAll();
}
