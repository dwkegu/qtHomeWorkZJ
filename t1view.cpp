#include "t1view.h"
#include "constant.h"
#include <iostream>

t1View::t1View(QWidget *parent):
    QWidget(parent)
{
    mainHLayout = new QHBoxLayout();
    mainHLayout->setMargin(0);
    selectedFunc = 0;
    leftcontainer = new QWidget();
    leftLayout = new QVBoxLayout();
    leftLayout->setMargin(0);
    leftcontainer->setStyleSheet("background-color:#efefef");
    leftcontainer->setMinimumWidth(240);
    leftcontainer->setMinimumHeight(400);
    QSizePolicy leftPolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    leftPolicy.setHorizontalStretch(1);
    leftcontainer->setSizePolicy(leftPolicy);
    //垂直布局
    leftLayout = new QVBoxLayout();
    createFunc1(leftLayout,1);
    createFunc2(leftLayout,2);
    createFunc3(leftLayout,3);
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

t1View::~t1View(){

}


void t1View::createFunc1(QBoxLayout *parent, int insertPosition){
    std::cout<<"createFunc1"<< std::endl;
    QVBoxLayout *itemLayout1 = new QVBoxLayout;
    itemLayout1->setContentsMargins(0,0,0,0);
    itemLayout1->setMargin(0);
    //功能选择
    funcSelector = new QComboBox();
    funcSelector->setStyleSheet("background-color:white;alignment:center");
    //添加功能选择内容
    QStringList *list = new QStringList();
    for(int i = 0; i < 4; i++){
        list->append(LINESFUNCS[i]);
    }
    funcSelector->addItems(*list);
    //设置当前选择的内容
    funcSelector->setCurrentIndex(selectedFunc);
    delete list;
    itemLayout1->addWidget(funcSelector);
    //整个view的容器1
    startXLabel = new QLabel(tr("起点x坐标:"));
    startYLabel = new QLabel(tr("起点y坐标:"));
    startXEdit = new QLineEdit();
    startXEdit->setMinimumWidth(40);
    startXEdit->setStyleSheet("background:white");
    connect(startXEdit,SIGNAL(textChanged(QString)),this,SLOT(onTextChange1(QString)));
    startYEdit = new QLineEdit();
    startYEdit->setMinimumWidth(40);
    startYEdit->setStyleSheet("background:white");
    connect(startYEdit,SIGNAL(textChanged(QString)),this,SLOT(onTextChange2(QString)));
    endXLabel = new QLabel("终点x坐标:");
    endYLabel = new QLabel("终点y坐标:");
    endXEdit = new QLineEdit();
    endXEdit->setMinimumWidth(40);
    endXEdit->setStyleSheet("background:white");
    connect(endXEdit,SIGNAL(textChanged(QString)),this,SLOT(onTextChange3(QString)));
    endYEdit = new QLineEdit();
    endYEdit->setMinimumWidth(40);
    endYEdit->setStyleSheet("background:white");
    connect(endYEdit,SIGNAL(textChanged(QString)),this,SLOT(onTextChange4(QString)));
    //起点位置容器
    QHBoxLayout *startHLayout = new QHBoxLayout;
    startHLayout->setContentsMargins(0,0,0,0);
    startHLayout->setAlignment(Qt::AlignHCenter);
    //终点位置容器
    QHBoxLayout *endHLayout = new QHBoxLayout;
    endHLayout->setContentsMargins(0,0,0,0);
    endHLayout->setAlignment(Qt::AlignHCenter);

    startHLayout->addWidget(startXLabel);
    startHLayout->addWidget(startXEdit);
    startHLayout->addWidget(startYLabel);
    startHLayout->addWidget(startYEdit);

    endHLayout->addWidget(endXLabel);
    endHLayout->addWidget(endXEdit);
    endHLayout->addWidget(endYLabel);
    endHLayout->addWidget(endYEdit);
    itemLayout1->addLayout(startHLayout);
    itemLayout1->addLayout(endHLayout);
    parent->addLayout(itemLayout1);
}

void t1View::createFunc2(QBoxLayout *parent, int insertPosition){
    circleCenterLabel = new QLabel("圆心坐标(x,y):");
    circleRadiusLabel = new QLabel("圆半径:");
    circleCenterXEdit = new QLineEdit();
    circleCenterXEdit->setMinimumWidth(40);
    circleCenterXEdit->setStyleSheet("background:white");
    circleCenterYEdit = new QLineEdit();
    circleCenterYEdit->setMinimumWidth(40);
    circleCenterYEdit->setStyleSheet("background:white");
    circleRadiusEdit = new QLineEdit();
    circleRadiusEdit->setMinimumWidth(40);
    circleRadiusEdit->setStyleSheet("background:white");
    QVBoxLayout *itemLayout = new QVBoxLayout();
    QHBoxLayout *row1 = new QHBoxLayout();
    row1->addWidget(circleCenterLabel);
    row1->addWidget(circleCenterXEdit);
    row1->addWidget(circleCenterYEdit);
    QHBoxLayout *row2 = new QHBoxLayout();
    row2->addWidget(circleRadiusLabel);
    row2->addWidget(circleRadiusEdit);
    itemLayout->addLayout(row1);
    itemLayout->addLayout(row2);
    parent->addLayout(itemLayout);
}

void t1View::createFunc3(QBoxLayout *parent, int insertPosition){
    ovalCenterLabel = new QLabel("椭圆心坐标(x,y):");
    ovalLongerRadiusLabel = new QLabel("长半轴:");
    ovalShorterRadiusLabel = new QLabel("短半轴:");
    ovalCenterXEdit = new QLineEdit();
    ovalCenterXEdit->setMinimumWidth(40);
    ovalCenterXEdit->setStyleSheet("background:white");
    ovalCenterYEdit = new QLineEdit();
    ovalCenterYEdit->setMinimumWidth(40);
    ovalCenterYEdit->setStyleSheet("background:white");
    ovalLongerRadiusEdit = new QLineEdit();
    ovalLongerRadiusEdit->setMinimumWidth(40);
    ovalLongerRadiusEdit->setStyleSheet("background:white");
    ovalShorterRadiusEdit = new QLineEdit();
    ovalShorterRadiusEdit->setMinimumWidth(40);
    ovalShorterRadiusEdit->setStyleSheet("background:white");
    QVBoxLayout *itemLayout = new QVBoxLayout();
    QHBoxLayout *row1 = new QHBoxLayout();
    row1->addWidget(ovalCenterLabel);
    row1->addWidget(ovalCenterXEdit);
    row1->addWidget(ovalCenterYEdit);
    QHBoxLayout *row2 = new QHBoxLayout();
    row2->addWidget(ovalLongerRadiusLabel);
    row2->addWidget(ovalLongerRadiusEdit);
    row2->addWidget(ovalShorterRadiusLabel);
    row2->addWidget(ovalShorterRadiusEdit);
    itemLayout->addLayout(row1);
    itemLayout->addLayout(row2);
    parent->addLayout(itemLayout);
}

void t1View::onTextChange1(QString arg){
    pointStart.setX(arg.toInt());
}
void t1View::onTextChange2(QString arg){
    pointStart.setY(arg.toInt());
}
void t1View::onTextChange3(QString arg){
    pointEnd.setX(arg.toInt());
}
void t1View::onTextChange4(QString arg){
    pointEnd.setY(arg.toInt());
}

void t1View::onBtnClick(){
    switch (selectedFunc) {
    case 0:
    drawItem->setLineParameter(pointStart,pointEnd);
        break;
    default:
        break;
    }

    drawItem->update();
}