#ifndef PACMANWIDGET_H
#define PACMANWIDGET_H

#include <QWidget>
#include "motionside.h"

class PacmanWidget : public QWidget
{
public:
    explicit PacmanWidget(QWidget *parent = 0);

    // QWidget interface
    void setSide(const MotionSide &value);

protected:
    void paintEvent(QPaintEvent *);


private:
    QImage * image;

    quint8 i{1};

    MotionSide side{RIGHT};                 //!< Движение
};

#endif // PACMANWIDGET_H
