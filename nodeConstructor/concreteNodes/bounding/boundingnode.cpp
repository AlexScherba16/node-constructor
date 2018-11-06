#include "boundingnode.h"
#include "boundingmodel.h"
#include "textprimitive.h"

#include <QGraphicsSceneDragDropEvent>
#include "nodeDelegate/BoundingNodeDelegate/boundingnodedelegate.h"

BoundingNode::BoundingNode(NodeModel* model) :  Node(model),
                                                _model(nullptr),
                                                _boundingText(nullptr)
{
    setFlag(QGraphicsItem::ItemDoesntPropagateOpacityToChildren, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);

//    setHandlesChildEvents(false);
//    setAcceptTouchEvents(bool enabled);

    setAcceptHoverEvents(true);
    if(model){
        _model = dynamic_cast<BoundingModel*>(model);
        _model->setNode(this);
    }
}

void BoundingNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(painter->pen());
    pen.setStyle(Qt::SolidLine);
    pen.setColor(QColor(Qt::green));
    pen.setWidth(5);

    painter->setClipRect(option->exposedRect);
    painter->setPen(pen);
    painter->drawRect(geometry().nodeBoundingRect());

    Node::paint(painter,option, widget);
}

QVariant BoundingNode::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if((change == ItemChildAddedChange) && childItems().size() > 1){
        setHandlesChildEvents(false);
        qDebug() << "____BOOUNDING_ADD_ITEM____";
    }

    else if(change == ItemChildRemovedChange){
        qDebug() << "____BOOUNDING_REMOVE_ITEM____";
        if(childItems().size() == 1){
            qDebug() << "~~~~~~~~~~~~~~~~ EMPTY_BOUNDING ~~~~~~~~~~~~~~~~";
            setHandlesChildEvents(true);
        }
    }
    return QGraphicsItem::itemChange(change, value);
}

void BoundingNode::recalculatePrimitivesSize(){
    auto width  = geometry().width() - 2 * geometry().spacer();
    _boundingText->setWidth(width);
    return;
}

void BoundingNode::generateGui(){
    if(_boundingText)
        return;

    auto x = geometry().spacer();
    auto y = geometry().spacer();

    _boundingText = new TextPrimitive();
    _boundingText->setText(_model->getBoundingText());

    _boundingText->setWidth(200);   _boundingText->setHeight(50);
    _boundingText->setPos(mapFromItem(this, x, y));

    addToGroup(_boundingText);
    geometry().setMinimalSize(childrenBoundingRect().size());
    return;
}

void BoundingNode::updateNodeUi(){
    _boundingText->setText(_model->getBoundingText());
    _boundingText->update(_boundingText->boundingRect());
    return;
}

void BoundingNode::invokeNodeDelegate(){
    BoundingNodeDelegate delegate(_model);
    if(delegate.exec())
        updateNodeUi();
}
