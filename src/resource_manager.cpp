#include "resource_manager.h"

#include <fstream>
#include <sstream>

namespace snowflake::utility {

CResourceManager::CResourceManager() {
    resources_path_ = "../res";
    shaders_path_ = resources_path_ + "/shaders/";
}

CResourceManager &CResourceManager::instance() {
    static CResourceManager instance;
    return instance;
}

std::string CResourceManager::GetShaderSrc(const std::string& a_name) const noexcept {
    std::ifstream fin(shaders_path_ + a_name);
    std::stringstream stream;
    stream << fin.rdbuf();
    fin.close();

    return stream.str();
}

}  // namespace snowflake::utility
