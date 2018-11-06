#include "framedtextprimitive.h"
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QFontMetricsF>

FramedTextPrimitive::FramedTextPrimitive(){
    _widht = 100;
    _height = 20;

    setFlag(QGraphicsItem::ItemIsMovable,                   false);
    setFlag(QGraphicsItem::ItemIsFocusable,                 false);
    setFlag(QGraphicsItem::ItemIsSelectable,                false);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges,   false);
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);

}

void FramedTextPrimitive::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(widget);
    QPen p(Qt::black, 1);
    painter->setPen(p);
    painter->setClipRect(option->exposedRect);
    QLinearGradient gradient(QPointF(0.0, 0.0), QPointF(2.0, _height));
    gradient.setColorAt(0.0,  "white");
    gradient.setColorAt(0.13, QColor(80, 80, 80));
    gradient.setColorAt(0.97, QColor(64, 64, 64));
    gradient.setColorAt(1.0,  QColor(58, 58, 58));

    painter->setBrush(gradient);
    painter->drawRect(boundingRect());


    QFont font("times", 15);
    QFontMetrics metrics (font);

    auto textRect = metrics.boundingRect(_text);

    painter->setPen(QPen(Qt::white, 3));

    QPointF frameCenter = boundingRect().center();
    textRect.moveCenter(frameCenter.toPoint());
    painter->drawText(textRect, Qt::AlignCenter, _text);
}
