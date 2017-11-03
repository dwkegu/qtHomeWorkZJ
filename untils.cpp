#include "untils.h"
#include <iostream>
#include <math.h>

int drawLine(QPoint start, QPoint end, QPoint* &result){
    int pointsCount = 0;
    if(abs(start.x()-end.x())>abs(start.y()-end.y())){
        //x轴大
        pointsCount = abs(start.x()-end.x())+1;
        int xstep = (start.x()-end.x())/abs(start.x()-end.x());
        double ystep = (start.y()-end.y())/(double)pointsCount;
        result = new QPoint[pointsCount];
        for(int i = 0; i <= abs(start.x()-end.x()); i++){
            result[i].setX(end.x()+i*xstep);
            result[i].setY(int(end.y()+i*ystep));
        }
    }else{
        //y轴大或者相同
        //相同点
        if(abs(start.x()-end.x())==abs(start.y()-end.y())&&abs(start.y()-end.y())==0){
            pointsCount = 1;
            result = new QPoint[1];
            result[0].setX(start.x());
            result[0].setY(start.y());
            return pointsCount;
        }
        //不同点
        pointsCount = abs(start.y()-end.y())+1;
        int ystep = (start.y()-end.y())/abs(start.y()-end.y());
        double xstep = (start.x()-end.x())/(double)pointsCount;
        result = new QPoint[pointsCount];
        for(int i = 0; i <= abs(start.y()-end.y()); i++){
            result[i].setX(int(end.x()+i*xstep));
            result[i].setY(end.y()+i*ystep);
        }
    }
    return pointsCount;
}

int drawCircle(QPoint center, int radius, QPoint* &result){
    //todo 绘制圆
    return 0;
}

int drawOval(QPoint center, int longRadius, int shortRadius, QPoint *&result){
    //todo 绘制椭圆
    return 0;
}

