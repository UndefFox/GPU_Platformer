#pragma once

#include <memory>

#include "ts/tag.h"



typedef Tag ComponentArrayTag;


struct ComponentArrayDeleter {
    void operator()(void* ptr) const;
};

class ComponentArray {
private:
    const size_t componentSize;
    const size_t aligment;
    size_t reserve;
    size_t length;
    std::unique_ptr<void, ComponentArrayDeleter> memory;

public:
    ComponentArray(size_t length, size_t cSize, size_t cAligment);

    void* data() const noexcept;
    size_t size() const noexcept;

    void resize(size_t length);
};
