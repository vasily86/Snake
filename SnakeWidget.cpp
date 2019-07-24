#include "SnakeWidget.h"

#include <QKeyEvent>

SnakeWidget::SnakeWidget(QWidget *parent) :
    QWidget(parent)
{
    int y = N / 2;
    timer = new QTimer(this);


    for (int i = 10; i > 0; --i) {
        listPoint.append(QPoint(i, y));
    }

    createPoint();
}

/*! Старт игры с интервалом \a msec */
void SnakeWidget::start(int msec)
{
    this->msec = msec;
    timer->disconnect();
    connect(timer, &QTimer::timeout, [=](){
        motion();

        this->update();
    });
    timer->start(msec);
}

void SnakeWidget::stop()
{
    timer->stop();
}

void SnakeWidget::pause()
{
    timer->stop();
}

void SnakeWidget::resume()
{
    timer->start(msec);
}

/*! Движение змеи */
void SnakeWidget::motion()
{
    QPoint first = listPoint.at(0);

    switch (side) {
    case RIGHT:
        first.setX(first.x() + 1);
        break;
    case LEFT:
        first.setX(first.x() - 1);
        break;
    case UP:
        first.setY(first.y() - 1);
        break;
    case DOWN:
        first.setY(first.y() + 1);
        break;
    }

    listPoint.insert(0, first);

    //Если начало змеи совпадает с точкой, создаём новую и не удаляем хвост
    if (first == point) {
        createPoint();
    } else {
        listPoint.removeLast();
    }

}

/*! Создание заднего фона */
void SnakeWidget::createBack()
{
    int w = this->width() / N;
    int h = this->height() / N;

    imageBack = std::make_shared<QImage>(width(), height(), QImage::Format_ARGB32);

    if (w == 0)
        w = 1;
    if (h == 0)
        h = 1;

    QPainter painter;
    painter.begin(imageBack.get());

    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(QColor(Qt::white)));
    painter.drawRect(this->rect());
    painter.restore();

    painter.setPen(Qt::DotLine);

    for (int i = 0; i < this->width(); i=i+w) {
        painter.drawLine(i, 0, i, this->height());
    }
    for (int i = 0; i < this->height(); i=i+h) {
        painter.drawLine(0, i, this->width(), i);
    }
    painter.end();
}

void SnakeWidget::createPoint()
{
    qsrand(QDateTime::currentDateTime().toMSecsSinceEpoch());
    int x = qrand() % N;
    int y = qrand() % N;

    for (QPoint p : listPoint) {
        if (p.x() == x && p.y() == y) {
            createPoint();
            break;
        }
    }

    point = QPoint(x, y);
}

void SnakeWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    int w = this->width() / N;
    int h = this->height() / N;

    painter.setPen(Qt::NoPen);
    QBrush br1 = QBrush(QColor(Qt::darkGreen));

    if (imageBack) {
        painter.save();
        //отрисовываем задний фон
        painter.drawImage(this->rect(), *imageBack.get());
        painter.restore();
    }

    //Отрисовываем змейку
    for (QPoint p : listPoint) {
        painter.setBrush(br1);
        painter.drawRect(p.x() * w, p.y() * h, w, h);
    }

    //Отрисовываем точку
    painter.setBrush(QBrush(QColor(Qt::yellow)));
    painter.drawRect(point.x() * w, point.y() * h, w, h);
}

/*! При изменении окна - изменяем задний фон */
void SnakeWidget::resizeEvent(QResizeEvent *)
{
    createBack();
}

void SnakeWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Right:
        side = RIGHT;
        break;
    case Qt::Key_Left:
        side = LEFT;
        break;
    case Qt::Key_Up:
        side = UP;
        break;
    case Qt::Key_Down:
        side = DOWN;
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}
