#include "moduleinstance.h"

#include <dlfcn.h>

#include "api.h"


#define LOAD_FUNC(handle, func) (decltype(func)*)dlsym(handle, #func)


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

ModuleInstance::~ModuleInstance()
{
    if (! *this) return;

    auto deinitFunc = LOAD_FUNC(handle.get(), deinitializeModule);
    deinitFunc();
}

ModuleInstance::operator bool() const noexcept { return handle != nullptr; }

void ModuleInstance::reset() noexcept
{
    if (! *this) return;

    auto deinitFunc = LOAD_FUNC(handle.get(), initializeModule);
    deinitFunc();

    handle.reset();
}

void ModuleInstance::reset(const std::string &path)
{
    if (*this) {
        dlerror();
        auto deinitFunc = LOAD_FUNC(handle.get(), initializeModule);
        if (const auto e = dlerror(); e) throw std::runtime_error(e);
        deinitFunc();
    }

    dlerror();
    handle.reset(dlopen(path.data(), RTLD_LAZY | RTLD_GLOBAL | RTLD_DEEPBIND));
    if (const auto e = dlerror(); e) throw std::runtime_error(e);

    dlerror();
    auto initFunc = LOAD_FUNC(handle.get(), initializeModule);
    if (const auto e = dlerror(); e) throw std::runtime_error(e);
    initFunc();
}





