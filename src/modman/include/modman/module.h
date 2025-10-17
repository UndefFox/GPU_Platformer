#pragma once

#include <string>

#include "moduleinstance.h"



struct Module {
public:


private:
    ModuleInstance instance;
    std::string path;


public:
    Module();
    Module(const std::string& path);
    Module(Module&) = delete;
    Module(Module&&) = default;

    ~Module() = default;

    void load();
    void unload() noexcept;

    Module& operator=(Module&) = delete;
    Module& operator=(Module&&) = default;
    explicit operator bool() const noexcept;

    void reset() noexcept;
    void reset(const std::string& path);
};
