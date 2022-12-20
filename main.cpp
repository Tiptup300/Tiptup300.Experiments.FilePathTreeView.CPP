#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;

template <typename... Args>
std::string Sprintf(const char *fmt, Args... args)
{
    const size_t n = snprintf(nullptr, 0, fmt, args...);
    std::vector<char> buf(n + 1);
    snprintf(buf.data(), n + 1, fmt, args...);
    return std::string(buf.data());
}

struct fileModel
{
    std::string filename;
    bool isDirectory;
    std::string fullPath;
};

int main()
{
    std::cout << "\n\n--------------------------\n\n";

    std::vector<fileModel> files;

    std::string rootDirectoryPath = "/home/tiptup300/repos/release-art-back";
    for (auto it = fs::directory_iterator(rootDirectoryPath); it != fs::directory_iterator(); ++it)
    {

        const fs::path &filePath = it->path();
        const std::string filename = filePath.filename();
        const fs::file_status &fileStatus = it->symlink_status();

        if (fs::is_directory(fileStatus))
        {
            std::cout << " + " << filename << "/" << std::endl;
        }
        else
        {
            std::cout << " - " << filename << "/" << std::endl;
        }
    }
    return 0;
}