#ifndef TEXTPRIMITIVE_H
#define TEXTPRIMITIVE_H

#include "graphicprimitive.h"
class TextPrimitive : public GraphicPrimitive
{
    Q_OBJECT
private:
    QString     _text;

public:
    TextPrimitive();
    ~TextPrimitive();

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
