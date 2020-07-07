#ifndef TREE_H
#define TREE_H

#include <QRect>
#include <QImage>
#include <QPainter>

class Tree
{
public:
    Tree();
    Tree(int with, int heigh);
    void picture(QPainter *p);
    int getTypeTree(int i) //возвращение типа ствола дерева
    {
        return tr[i].typeTree;
    }
    int getXTrunk(int i) //возвращение координаты Х i-го ствола дерева
    {
        return tr[i].x;
    }
    void deleteTrunk(bool LeftRight); //Удаление ствола дерева
    void DownTree(); //cпуск дерева
    bool getRybTree()
    {
        return RybTree;
    }

private:
    struct tree //состовляющее ствола
    {
        int x; //координата Х
        int y; //координата У
        QImage img; //изображение соответствующего ствола
        int sizeWith; //размер ствола по ширине
        int sizeHeigh=140; //размер ствола по высоте
        int typeTree; //тип ствола дерева (0-центральное, 1-ветка слева, 2-ветка справа)
        int Ygol=0;
        bool LeftRight=false;//при каком направлении срублено
    };
    int startX; //начальное положение по координате Х
    int indentH=50; //отступ по координате У
    QList <tree> tr; //само дерево
    QList <tree> Qtr; //очередь на вылет
    int sizeWith1=140; // ширина ствола 0 типа
    int sizeWith2=280; // ширина стволов 2 и 1 типов
    int NumberTrunk; //количество состовляющих стволов
    int zapY;
    bool RybTree=false;//срублено или нет
};

#endif // TREE_H
