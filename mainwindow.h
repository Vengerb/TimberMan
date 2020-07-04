#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <timberman.h>
#include <tree.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *event);
    void cut_left();
    void cut_right();
    void paintEvent(QPaintEvent *event);
    void ProvGameOver();

private:
    Ui::MainWindow *ui;
    Timberman *timberman;
    Tree *tree=nullptr;
    bool LeftORRight=true;
    int gameOver=0;
    const int interval=25;
    QTimer *timerPaint=nullptr;
    int indentTree=20; //отступ от дерева

private slots:
    void Update();
};
#endif // MAINWINDOW_H
