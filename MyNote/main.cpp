#include "MyNote.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyNote w;
    w.show();
    return a.exec();
}
