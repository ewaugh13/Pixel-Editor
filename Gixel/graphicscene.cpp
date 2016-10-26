#include "graphicscene.h"
#include <QGraphicsScene>
#include <iostream>
#include <QPainter>

GraphicsScene::GraphicsScene() :
    QGraphicsScene()
{
    this->setBackgroundBrush(Qt::gray);
    drawing = false;
    width = 0.0;
    height = 0.0;
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


void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent)
{   
    if(mouseEvent->button() == Qt::LeftButton)
    {
        drawing = true;
        lastPos = mouseEvent->scenePos().toPoint();
        int x = lastPos.x()/width;
        int y = lastPos.y()/height;

        std::cout<<x <<"," <<y <<std::endl;
        drawRectOnCanvas(x * width, y * height);
        emit graphicsSceneDrawn();
    }
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    if ((mouseEvent->buttons() & Qt::LeftButton) && drawing)
    {

        QPoint point = mouseEvent->scenePos().toPoint();
        int x = lastPos.x()/width;
        int y = lastPos.y()/height;
        int curX = point.x()/width;
        int curY = point.y()/height;
        if((x != curX) || (y != curY))
        {
            lastPos = point;
            drawRectOnCanvas(x * width,y * height);

            emit graphicsSceneDrawn();
        }
    }
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent)
{

    if(mouseEvent->button() == Qt::LeftButton)
    {
        drawing = false;
        lastPos = mouseEvent->scenePos().toPoint();
    }
}

void GraphicsScene::drawRectOnCanvas(qreal x, qreal y)
{
    QPainter* painter = new QPainter(picture);//pix was picture
    painter->setBrush(Qt::blue);
    painter->fillRect(QRectF(x,y, static_cast<qreal>(width), static_cast<qreal>(height)), painter->brush());//factor was originally 33.33
    delete painter;
}
/*
void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * me)
{
    QGraphicsScene::mouseReleaseEvent(me);
}
*/

void GraphicsScene::InitializeWorkspace(QPixmap* pix, double scaleFactorX, double scaleFactorY)
{
    //Scale factor was original 33.166
    QPainter* painter = new QPainter(pix);
    painter->setBrush(Qt::black);

    double columns = pix->size().width() / scaleFactorX;
    double rows = pix->size().height() / scaleFactorY;

    std::cout << pix->size().width() << std::endl;

    workspace2DVector.resize(columns);
    for(int i = 0; i < (columns); i++) // i = x, number of columns
    {
        workspace2DVector[i].resize(rows);
        for(int j = 0; j < (rows); j++) // j = y, number of rows
        {
            if((i+j)%2 == 0)
            {
                painter->setBrush(Qt::black);
            }
            else
            {
                painter->setBrush(Qt::gray);
            }
            painter->fillRect(QRectF(static_cast<qreal>(i * scaleFactorX),static_cast<qreal>(scaleFactorY * j), static_cast<qreal>(scaleFactorX), static_cast<qreal>(scaleFactorY)), painter->brush());//factor was originally 33.33

        }
        /*
        if(painter->brush() == Qt::gray)
        {
            painter->setBrush(Qt::black);
        }
        else
        {
            painter->setBrush(Qt::gray);
        }*/
    }
    delete painter;
}
void GraphicsScene::InitializeColorspace(QPixmap* pix, double scaleFactorX, double scaleFactorY)
{
    QPainter* painter = new QPainter(pix);
    width = scaleFactorX;
    height = scaleFactorY;
    //picture = pix;

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
    delete painter;
}
void GraphicsScene::combineForeAndBack(QPixmap* pixResultant, QPixmap* pixBackground, QPixmap* pixForeground)
{
    QPainter painter(pixResultant);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
    painter.drawPixmap(0,0,*pixBackground);
    painter.drawPixmap(0,0,*pixForeground);
    picture = pixResultant;
}
