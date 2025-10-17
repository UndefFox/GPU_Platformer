#include "moduleinstance.h"

#include <dlfcn.h>



void ModuleInstance::ModuleDestructor::operator()(void* handle) const noexcept
{
    dlclose(handle);
}

ModuleInstance::ModuleInstance()
{
    reset();
}

ModuleInstance::ModuleInstance(const std::string& path)
{
    reset(path);
}

ModuleInstance::operator bool() const noexcept { return handle != nullptr; }

void ModuleInstance::reset() noexcept
{
    handle.reset();
}

void ModuleInstance::reset(const std::string &path)
{
    dlerror();
    handle.reset(dlopen(path.data(), RTLD_LAZY | RTLD_GLOBAL | RTLD_DEEPBIND));

    if (const auto e = dlerror(); e) throw std::runtime_error(e);
}





