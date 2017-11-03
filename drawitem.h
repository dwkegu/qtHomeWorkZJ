#ifndef DRAWITEM_H
#define DRAWITEM_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPoint>

class DrawItem:public QGraphicsItem
{
public:
    DrawItem();
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    void setLineParameter(QPoint start, QPoint end);

//protected:
//    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
    int func;
    QPoint linePoint[2];
};



#endif // DRAWITEM_H
