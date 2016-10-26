#include "graphicscene.h"
#include <QGraphicsScene>
#include <iostream>
#include <QPainter>

GraphicsScene::GraphicsScene() :
    QGraphicsScene()
{
    this->setBackgroundBrush(Qt::gray);
}
GraphicsScene::GraphicsScene(Ui::MainWindow* mainWindow) : QGraphicsScene()
{
    mainWindow->Workspace->setMouseTracking(true);
    //mainWindow->Workspace->qApp->installEventFilter(this);
}
void GraphicsScene::UpdateWorkspace(Ui::MainWindow* mainWindow)
{
    mainWindow->Workspace->update(0,0,512,512);
}
void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    //qDebug() << Q_FUNC_INFO << mouseEvent->scenePos();
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    std::cout <<"Clicking in scene" <<std::endl;

    std::cout<<"mouse detected at " <<mouseEvent->scenePos().x() <<"," <<mouseEvent->scenePos().y() <<std::endl;
    //QGraphicsScene::mousePressEvent(mouseEvent);
    QPointF point = mouseEvent->scenePos();
    emit graphicsSceneClicked(point);
}

void GraphicsScene::InitializeWorkspace(QPixmap* pix, double scaleFactorX, double scaleFactorY)
{
    //Scale factor was original 33.166
    QPainter* painter = new QPainter(pix);
    painter->setBrush(Qt::black);
    pix->size();
    double columns = pix->size().width() / scaleFactorX;
    double rows = pix->size().height() / scaleFactorY;

    std::cout << pix->size().width() << std::endl;

    for(int i = 0; i < (columns); i++) // i = x, number of columns
    {
        for(int j = 0; j < (rows); j++) // j = y, number of rows
        {
            if(painter->brush() == Qt::gray)
            {
                painter->setBrush(Qt::black);
            }
            else
            {
                painter->setBrush(Qt::gray);
            }
            painter->fillRect(QRectF(static_cast<qreal>(i * scaleFactorX),static_cast<qreal>(scaleFactorY * j), static_cast<qreal>(scaleFactorX), static_cast<qreal>(scaleFactorY)), painter->brush());//factor was originally 33.33

        }
        if(painter->brush() == Qt::gray)
        {
            painter->setBrush(Qt::black);
        }
        else
        {
            painter->setBrush(Qt::gray);
        }
    }
    delete painter;
}


void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * me)
{
    /*
    qDebug() << Q_FUNC_INFO << me->scenePos();
    int radius = 20;
    QGraphicsEllipseItem * ellipse = this->addEllipse(me->scenePos().x() - radius, me->scenePos().y() - radius, radius*2, radius*2);

    ellipse->setBrush(Qt::white);
    m_points.append(me->scenePos());
    if(m_points.size() == 3)
    {
        // use math to define the circle
        QLineF lineBC(m_points.at(1), m_points.at(2));
        QLineF lineAC(m_points.at(0), m_points.at(2));
        QLineF lineBA(m_points.at(1), m_points.at(0));
        qreal rad = qAbs(lineBC.length()/(2*qSin(qDegreesToRadians(lineAC.angleTo(lineBA)))));

        QLineF bisectorBC(lineBC.pointAt(0.5), lineBC.p2());
        bisectorBC.setAngle(lineBC.normalVector().angle());

        QLineF bisectorBA(lineBA.pointAt(0.5), lineBA.p2());
        bisectorBA.setAngle(lineBA.normalVector().angle());

        QPointF center;
        bisectorBA.intersect(bisectorBC, &center);

        qDebug() << rad << center;

        bool drawCircle = true;

        QGraphicsEllipseItem * ellipse = new QGraphicsEllipseItem(center.x() - rad, center.y() - rad, rad*2, rad*2);
        if(drawCircle)
            this->addItem(ellipse);

        // add arc
        // this->addItem(path);
        QPainterPath path;
        QLineF lineOA(center, m_points.at(0));
        QLineF lineOC(center, m_points.at(2));
        path.arcMoveTo(ellipse->boundingRect(),lineOA.angle());
        path.arcTo(ellipse->boundingRect(), lineOA.angle(), lineOC.angle() - lineOA.angle());
        QGraphicsPathItem * pathItem = new QGraphicsPathItem(path);
        pathItem->setPen(QPen(Qt::red,10));
        this->addItem(pathItem);

        if(!drawCircle)
            delete ellipse;
        m_points.clear();
    }

    QGraphicsScene::mouseReleaseEvent(me);*/
}
