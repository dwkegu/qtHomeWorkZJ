#ifndef T2VIEW_H
#define T2VIEW_H
#include <QWidget>
#include <QString>
#include <QPoint>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsView>
#include "drawitem.h"

class t2View:public QWidget
{
public:
    t2View(QWidget* parent = 0);
    ~t2View();
public slots:
    void onBezierTextChanged1(QString arg);

private:
    QHBoxLayout* mainHLayout;
    QWidget* leftcontainer;
    QGraphicsView *graphView;
    QGraphicsScene *sence;
    QGraphicsItem *drawItem;
    QComboBox * selector;
    QPushButton *confirmBtn;
    int selectedFunc;

    QPoint BezierPoints[3];
    QLabel *point1Label;
    QLabel *point2Label;
    QLabel *point3Label;
    QLineEdit *point1XEdit;
    QLineEdit *point1YEdit;
    QLineEdit *point2XEdit;
    QLineEdit *point2YEdit;
    QLineEdit *point3XEdit;
    QLineEdit *point3YEdit;
};

#endif // T2VIEW_H
