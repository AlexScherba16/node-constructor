#ifndef TEXTMODEL_H
#define TEXTMODEL_H

#include "nodeModel/nodemodel.h"
#include "concreteNodes/text/textnode.h"

class TextModel : public NodeModel
{
    Q_OBJECT
private:
    QString _text;
    Node*   _node;

public:
    TextModel();
    ~TextModel();

    void    setText(const QString& text)    {_text = text;}
    QString getText()                       {return _text;}

    void updateNode();
    void setNode(Node* node);
};

#endif // TEXTMODEL_H
