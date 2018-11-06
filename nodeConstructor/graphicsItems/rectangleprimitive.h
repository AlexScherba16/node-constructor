#ifndef RECTANGLEPRIMITIVE_H
#define RECTANGLEPRIMITIVE_H

#include "graphicprimitive.h"
class RectanglePrimitive : public GraphicPrimitive
{
    Q_OBJECT
private:


public:
    RectanglePrimitive();
    ~RectanglePrimitive();

protected:
    void
    paint(QPainter*                       painter,
          QStyleOptionGraphicsItem const* option,
          QWidget*                        widget = 0) override;

    QVariant
    itemChange(GraphicsItemChange change, const QVariant &value) override;

//    void mousePressEvent(QGraphicsSceneMouseEvent *event)       override;

};

#endif // RECTANGLEPRIMITIVE_H
