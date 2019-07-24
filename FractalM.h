#ifndef FRACTALM_H
#define FRACTALM_H

#include <QWidget>

class FractalM : public QWidget
{
public:
    explicit FractalM(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

};

#endif // FRACTALM_H
