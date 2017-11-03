#include "mainwindow.h"
#include "constant.h"
#include<QPainter>
#include<QPushButton>
#include<QBoxLayout>
#include<QLayout>
#include<QLabel>
#include<QLayout>
#include<QStringList>
#include<QTextStream>
#include"untils.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{

    tabview = new QTabWidget;
    t1 = new t1View();
    tabview->addTab(t1, "图元生成");
    t2 = new t2View();
    tabview->addTab(t2, "样条曲线生成");
    t3 = new t3View();
    tabview->addTab(t3, "分形图形生成");
    QVBoxLayout* layou = new QVBoxLayout();
    layou->addWidget(tabview);
    setLayout(layou);
}



MainWindow::~MainWindow()
{
}

