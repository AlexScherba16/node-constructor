#ifndef ACTIONNODEMODEL_H
#define ACTIONNODEMODEL_H

#include "nodeModel/nodemodel.h"

class  ActionNodeModel : public NodeModel
{
    Q_OBJECT
private:
//    Q_PROPERTY(QColor color MEMBER m_color NOTIFY colorChanged)

    QString _name;
    QString _delay;
    QString _uncondition;

public:
    ActionNodeModel();
    ~ActionNodeModel();

    void setName(const QString& name);
    void setDelay(const QString& delay);
    void setUncondition(const QString& uncondition);

    QString getName();
    QString getDelay();
    QString getUncondition();

    void updateNode();

signals:

public  slots:
};

#endif // ACTIONNODEMODEL_H
