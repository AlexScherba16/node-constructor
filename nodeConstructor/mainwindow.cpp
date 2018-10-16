#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>


#include "diagramView/diagramView.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _scene = new DiagramScenee();
    _scene->setSceneRect(QRectF(0, 0, 5000, 5000));

    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(toolBox);
    _view = new DiagramView(_scene);
    layout->addWidget(_view);

    setCentralWidget(_view);


//    ActionNode *actNode = new ActionNode();
//    actNode->generate();
//    _scene->addItem(actNode);
}

MainWindow::~MainWindow()
{
    delete ui;
}
