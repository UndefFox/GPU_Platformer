#include "componentarray.h"

#include <cstdlib>
#include <cstring>



void ComponentArrayDeleter::operator()(void *ptr) const
{
    std::free(ptr);
}

ComponentArray::ComponentArray(size_t length, size_t cSize, size_t cAligment) :
    componentSize(cSize),
    aligment(cAligment),
    reserve(length),
    length(length),
    memory(std::aligned_alloc(aligment, reserve * componentSize))
{ }

void* ComponentArray::data() const noexcept
{
    return memory.get();
}

size_t ComponentArray::size() const noexcept
{
    return length;
}

void ComponentArray::resize(size_t newLength)
{
    std::unique_ptr<void, ComponentArrayDeleter> newData(std::aligned_alloc(aligment, newLength * componentSize));
    std::memcpy(newData.get(), memory.get(), length * componentSize);
    memory = std::move(newData);
    reserve = newLength;
    length = (newLength < length ? newLength : length);
}
