#ifndef ACTIONNODE_H
#define ACTIONNODE_H

#include <QGraphicsObject>
#include <graphicprimitive.h>
#include "node/node.h"


class ActionNodeModel;
class NodeModel;

class RectanglePrimitive;
class TextPrimitive;
class FramedTextPrimitive;

class ActionNode : public Node
{

public:
    ActionNode(NodeModel* model );
    ~ActionNode() = default;

    void generateGui();
    void updateNodeUi();
    void invokeNodeDelegate();

protected:
    void
    paint(QPainter*                       painter,
          QStyleOptionGraphicsItem const* option,
          QWidget*                        widget = 0) override;

    QVariant
    itemChange(GraphicsItemChange change, const QVariant &value) override;

    void recalculatePrimitivesSize()    override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)     override;

private:
    ActionNodeModel*            _model;

    FramedTextPrimitive *indexPr;
    FramedTextPrimitive *namePr ;
    FramedTextPrimitive *delayPr;
    RectanglePrimitive  *condition;
    FramedTextPrimitive *uncondition;
};

#endif // ACTIONNODE_H
