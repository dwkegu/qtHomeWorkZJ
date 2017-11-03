#ifndef T1VIEW_H
#define T1VIEW_H
#include <QWidget>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGraphicsView>
#include <QPoint>
#include <QGraphicsScene>
#include "drawitem.h"

class t1View:public QWidget
{
    Q_OBJECT
public:
    t1View(QWidget *parent = 0);
    ~t1View();

public slots:
    void onSelectChanged(int position);

    void onTextChange1(QString arg);
    void onTextChange2(QString arg);
    void onTextChange3(QString arg);
    void onTextChange4(QString arg);
    void onBtnClick();

    void onCirclTextChanged1(QString arg);
    void onCirclTextChanged2(QString arg);
    void onCirclTextChanged3(QString arg);

    void onOvalTextChange1(QString arg);
    void onOvalTextChange2(QString arg);
    void onOvalTextChange3(QString arg);
    void onOvalTextChange4(QString arg);

private:
    int selectedFunc;
    //main layout
    QHBoxLayout *mainHLayout;

    //left spanner layout and widgets
    //
    QWidget *leftcontainer;
    QVBoxLayout *leftLayout;
    QComboBox * funcSelector;

    QPushButton *confirmBtn;
    //画直线
    QLabel *startXLabel;
    QLabel *startYLabel;
    QLineEdit *startXEdit;
    QLineEdit *startYEdit;
    QLabel *endXLabel;
    QLabel *endYLabel;
    QLineEdit *endXEdit;
    QLineEdit *endYEdit;
    QPoint pointStart;
    QPoint pointEnd;

    //画圆
    QLabel *circleCenterLabel;
    QLabel *circleRadiusLabel;
    QLineEdit *circleCenterXEdit;
    QLineEdit *circleCenterYEdit;
    QLineEdit *circleRadiusEdit;
    QPoint circleCenterPoint;
    int circleRadius;
    //画椭圆
    QLabel *ovalCenterLabel;
    QLabel *ovalLongerRadiusLabel;
    QLabel *ovalShorterRadiusLabel;
    QLineEdit *ovalCenterXEdit;
    QLineEdit *ovalCenterYEdit;
    QLineEdit *ovalLongerRadiusEdit;
    QLineEdit *ovalShorterRadiusEdit;
    QPoint ovalCenter;
    int ovalLongRadius;
    int ovalShortRadius;

    //right graph view
    QGraphicsView * graphView;
    QGraphicsScene* sence;
    DrawItem *drawItem;

    /**
     * @brief createFunc1 生成功能1的参数输入UI
     * @param parent 父布局
     * @param insertPosition 当前UI插入位置
     */
    void createFunc1(QBoxLayout *parent, int insertPosition);

    void createFunc2(QBoxLayout *parent, int insertPosition);

    void createFunc3(QBoxLayout *parent, int insertPosition);

};

#endif // T1VIEW_H
