#include "win.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Win win(0);
    win.show();
    return a.exec();
}
