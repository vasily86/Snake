#ifndef SNAKEWIDGET_H
#define SNAKEWIDGET_H

#include <QDateTime>
#include <QMap>
#include <QPainter>
#include <QTimer>
#include <QWidget>
#include "motionside.h"
#include <memory>



class SnakeWidget : public QWidget
{
public:
    explicit SnakeWidget(QWidget *parent = 0);

    void start(int msec);
    void stop();

    void pause();
    void resume();

protected:
    void motion();
    void createBack();
    void createPoint();
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

private:
    static constexpr int N = 50;            //!< Размер

    QList<QPoint> listPoint;

    std::shared_ptr<QImage> imageBack;      //!< Задний фон
    QTimer * timer;                         //!< Таймер генератор шагов

    MotionSide side{RIGHT};                 //!< Движение

    QPoint point;
    int msec;



    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // SNAKEWIDGET_H
