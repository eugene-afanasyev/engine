#include "resource_manager.h"

#include <fstream>
#include <sstream>

namespace snowflake::utility {

CResourceSystem::CResourceSystem() {
    resources_path_ = "../res";
    shaders_path_ = resources_path_ + "/shaders/";
}

CResourceSystem &CResourceSystem::instance() {
    static CResourceSystem instance;
    return instance;
}

std::string CResourceSystem::GetShaderSrc(const std::string& a_name) const noexcept {
    std::ifstream fin(shaders_path_ + a_name);
    std::stringstream stream;
    stream << fin.rdbuf();
    fin.close();

    return stream.str();
}

}  // namespace snowflake::utility
