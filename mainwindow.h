#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "constants.h"
#include "gamecontroller.h"
#include <QMainWindow>

class QGraphicsScene;
class QGraphicsView;

class GameController;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void adjustViewSize();

private:
    void initScene();
    void initSceneBackground();

    QGraphicsScene *scene;
    QGraphicsView *view;

    GameController *game;//游戏控制类
};

#endif // MAINWINDOW_H
