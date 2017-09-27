#include "widget.h"
#include <QApplication>
#include "mymainwin.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myMainwin w;
    w.show();

    return a.exec();
}
