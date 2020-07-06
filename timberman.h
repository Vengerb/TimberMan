#ifndef TIMBERMAN_H
#define TIMBERMAN_H
#include <QPixmap>
class Timberman
{
public:
    Timberman(int heigh);

    void draw(QPainter *p);

    void setIm(const QPixmap &value);

    void setX(int value);

    QPixmap getIm() const;

    int getX() const;

    void UPsost();

    int getSost();

private:
    QPixmap im;         //изображение в png
                        // не использую QImage т.к оно похоже предназанчено для jpg

    int x;              // координата по х левого верхнего угла
    int y = 380; // при размере окна 800*600 и размера картинки 220*220 - координата по у левого верхнего угла
                       // я увеличила картинку т.к 110*110 очень мелко (можно исправить в draw)
                       // можно уменьшить - тогда в дальнейшем будет видно дерево на меньшую высоту
    int SizeWith=220;
    int SizeHeight=220;
    int indentH=110;
    int indentTree=20;
    int sost=0;//нужно для анимации
};

#endif // TIMBERMAN_H
