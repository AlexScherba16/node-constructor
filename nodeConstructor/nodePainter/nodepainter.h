#ifndef NODEPAINTER_H
#define NODEPAINTER_H

#include <QtGui/QPainter>

class Node;
class QStyleOptionGraphicsItem;
class NodePainter
{
public:
    NodePainter() = default;

    static void paintNode(QPainter* painter, const QStyleOptionGraphicsItem *option,   const Node &node);
    static void drawSelectedNode(QPainter* painter, const QStyleOptionGraphicsItem *option,   const Node &node);
};

#endif // NODEPAINTER_H
