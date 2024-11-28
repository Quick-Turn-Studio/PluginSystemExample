#pragma once

#include <BaseString.h>

namespace qts
{

class Version
{
public:
    explicit Version(const base::String& version);

    [[nodiscard]] int getMajorVersion() const;
    [[nodiscard]] int getMinorVersion() const;
    [[nodiscard]] int getPatchVersion() const;
    [[nodiscard]] int getTweakVersion() const;

    [[nodiscard]] base::String toString() const;

private:
    int major = 0;
    int minor = 0;
    int patch = 0;
    int tweak = 0;
};

} // namespace qts
