#ifndef GRAPHICPRIMITIVE_H
#define GRAPHICPRIMITIVE_H

#include<QGraphicsObject>
#include <QPoint>

class GraphicPrimitive : public QGraphicsObject
{
    Q_OBJECT
private:

protected:
    unsigned int _widht;
    unsigned int _height;

public:
    GraphicPrimitive() = default;
    virtual ~GraphicPrimitive() {}

    void            setWidth(unsigned int widht)    {_widht = widht;}
    void            setHeight(unsigned int height)  {_height = height;}
    unsigned int    getWidth()  {return _widht;}
    unsigned int    getHeight() {return _height;}

};

#endif // GRAPHICPRIMITIVE_H
