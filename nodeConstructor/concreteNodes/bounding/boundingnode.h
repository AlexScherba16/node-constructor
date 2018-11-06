#ifndef BOUNDINGNODE_H
#define BOUNDINGNODE_H

#include <graphicprimitive.h>
#include "node/node.h"

class BoundingModel;
class TextPrimitive;

class BoundingNode : public Node
{
public:
    BoundingNode(NodeModel* model);
    ~BoundingNode() = default;

    void generateGui();
    void updateNodeUi();
    void invokeNodeDelegate() override;
    TNodeType nodeType() { return BOUNDING_NODE;}

protected:
    void
    paint(QPainter*                       painter,
          QStyleOptionGraphicsItem const* option,
          QWidget*                        widget = 0) override;

    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    void recalculatePrimitivesSize()    override;

//    void mousePressEvent(QGraphicsSceneMouseEvent *event)       override;
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event)        override;
//    void hoverMoveEvent(QGraphicsSceneHoverEvent* event) override;

private:
    BoundingModel*            _model;
    TextPrimitive*            _boundingText;
};

#endif // BOUNDINGNODE_H
