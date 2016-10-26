#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QList>
#include <QMainWindow>
#include "ui_mainwindow.h"

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GraphicsScene();
    GraphicsScene(Ui::MainWindow* parent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void UpdateWorkspace(Ui::MainWindow* mainWindow);
    void InitializeWorkspace(QPixmap*,double scaleFactorX,double scaleFactorY);//Pixmap,scaleFactorX,scaleFactorY

signals:
    void graphicsSceneClicked(QPointF);

public slots:

private:
    QList <QPointF> m_points;
    //bool eventFilter(QObject*, QEvent*);
};

#endif
