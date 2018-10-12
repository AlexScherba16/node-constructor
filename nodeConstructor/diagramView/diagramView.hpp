#pragma once

#include <QtWidgets/QGraphicsView>

//#include "Export.hpp"

namespace QtNodes
{

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
    int pos;
    DiagramScenee* _scene;
};
}
