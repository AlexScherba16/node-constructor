#ifndef ACTIONNODEMODEL_H
#define ACTIONNODEMODEL_H

#include "nodeModel/nodemodel.h"

class  ActionNodeModel : public NodeModel
{
    Q_OBJECT
private:

    QString _index;
    QString _name;
    QString _delay;
    QString _uncondition;

public:
    ActionNodeModel() : NodeModel(), _index("1.1"), _name("Action"), _delay("100"), _uncondition("LONG_SUPER_MEGA_OPTIMAL_TEXT"){}
    ~ActionNodeModel() {}

    void setIndex(const QString& index)                 {_index = index;}
    void setName(const QString& name)                   {_name = name;}
    void setDelay(const QString& delay)                 {_delay = delay;}
    void setUncondition(const QString& uncondition)     {_uncondition = uncondition;}

    QString getIndex()                                  {return _index;}
    QString getName()                                   {return _name;}
    QString getDelay()                                  {return _delay;}
    QString getUncondition()                            {return _uncondition;}

    std::unique_ptr<NodeModel> clone() const override   {return std::make_unique<ActionNodeModel>();}

signals:

public  slots:
};

#endif // ACTIONNODEMODEL_H
