#include "node.h"

Node* Node::isInsideBounding(const QList<QGraphicsItem *> itemsList){
    if(itemsList.isEmpty())
        return nullptr;

    auto begin = itemsList.constBegin();
    auto end = itemsList.constEnd();

    while(begin != end){
        if(((Node*)*begin)->nodeType() == BOUNDING_NODE)
            return ((Node*)*begin);
        ++begin;
    }
    return nullptr;
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event){
    update();
    QGraphicsItemGroup::mousePressEvent(event);
}

void Node::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
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
        QPointF diff = event->scenePos() - event->lastScenePos();
        moveBy(diff.x(), diff.y());
//        QGraphicsItemGroup::mouseMoveEvent(event);
    }
    QRectF r = scene()->sceneRect();
    r = r.united(mapToScene(boundingRect()).boundingRect());
    scene()->setSceneRect(r);
//    QGraphicsItemGroup::mouseMoveEvent(event);
}

void Node::hoverMoveEvent(QGraphicsSceneHoverEvent *event){
    bool resizeResult = false;
    if (geometry().resizeMarkersContainsMouse(event->pos()) && isSelected()){
        resizeResult = true;
        setCursor(QCursor(Qt::SizeFDiagCursor));
    }
    else
        setCursor(QCursor());

    state().setResizingState(resizeResult);
    QGraphicsItemGroup::hoverMoveEvent(event);
}

void Node::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
    invokeNodeDelegate();
    QGraphicsItemGroup::mouseDoubleClickEvent(event);
}



void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(widget);
    NodePainter::paintNode(painter, option, *this);
}
