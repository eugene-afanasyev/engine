#include "resource_system.h"

#include <fstream>
#include <sstream>

namespace snowflake::utility {

std::shared_ptr<std::string> GetTexturePath(const std::string& aName) {
    return std::make_shared<std::string>(CResourceSystem::instance().GetPathToTexture(aName));
}

CResourceSystem::CResourceSystem() {
    mPathToResources = "../res";
    mPathToShaders = mPathToResources + "/shaders/";
    mPathToTextures = mPathToResources + "/textures/";
}

CResourceSystem &CResourceSystem::instance() {
    static CResourceSystem instance;
    return instance;
}

std::string CResourceSystem::GetShaderSource(const std::string& aName) const {
    std::ifstream fin(mPathToShaders + aName);
    std::stringstream stream;
    stream << fin.rdbuf();
    fin.close();

    return stream.str();
}

std::string CResourceSystem::GetPathToTexture(const std::string &aName) const {
    return mPathToTextures + aName;
}

}  // namespace snowflake::utility
