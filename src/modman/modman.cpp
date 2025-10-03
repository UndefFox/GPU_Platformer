#include "modman.h"

#include <dlfcn.h>



void ModuleManager::loadModule(const std::string_view& path)
{
    const ModuleHandle handle = dlopen(path.data(), RTLD_LAZY | RTLD_GLOBAL | RTLD_DEEPBIND);

    if (!handle) {
        return;
    }


    dlerror();
}
