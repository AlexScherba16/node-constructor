#ifndef ACTIONNODE_H
#define ACTIONNODE_H

#include <QGraphicsObject>
#include <graphicprimitive.h>
//#include <QGraphicsItemGroup>
#include "node/node.h"


class ActionNodeModel;
class NodeModel;

class RectanglePrimitive;
class TextPrimitive;

class ActionNode : public Node//QGraphicsItemGroup
{

public:
    ActionNode(NodeModel* model );
    ~ActionNode() = default;

    QRectF boundingRect() const override;

    void generateGui();
    void updateNodeUi();
protected:
    void
    paint(QPainter*                       painter,
          QStyleOptionGraphicsItem const* option,
          QWidget*                        widget = 0) override;

    QVariant
    itemChange(GraphicsItemChange change, const QVariant &value) override;

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;

private:
    QVector<GraphicPrimitive*>  _vectPrimitive;
    ActionNodeModel*            _model;

    RectanglePrimitive *indexPr;
    RectanglePrimitive *namePr ;
    RectanglePrimitive *delayPr;
    RectanglePrimitive *condition;
//    RectanglePrimitive *uncondition = new RectanglePrimitive();
    TextPrimitive *uncondition;




};

#endif // ACTIONNODE_H
