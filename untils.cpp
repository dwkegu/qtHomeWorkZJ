#include "untils.h"
#include <iostream>

void clearLayout(QHBoxLayout *layout,const int position){
    QLayoutItem *item;
    std::cout<<layout->count()<<std::endl;
    if(position>=0){
        if((item = layout->takeAt(position))!=0) {
//            if (item->layout()) {
//                clearLayout(item->layout(), -1);
//                delete item->layout();
//            }
//            if (item->widget()) {
//                delete item->widget();
//            }
            delete item;
        }
    }else{
        while((item = layout->takeAt(0))!=0) {
//            if (item->layout()) {
//                clearLayout(item->layout(), 0);
//                delete item->layout();
//            }
//            if (!item->isEmpty()&&item->widget()!=0) {
//                delete item->widget();
//            }
            delete item;
        }
    }
}

