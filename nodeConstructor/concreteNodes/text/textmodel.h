#ifndef TEXTMODEL_H
#define TEXTMODEL_H

#include "nodeModel/nodemodel.h"

class TextModel : public NodeModel
{
    Q_OBJECT
private:
    QString _text;

public:
    TextModel() : NodeModel(), _text("DEFAULT_TEXT") {}
    ~TextModel() {}

    void    setText(const QString& text)                {_text = text;}
    QString getText()                                   {return _text;}

    std::unique_ptr<NodeModel> clone() const override   {return std::make_unique<TextModel>();}

};

#endif // TEXTMODEL_H
