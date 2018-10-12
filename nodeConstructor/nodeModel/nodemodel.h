#ifndef NODEMODEL_H
#define NODEMODEL_H

#include <QObject>

class NodeModel : public QObject
{
    Q_OBJECT
private:


public:
    NodeModel();
    virtual ~NodeModel();

    virtual void updateNode() {}

signals:

public slots:
};

#endif // NODEMODEL_H
