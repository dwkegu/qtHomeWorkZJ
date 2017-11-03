#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <iostream>
#include <string>
#include <QSplitter>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QTextEdit>
#include <QComboBox>
#include <QHBoxLayout>
#include <QBoxLayout>
#include <QLayout>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMap>
#include <QTabWidget>
#include "t1view.h"
#include "t2view.h"
#include "t3view.h"
//namespace Ui {
//class MainWindow;
//}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
//    Ui::MainWindow *ui;
    QTabWidget *tabview;
    t1View *t1;
    t2View *t2;
    t3View *t3;
    int selectedFunc;

};

#endif // MAINWINDOW_H
