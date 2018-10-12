#ifndef GRAPHICPRIMITIVE_H
#define GRAPHICPRIMITIVE_H

#include<QGraphicsObject>
#include <QPoint>

class GraphicPrimitive : public QGraphicsObject
{
    Q_OBJECT
private:
    QPoint _position;

public:
    GraphicPrimitive() = default;
    virtual ~GraphicPrimitive() {}

    void setPosition(const QPoint &val){ _position = val; }
    QPoint getPosition(){ return _position; }

    virtual void setWidth(int) {}
    virtual void setHeight(int){}

};

#endif // GRAPHICPRIMITIVE_H
