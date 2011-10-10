#include <QApplication>
#include "GLWidget.h"


int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    GLWidget glWidget;
    glWidget.show();
    return app.exec();
}
