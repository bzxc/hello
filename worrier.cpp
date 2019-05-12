#include "worrier.h"
#include <iostream>
Worrier::Worrier(GameController &gamecontrol, qreal x, qreal y):
    controller(gamecontrol)
{
    setPos(x, y);

}

QRectF Worrier::boundingRect() const
{
    return QRectF(-TILE_SIZE,    -TILE_SIZE,
                   TILE_SIZE * 2, TILE_SIZE * 2 );
}

void Worrier::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::green);

    painter->restore();
}

QPainterPath Worrier::shape() const
{
    QPainterPath p;
    p.addEllipse(this->x(), this->y(), TILE_SIZE, TILE_SIZE);
    return p;
}

void Worrier::move(qreal x1, qreal y1)
{
    if(x1<(this->x()+2*TILE_SIZE)&&x1>(this->x()-TILE_SIZE)&&y1<(this->y()+2*TILE_SIZE)&&y1>(this->y()-TILE_SIZE)){
        if(x1>(this->x()+TILE_SIZE)&&y1<this->y()+TILE_SIZE){
            this->setX(this->x()+TILE_SIZE);
        }
    }
}

void Worrier::advance(int step)
{
    if (!step) {
        return;
    }
    move(x_next, y_next);
    std::cout <<"1";
}
void Worrier::setXY(qreal x0, qreal y0)
{
    x_next = x0;
    y_next = y0;
}
