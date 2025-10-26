#pragma once

#include <memory>
#include <string_view>



class ModuleInstance {
public:

private:
    struct ModuleDestructor { void operator()(void* handle) const noexcept; };
    std::unique_ptr<void, ModuleDestructor> handle;


public:
    ModuleInstance();
    ModuleInstance(const std::string_view path);
    ModuleInstance(ModuleInstance&) = delete;
    ModuleInstance(ModuleInstance&&) = default;

    ~ModuleInstance();

    ModuleInstance& operator=(ModuleInstance&) = delete;
    ModuleInstance& operator=(ModuleInstance&&) = default;
    explicit operator bool() const noexcept;

    void reset() noexcept;
    void reset(const std::string_view path);

private:
    void preReset() noexcept;
    void postReset() noexcept;
    void postReset(const std::string_view path);
};
