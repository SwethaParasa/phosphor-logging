#include "extensions/openpower-pels/paths.hpp"

#include <filesystem>

namespace openpower
{
namespace pels
{

// Use paths that work in unit tests.

std::filesystem::path getPELIDFile()
{
    static std::string idFile;

    if (idFile.empty())
    {
        char templ[] = "/tmp/logidtestXXXXXX";
        std::filesystem::path dir = mkdtemp(templ);
        idFile = dir / "logid";
    }
    return idFile;
}

std::filesystem::path getPELRepoPath()
{
    static std::string repoPath;

    if (repoPath.empty())
    {
        char templ[] = "/tmp/repopathtestXXXXXX";
        std::filesystem::path dir = mkdtemp(templ);
        repoPath = dir;
    }
    return repoPath;
}

std::filesystem::path getMessageRegistryPath()
{
    static std::string registryPath;

    if (registryPath.empty())
    {
        char templ[] = "/tmp/msgregtestXXXXXX";
        registryPath = mkdtemp(templ);
    }

    return registryPath;
}

} // namespace pels
} // namespace openpower