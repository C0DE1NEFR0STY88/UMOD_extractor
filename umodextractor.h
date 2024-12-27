#ifndef UMODEXTRACTOR_H
#define UMODEXTRACTOR_H

#include <QMainWindow>
#include <QProgressBar>
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QComboBox>

class UMODExtractor : public QMainWindow 
{
    Q_OBJECT

public:
    UMODExtractor(QWidget *parent = nullptr);
    ~UMODExtractor();

private slots:
    void openUMODFile();
    void extractFiles();
    void updateFileList();  //update table based on filter

private:
    QLabel *fileLabel;
    QProgressBar *progressBar;
    QPushButton *openButton;
    QPushButton *extractButton;
    QString umodFilePath;
    QTableWidget *fileTable;
    QComboBox *fileTypeComboBox;  //file type filter

    std::vector<std::tuple<QString, QString, int>> allFiles;  //file list

    void populateFileList();  //populate full file list
};

#endif //UMODEXTRACTOR_H
