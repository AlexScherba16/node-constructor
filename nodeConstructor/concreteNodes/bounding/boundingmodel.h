#ifndef BOUNDINGMODEL_H
#define BOUNDINGMODEL_H

#include "nodeModel/nodemodel.h"

class BoundingModel : public NodeModel
{
    Q_OBJECT
private:

    QString     _boundingText;


public:
    BoundingModel() : NodeModel(), _boundingText("DEFAULT_BOUNDING"){}
    ~BoundingModel() {}

    void    setBoundingText (const QString& text)   {_boundingText = text;}
    QString getBoundingText ()                      {return _boundingText;}


    std::unique_ptr<NodeModel> clone() const override   {return std::make_unique<BoundingModel>();}

signals:

public  slots:
};

#endif // BOUNDINGMODEL_H
