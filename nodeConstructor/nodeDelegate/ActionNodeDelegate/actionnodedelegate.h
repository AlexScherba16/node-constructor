#ifndef ACTIONNODEDELEGATE_H
#define ACTIONNODEDELEGATE_H

#include <QDialog>

class ActionNodeModel;

namespace Ui {
class ActionNodeDelegate;
}

class ActionNodeDelegate : public QDialog
{
    Q_OBJECT

public:
    explicit ActionNodeDelegate(ActionNodeModel* model);//QWidget *parent = 0);
    ~ActionNodeDelegate();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ActionNodeDelegate *ui;
    ActionNodeModel*        _actionModel;

    void setModelDataToUi();
};

#endif // ACTIONNODEDELEGATE_H
