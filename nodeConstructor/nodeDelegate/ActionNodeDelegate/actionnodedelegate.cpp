#include "actionnodedelegate.h"
#include "ui_actionnodedelegate.h"
#include "concreteNodes/action/actionnodemodel.h"
#include <QMessageBox>
#include <QPushButton>

ActionNodeDelegate::ActionNodeDelegate(ActionNodeModel* model) :
    QDialog(nullptr),
    ui(new Ui::ActionNodeDelegate)
{
    ui->setupUi(this);
    if(model){
        _actionModel = model;
        setModelDataToUi();
    }
    else{
        QMessageBox::critical(this, tr("Delegate error"),
                              tr("ActionModel nullptr ") + __PRETTY_FUNCTION__,
                              QMessageBox::Discard);
        ui->lineEditName->setText("___CRITICAL_NODE_ERROR___");
        auto button = ui->buttonBox->button(QDialogButtonBox::Ok);
        button->setDisabled(true);
    }
}

ActionNodeDelegate::~ActionNodeDelegate(){
    delete ui;
}

void ActionNodeDelegate::setModelDataToUi(){
    ui->lineEditIndex->setText(_actionModel->getIndex());
    ui->lineEditName->setText(_actionModel->getName());
    ui->spinBoxInterval->setValue(_actionModel->getDelay().toUInt());
    ui->lineEditUncondition->setText(_actionModel->getUncondition());
}

void ActionNodeDelegate::on_buttonBox_accepted(){
    _actionModel->setIndex(ui->lineEditIndex->text());
    _actionModel->setName(ui->lineEditName->text());
    _actionModel->setDelay(ui->spinBoxInterval->text());
    _actionModel->setUncondition(ui->lineEditUncondition->text());
    accept();
}
