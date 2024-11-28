#include "Version.h"

#include <sstream>

namespace qts
{

Version::Version(const std::string& version)
{
    std::stringstream stream (version);
    char mark;
    stream >> major;
    stream >> mark;
    stream >> minor;
    stream >> mark;
    stream >> patch;
    stream >> mark;
    stream >> tweak;
    stream >> mark;
}

int Version::getMajorVersion() const
{
    return major;
}

int Version::getMinorVersion() const
{
    return minor;
}

int Version::getPatchVersion() const
{
    return patch;
}

int Version::getTweakVersion() const
{
    return tweak;
}

std::string Version::toString() const
{
    std::stringstream stream;
    stream << major << "." << minor << "." << patch << "." << tweak;
    return stream.str();
}

}