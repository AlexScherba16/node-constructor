#ifndef NODE_H
#define NODE_H

//#include <QObject>
#include <QGraphicsItemGroup>


class NodeModel;
class Node : public QGraphicsItemGroup
{
//    Q_OBJECT
public:
    Node() {}
    Node(NodeModel* model) {Q_UNUSED(model)}
    virtual ~Node() {}

    virtual void generateGui()  {}
    virtual void updateNodeUi() {}
protected:
};

#endif // NODE_H
