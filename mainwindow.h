#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <timberman.h>
#include <tree.h>
#include <QTimer>
#include <QFontDatabase>

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
    void paintEvent(QPaintEvent *event);
    void ProvGameOver();
    int id = QFontDatabase::addApplicationFont(":/Goudy Stout.ttf"); //путь к шрифту
    QString family = QFontDatabase::applicationFontFamilies(id).at(0); //имя шрифта
    QFont f_white = QFont(family, 25);  // QFont c вашим шрифтом
    QFont f_black = QFont (family, 30);  // QFont c вашим шрифтом


private:
    Ui::MainWindow *ui;
    Timberman *timberman;
    Tree *tree=nullptr;
    bool LeftORRight=true;
    int gameOver=0;
    const int interval=25;
    QTimer *timerPaint=nullptr;
    int indentTree=20; //отступ от дерева
    float timeRemaining = 650/2-650/4;
    int score = 0;

private slots:
    void Update();
};
#endif // MAINWINDOW_H
