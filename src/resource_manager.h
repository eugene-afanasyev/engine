#ifndef SNOWFLAKE_RESOURCE_MANAGER_H
#define SNOWFLAKE_RESOURCE_MANAGER_H

#include <string>


namespace snowflake::utility {

class CResourceSystem {
 public:
    CResourceSystem();
    static CResourceSystem& instance();

    [[nodiscard]] std::string GetShaderSrc(const std::string& a_name) const noexcept;

 private:
    bool init_ = false;

    std::string resources_path_;
    std::string shaders_path_;
};

}  // namespace snowflake::utility

#endif  // SNOWFLAKE_RESOURCE_MANAGER_H
