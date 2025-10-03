#pragma once



extern "C" int getModuleName();
typedef int (*GetModuleNameFunc)();

extern "C" int getModuleSystems();
typedef int (*GetModuleSystemsFunc)();

extern "C" int getModuleComponents();
typedef int (*GetModuleComponentsFunc)();

extern "C" int getModuleArcheTypes();
typedef int (*GetModuleArcheTypesFunc)();
