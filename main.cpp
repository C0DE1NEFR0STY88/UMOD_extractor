#include <QApplication>
#include "umodextractor.h"

int main(int argc, char *argv[]) 
{
    QApplication app(argc, argv);

    UMODExtractor window;
    window.show();

    return app.exec();
}
