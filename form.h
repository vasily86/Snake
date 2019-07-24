#ifndef FORM_H
#define FORM_H

#include <QWidget>

#include "PacmanWidget.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private:
    Ui::Form *ui;

    PacmanWidget *p ;

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // FORM_H
