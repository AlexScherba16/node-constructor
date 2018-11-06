#include "textnode.h"
#include "textprimitive.h"
#include "textmodel.h"
#include <QStyleOptionGraphicsItem>
#include <QPainter>

TextNode::TextNode(NodeModel *model) : Node(model), _model(nullptr), _text(nullptr){
    setFlag(QGraphicsItem::ItemDoesntPropagateOpacityToChildren, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
//    setHandlesChildEvents(false);
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);

    setAcceptHoverEvents(true);

    if(model){
        _model = dynamic_cast<TextModel*>(model);
        _model->setNode(this);
    }
}

void TextNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Node::paint(painter,option,widget);
}

QVariant TextNode::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value){
    return QGraphicsItem::itemChange(change, value);
}

void TextNode::recalculatePrimitivesSize(){
    auto width  = geometry().width() - 2 * geometry().spacer();
    auto height = geometry().height() - 2 * geometry().spacer();

    _text->setWidth(width);
    _text->setHeight(height);

    return;
}

void TextNode::mousePressEvent(QGraphicsSceneMouseEvent *event){
    Node::mousePressEvent(event);
}

void TextNode::generateGui(){
    if(_text)
        return;

    auto x = geometry().spacer();
    auto y = geometry().spacer();

    _text = new TextPrimitive();
    _text->setText(_model->getText());
    _text->setPos(mapFromItem(this,x, y));
    addToGroup(_text);
    geometry().setMinimalSize(childrenBoundingRect().size());
}

void TextNode::updateNodeUi(){
    _text->setText(_model->getText());
    _text->update(_text->boundingRect());
}
