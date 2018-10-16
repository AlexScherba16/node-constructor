#ifndef FRAMEDTEXTNODE_H
#define FRAMEDTEXTNODE_H

#include "node/node.h"
#include <graphicprimitive.h>

class TextModel;
class NodeModel;

class RectanglePrimitive;
class TextPrimitive;


class FramedTextNode : public Node
{
public:
    FramedTextNode(NodeModel* model );
    ~FramedTextNode() = default;

    QRectF boundingRect() const override;

    void generateGui();
    void updateNodeUi();

protected:
    void paint( QPainter* painter,
                QStyleOptionGraphicsItem const* option,
                QWidget*                        widget = 0) override;

    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
    TextModel*          _model;
    TextPrimitive*      _text;
};

#endif // FRAMEDTEXTNODE_H
