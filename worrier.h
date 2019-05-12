#ifndef WORRIER_H
#define WORRIER_H

#include <QGraphicsItem>
#include <QRectF>
#include <constants.h>
#include <QPainter>

class GameController;

class Worrier : public QGraphicsItem
{
public:


    Worrier(GameController & controller, qreal x=0, qreal y=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QPainterPath shape() const;
    void move(qreal x, qreal y);
    void setXY(qreal, qreal);

protected:
    void advance(int step);

private:
    GameController &controller;
    qreal x_next;
    qreal y_next;
};


#endif // WORRIER_H
