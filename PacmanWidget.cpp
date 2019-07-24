#include "PacmanWidget.h"

#include <QFile>
#include <QPainter>
#include <QTimer>


PacmanWidget::PacmanWidget(QWidget *parent) :
    QWidget(parent)
{

    image = new QImage("://res/pacman.png");

    QTimer * timer = new QTimer();
    connect(timer, &QTimer::timeout, [=](){
        i++;

        if (i == 4)
            i = 0;
        this->update();


    });
    timer->start(300);

//    QTimer * timer = new QTimer();
//    connect(timer, &QTimer::timeout, [=](){
//        i++;

//        if (i == 4)
//            i = 0;
//        this->update();


//    });
//    timer->start(300);
}

void PacmanWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //painter.drawRect(this->rect());

    if (image) {
        painter.save();

        painter.translate(15, 15);

        switch (side) {
        case RIGHT:
            break;
        case LEFT:
            painter.rotate(180);
            break;
        case UP:
            painter.rotate(270);
            break;
        case DOWN:
            painter.rotate(90);
            break;
        }

        //отрисовываем задний фон
        int c = i;
        if (c == 3)
            c = 1;
        painter.drawImage(-15, -15, *image, c * 30, 0, 30, 30);

        painter.restore();
    }
}

void PacmanWidget::setSide(const MotionSide &value)
{
    side = value;
}
