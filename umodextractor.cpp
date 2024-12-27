#include "umodextractor.h"
#include <QMessageBox>
#include <fstream>

UMODExtractor::UMODExtractor(QWidget *parent) : QMainWindow(parent) 
{

    fileLabel = new QLabel("No UMOD file selected", this);
    progressBar = new QProgressBar(this);
    openButton = new QPushButton("Open UMOD File", this);
    extractButton = new QPushButton("Extract Files", this);
    extractButton->setEnabled(false);

    fileTable = new QTableWidget(this);
    fileTable->setColumnCount(2);
    fileTable->setHorizontalHeaderLabels(QStringList() << "Filename" << "Size (KB)");

    fileTypeComboBox = new QComboBox(this);
    fileTypeComboBox->addItem("All");
    fileTypeComboBox->addItem("Textures");
    fileTypeComboBox->addItem("Maps");
    fileTypeComboBox->addItem("Scripts");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(fileLabel);
    layout->addWidget(openButton);
    layout->addWidget(fileTypeComboBox);
    layout->addWidget(fileTable);
    layout->addWidget(extractButton);
    layout->addWidget(progressBar);

    QWidget *widget = new QWidget();
    widget->setLayout(layout);
    setCentralWidget(widget);

    connect(openButton, &QPushButton::clicked, this, &UMODExtractor::openUMODFile);
    connect(extractButton, &QPushButton::clicked, this, &UMODExtractor::extractFiles);
    connect(fileTypeComboBox, &QComboBox::currentTextChanged, this, &UMODExtractor::updateFileList);

    setWindowTitle("UMOD Extractor");
}

UMODExtractor::~UMODExtractor() 
{}

void UMODExtractor::openUMODFile() 
{
    umodFilePath = QFileDialog::getOpenFileName(this, "Open UMOD File", "", "*.umod");
    if (!umodFilePath.isEmpty()) 
    {
        fileLabel->setText(umodFilePath);
        extractButton->setEnabled(true);
        populateFileList();
    } 
    else 
    {
        fileLabel->setText("No UMOD file selected");
        extractButton->setEnabled(false);
        fileTable->setRowCount(0);
    }
}

void UMODExtractor::populateFileList() 
{
    allFiles = 
                {
                    {"file1.txt", "Scripts", 45},
                    {"texture1.utx", "Textures", 200},
                    {"map1.unr", "Maps", 1024},
                };
    updateFileList();
}

void UMODExtractor::updateFileList() 
{
    QString selectedType = fileTypeComboBox->currentText();
    fileTable->setRowCount(0);

    int row = 0;
    for (const auto &file : allFiles) 
    {
        if (selectedType == "All" || std::get<1>(file) == selectedType) 
        {
            fileTable->insertRow(row);
            fileTable->setItem(row, 0, new QTableWidgetItem(std::get<0>(file)));
            fileTable->setItem(row, 1, new QTableWidgetItem(QString::number(std::get<2>(file))));
            ++row;
        }
    }
}

void UMODExtractor::extractFiles() 
{
    if (umodFilePath.isEmpty()) 
    {
        QMessageBox::warning(this, "Error", "No UMOD file selected!");
        return;
    }
    progressBar->setValue(100);  //dummy value for now
    QMessageBox::information(this, "Extraction Complete", "Files extracted successfully!");
}
