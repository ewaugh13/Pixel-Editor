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
    eraseColor = QColor(0,0,0,0);
    imageHistory = new std::vector<QImage>;
    //imageHistory->push_back();
    redoStack = new std::vector<QImage>;
}


void DrawModel::paintEvent(QPaintEvent * paintEvent)
{
    QPainter painter(this);
    painter.setBrush(*currentBrush);
    QRect rectangle = paintEvent->rect();
    painter.scale(scaleFactorX, scaleFactorY);
    painter.drawImage(rectangle, picture, rectangle);
    emit sendPreviewImage(picture);
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
        erasing = true;
        drawALine( lastPoint, QPoint(x,y));
    }
    else if(currentTool == "Ellipse")
    {
        renderShapes(lastPoint, QPoint(x,y));
    }
    else if(currentTool == "Rectangle")
    {
        renderShapes(lastPoint, QPoint(x,y));
    }
    else if(currentTool == "Line")
    {
        renderShapes(lastPoint, QPoint(x,y));
    }
    else if(currentTool == "FillBucket")
    {
    }


}

void DrawModel::mousePressEvent(QMouseEvent* mouseEvent)
{
    if (imageHistory->size()>=3)
    {
        imageHistory->erase(imageHistory->begin());
        imageHistory->push_back(picForeGround);
    }
    else
    {
        imageHistory->push_back(picForeGround);
    }
    QPoint point(mouseEvent->pos());
    int x = point.x()/scaleFactorX;
    int y = point.y()/scaleFactorY;
    lastPoint = QPoint(x,y);
    if(currentTool == "Pen")
    {
        std::cout << currentTool << std::endl;

        drawAPoint(QPoint(x,y));
    }
    else if(currentTool == "Eraser")
    {
        erasing = true;
        drawAPoint(QPoint(x,y));
    }
    else if(currentTool == "Ellipse")
    {
        renderShapes(QPoint(x,y), QPoint(x,y));
    }
    else if(currentTool == "Rectangle")
    {

        renderShapes(QPoint(x,y), QPoint(x,y));
    }
    else if(currentTool == "Line")
    {
        renderShapes(QPoint(x,y), QPoint(x,y));
    }
    else if(currentTool == "FillBucket")
    {
    }
    else if(currentTool == "Eyedropper")
    {
        QColor pixelColor = getPixelColor(QPoint(x,y));
        *currentColor = pixelColor;
        emit sendEyedropperColor(pixelColor);
    }
}

void DrawModel::mouseReleaseEvent(QMouseEvent* mouseEvent)
{
    QPoint point(mouseEvent->pos());
    int x = point.x()/scaleFactorX;
    int y = point.y()/scaleFactorY;
    if(currentTool == "Line")
    {
        createShapes(lastPoint, QPoint(x,y));
    }
    else if(currentTool == "Rectangle")
    {
        createShapes(lastPoint, QPoint(x,y));
    }

    else if(currentTool == "Ellipse")
    {
        createShapes(lastPoint, QPoint(x,y));
    }
}

void DrawModel::drawAPoint(QPoint pos)
{


    QPainter painter(&picForeGround);

    painter.setBrush(*currentBrush);
    if(currentTool == "Pen")
    {
        pen.setColor(*currentColor);
    }
    else if(currentTool == "Eraser")
    {
        painter.setCompositionMode(QPainter::CompositionMode_Clear);
        pen.setColor(eraseColor);
    }
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

    painter.setBrush(*currentBrush);
    if(currentTool == "Pen")
    {
        pen.setColor(*currentColor);
    }
    else if(currentTool == "Eraser")
    {
        painter.setCompositionMode(QPainter::CompositionMode_Clear);
        pen.setColor(eraseColor);
    }
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
    else if(tool == "Eyedropper")
    {

    }

}

void DrawModel::changePenSize(int size)
{

    penWidth = size;
}

void DrawModel::changePenColor(QColor newColor)
{
    *currentColor = newColor;
}
QColor DrawModel::getPixelColor(QPoint pos)
{
    QColor theColor;
    theColor.setRgba(picForeGround.pixel(pos.x(),pos.y()));
    if(theColor == Qt::transparent){
        theColor = *currentColor;
    }

    return theColor;
}

void DrawModel::renderShapes(QPoint start, QPoint finish)
{
    QImage realTimeImage = picForeGround;
    QPainter painter(&realTimeImage);
    painter.setBrush(Qt::transparent);
    pen.setWidth(penWidth);
    pen.setColor(*currentColor);
    painter.setPen(pen);
    if(currentTool == "Line")
    {
        painter.drawLine(start, finish);
    }
    else if(currentTool == "Rectangle")
    {

        QPoint horizontalToStart(finish.x(), start.y());
        QPoint horizontalToEnd(start.x(), finish.y());
        painter.drawLine(start, horizontalToStart);
        painter.drawLine(start, horizontalToEnd);
        painter.drawLine(finish, horizontalToStart);
        painter.drawLine(finish, horizontalToEnd);
    }
    else if(currentTool == "Ellipse")
    {
        painter.drawEllipse(start.x(), start.y(), finish.x() - start.x(), finish.y() - start.y());
    }

    QImage result = picBackGround;
    QPainter painter2(&result);
    painter2.drawImage(QPoint(0,0), realTimeImage);
    picture = result;
    update();
}

void DrawModel::createShapes(QPoint start, QPoint finish)
{
    QPainter painter(&picForeGround);
    painter.setBrush(Qt::transparent);
    pen.setWidth(penWidth);
    pen.setColor(*currentColor);
    painter.setPen(pen);

    if(currentTool == "Line")
    {
        painter.drawLine(start, finish);
    }
    else if(currentTool == "Rectangle")
    {
        QPoint horizontalToStart(finish.x(), start.y());
        QPoint horizontalToEnd(start.x(), finish.y());
        painter.drawLine(start, horizontalToStart);
        painter.drawLine(start, horizontalToEnd);
        painter.drawLine(finish, horizontalToStart);
        painter.drawLine(finish, horizontalToEnd);
    }
    else if(currentTool == "Ellipse")
    {
        painter.drawEllipse(start.x(), start.y(), finish.x() - start.x(), finish.y() - start.y());
    }
    QImage result = picBackGround;
    QPainter painter2(&result);
    painter2.drawImage(QPoint(0,0), picForeGround);
    picture = result;
    update();
}


void DrawModel::undoSlot()
{
    if (imageHistory->size() > 0)
    {
        std::cout << "undo" << std::endl;
        redoStack->push_back(picForeGround);
        picForeGround = imageHistory->back();
        //redoStack->push_back(imageHistory->back());

        std::cout << redoStack->size() << std::endl;
        imageHistory->pop_back();
        QImage result = picBackGround;
        QPainter painter2(&result);
        painter2.drawImage(QPoint(0,0), picForeGround);
        picture = result;
        update();
    }

}

void DrawModel::redoSlot()
{
    if(redoStack->size() > 0){
        std::cout << "redo" << std::endl;
        imageHistory->push_back(picForeGround);
        picForeGround = (*redoStack)[redoStack->size() - 1];
        std::cout << redoStack->size() << std::endl;

        //imageHistory->push_back(redoStack->back());

        redoStack->pop_back();
        QImage result = picBackGround;
        QPainter painter2(&result);
        painter2.drawImage(QPoint(0,0), picForeGround);
        picture = result;
        update();
    }
}



