#ifndef NODEMODEL_H
#define NODEMODEL_H

#include <QObject>
class Node;


class NodeModel : public QObject
{
    Q_OBJECT
private:


public:
    NodeModel();
    virtual ~NodeModel();
    virtual void setNode(Node* node) {Q_UNUSED(node);}
    virtual void updateNode() {}

signals:

public slots:
};

#endif // NODEMODEL_H
