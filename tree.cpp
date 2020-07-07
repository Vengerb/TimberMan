#include "tree.h"
#include <random>
#include <ctime>
#include<QThread>

//создание дерева
Tree::Tree(int with, int heigh)
{
    srand(time(NULL));//чтобы рандом всегда был разный
    startX=with/2;
    tr.append(tree {});
    tr[0].x=startX;
    tr[0].y=heigh-indentH*3-tr[0].sizeHeigh/2;
    tr[0].sizeWith=sizeWith1;
    tr[0].img=QImage(":/tree/Images/derevo1.png");
    tr[0].typeTree=0;
    NumberTrunk=6;
    for (int i=1;i<NumberTrunk;i++)
    {
        tr.append(tree {});
        tr[i].typeTree=rand()%3; //определения типа ствола (рандомно)
        //проверка чтобы между 1 и 2 типом было как минимум 1-н ствол 0 типа
        if (i-1>-1)
            if (tr[i-1].typeTree!=tr[i].typeTree&&tr[i-1].typeTree!=0)
                tr[i].typeTree=0;
        //заполнение ствола от соответствующего типа ствола
        switch(tr[i].typeTree)
        {
            case 0:
            {
                tr[i].x=startX;
                tr[i].sizeWith=sizeWith1;
                tr[i].img=QImage(":/tree/Images/derevo1.png");
                break;
            }
            case 1:
            {
                tr[i].x=startX;
                tr[i].sizeWith=sizeWith2;
                tr[i].x-=sizeWith1/2;
                tr[i].img=QImage(":/tree/Images/derevo1_lev.png");
                break;
            }
            case 2:
            {
                tr[i].x=startX;
                tr[i].sizeWith=sizeWith2;
                tr[i].x+=sizeWith1/2;
                tr[i].img=QImage(":/tree/Images/derevo1_prav.png");
                break;
            }

        }
        tr[i].y=tr[i-1].y-tr[i].sizeHeigh;
    }
}

//отрисовка дерева состоящего из стволов
void Tree::picture(QPainter *p)
{
    QPainter *p0=p;
    for (int i=0;i<NumberTrunk;i++)
    {
        p->drawImage(QRect(tr[i].x-tr[i].sizeWith/2,tr[i].y-tr[i].sizeHeigh/2,tr[i].sizeWith,tr[i].sizeHeigh),tr[i].img);
        if (i<Qtr.length())
        {
            p->translate(Qtr[i].x-Qtr[i].sizeWith/2,Qtr[i].y-Qtr[i].sizeHeigh/2);
            p->rotate(Qtr[i].Ygol);
            p->drawImage(QRect(0,0,Qtr[i].sizeWith,Qtr[i].sizeHeigh),Qtr[i].img);
            p->rotate(-Qtr[i].Ygol);
            p->translate(-(Qtr[i].x-Qtr[i].sizeWith/2),-(Qtr[i].y-Qtr[i].sizeHeigh/2));
            if (Qtr[i].Ygol>60)Qtr[i].Ygol=0; else Qtr[i].Ygol+=10;
        }
    }
    p=p0;
}

//удаление нижнего ствола и переприсваивание последующих стволов
void Tree::deleteTrunk(bool LeftRight)
{
    zapY=tr[0].y;
    tr[0].LeftRight=LeftRight;
    Qtr.append(tr[0]);
    for (int i=0;i<NumberTrunk-1;i++)
    {
        tr[i].x=tr[i+1].x;
        tr[i].y-=50;
        tr[i].img=tr[i+1].img;
        tr[i].sizeWith=tr[i+1].sizeWith;
        tr[i].typeTree=tr[i+1].typeTree;
    }
    RybTree=true;
    int ind=NumberTrunk-1;
    tr[ind].typeTree=rand()%3;
        if (tr[ind-1].typeTree!=tr[ind].typeTree&&tr[ind-1].typeTree!=0)
            tr[ind].typeTree=0;
    switch(tr[ind].typeTree)
    {
        case 0:
        {
            tr[ind].x=startX;
            tr[ind].sizeWith=sizeWith1;
            tr[ind].img=QImage(":/tree/Images/derevo1.png");
            break;
        }
        case 1:
        {
            tr[ind].x=startX;
            tr[ind].sizeWith=sizeWith2;
            tr[ind].x-=sizeWith1/2;
            tr[ind].img=QImage(":/tree/Images/derevo1_lev.png");
            break;
        }
        case 2:
        {
            tr[ind].x=startX;
            tr[ind].sizeWith=sizeWith2;
            tr[ind].x+=sizeWith1/2;
            tr[ind].img=QImage(":/tree/Images/derevo1_prav.png");
            break;
        }

    }
    tr[ind].y=tr[ind-1].y-tr[ind].sizeHeigh;
}

void Tree::DownTree()
{
    if (RybTree)//если дерево срублено
    {
        int summ=0;
        if (zapY!=tr[0].y)
            {
                for (int i=0;i<NumberTrunk;i++)
                    {
                        tr[i].y+=20;//опустить вниз на 20
                        if (tr[0].y>zapY) summ=tr[0].y-zapY; //если преувеличивает изначального значения то поднять повыше на summ
                        tr[i].y-=summ;
                    }
            }
        else RybTree=false; //снова не срубленно
    }
    int i=0;
    while (i<Qtr.length())
    {
        if (!Qtr[i].LeftRight) Qtr[i].x-=20; else Qtr[i].x+=30;
        Qtr[i].y=int (-(Qtr[i].x)*(Qtr[i].x)*20/(400*400)+20)+750;
        if (Qtr[i].x>800 || Qtr[i].x<0) Qtr.removeAt(i);
        else i++;
    }

}
