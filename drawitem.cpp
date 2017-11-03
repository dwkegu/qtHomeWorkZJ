#include "drawitem.h"


DrawItem::DrawItem()
{
    func=0;
}
QRectF DrawItem::boundingRect() const{

    return QRectF(0, 0, 400, 400);
}

QPainterPath DrawItem::shape() const
{
    QPainterPath path;
    path.addRect(14, 14, 82, 42);
    return path;
}

void DrawItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget){
    /*
    switch (func) {
    case 0:
    painter->drawLine(linePoint[0].x(),linePoint[0].y(),linePoint[1].x(),linePoint[1].y());
        break;
    case 1:

        break;
    default:
        break;
    }
    */


}

void DrawItem::setLineParameter(QPoint start, QPoint end){
    linePoint[0] = start;
    linePoint[1] = end;
}
