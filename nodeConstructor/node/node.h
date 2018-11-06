#pragma once

/*
 *
{
  "FlowViewStyle": {
    "BackgroundColor": [53, 53, 53],
    "FineGridColor": [60, 60, 60],
    "CoarseGridColor": [25, 25, 25]
  },
  "NodeStyle": {
    "NormalBoundaryColor": [255, 255, 255],
    "SelectedBoundaryColor": [255, 165, 0],
    "GradientColor0": "gray",
    "GradientColor1": [80, 80, 80],
    "GradientColor2": [64, 64, 64],
    "GradientColor3": [58, 58, 58],
    "ShadowColor": [20, 20, 20],
    "FontColor" : "white",
    "FontColorFaded" : "gray",
    "ConnectionPointColor": [169, 169, 169],
    "FilledConnectionPointColor": "cyan",
    "ErrorColor": "red",
    "WarningColor": [128, 128, 0],

    "PenWidth": 1.0,
    "HoveredPenWidth": 1.5,

    "ConnectionPointDiameter": 8.0,

    "Opacity": 0.8
  },
  "ConnectionStyle": {
    "ConstructionColor": "gray",
    "NormalColor": "darkcyan",
    "SelectedColor": [100, 100, 100],
    "SelectedHaloColor": "orange",
    "HoveredColor": "lightcyan",

    "LineWidth": 3.0,
    "ConstructionLineWidth": 2.0,
    "PointDiameter": 10.0,

    "UseDataDefinedColors": false
  }
}
 *
 *
 */










//#include <QObject>
#include <QGraphicsItemGroup>
#include <QGraphicsSceneMouseEvent>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsScene>

#include "state/state.h"
#include "geometry/geometry.h"
#include <QDebug>
#include <QPen>
#include "stdutil.h"

#include "nodePainter/nodepainter.h"

typedef enum{
    DEFAULT_NODE = 0,
    BOUNDING_NODE,
}TNodeType;


class NodeModel;
class Node : public QGraphicsItemGroup
{
//    Q_OBJECT
public:
    Node() = delete;
//    Node(std::unique_ptr<NodeModel> && dataModel);
    Node(NodeModel* model) : QGraphicsItemGroup(),
                            _nodeModel(nullptr),
                            _nodeGeometry(Geometry()),
                            _nodeState(State())

    {
        Q_UNUSED(model);
    }
    virtual ~Node() {}

    virtual void generateGui()          = 0;
    virtual void invokeNodeDelegate()   = 0;
    virtual void updateNodeUi() {}

    State& state() {return _nodeState;}
    const State& state() const {return _nodeState;}

    Geometry& geometry() {return _nodeGeometry;}
    const Geometry& geometry() const {return _nodeGeometry;}

    QRectF boundingRect() const {return geometry().nodeBoundingRect();}
    virtual TNodeType nodeType() {return DEFAULT_NODE;}

//    bool contains(const QPointF &point) {} const override;

protected:

    Node *isInsideBounding(const QList<QGraphicsItem *> itemsList);

    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void hoverMoveEvent(QGraphicsSceneHoverEvent* event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

    void paint(QPainter*                       painter,
          QStyleOptionGraphicsItem const* option,
          QWidget*                        widget = 0) override;



    virtual void recalculatePrimitivesSize() = 0;

//    std::unique_ptr<NodeModel>  _nodeModel;
    NodeModel*                  _nodeModel;
    Geometry                    _nodeGeometry;
    State                       _nodeState;

};

