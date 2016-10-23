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
    //virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    //virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

signals:

public slots:

private:
    QList <QPointF> m_points;
};

#endif
