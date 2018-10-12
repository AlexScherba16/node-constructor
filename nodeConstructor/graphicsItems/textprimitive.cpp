#include "textprimitive.h"
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

#include <QDebug>

TextPrimitive::TextPrimitive() : _widht(100), _height(20), _text("TEST_TEXT")
{
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

QRectF TextPrimitive::boundingRect() const
{
    return QRectF(0,0, _widht, _height);
}

void TextPrimitive::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

//    qDebug() << _text;

    QPen p(Qt::magenta, 5);
    painter->setPen(p);
    painter->drawText(QPointF(0, _height), _text);
}

QVariant TextPrimitive::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value){
//    qDebug() << "ITEM_CHANGE";

    return QGraphicsItem::itemChange(change, value);
}

//void TextPrimitive::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
//    qDebug() << "TEXT_PRIMITIVE_DOUBLE_CLICKED";
//}
