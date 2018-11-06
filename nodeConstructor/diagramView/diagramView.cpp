#include "diagramView.hpp"

//#include <QtWidgets/QGraphicsScene>

#include <QtGui/QPen>
#include <QtGui/QBrush>
#include <QtWidgets/QMenu>

#include <QtCore/QRectF>

//#include <QtOpenGL>
#include <QtWidgets>

#include <QDebug>
#include <iostream>

#include "diagramScene/diagramScene.hpp"

//#include "DataModelRegistry.hpp"
//#include "Node.hpp"
//#include "NodeGraphicsObject.hpp"
//#include "ConnectionGraphicsObject.hpp"
//#include "StyleCollection.hpp"

//#include <QGraphicsItemGroup>

#include <QDebug>

//using QtNodes::DiagramView;

DiagramView::DiagramView(DiagramScenee *scene) : QGraphicsView(scene), _scene(scene)
{
    _actionModel    = new ActionNodeModel;
    _boundingModel  = new BoundingModel;
    _textModel      = new TextModel;



    setDragMode(QGraphicsView::ScrollHandDrag);
    setRenderHint(QPainter::Antialiasing);

    setBackgroundBrush(QBrush(QColor(53,70,70)));
//    setBackgroundBrush(QBrush(QColor(53,53,53)));

  //setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
  //setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);


  setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

  setCacheMode(QGraphicsView::CacheBackground);

//  setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
}


void DiagramView:: contextMenuEvent(QContextMenuEvent *event){
    _scene->clearSelection();

    QMenu modelMenu;
    modelMenu.addAction("Bounding node");
    modelMenu.addAction("Action node");
    if (QAction * action = modelMenu.exec(event->globalPos())){
        NodeModel* model = nullptr;
        Node* node = nullptr;

        if(action->text() == "Bounding node"){
            model = new BoundingModel;
            node = new BoundingNode(model);
        }
        else if(action->text() == "Action node"){
            model = new ActionNodeModel;
            node = new ActionNode(model);
        }
        node->generateGui();
        node->setPos(mapToScene(event->pos()));
        _scene->addItem(node);
    }

//    auto nodetype = _actionModel->clone();
//    if(type){
//        auto& node = _scene->createNode(std::move(type));


//    }

//    auto type = _scene->registry().create(modelName);
//    if (type){
//        auto& node = _scene->createNode(std::move(type));
//        QPoint pos = event->pos();
//        QPointF posView = this->mapToScene(pos);
//        node.nodeGraphicsObject().setPos(posView);
//    }
//    else
//      qDebug() << "Model not found";

    event->accept();


//    QMenu modelMenu;

//  auto filterActionText = QStringLiteral("skip me");

//  auto *txtBox = new QLineEdit(&modelMenu);
//  txtBox->setPlaceholderText(QStringLiteral("Filter"));
//  txtBox->setClearButtonEnabled(true);

//  auto *txtBoxAction = new QWidgetAction(&modelMenu);
//  txtBoxAction->setDefaultWidget(txtBox);
//  txtBoxAction->setText(filterActionText);

//  modelMenu.addAction(txtBoxAction);

//  connect(txtBox, &QLineEdit::textChanged, [&](const QString &text)
//  {
//    for (auto action : modelMenu.actions())
//    {
//      auto actionText = action->text();
//      if (actionText != filterActionText && !actionText.contains(text, Qt::CaseInsensitive))
//      {
//        action->setVisible(false);
//      }
//      else
//      {
//        action->setVisible(true);
//      }
//    }
//  });

//  for (auto const &modelRegistry : _scene->registry().registeredModels())
//  {
//    QString const &modelName = modelRegistry.first;
//    modelMenu.addAction(modelName);
//  }
  
//  // make sure the text box gets focus so the user doesn't have to click on it
//  txtBox->setFocus();
  
//  if (QAction * action = modelMenu.exec(event->globalPos()))
//  {
//    QString modelName = action->text();

//    auto type = _scene->registry().create(modelName);
//    if (type)
//    {
//        QPointF groupScenePos = mapToScene(event->pos());
//        auto& node1 = _scene->createNode(std::move(type));
//        if(node1.nodeDataModel()->isGroupModel()){

}


void DiagramView::wheelEvent(QWheelEvent *event)
{
    Q_UNUSED(event)
    QPoint delta = event->angleDelta();

  if (delta.y() == 0)
  {
        event->ignore();
        return;
  }

  double const d = delta.y() / std::abs(delta.y());

  if (d > 0.0)
    scaleUp();
  else
    scaleDown();
}


void DiagramView::scaleUp()
{
    double const step   = 1.2;
    double const factor = std::pow(step, 1.0);

    QTransform t = transform();

  if (t.m11() > 2.0)
    return;
  scale(factor, factor);
}


void DiagramView::scaleDown()
{
  double const step   = 1.2;
  double const factor = std::pow(step, -1.0);
  scale(factor, factor);
  }


void DiagramView::keyPressEvent(QKeyEvent *event)
{
//    switch (event->key())
//    {
//    case Qt::Key_Escape:
//      _scene->clearSelection();
//      break;

//    case Qt::Key_Delete:
//    {
//      std::vector<Node*> nodesToDelete;
//      std::vector<Connection*> connectionsToDelete;
//      for (QGraphicsItem * item : _scene->selectedItems())
//      {
//        if (auto n = dynamic_cast<NodeGraphicsObject*>(item))
//          nodesToDelete.push_back(&n->node());

//        if (auto c = dynamic_cast<ConnectionGraphicsObject*>(item))
//          connectionsToDelete.push_back(&c->connection());
//      }

//      for( auto & n : nodesToDelete )
//        _scene->removeNode(*n);

//      for( auto & c : connectionsToDelete )
//        _scene->deleteConnection(*c);

//    }

//    break;

//    case Qt::Key_Shift:
//      setDragMode(QGraphicsView::RubberBandDrag);
//      break;

//    default:
//      break;
//  }

  QGraphicsView::keyPressEvent(event);
}


void DiagramView::keyReleaseEvent(QKeyEvent *event)
{
//  switch (event->key())
//  {
//    case Qt::Key_Shift:
//      setDragMode(QGraphicsView::ScrollHandDrag);
//      break;

//    default:
//      break;
//  }
  QGraphicsView::keyReleaseEvent(event);
}


void DiagramView::drawBackground(QPainter* painter, const QRectF& r)
{
  QGraphicsView::drawBackground(painter, r);

  auto drawGrid =
  [&](double gridStep)
  {
    QRect   windowRect = rect();
    QPointF tl = mapToScene(windowRect.topLeft());
    QPointF br = mapToScene(windowRect.bottomRight());

    double left   = std::floor(tl.x() / gridStep - 0.5);
    double right  = std::floor(br.x() / gridStep + 1.0);
    double bottom = std::floor(tl.y() / gridStep - 0.5);
    double top    = std::floor (br.y() / gridStep + 1.0);

    // vertical lines
    for (int xi = int(left); xi <= int(right); ++xi)
    {
      QLineF line(xi * gridStep, bottom * gridStep,
                  xi * gridStep, top * gridStep );

      painter->drawLine(line);
    }

    // horizontal lines
    for (int yi = int(bottom); yi <= int(top); ++yi)
    {
      QLineF line(left * gridStep, yi * gridStep,
                  right * gridStep, yi * gridStep );
      painter->drawLine(line);
    }
  };

//  auto const &flowViewStyle = StyleCollection::flowViewStyle();
//  QBrush bBrush = backgroundBrush();

  QPen pfine(QColor(60,60,60), 1.0);//(flowViewStyle.FineGridColor, 1.0);

  painter->setPen(pfine);
  drawGrid(15);

  QPen p(QColor(25,25,25), 1.0);  // flowViewStyle.CoarseGridColor, 1.0);

  painter->setPen(p);
  drawGrid(150);
}


void DiagramView::showEvent(QShowEvent *event){
    _scene->setSceneRect(this->rect());
    QGraphicsView::showEvent(event);
}

void DiagramView::mousePressEvent(QMouseEvent* event){
//    auto list = _scene->items();        // TODO _scene->nodes()
//    if(event->button() == Qt::LeftButton && list.size()){

//        foreach (auto item , list) {
//            auto node = dynamic_cast<Node* >(item);
//            if(node){
//                auto bottomLeft = node->geometry().nodeBoundingRect().bottomLeft();
//                qDebug() << node->pos() << event->pos() << mapToScene(event->pos()) << mapFromScene(event->pos()) << node->boundingRect().contains(mapFromScene(event->pos()));

////                if(node->geometry().nodeBoundingRect().contains(mapToScene(event->pos()))){
////                    qDebug() << "CONTAINS";
////                }
////                else{
////                    qDebug() << "DESELECT";
//                    node->state().setSelectedState(false);
////                }
//            }
//        }
//    }
    QGraphicsView::mousePressEvent(event);
}

void DiagramView::mouseMoveEvent(QMouseEvent* event){
  QGraphicsView::mouseMoveEvent(event);
}
