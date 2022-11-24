//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#include <QApplication>

#include "MainWindowGUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindowGUI app;

    app.show();

    return a.exec();
}
