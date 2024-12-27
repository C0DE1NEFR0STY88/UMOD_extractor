#ifndef UMODFILE_H
#define UMODFILE_H

#include <QString>
#include <vector>
#include <tuple>

class UMODFile 
{
public:
    explicit UMODFile(const QString &filePath);
    ~UMODFile();

    bool open();
    std::vector<std::tuple<QString, QString, int>> listFiles();
    bool extractAll(const QString &outputDir);

private:
    QString filePath;
    std::vector<std::tuple<QString, QString, int>> files;
};

#endif // UMODFILE_H
