#include "drawmodel.h"

DrawModel::DrawModel(QWidget *parent) : QWidget(parent)
{
    width = 8;
    height = 8;
    erasing = false;
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

    picForeGround = QImage(width, height, QImage::Format_ARGB32);
    picBackGround = QImage(width, height, QImage::Format_ARGB32);
    picForeGround.fill(Qt::transparent);
    currentTool = "Pen";
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
        *currentColor = Qt::white;
        drawALine(lastPoint, QPoint(x,y));
    }
    else if(currentTool == "Eraser")
    {
        //((x + y) % 2 == 0 )? *currentColor = QColor(100,100,100,255): *currentColor = QColor(150,150,150,255);
        erasing = true;
        *currentColor = Qt::transparent;
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
        *currentColor = Qt::white;
        drawAPoint(QPoint(x,y));
    }
    else if(currentTool == "Eraser")
    {
        //((x + y) % 2 == 0 )? *currentColor = QColor(100,100,100,0): *currentColor = QColor(150,150,150,0);
        *currentColor = Qt::transparent;
        erasing = true;
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

    QPainter painter(&picForeGround);

    if(currentTool == "Eraser"){
        painter.setCompositionMode(QPainter::CompositionMode_Clear);
    }
    painter.setBrush(*currentBrush);
    pen.setColor(*currentColor);
    pen.setWidth(penWidth);
    painter.setPen(pen);
    painter.drawPoint(pos);
    QImage result = picBackGround;
    QPainter p(&result);
    p.drawImage(QPoint(0,0),picForeGround);
    picture = result;
    update();
    lastPoint = pos;
    if(currentTool == "Eraser"){
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
        erasing = false;
    }
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
            QPainter painter(&picBackGround);
            painter.setBrush(*currentBrush);
            painter.setPen(QPen(*color, 1));
            painter.drawPoint(i , j);

        }
    }
    picture = picBackGround;
    update();
}

void DrawModel::drawALine(QPoint lastPos, QPoint currentPos)//Remove QColor color
{
    QPainter painter(&picForeGround);
    if(currentTool == "Eraser"){
        painter.setCompositionMode(QPainter::CompositionMode_Clear);
    }
    painter.setBrush(*currentBrush);
    pen.setColor(*currentColor);
    pen.setWidth(penWidth);
    painter.setPen(pen);
    painter.drawLine(lastPos, currentPos);
    lastPoint = currentPos;
    QImage result = picBackGround;
    QPainter p(&result);
    p.drawImage(QPoint(0,0),picForeGround);
    picture = result;
    update();
    if(currentTool == "Eraser"){
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
        erasing = false;
    }

}

void DrawModel::userGivenWidthAndHeight(int passedWidth, int passedHeight)
{
    width = passedWidth;
    height = passedHeight;
    scaleFactorX = 512/width;
    scaleFactorY = 512/height;

    picForeGround = QImage(width, height, QImage::Format_ARGB32);
    picBackGround = QImage(width, height, QImage::Format_ARGB32);
    picForeGround.fill(Qt::transparent);
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

/*
void DrawModel::resizeEvent(QResizeEvent *event)
{
    scaleFactorX = this->width/width;
    scaleFactorY = this->height/height;
}

*/

