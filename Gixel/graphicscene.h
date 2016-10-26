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

    void UpdateWorkspace(Ui::MainWindow* mainWindow);
    void InitializeWorkspace(QPixmap*,double scaleFactorX,double scaleFactorY);//Pixmap,scaleFactorX,scaleFactorY

signals:
    void graphicsSceneDrawn();

public slots:

protected:
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
private:
    QList <QPointF> m_points;
    bool drawing;
    QPoint lastPos;
    qreal width;
    qreal height;
    QPixmap* picture;
    void drawRectOnCanvas(qreal x, qreal y);
    //bool eventFilter(QObject*, QEvent*);
};

#endif
