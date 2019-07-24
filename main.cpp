#include "mainwindow.h"
#include <QApplication>

#include "SnakeWidget.h"

#include "PacmanWidget.h"
#include "form.h"

#include "FractalM.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    SnakeWidget snake;
    snake.setGeometry(50, 50, 600, 600);
    snake.show();
    snake.start(100);

//    PacmanWidget  p;
//    p.show();

//    Form f;
//    f.show();

//    FractalM f;
//    f.setGeometry(50, 50, 300, 300);
//    f.show();

    return a.exec();
}
