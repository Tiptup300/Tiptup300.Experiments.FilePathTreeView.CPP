#include <vector>
#include <string>

using namespace std;

struct FileModel
{
    string m_filename;
    bool m_isDirectory;
    string m_fullPath;
    vector<FileModel> m_directoryFiles;
};

void sortFileModels(const vector<FileModel> *fileModels)
{
    // not implemented yet
}