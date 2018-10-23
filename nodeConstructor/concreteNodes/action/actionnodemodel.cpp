#include "actionnodemodel.h"
#include <QDebug>

ActionNodeModel::ActionNodeModel() :    _name("TEST_NAME"),
                                        _delay("TEST_DELAY"),
                                        _uncondition("LONG_SUPER_MEGA_OPTIMAL_TEXT"),
                                        _node(nullptr)
{}

ActionNodeModel::~ActionNodeModel(){}

