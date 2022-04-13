#ifndef SNOWFLAKE_RESOURCE_MANAGER_H
#define SNOWFLAKE_RESOURCE_MANAGER_H

#include <string>
#include <memory>

namespace snowflake::utility {

std::shared_ptr<std::string> GetTexturePath(const std::string& aName);

class CResourceSystem {
 public:
    CResourceSystem();
    static CResourceSystem& instance();

    [[nodiscard]] std::string GetShaderSource(const std::string& aName) const;
    [[nodiscard]] std::string GetPathToTexture(const std::string& aName) const;

private:
    std::string mPathToResources;
    std::string mPathToShaders;
    std::string mPathToTextures;
};

}  // namespace snowflake::utility

#endif  // SNOWFLAKE_RESOURCE_MANAGER_H
