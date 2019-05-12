#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QTimer>

class QGraphicsScene;
class QMouseEvent;
class Worrier;
class GameController : public QObject //游戏控制
{
    Q_OBJECT
public:
    GameController(QGraphicsScene &scene, QObject *parent = 0);

signals:

public slots:
    //void pause();
    void resume();
    //void gameOver();


protected:
     bool eventFilter(QObject *object, QEvent *event);

private:
    void handleMouseClicked(QMouseEvent *event);
    QTimer timer;
    QGraphicsScene &scene;

    Worrier *worrier; //游戏主角
};

#endif // GAMECONTROLLER_H
