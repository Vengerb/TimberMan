#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QPainter>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(650, 950);     // фиксируем окно, чтобы было проще с координатами
    timerPaint=new QTimer;
    connect(timerPaint,SIGNAL(timeout()),this,SLOT(Update()));
    timerPaint->setInterval(0.00000000005);
    timerPaint->start();
    timberman = new Timberman(980);
    tree=new Tree(650,980);
    repaint();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (!tree->getRybTree())
    {
        switch(event->key()){
            case (Qt::Key_Left):{
                cut_left();
                break;
            }
            case (Qt::Key_Right):{
                cut_right();
                break;
            }
        }
        ProvGameOver();
        tree->deleteTrunk();
        ProvGameOver();
        repaint();
    }
}

void MainWindow::cut_left()
{
    LeftORRight=true;
//    перемещаемся влево
//    QThread::msleep(100) здесь и далее - задержка в 100 мсек, чтобы действие было заметно
//    (можно еще уменьшить)
    timberman->setIm(QPixmap(":/images/drovosek1_lev.png"));
    timberman->setX(timberman->getIm().width()-indentTree);
    repaint();
    QThread::msleep(interval);

//    замахиваемся
    timberman->setIm(QPixmap(":/images/drovosek2_lev.png"));
    repaint();
    QThread::msleep(interval);

//    рубим
    timberman->setIm(QPixmap(":/images/drovosek3_lev.png"));
    repaint();
    QThread::msleep(interval);

//    исходное состояние
    timberman->setIm(QPixmap(":/images/drovosek1_lev.png"));
    repaint();

}

void MainWindow::cut_right()
{
    LeftORRight=false;
//    перемещаемся вправо
//    вычитаем 3 ширины картики(т.к пока она 110*110) т.е -330
    timberman->setIm(QPixmap(":/images/drovosek1_prav.png"));
    timberman->setX(MainWindow::size().width() - 3*timberman->getIm().width()+indentTree);
    repaint();
    QThread::msleep(interval);

//    замахиваемся
    timberman->setIm(QPixmap(":/images/drovosek2_prav.png"));
    repaint();
    QThread::msleep(interval);

//    рубим
    timberman->setIm(QPixmap(":/images/drovosek3_prav.png"));
    repaint();
    QThread::msleep(interval);

//    исходное положение
    timberman->setIm(QPixmap(":/images/drovosek1_prav.png"));
    repaint();

}

void MainWindow::paintEvent(QPaintEvent *event)
{
     QPainter p(this);
     p.drawPixmap(QRect(0,0,650,950),QPixmap(":/fon/Images/fon.png"));
     tree->picture(&p);
     timberman->draw(&p);
}

void MainWindow::ProvGameOver()
{
    switch(tree->getTypeTree(0))
    {
        case 1:
        {
            if (LeftORRight)
            {
                qDebug("game over  %d",++gameOver);
                timberman->setIm(QPixmap(":Rip/Images/rip_lev.png"));
            }
            break;
        }
        case 2:
        {
            if (!LeftORRight)
            {
                qDebug("game over  %d",++gameOver);
                timberman->setIm(QPixmap(":Rip/Images/rip_prav.png"));
            }
            break;
        }
    }
}

void MainWindow::Update()
{
    tree->DownTree();
    repaint();
}

