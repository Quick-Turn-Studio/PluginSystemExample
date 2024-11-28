#pragma once

#include <memory>

namespace qts::base
{

template<typename T>
using UniquePtr = std::unique_ptr<T>;

template<typename T, typename... Args>
UniquePtr<T> makeUnique(Args&&... args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

} // namespace qts::base
