#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    Dialog window;

    window.show();

    return application.exec();
}
