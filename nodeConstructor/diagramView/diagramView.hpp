#pragma once

#include <QtWidgets/QGraphicsView>

#include "nodeModel/nodemodel.h"                    //// TODO move to Registry
#include "concreteNodes/action/actionnode.h"
#include "concreteNodes/action/actionnodemodel.h"

#include "concreteNodes/text/textnode.h"
#include "concreteNodes/text/textmodel.h"

#include "concreteNodes/framedText/framedtextnode.h"

#include "concreteNodes/bounding/boundingmodel.h"
#include "concreteNodes/bounding/boundingnode.h"


class DiagramScenee;

class DiagramView : public QGraphicsView
{
public:
    DiagramView(DiagramScenee *scene);

public slots:
    void scaleUp();
    void scaleDown();

protected:

    void contextMenuEvent(QContextMenuEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

    void drawBackground(QPainter* painter, const QRectF& r) override;

    void showEvent(QShowEvent *event) override;

    void mouseMoveEvent(QMouseEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override;

private:
    DiagramScenee* _scene;


    ActionNodeModel*    _actionModel;
    BoundingModel*      _boundingModel;
    TextModel*          _textModel;
};
//}
