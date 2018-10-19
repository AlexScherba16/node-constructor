#ifndef GEOMETRY_H
#define GEOMETRY_H

class QPointF;
class QGraphicsItem;

#include <QRectF>
//#include <QGraphicsRectItem>

class Geometry
{
private:
//    QGraphicsRectItem _bottomRightResizeRect;
    QRectF  _bottomRightResizeRect;

    unsigned int _spacer;

    unsigned int _width;
    unsigned int _height;

    unsigned int _minWidth;
    unsigned int _minHeight;

    void recalculateResizeRects();

public:
    Geometry();

    bool resizeMarkersContainsMouse(const QPointF& mousePosition );

    QRectF nodeBoundingRect() const;
    QVector<QRectF> getResizeRects() const;


    void recalculateSize();

    unsigned int spacer() const {return _spacer;}
    unsigned int width()  const {return _width;}
    unsigned int height() const {return _height;}

    void setWidth(const unsigned int &width)    {_width = (width < _minWidth) ? _minWidth : width;}
    void setHeight(const unsigned int &height)  {_height = (height < _minHeight) ? _minHeight : height;}

    void setMinimalSize(const QSizeF &minimalSize );
};

#endif // GEOMETRY_H
