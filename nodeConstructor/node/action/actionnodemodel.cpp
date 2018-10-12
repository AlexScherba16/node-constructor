#include "actionnodemodel.h"
#include <QDebug>

ActionNodeModel::ActionNodeModel(){}

ActionNodeModel::~ActionNodeModel()
{

}

void ActionNodeModel::setName(const QString &name){
    _name = name;
}

void ActionNodeModel::setDelay(const QString &delay){
    _delay = delay;
}

void ActionNodeModel::setUncondition(const QString &uncondition){
    _uncondition = uncondition;

//    abstNode->updateUI();

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

    qDebug() << "updateNode";
}
