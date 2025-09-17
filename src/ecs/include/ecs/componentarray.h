#pragma once

#include <memory>
#include <span>
#include <type_traits>

struct ComponentArrayDeleter {
    void operator()(void* ptr) const;
};

class ComponentArray {
private:
    const size_t componentSize;
    const size_t aligment;
    size_t reserve;
    size_t length;
    std::unique_ptr<void, ComponentArrayDeleter> data;


private:
    ComponentArray(size_t length, size_t cSize, size_t cAligment);

public:
    template <class T> requires
        std::is_trivially_copyable<T>::value
    static inline ComponentArray createInstance(size_t length) { return ComponentArray(length, sizeof(T), alignof(T)); }

    template <class T>
    inline const std::span<T> getData() const { return static_cast<T>(data.get()); }

    void resize(size_t length);
};
