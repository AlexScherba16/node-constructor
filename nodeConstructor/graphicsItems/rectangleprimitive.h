#ifndef RECTANGLEPRIMITIVE_H
#define RECTANGLEPRIMITIVE_H

#include "graphicprimitive.h"
class RectanglePrimitive : public GraphicPrimitive
{
    Q_OBJECT
private:
    int _widht;
    int _height;

public:
    RectanglePrimitive();
    ~RectanglePrimitive();

    void setWidth(int v) { _widht = v; }
    void setHeight(int v){ _height = v;}

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
