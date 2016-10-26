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
void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * me)
{
    QGraphicsScene::mouseReleaseEvent(me);
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

    workspace2DVector.resize(columns);
    for(int i = 0; i < (columns); i++) // i = x, number of columns
    {
        workspace2DVector[i].resize(rows);
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
    //Comment this back in if you wish to print out the vector data of the frame
    /*
    for(int i = 0; i < workspace2DVector.size(); i++)
    {
        for(int j = 0; j < workspace2DVector[i].size(); j++)
        {
            std::cout<<"I:" <<i <<":" <<workspace2DVector[i][j].red()<<","<<workspace2DVector[i][j].green()<<","
                    <<workspace2DVector[i][j].blue()<<"," <<workspace2DVector[i][j].alpha()<<std::endl;
        }
    }*/
    delete painter;
}
void GraphicsScene::InitializeColorspace(QPixmap* pix, double scaleFactorX, double scaleFactorY)
{
    //Scale factor was original 33.166
    QPainter* painter = new QPainter(pix);
    pix->size();

    double columns = pix->size().width() / scaleFactorX;
    double rows = pix->size().height() / scaleFactorY;

    std::cout << pix->size().width() << std::endl;

    workspace2DVector.resize(columns);
    for(int i = 0; i < (columns); i++) // i = x, number of columns
    {
        workspace2DVector[i].resize(rows);
        for(int j = 0; j < (rows); j++) // j = y, number of rows
        {
            painter->setBrush(Qt::transparent);
            painter->fillRect(QRectF(static_cast<qreal>(i * scaleFactorX),static_cast<qreal>(scaleFactorY * j), static_cast<qreal>(scaleFactorX), static_cast<qreal>(scaleFactorY)), painter->brush());
            workspace2DVector[i][j] = Qt::transparent;
        }
    }
}
