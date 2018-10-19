#include "geometry.h"
#include <QPointF>
#include <QVector>
#include <QDebug>
#include <QGraphicsItem>
#include <QRectF>
#include "graphicprimitive.h"

#define RESIZE_RECT_SIZE        40U
#define OFFSET                  RESIZE_RECT_SIZE/2

Geometry::Geometry() : _spacer(RESIZE_RECT_SIZE),
                       _width(RESIZE_RECT_SIZE),
                       _height(RESIZE_RECT_SIZE),
                       _bottomRightResizeRect(QRectF(0,0,RESIZE_RECT_SIZE,RESIZE_RECT_SIZE))
{

}

bool Geometry::resizeMarkersContainsMouse(const QPointF &mousePosition){
    bool contains = false;

    if(_bottomRightResizeRect.contains(mousePosition)){
        contains = true;
    }
    return contains;
}

QRectF Geometry::nodeBoundingRect() const{
    return QRectF(0,0, _width, _height);
}

QVector<QRectF> Geometry::getResizeRects() const{
    QVector<QRectF> rectVector;
    rectVector << _bottomRightResizeRect;//_topLeftResizeRect << _topRightResizeRect << _bottomLeftResizeRect << _bottomRightResizeRect;
    return rectVector;
}

void Geometry::recalculateSize(){
    recalculateResizeRects();
}

void Geometry::setMinimalSize(const QSizeF &minimalSize){
    _minWidth = minimalSize.width() + 2 * _spacer;
    _minHeight = minimalSize.height() + 2 * _spacer;

    _width  = _minWidth;
    _height = _minHeight;
    recalculateResizeRects();
}

void Geometry::recalculateResizeRects(){
    auto rect = nodeBoundingRect();
    _bottomRightResizeRect.moveBottomRight(rect.bottomRight());
    return;
}
