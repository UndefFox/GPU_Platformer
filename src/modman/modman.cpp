#include "modman.h"

#include <filesystem>
#include <algorithm>



namespace {
namespace FONValuesNames {
    const std::string Name = "ModManager";
    const std::string ModFolder = "ModFolder";
}
}

ModuleManager::ModuleManager() noexcept
{
    postReset();
}

ModuleManager::ModuleManager(const FONEntry& object)
{
    postReset(object);
}

void ModuleManager::reset() noexcept
{
    preReset();
    postReset();
}

void ModuleManager::reset(const FONEntry& object)
{
    preReset();
    postReset(object);
}

void ModuleManager::loadAll()
{
    for (auto& module : modules.nodeView()) {
        module.load();
    }
}

void ModuleManager::serialize(FONEntry &save) const
{
    FONEntry root{};
    root.name = FONValuesNames::Name;

    FONEntry modFolderEntry{};
    modFolderEntry.name = FONValuesNames::ModFolder;
    modFolderEntry.value = modFolder;
    root.children.push_back(modFolderEntry);

    save.children.push_back(std::move(root));
}

void ModuleManager::preReset() noexcept
{
    modules.clear();
}

void ModuleManager::postReset() noexcept
{
    modFolder = "./mods";
}

void ModuleManager::postReset(const FONEntry& object)
{
    const FONEntry* params;
    if (auto result = object.getEntryByName(FONValuesNames::Name)) {
        params = *result;
    }
    else {
        postReset();
        return;
    }

    if (params->loadParamIfExits(modFolder, FONValuesNames::ModFolder)) {}
    else {
        postReset();
        return;
    }

    for (const auto& entry : std::filesystem::directory_iterator(modFolder)) {
        modules.emplace(entry.path().string());
    }
}
