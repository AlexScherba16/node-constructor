#include "rectangleprimitive.h"
#include <QDebug>
#include <QPainter>
#include <QPen>
#include <QStyleOptionGraphicsItem>


RectanglePrimitive::RectanglePrimitive(): _widht(100), _height(80)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);

    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
}

RectanglePrimitive::~RectanglePrimitive()
{

}

QRectF RectanglePrimitive::boundingRect() const{
    return QRectF(0,0, _widht, _height);
}

void RectanglePrimitive::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    QPen p(Qt::black, 5);
    painter->setPen(p);
    painter->setClipRect(option->exposedRect);
    painter->drawRoundedRect(boundingRect(), 5, 5);
}

QVariant RectanglePrimitive::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value){
    return QGraphicsItem::itemChange(change, value);
}
