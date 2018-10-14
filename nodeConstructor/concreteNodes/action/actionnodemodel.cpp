#include "actionnodemodel.h"
#include <QDebug>

ActionNodeModel::ActionNodeModel() :    _node(nullptr),
                                        _name("TEST_NAME"),
                                        _delay("TEST_DELAY"),
                                        _uncondition("TEST_UNCONDITION")
{}

ActionNodeModel::~ActionNodeModel(){}

void ActionNodeModel::setName(const QString &name){
    _name = name;
}

void ActionNodeModel::setDelay(const QString &delay){
    _delay = delay;
}

void ActionNodeModel::setUncondition(const QString &uncondition){
    _uncondition = uncondition;
}

QString ActionNodeModel::getName(){
    return _name;
}

QString ActionNodeModel::getDelay(){
    return _delay;
}

QString ActionNodeModel::getUncondition(){
    return _uncondition;
}

void ActionNodeModel::updateNode(){
    _node->updateNodeUi();
}

void ActionNodeModel::setNode(Node *node){
    _node = dynamic_cast<ActionNode*> (node);
}
