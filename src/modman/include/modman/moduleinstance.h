#pragma once

#include <string>
#include <memory>



class ModuleInstance {
public:

private:
    struct ModuleDestructor { void operator()(void* handle) const noexcept; };
    std::unique_ptr<void, ModuleDestructor> handle;


public:
    ModuleInstance();
    ModuleInstance(const std::string& path);
    ModuleInstance(ModuleInstance&) = delete;
    ModuleInstance(ModuleInstance&&) = default;

    ~ModuleInstance() = default;

    ModuleInstance& operator=(ModuleInstance&) = delete;
    ModuleInstance& operator=(ModuleInstance&&) = default;
    explicit operator bool() const noexcept;

    void reset() noexcept;
    void reset(const std::string& path);
};
