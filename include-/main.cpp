#include <QtGui/QApplication>
#include "ccollege.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cCollege w;
    w.show();

    return a.exec();
}
