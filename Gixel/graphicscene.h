#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QList>

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:

    GraphicsScene();
    GraphicsScene(QObject* parent);
    //virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    //virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

signals:
    void graphicsSceneClicked(QPointF);


public slots:

private:
    QList <QPointF> m_points;
};

#endif
