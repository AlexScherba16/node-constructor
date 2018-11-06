#include "boundingnodedelegate.h"
#include "ui_boundingnodedelegate.h"
#include "concreteNodes/bounding/boundingmodel.h"
#include <QMessageBox>
#include <QPushButton>

BoundingNodeDelegate::BoundingNodeDelegate(BoundingModel* model) :
    QDialog(nullptr),
    ui(new Ui::BoundingNodeDelegate)
{
    ui->setupUi(this);
    if(model){
        _boundingModel = model;
        setModelDataToUi();
    }
    else{
        QMessageBox::critical(this, tr("Delegate error"),
                              tr("BoundingModel nullptr ") + __PRETTY_FUNCTION__,
                              QMessageBox::Discard);
        ui->lineEditHeaderText->setText("___CRITICAL_NODE_ERROR___");
        auto button = ui->buttonBox->button(QDialogButtonBox::Ok);
        button->setDisabled(true);
    }
}

BoundingNodeDelegate::~BoundingNodeDelegate(){
    delete ui;
}

void BoundingNodeDelegate::setModelDataToUi(){
    ui->lineEditHeaderText->setText(_boundingModel->getBoundingText());
}

void BoundingNodeDelegate::on_buttonBox_accepted(){
    _boundingModel->setBoundingText(ui->lineEditHeaderText->text());
    accept();
}
