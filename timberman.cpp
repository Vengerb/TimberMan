#include "timberman.h"
#include <QPainter>
#include "mainwindow.h"

Timberman::Timberman(int heigh)
{
    this->im = QPixmap(":/images/drovosek1_lev.png");
    this->x=this->im.width()-indentTree;
    y=heigh-SizeHeight-indentH;
}

void Timberman::draw(QPainter *p)
{
    this->im = this->im.scaled(220, 220, Qt::KeepAspectRatio);// увеличиваем изображение в 2 раза (с сохраниением соотношения сторон?)
    p->drawPixmap(this->x, this->y, this->im);
}



void Timberman::setIm(const QPixmap &value)
{
    im = value;
}

void Timberman::setX(int value)
{
    x = value;
}

QPixmap Timberman::getIm() const
{
    return im;
}

int Timberman::getX() const
{
    return x;
}

void Timberman::UPsost()
{
    sost++;
    if (sost>3) sost=0;
}

int Timberman::getSost()
{
    return sost;
}
