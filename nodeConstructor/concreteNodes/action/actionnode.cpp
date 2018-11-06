#include "actionnode.h"
#include <rectangleprimitive.h>
#include "textprimitive.h"
#include "framedtextprimitive.h"

#include "actionnodemodel.h"
#include "nodeDelegate/ActionNodeDelegate/actionnodedelegate.h"

#include <QDebug>

ActionNode::ActionNode(NodeModel* model) :  Node(model),
                                            _model(nullptr),
                                            indexPr(nullptr),
                                            namePr(nullptr),
                                            delayPr(nullptr),
                                            condition(nullptr),
                                            uncondition(nullptr)
{
//    setFlag(QGraphicsItem::ItemDoesntPropagateOpacityToChildren, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);

//    setHandlesChilbdEvents(false);
    setAcceptHoverEvents(true);
    if(model){
        _model = dynamic_cast<ActionNodeModel*>(model);
        _model->setNode(this);
    }
}

void ActionNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Node::paint(painter,option,widget);
}

QVariant ActionNode::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value){
    return QGraphicsItem::itemChange(change, value);
}

void ActionNode::recalculatePrimitivesSize(){
    auto width  = geometry().width() - 2 * geometry().spacer();
    auto height = geometry().height() - 2 * geometry().spacer();

    namePr->setWidth(width - delayPr->getWidth());
    delayPr->setPos(mapFromItem(namePr,namePr->boundingRect().topRight()));

    condition->setWidth(width);
    condition->setHeight(height - (namePr->getHeight() + delayPr->getHeight() + uncondition->getHeight()));

    uncondition->setWidth(width);
    uncondition->setPos(mapFromItem(condition,condition->boundingRect().bottomLeft()));
    return;
}

void ActionNode::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    auto boundingNode = isInsideBounding(collidingItems(Qt::ContainsItemShape));

    if(parentItem() == nullptr){
        if(boundingNode){
            state().setInsideBoundingState(true);
            boundingNode->addToGroup(this);
        }
    }
    else{
        if(boundingNode == nullptr){
            ((Node*)parentItem())->removeFromGroup(this);
            state().setInsideBoundingState(false);
        }
    }
    Node::mouseReleaseEvent(event);
}

void ActionNode::generateGui(){

    if(indexPr && namePr && delayPr && condition && uncondition)
        return;

    auto x = geometry().spacer();
    auto y = geometry().spacer();

    indexPr     = new FramedTextPrimitive();
    namePr      = new FramedTextPrimitive();
    delayPr     = new FramedTextPrimitive();
    condition   = new RectanglePrimitive();
    uncondition = new FramedTextPrimitive();

    indexPr->setText(_model->getIndex());
    namePr->setText(_model->getName());
    uncondition->setText(_model->getUncondition());
    delayPr->setText(_model->getDelay());

    indexPr->setPos(mapFromItem(this,x, y));
    indexPr->setWidth(50);      indexPr->setHeight(30);
    y += indexPr->getHeight();

    namePr->setPos(mapFromItem(this, x,y));
    namePr->setWidth(150);      namePr->setHeight(30);
    x += namePr->getWidth();

    delayPr->setWidth(50);      delayPr->setHeight(30);
    delayPr->setPos(mapFromItem(this, x, y));
    y += delayPr->getHeight();
    x = geometry().spacer();

    condition->setWidth(200);   condition->setHeight(150);
    condition->setPos(mapFromItem(this, x, y));
    y += condition->getHeight();

    uncondition->setWidth(200);   uncondition->setHeight(50);
    uncondition->setPos(mapFromItem(this, x, y));

    addToGroup(indexPr);
    addToGroup(namePr);
    addToGroup(delayPr);
    addToGroup(condition);
    addToGroup(uncondition);
    geometry().setMinimalSize(childrenBoundingRect().size());
}

void ActionNode::updateNodeUi(){
    indexPr->setText(_model->getIndex());           indexPr->update(indexPr->boundingRect());
    namePr->setText(_model->getName());             namePr->update(namePr->boundingRect());
    delayPr->setText(_model->getDelay());           delayPr->update(delayPr->boundingRect());
    uncondition->setText(_model->getUncondition()); uncondition->update(uncondition->boundingRect());
}

void ActionNode::invokeNodeDelegate(){
    ActionNodeDelegate delegate(_model);
    if(delegate.exec())
        updateNodeUi();
}
