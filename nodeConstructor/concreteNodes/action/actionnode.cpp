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

#include <QGraphicsScene>

ActionNode::ActionNode(NodeModel* model) :  Node(model),
                                            _model(nullptr),
                                            indexPr(nullptr),
                                            namePr(nullptr),
                                            delayPr(nullptr),
                                            condition(nullptr),
                                            uncondition(nullptr)
{
    setFlag(QGraphicsItem::ItemDoesntPropagateOpacityToChildren, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
//    setHandlesChildEvents(false);
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);

    setAcceptHoverEvents(true);
    if(model){
        _model = dynamic_cast<ActionNodeModel*>(model);
        _model->setNode(this);
    }
}

QRectF ActionNode::boundingRect() const{
    return geometry().nodeBoundingRect();
}

void ActionNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(widget);

    if(!state().isResizing())
        return;

    QPen pen(painter->pen());
    pen.setStyle(Qt::SolidLine);
    pen.setColor(QColor(Qt::darkCyan));
    pen.setWidth(1);

    painter->setBrush(Qt::SolidPattern);
    painter->setClipRect(option->exposedRect);
    painter->setPen(pen);
    painter->drawRects(geometry().getResizeRects());
}

QVariant ActionNode::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value){
    return QGraphicsItem::itemChange(change, value);
}

void ActionNode::mousePressEvent(QGraphicsSceneMouseEvent *event){

    bool resizeState = (event->modifiers() & Qt::ShiftModifier) ? true : false;
    state().setResizingState(resizeState);
    update();
    Node::mousePressEvent(event);
}

void ActionNode::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(state().isResizing()){
        prepareGeometryChange();
        auto oldSize = QSize(geometry().width(), geometry().height());
        auto diff = event->pos() - event->lastPos();
        oldSize += QSize(diff.x(), diff.y());

        geometry().setWidth(oldSize.width());
        geometry().setHeight(oldSize.height());

        recalculatePrimitivesSize();
        geometry().recalculateSize();

        update();

        event->accept();
    }
    else{
        Node::mouseMoveEvent(event);
    }
    QRectF r = scene()->sceneRect();
    r = r.united(mapToScene(boundingRect()).boundingRect());
    scene()->setSceneRect(r);
}

void ActionNode::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
    Node::mouseDoubleClickEvent(event);
    //    _model->setUncondition("QUTWG");uncondition->setText(_model->getUncondition()); uncondition->update(uncondition->boundingRect());
}

void ActionNode::hoverMoveEvent(QGraphicsSceneHoverEvent *event){
    auto & geom = geometry();
    if (geom.resizeMarkersContainsMouse(event->pos()) && state().isResizing()){// .resizeRect().contains(QPoint(pos.x(), pos.y()))){
      setCursor(QCursor(Qt::SizeFDiagCursor));
    }
    else{
      setCursor(QCursor());
    }

    event->accept();
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

void ActionNode::generateGui(){

    if(indexPr && namePr && delayPr && condition && uncondition)
        return;

    auto x = geometry().spacer();
    auto y = geometry().spacer();

    indexPr = new RectanglePrimitive();
    namePr = new RectanglePrimitive();
    delayPr = new RectanglePrimitive();
    condition = new RectanglePrimitive();
    uncondition = new TextPrimitive();
    uncondition->setText(_model->getUncondition());

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
    uncondition->setText(_model->getUncondition());
    uncondition->update(uncondition->boundingRect());
}
