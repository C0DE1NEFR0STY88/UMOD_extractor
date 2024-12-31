#include "umodfile.h"

UMODFile::UMODFile(const QString &filePath) : filePath(filePath) 
{}

UMODFile::~UMODFile() 
{}

bool UMODFile::open() 
{
    //placeholder logic; NEEDS TO BE UPDATED WITH ACTUAL PARSING.
    files = 
            {
                {"file1.txt", "Scripts", 45},
                {"texture1.utx", "Textures", 200},
                {"map1.unr", "Maps", 1024},
            };
    return true;
}

std::vector<std::tuple<QString, QString, int>> UMODFile::listFiles() 
{
    return files;
}

bool UMODFile::extractAll(const QString &outputDir) 
{
    //placeholder logic space
    return true;
}
