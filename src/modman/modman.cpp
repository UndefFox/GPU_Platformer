#include "modman.h"

#include <filesystem>



ModuleManager::ModuleManager() noexcept
{
    postReset();
}

ModuleManager::ModuleManager(const std::string_view modFolder)
{
    postReset(modFolder);
}

void ModuleManager::reset() noexcept
{
    preReset();
    postReset();
}

void ModuleManager::reset(const std::string_view modFolder)
{
    preReset();
    postReset(modFolder);
}

void ModuleManager::loadAll()
{
    for (auto& module : modules.nodeView()) {
        module.load();
    }
}

void ModuleManager::preReset() noexcept
{
    modules.clear();
}

void ModuleManager::postReset() noexcept
{

}

void ModuleManager::postReset(const std::string_view modFolder)
{
    for (const auto& entry : std::filesystem::directory_iterator(modFolder)) {
        modules.emplace(entry.path().string());
    }
}
