#ifndef TEXTPRIMITIVE_H
#define TEXTPRIMITIVE_H

#include "graphicprimitive.h"
class TextPrimitive : public GraphicPrimitive
{
    Q_OBJECT
private:
    int _widht;
    int _height;

    QString     _text;

public:
    TextPrimitive();
    ~TextPrimitive();

    void setWidth(int v) { _widht = v; }
    void setHeight(int v){ _height = v;}

    void setText(const QString& newText);
    QString getText();

    QRectF boundingRect() const override;

protected:
    void
    paint(QPainter*                       painter,
          QStyleOptionGraphicsItem const* option,
          QWidget*                        widget = 0) override;

    QVariant
    itemChange(GraphicsItemChange change, const QVariant &value) override;

//    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // TEXTPRIMITIVE_H
