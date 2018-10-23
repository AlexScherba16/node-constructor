#include "textprimitive.h"
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QFontMetricsF>
#include <QDebug>

TextPrimitive::TextPrimitive() : _text("TEST_TEXT")
{
    _widht = 100;
    _height = 20;

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);

    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
}

TextPrimitive::~TextPrimitive(){}

void TextPrimitive::setText(const QString &newText){
    _text = newText;
}

QString TextPrimitive::getText(){
    return _text;
}

QRectF TextPrimitive::boundingRect() const{
    return QRectF(0,0, _widht, _height);
}

void TextPrimitive::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(widget);
    QPen p(Qt::black, 1);
    painter->setPen(p);
    painter->setClipRect(option->exposedRect);
    painter->drawRect(boundingRect());

    QFont font("times", 15);
    QFontMetrics metrics (font);

    auto textRect = metrics.boundingRect(_text);

    painter->setPen(QPen(Qt::magenta, 3));

    QPointF frameCenter = boundingRect().center();
    textRect.moveCenter(frameCenter.toPoint());
    painter->drawText(textRect, Qt::AlignCenter, _text);
}

QVariant TextPrimitive::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value){
//    qDebug() << "ITEM_CHANGE";

    return QGraphicsItem::itemChange(change, value);
}

//void TextPrimitive::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
//    qDebug() << "TEXT_PRIMITIVE_DOUBLE_CLICKED";
//}
