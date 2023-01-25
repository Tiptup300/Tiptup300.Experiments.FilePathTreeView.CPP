#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#include "./FileModel.hpp"

using namespace std;
namespace fs = filesystem;

vector<FileModel> generateModels(const string &);

string rootDirectoryPath;

void writeFileNames(vector<FileModel> fileModels)
{
    for (auto it = fileModels.begin(); it != fileModels.end(); ++it)
    {
        string &filename = it->m_filename;
        if (it->m_isDirectory)
        {
            cout << " + " << filename << "/..." << endl;
        }
        else
        {
            cout << " - " << filename << endl;
        }
    }
}

int main()
{
    rootDirectoryPath = "/home/tiptup300/repos/release-art-back";

    cout << "starting from path:" << rootDirectoryPath << "\n";

    const vector<FileModel> fileModels = generateModels(rootDirectoryPath);
    sortFileModels(&fileModels);

    writeFileNames(fileModels);
}

vector<FileModel> generateModels(const string &rootDirectoryPath)
{
    vector<FileModel> output;
    for (auto it = fs::directory_iterator(rootDirectoryPath); it != fs::directory_iterator(); ++it)
    {
        const fs::path &filePath = it->path();
        FileModel fileModel;

        if (fs::is_directory(it->symlink_status()))
        {
            FileModel fileModel;
            fileModel.m_filename = filePath.filename();
            fileModel.m_fullPath = filePath.native();
            fileModel.m_isDirectory = true;
            fileModel.m_directoryFiles = generateModels(filePath.native());

            output.push_back(fileModel);
        }
        else
        {
            FileModel fModel;
            fModel.m_filename = filePath.filename();
            fModel.m_fullPath = filePath.native();
            fModel.m_isDirectory = false;

            output.push_back(fModel);
        }
    }

    return output;
}
