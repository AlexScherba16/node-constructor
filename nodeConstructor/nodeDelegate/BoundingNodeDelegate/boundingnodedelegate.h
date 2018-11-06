#ifndef BOUNDINGNODEDELEGATE_H
#define BOUNDINGNODEDELEGATE_H

#include <QDialog>

class BoundingModel;
namespace Ui {
class BoundingNodeDelegate;
}

class BoundingNodeDelegate : public QDialog
{
    Q_OBJECT

public:
    explicit BoundingNodeDelegate(BoundingModel* model);
    ~BoundingNodeDelegate();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::BoundingNodeDelegate *ui;
    BoundingModel*  _boundingModel;
    void setModelDataToUi();
};

#endif // BOUNDINGNODEDELEGATE_H
