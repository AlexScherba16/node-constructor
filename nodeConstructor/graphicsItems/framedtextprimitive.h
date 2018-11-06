#ifndef FRAMEDTEXTPRIMITIVE_H
#define FRAMEDTEXTPRIMITIVE_H

#include "graphicprimitive.h"
class FramedTextPrimitive : public GraphicPrimitive
{
    Q_OBJECT
private:
    QString     _text;

public:
    FramedTextPrimitive();
    ~FramedTextPrimitive() {}

    void setText(const QString& newText)        {_text = newText;}
    QString getText()                           {return _text;}

protected:
    void
    paint(QPainter*                       painter,
          QStyleOptionGraphicsItem const* option,
          QWidget*                        widget = 0) override;

//    QVariant
//    itemChange(GraphicsItemChange change, const QVariant &value) override;

};

#endif // FRAMEDTEXTPRIMITIVE_H
