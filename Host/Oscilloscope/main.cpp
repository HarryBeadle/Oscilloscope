#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setDesktopSettingsAware(false);
    qDebug() << QStyleFactory::keys();
    QApplication::setStyle("Fusion");
    QApplication a(argc, argv);
    Window w;
    w.show();
    return a.exec();
}
