#ifndef NODE_H
#define NODE_H

//#include <QObject>
#include <QGraphicsItemGroup>

#include "state/state.h"
#include "geometry/geometry.h"
#include <QDebug>

class NodeModel;
class Node : public QGraphicsItemGroup
{
//    Q_OBJECT
public:
    Node() = delete;
    Node(NodeModel* model) : QGraphicsItemGroup(),
                            _nodeGeometry(Geometry()),
                            _nodeState(State())

    {
        Q_UNUSED(model);
        qDebug() << __PRETTY_FUNCTION__;

    }
    virtual ~Node() {}

    virtual void generateGui()  = 0;
    virtual void updateNodeUi() {}

    State& state() {return _nodeState;}
    const State& state() const {return _nodeState;}

    Geometry& geometry() {return _nodeGeometry;}
    const Geometry& geometry() const {return _nodeGeometry;}

protected:

    virtual void recalculatePrimitivesSize() = 0;

    Geometry            _nodeGeometry;
    State               _nodeState;

};

#endif // NODE_H
