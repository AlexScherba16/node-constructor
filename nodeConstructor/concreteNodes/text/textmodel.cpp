#include "textmodel.h"

TextModel::TextModel() : _text("DEFAULT_TEXT"), _node(nullptr){}
TextModel::~TextModel()     {}

void TextModel::updateNode(){
    if(_node)
        _node->updateNodeUi();
}

void TextModel::setNode(Node* node){
    _node = node;
}
