#ifndef NODEMODEL_H
#define NODEMODEL_H

#include <QObject>
#include "stdutil.h"
#include "node/node.h"


class NodeModel : public QObject
{
    Q_OBJECT
private:

protected:
    Node* _node;

public:
    NodeModel() : QObject(), _node(nullptr)             {}
    virtual ~NodeModel()                                {}

    virtual void updateNode()                           {if(_node)  _node->updateNodeUi();}
    virtual void setNode(Node* node)                    {if(node) _node = node;}
    virtual QString getName()                           {return QString();}
    virtual std::unique_ptr<NodeModel> clone() const    {return nullptr;}//= 0;

signals:

public slots:
};

#endif // NODEMODEL_H
