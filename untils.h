#ifndef UNTILS_H
#define UNTILS_H
#include <QPoint>

/**
 * @brief drawLine 画直线
 * @param start 起点
 * @param end 终点
 * @param result    需要绘制的点，结果
 * @return  点的数量
 */
int drawLine(QPoint start, QPoint end, QPoint* &result);

#endif // UNTILS_H
