#include "form.h"
#include "ui_form.h"


#include <QKeyEvent>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    p = new PacmanWidget(this);
    p->setGeometry(10, 10, 30, 30);
    p->show();


}

Form::~Form()
{
    delete ui;
}

void Form::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Right:
        p->move(p->x() + 10, p->y());
        p->setSide(MotionSide::RIGHT);
        break;
    case Qt::Key_Left:
        p->move(p->x() - 10, p->y());
        p->setSide(MotionSide::LEFT);
        break;
    case Qt::Key_Up:
        p->move(p->x(), p->y() - 10);
        p->setSide(MotionSide::UP);
        break;
    case Qt::Key_Down:
        p->move(p->x(), p->y() + 10);
        p->setSide(MotionSide::DOWN);
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}
