#include "FractalM.h"

#include <QPainter>
#include <math.h>

FractalM::FractalM(QWidget *parent) :
    QWidget(parent)
{

}

void FractalM::paintEvent(QPaintEvent *)
{
    int depth = 30;

    QPainter painter(this);
    float zi, zr, ci, cr, tmp;
    int i, j, k, m;

    for (i = -160; i < 160; ++i) {

        ci = ((float) i) / 160.0;

        for (j = -190; j < 100; ++j) {
            cr = ((float) j) / 120.0;

            zi = zr = 0.0;

            for (k = 0; k < depth; ++k) {
                tmp = pow(zr, 2) - pow(zi, 2);
                zi = 2*zr*zi + ci;
                zr = tmp + cr;
                if ((pow(zr, 2) - pow(zi, 2)) > 1.0E5)
                    break;
            }

            if (k < depth) {
                m = k%8 + 1;
                painter.save();
                painter.setBrush(QColor(m, m*8 + 7, 0));
                painter.setPen(QColor(Qt::red));
                painter.drawPoint(j + 190, i + 160);
                painter.restore();
            } else {

                painter.drawPoint(j + 190 , i + 160);
            }
        }
    }
}
