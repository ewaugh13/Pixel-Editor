#include "drawmodel.h"

DrawModel::DrawModel(QWidget *parent) : QWidget(parent)
{
    width = 8;
    height = 8;
    scaleFactorX = 512/width;
    scaleFactorY = 512/height;
    currentColor = new QColor(255,255,255,255);
    currentBrush = new QBrush(*currentColor);
    penWidth = 1;
    QImage newPicture =  QImage(width, height, QImage::Format_ARGB32);
    newPicture.fill(qRgb(12,155,134));
    QPainter painter(&newPicture);
    painter.setBrush(*currentBrush);
    painter.drawImage(QPoint(0,0), newPicture);
    picture = newPicture;
    currentTool = "Pen";
    eraseColor = QColor(0,0,0,0);
}


void DrawModel::paintEvent(QPaintEvent * paintEvent)
{
    QPainter painter(this);
    painter.setBrush(*currentBrush);
    QRect rectangle = paintEvent->rect();
    painter.scale(scaleFactorX, scaleFactorY);
    painter.drawImage(rectangle, picture, rectangle);
}

void DrawModel::mouseMoveEvent(QMouseEvent* mouseEvent)
{
    QPoint point(mouseEvent->pos());
    int x = point.x()/scaleFactorX;
    int y = point.y()/scaleFactorY;
    if(currentTool == "Pen")
    {

        drawALine(lastPoint, QPoint(x,y));
    }
    else if(currentTool == "Eraser")
    {
        ((x + y) % 2 == 0 )? eraseColor = QColor(100,100,100,255): eraseColor = QColor(150,150,150,255);
        drawAPoint( QPoint(x,y));
    }
    else if(currentTool == "Ellipse")
    {

    }
    else if(currentTool == "Rectangle")
    {
    }
    else if(currentTool == "Line")
    {
    }
    else if(currentTool == "FillBucket")
    {
    }
    else if(currentTool == "Circle")
    {

    }


}

void DrawModel::mousePressEvent(QMouseEvent* mouseEvent)
{
    QPoint point(mouseEvent->pos());
    int x = point.x()/scaleFactorX;
    int y = point.y()/scaleFactorY;
    if(currentTool == "Pen")
    {
        std::cout << currentTool << std::endl;

        drawAPoint(QPoint(x,y));
    }
    else if(currentTool == "Eraser")
    {
        ((x + y) % 2 == 0 )? eraseColor = QColor(100,100,100,0): eraseColor = QColor(150,150,150,0);
        drawAPoint(QPoint(x,y));
    }
    else if(currentTool == "Ellipse")
    {

    }
    else if(currentTool == "Rectangle")
    {
    }
    else if(currentTool == "Line")
    {
    }
    else if(currentTool == "FillBucket")
    {
    }
    else if(currentTool == "Circle")
    {

    }

}

void DrawModel::mouseReleaseEvent(QMouseEvent* mouseEvent)
{
    QPoint point(mouseEvent->pos());
    lastPoint = point/32;
}

void DrawModel::drawAPoint(QPoint pos)
{

    QPainter painter(&picture);
    painter.setBrush(*currentBrush);
    if(currentTool == "Pen")
    {
        pen.setColor(*currentColor);
    }
    else if(currentTool == "Eraser")
    {
        pen.setColor(eraseColor);
    }
    pen.setWidth(penWidth);
    painter.setPen(pen);
    painter.drawPoint(pos.x(), pos.y());
    lastPoint = pos;
    update();
}

void DrawModel::drawGrid()
{
    QColor* color = new QColor();
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if((i + j) % 2 == 0)
            {
                color = new QColor(100, 100, 100, 255);
            }
            else
            {
                color = new QColor(150, 150, 150, 255);
            }
            QPainter painter(&picture);
            painter.setBrush(*currentBrush);
            painter.setPen(QPen(*color, 1));
            painter.drawPoint(i , j);

        }
    }
    update();
}

void DrawModel::drawALine(QPoint lastPos, QPoint currentPos)//Remove QColor color
{
    QPainter painter(&picture);
    painter.setBrush(*currentBrush);
    if(currentTool == "Pen")
    {
        pen.setColor(*currentColor);
    }
    else if(currentTool == "Eraser")
    {
        pen.setColor(eraseColor);
    }
    pen.setWidth(penWidth);
    painter.setPen(pen);
    painter.drawLine(lastPos, currentPos);
    lastPoint = currentPos;
    update();
}

void DrawModel::userGivenWidthAndHeight(int passedWidth, int passedHeight)
{
    width = passedWidth;
    height = passedHeight;
    scaleFactorX = 512/width;
    scaleFactorY = 512/height;

    QImage newPicture =  QImage(width, height, QImage::Format_ARGB32);
    newPicture.fill(qRgb(255,255,255));
    QPainter painter(&newPicture);
    painter.setBrush(*currentBrush);
    painter.drawImage(QPoint(0,0), newPicture);
    picture = newPicture;
    drawGrid();
}

void DrawModel::changeTools(std::string tool)
{
    std::cout << "Got to change tools" << std::endl;
    currentTool = tool;
    if(tool == "Pen")
    {

    }
    else if(tool == "Eraser")
    {
    }
    else if(tool == "Ellipse")
    {

    }
    else if(tool == "Rectangle")
    {
    }
    else if(tool == "Line")
    {
    }
    else if(tool == "FillBucket")
    {
    }
    else if(tool == "Circle")
    {

    }

}

void DrawModel::changePenSize(int size)
{
    std::cout << "Got to change pen size" << std::endl;
    penWidth = size;
}

void DrawModel::changePenColor(QColor newColor)
{
    std::cout<< "here" << std::endl;
    *currentColor = newColor;
}

/*
void DrawModel::resizeEvent(QResizeEvent *event)
{
    scaleFactorX = this->width/width;
    scaleFactorY = this->height/height;
}

*/

