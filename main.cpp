#include "mainwindow.h"
#include <QApplication>

#include "SnakeWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //SnakeWidget snake;
    MainWindow snake;
    snake.setGeometry(50, 50, 600, 600);
    snake.show();
    //snake.start(100);

    return a.exec();
}
