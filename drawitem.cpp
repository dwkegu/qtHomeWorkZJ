#include "drawitem.h"
#include <iostream>

DrawItem::DrawItem()
{
    func=0;
    drawErea = NULL;
    pointsCount = 0;
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
    if(NULL!=drawErea){
        painter->drawPoints(drawErea, pointsCount);
    }

}

void DrawItem::setLineParameter(QPoint start, QPoint end){
    linePoint[0] = start;
    linePoint[1] = end;

}

void DrawItem::setDrawErea(QPoint *erea, int pointsCount){
    for(int i = 0; i < pointsCount; i++){
        std::cout<<erea[i].x()<< ","<< erea[i].y()<<std::endl;
    }
    if(this->drawErea){
        delete[] drawErea;
        this->pointsCount = 0;
        drawErea = NULL;
    }
    this->drawErea = erea;
    this->pointsCount = pointsCount;
    update();
}
