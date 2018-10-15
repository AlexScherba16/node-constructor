#include "actionnode.h"

#include <rectangleprimitive.h>
#include "textprimitive.h"

#include <QPainter>
#include <QPen>
#include <QStyleOptionGraphicsItem>
#include "actionnodemodel.h"

#include <QGraphicsSceneMouseEvent>
#include "nodeModel/nodemodel.h"
#include <QDebug>


#define ITEM_TEST

ActionNode::ActionNode(NodeModel* model)
{
    setFlag(QGraphicsItem::ItemDoesntPropagateOpacityToChildren, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
//    setHandlesChildEvents(false);
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);

    setAcceptHoverEvents(true);

    _model = dynamic_cast<ActionNodeModel*>(model);
    _model->setNode(this);
}

QRectF ActionNode::boundingRect() const{
    return childrenBoundingRect();
//    return QRectF(0,0, 200, 350);
}

void ActionNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    Q_UNUSED(widget);

    QPen pen(painter->pen());
    pen.setStyle(Qt::DashLine);
    pen.setColor(QColor(Qt::green));

    painter->setClipRect(option->exposedRect);
    painter->setPen(pen);
//    painter->setBrush(Qt::SolidPattern);
    painter->drawRoundedRect(boundingRect(), 10, 10);

}


QVariant ActionNode::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    return QGraphicsItem::itemChange(change, value);
}

void ActionNode::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
    Q_UNUSED(event)
    _model->setUncondition("QUTWG");
    uncondition->setText(_model->getUncondition());
    uncondition->update(uncondition->boundingRect());
}

void ActionNode::generateGui(){

    indexPr = new RectanglePrimitive();
    namePr = new RectanglePrimitive();
    delayPr = new RectanglePrimitive();
    condition = new RectanglePrimitive();
//    RectanglePrimitive *uncondition = new RectanglePrimitive();
    uncondition = new TextPrimitive();

    uncondition->setText(_model->getUncondition());

    indexPr->setWidth(50);      indexPr->setHeight(50);
    namePr->setWidth(150);      namePr->setHeight(50);
    delayPr->setWidth(50);      delayPr->setHeight(50);
    condition->setWidth(200);   condition->setHeight(200);
    indexPr->setWidth(200);     indexPr->setHeight(50);

#ifdef ITEM_TEST
    indexPr->setPos(mapFromItem(this,0,0));
    namePr->setPos(mapFromItem(this, 0,50));
    delayPr->setPos(mapFromItem(this, 150,50));
    condition->setPos(mapFromItem(this, 0,100));
    uncondition->setPos(mapFromItem(this, 0,300));
#else
    indexPr->setPos(0,0);
    namePr->setPos(0,50);
    delayPr->setPos(150,50);
    condition->setPos(0,100);
    uncondition->setPos(0,300);
#endif

    addToGroup(indexPr);
    addToGroup(namePr);
    addToGroup(delayPr);
    addToGroup(condition);
    addToGroup(uncondition);

    qDebug() << __PRETTY_FUNCTION__;


//    _vectPrimitive.append((GraphicPrimitive*)indexPr);
//    _vectPrimitive.append((GraphicPrimitive*)namePr);
//    _vectPrimitive.append((GraphicPrimitive*)delayPr);
//    _vectPrimitive.append((GraphicPrimitive*)condition );
//    _vectPrimitive.append((GraphicPrimitive*)uncondition);
}

void ActionNode::updateNodeUi(){
    uncondition->setText(_model->getUncondition());
    uncondition->update(uncondition->boundingRect());

//    _model->getDelay();
//    _model->getName();
}
