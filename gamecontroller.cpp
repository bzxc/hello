#include <QEvent>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <iostream>
#include "gamecontroller.h"
#include "worrier.h"
GameController::GameController(QGraphicsScene &scene, QObject *parent) :
    QObject(parent),
    scene(scene),
    worrier(new Worrier(*this))
{
    timer.start( 1000/33 );

    scene.addItem(worrier);
    scene.installEventFilter(this);

    resume();
}

void GameController::resume()
{
    connect(&timer, SIGNAL(timeout()),
            &scene, SLOT(advance()));
}

void GameController::handleMouseClicked(QMouseEvent *event)
{
    worrier->setXY(event->x(), event->y());
    std::cout << 2;

}


bool GameController::eventFilter(QObject *object, QEvent *event)
{

    if (event->type() == QEvent::MouseButtonPress)
    {
        qDebug("The Left2 Button Event!");
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if(mouseEvent->buttons() == Qt::LeftButton)
        {
            qDebug("The Left Button Event!");
            handleMouseClicked((QMouseEvent *)event);
        }
        return true;
    } else {
        return QObject::eventFilter(object, event);
    }
}

