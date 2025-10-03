#pragma once



typedef void* ModuleHandle;

struct Module {
public:
    bool isEnabled;

private:
    ModuleHandle handle;



public:
    inline bool isLoaded() const noexcept { return handle == nullptr; };
};
