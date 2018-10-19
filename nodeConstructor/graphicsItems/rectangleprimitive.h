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


    QRectF boundingRect() const override;


protected:
    void
    paint(QPainter*                       painter,
          QStyleOptionGraphicsItem const* option,
          QWidget*                        widget = 0) override;

    QVariant
    itemChange(GraphicsItemChange change, const QVariant &value) override;

};

#endif // RECTANGLEPRIMITIVE_H
