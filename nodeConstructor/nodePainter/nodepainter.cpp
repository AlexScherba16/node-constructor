#include "nodepainter.h"
#include <QStyleOptionGraphicsItem>
#include "node/node.h"

void NodePainter::paintNode(QPainter *painter, const QStyleOptionGraphicsItem *option, const Node& node){
    if(node.isSelected()){
        drawSelectedNode(painter, option, node);
    }
}

void NodePainter::drawSelectedNode(QPainter *painter, const QStyleOptionGraphicsItem *option, const Node &node)
{
    auto color = QColor(Qt::darkCyan); //QColor(255, 165, 0) : QColor(Qt::darkCyan); //QColor(255, 255, 255);
    QPen pen(painter->pen());

    pen.setWidth(1);
    pen.setStyle(Qt::SolidLine);
    pen.setColor(color);//QColor(Qt::darkCyan));

    painter->setBrush(Qt::SolidPattern);
    painter->setClipRect(option->exposedRect);
    painter->setPen(pen);
    painter->drawRects(node.geometry().getResizeRects());


//    pen.setColor(QColor(255, 165, 0));
//    painter->setPen(pen);
//    painter->setBrush(Qt::NoBrush);
//    painter->drawRect(node.boundingRect());
}
