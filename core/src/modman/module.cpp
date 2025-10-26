#include "module.h"

#include <filesystem>



Module::Module()
{
    postReset();
}

Module::Module(const std::string_view path)
{
    postReset(path);
}

Module::~Module()
{
    preReset();
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
    preReset();
    postReset();
}

void Module::reset(const std::string_view path)
{
    preReset();
    postReset(path);
}

void Module::preReset() noexcept
{

}

void Module::postReset() noexcept
{
    instance.reset();
    path.clear();
}

void Module::postReset(const std::string_view path)
{
    if (!std::filesystem::exists(path)) throw std::runtime_error("Module folder doesn't exist.");

    this->path = path;
}


