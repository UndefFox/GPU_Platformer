#include "modman.h"

#include <filesystem>



ModuleManager::ModuleManager() noexcept
{
    reset();
}

ModuleManager::ModuleManager(const std::string_view modFolder)
{
    reset(modFolder);
}

void ModuleManager::reset() noexcept
{
    modules.clear();
}

void ModuleManager::reset(const std::string_view modFolder)
{
    modules.clear();

    for (const auto& entry : std::filesystem::directory_iterator(modFolder)) {
        modules.emplace(entry.path().string());
    }
}

void ModuleManager::loadAll()
{
    for (auto& module : modules.nodeView()) {
        module.load();
    }
}
