#include "qimage2matdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QImage2MatDialog w;
    w.show();

    return a.exec();
}
