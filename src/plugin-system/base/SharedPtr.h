#pragma once

#include <memory>
#include <utility>

namespace qts::base
{

template<typename T>
using SharedPtr = std::shared_ptr<T>;

template<typename T, typename... Args>
SharedPtr<T> makeShared(Args&&... args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

template<typename T, typename... Args>
SharedPtr<T> makeSharedSeparated(Args&&... args)
{
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

} // namespace qts::base
