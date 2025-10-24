#pragma once

#include <string>
#include <string_view>

#include "moduleinstance.h"



struct Module {
public:


private:
    ModuleInstance instance;
    std::string path;


public:
    Module();
    Module(const std::string_view path);
    Module(Module&) = delete;
    Module(Module&&) = default;

    ~Module();

    void load();
    void unload() noexcept;

    Module& operator=(Module&) = delete;
    Module& operator=(Module&&) = default;
    explicit operator bool() const noexcept;

    void reset() noexcept;
    void reset(const std::string_view path);

private:
    void preReset() noexcept;
    void postReset() noexcept;
    void postReset(const std::string_view path);
};
