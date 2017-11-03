#include "t2view.h"

t2View::t2View(QWidget* parent):
    QWidget(parent)
{
    mainHLayout = new QHBoxLayout();
    mainHLayout->setMargin(0);
    selectedFunc = 0;
    leftcontainer = new QWidget();
    QVBoxLayout *leftLayout = new QVBoxLayout();
    leftLayout->setMargin(0);
    leftcontainer->setStyleSheet("background-color:#efefef");
    leftcontainer->setMinimumWidth(240);
    leftcontainer->setMinimumHeight(400);
    QSizePolicy leftPolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    leftPolicy.setHorizontalStretch(1);
    leftcontainer->setSizePolicy(leftPolicy);
    //垂直布局
    leftLayout = new QVBoxLayout();
//    createFunc1(leftLayout);
//    createFunc2(leftLayout);
//    createFunc3(leftLayout);
    confirmBtn = new QPushButton("绘图");
    connect(confirmBtn, SIGNAL(clicked(bool)),SLOT(onBtnClick()));
    leftLayout->addWidget(confirmBtn);
    leftcontainer->setLayout(leftLayout);
    mainHLayout->addWidget(leftcontainer);
    QSizePolicy rightPoliccy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    rightPoliccy.setHorizontalStretch(3);
    drawItem = new DrawItem;
    sence = new QGraphicsScene();
    sence->addItem(drawItem);
    graphView = new QGraphicsView(sence);
    graphView->setSizePolicy(rightPoliccy);
    graphView->setMinimumWidth(400);
    mainHLayout->addWidget(graphView);
    setLayout(mainHLayout);

}

t2View::~t2View(){

}
