#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "diagramScene/diagramScene.hpp"
#include "diagramView/diagramView.hpp"


using QtNodes::DiagramScenee;
using QtNodes::DiagramView;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    DiagramScenee*  _scene;
    DiagramView*    _view;
};

#endif // MAINWINDOW_H
