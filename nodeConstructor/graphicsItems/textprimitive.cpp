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

    QFont font("bold");
    QFontMetrics metrics (font);
    auto textRect = metrics.boundingRect(_text);

    painter->setPen(QPen(Qt::magenta, 5));
    double x = /*(double)_widht / 1.0 - */(double)textRect.width() / 1.0;
    double y = (double)_height / 2.0 - (double)textRect.height() / 2.0;

    QPointF textPos (x, y);
    painter->drawText(textPos, _text);
}

QVariant TextPrimitive::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value){
//    qDebug() << "ITEM_CHANGE";

    return QGraphicsItem::itemChange(change, value);
}

//void TextPrimitive::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
//    qDebug() << "TEXT_PRIMITIVE_DOUBLE_CLICKED";
//}
