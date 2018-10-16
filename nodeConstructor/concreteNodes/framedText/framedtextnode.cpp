#include "framedtextnode.h"
#include "textprimitive.h"
#include "concreteNodes/text/textmodel.h"
#include <QStyleOptionGraphicsItem>
#include <QPainter>



FramedTextNode::FramedTextNode(NodeModel *model) : _model(nullptr), _text(nullptr){
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
        _model->setText("FRAMED");
        _model->setNode(this);
    }
}

QRectF FramedTextNode::boundingRect() const{
    return childrenBoundingRect();
}

void FramedTextNode::generateGui(){
    if(_text)
        return;

    _text = new TextPrimitive();
    _text->setText(_model->getText());
    _text->setPos(mapFromItem(this,0,0));
    addToGroup(_text);
}

void FramedTextNode::updateNodeUi(){
    _text->setText(_model->getText());
    _text->update(_text->boundingRect());
}

void FramedTextNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(widget);
    QPen pen(painter->pen());
    pen.setStyle(Qt::DashLine);
    pen.setColor(QColor(Qt::green));

    painter->setClipRect(option->exposedRect);
    painter->setPen(pen);
    painter->drawRoundedRect(boundingRect(), 10, 10);
}

QVariant FramedTextNode::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value){
    return QGraphicsItem::itemChange(change, value);
}
