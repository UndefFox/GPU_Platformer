#include "module.h"

#include <filesystem>



Module::Module()
{
    reset();
}

Module::Module(const std::string& path)
{
    reset(path);
}

void Module::load()
{
    instance.reset(path + "/module.so");
}

void Module::unload() noexcept
{
    instance.reset();
}

Module::operator bool() const noexcept
{
    return !path.empty();
}

void Module::reset() noexcept
{
    instance.reset();
    path.clear();
}

void Module::reset(const std::string& path)
{
    if (!std::filesystem::exists(path)) throw std::runtime_error("Module folder doesn't exist.");

    this->path = path;
}


