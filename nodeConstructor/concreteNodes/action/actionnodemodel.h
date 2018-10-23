#ifndef ACTIONNODEMODEL_H
#define ACTIONNODEMODEL_H

#include "nodeModel/nodemodel.h"


#include "concreteNodes/action/actionnode.h"

class  ActionNodeModel : public NodeModel
{
    Q_OBJECT
private:
//    Q_PROPERTY(QColor color MEMBER m_color NOTIFY colorChanged)

    QString _name;
    QString _delay;
    QString _uncondition;
    ActionNode* _node;

public:
    ActionNodeModel();
    ~ActionNodeModel();

    void setName(const QString& name)                   {_name = name;}
    void setDelay(const QString& delay)                 {_delay = delay;}
    void setUncondition(const QString& uncondition)     {_uncondition = uncondition;}

    QString getName()                                   {return _name;}
    QString getDelay()                                  {return _delay;}
    QString getUncondition()                            {return _uncondition;}

    void updateNode()                                   {_node->updateNodeUi();}
    void setNode(Node* node)                            {_node = dynamic_cast<ActionNode*> (node);}

signals:

public  slots:
};

#endif // ACTIONNODEMODEL_H
