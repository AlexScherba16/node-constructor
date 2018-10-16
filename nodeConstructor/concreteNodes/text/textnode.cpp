#include "textnode.h"
#include "textprimitive.h"

TextNode::TextNode(NodeModel *model){
    setFlag(QGraphicsItem::ItemDoesntPropagateOpacityToChildren, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
//    setHandlesChildEvents(false);
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);

    setAcceptHoverEvents(true);

//    _model = dynamic_cast<TextModel*>(model);
//    _model->setNode(this);
}

QRectF TextNode::boundingRect() const{
    return childrenBoundingRect();
}

void TextNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

}

QVariant TextNode::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value){
    return QGraphicsItem::itemChange(change, value);
}

void TextNode::generateGui(){
     _text = new TextPrimitive();
//     _text->setText(_model->getText());
}

void TextNode::updateNodeUi(){
//    uncondition->setText(_model->getUncondition());
//    uncondition->update(uncondition->boundingRect());
}
