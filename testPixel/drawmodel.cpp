#include "drawmodel.h"

DrawModel::DrawModel(QWidget *parent) : QWidget(parent)
{
    width = 16;
    height = 16;
    widgetWidth = 815.0;
    widgetHeight = 815.0;
    erasing = false;
    scaleFactorX = widgetWidth/width;
    scaleFactorY = widgetHeight/height;
    scaleFactor = widgetWidth/width;

    currentColor = new QColor(255,255,255,255);
    currentBrush = new QBrush(*currentColor);
    penWidth = 1;

    picForeGround = QImage(width, height, QImage::Format_ARGB32);
    picBackGround = QImage(width, height, QImage::Format_ARGB32);
    picForeGround.fill(Qt::transparent);
    currentTool = "Pen";
    eraseColor = QColor(0,0,0,0);

    imageHistory = new std::vector<QImage>;
    //imageHistory->push_back();
    redoStack = new std::vector<QImage>;

    drawing = false;
    this->setMouseTracking(true);
    playing = false;


}

void DrawModel::paintEvent(QPaintEvent * paintEvent)
{
    QPainter painter(this);
    painter.setBrush(*currentBrush);
    QRect rectangle = paintEvent->rect();
    painter.scale(scaleFactorX, scaleFactorY);
    painter.drawImage(rectangle, picture, rectangle);
    if(!playing)
    {
        emit sendPreviewImage(picture);
    }

}

void DrawModel::mouseMoveEvent(QMouseEvent* mouseEvent)
{
    QPoint point(mouseEvent->pos());
    int x = point.x()/scaleFactorX;
    int y = point.y()/scaleFactorY;

    if(currentTool == "Pen")
    {
        if(drawing == true)
        {
            drawALine(lastPoint, QPoint(x,y));
        }
        else
        {
            renderShapes(QPoint(x,y), QPoint(x,y));
        }
    }
    else if(currentTool == "Eraser")
    {
        erasing = true;
        if(drawing == true)
        {
            drawALine(lastPoint, QPoint(x,y));
        }
        else
        {
            renderShapes(QPoint(x,y), QPoint(x,y));
        }
    }
    else if(currentTool == "Ellipse")
    {
        if(drawing == true)
        {
            renderShapes(lastPoint, QPoint(x,y));
        }
        else
        {
            renderShapes(QPoint(x,y), QPoint(x,y));
        }
    }
    else if(currentTool == "Rectangle")
    {
        if(drawing == true)
        {
            renderShapes(lastPoint, QPoint(x,y));
        }
        else
        {
            renderShapes(QPoint(x,y), QPoint(x,y));
        }
    }
    else if(currentTool == "Line")
    {
        if(drawing == true)
        {
            renderShapes(lastPoint, QPoint(x,y));
        }
        else
        {
            renderShapes(QPoint(x,y), QPoint(x,y));
        }
    }
    else if(currentTool == "FillBucket")
    {
        if(drawing == false)
        {
            renderShapes(QPoint(x,y), QPoint(x,y));
        }
    }
    else if(currentTool == "Eyedropper")
    {
        if(drawing == false)
        {
            renderShapes(QPoint(x,y), QPoint(x,y));
        }
    }


}

void DrawModel::mousePressEvent(QMouseEvent* mouseEvent)
{

    if (imageHistory->size()>=50)
    {
        imageHistory->erase(imageHistory->begin());
        imageHistory->push_back(picForeGround);
    }
    else
    {
        imageHistory->push_back(picForeGround);
    }
    //if a distinct change occurs cannot redo because this is new history
    redoStack->clear();

    drawing = true;
    QPoint point(mouseEvent->pos());
    int x = point.x()/scaleFactorX;
    int y = point.y()/scaleFactorY;
    lastPoint = QPoint(x,y);
    if(currentTool == "Pen")
    {
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
        QColor targetColor = getPixelColor(QPoint(x,y));

        if(targetColor.rgb() != currentColor->rgb())
        {
            int alpha = currentColor->alpha();
            if(targetColor.alpha() == 255 && currentColor->alpha() <255)
            {
                currentColor->setAlpha(255);
            }
            pixelStack.clear();
            pixelStack.push_back(QPoint(x,y));
            boundaryFill(QPoint(x,y),targetColor);
            currentColor->setAlpha(alpha);
        }
        else if(targetColor.rgb() == currentColor->rgb())
        {
            if(targetColor.alpha()+currentColor->alpha() <= 255)
            {
                pixelStack.clear();
                pixelStack.push_back(QPoint(x,y));
                boundaryFill(QPoint(x,y),targetColor);
            }
        }
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
    drawing = false;
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
    getFrameToUpdate();
}

void DrawModel::updateCanvas(QImage drawing)
{

    QImage result = picBackGround.copy();
    QPainter p(&result);
    p.drawImage(QPoint(0,0),drawing);
    picture = result.copy();
    update();
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
    else if(currentTool == "FillBucket")
    {
        pen.setColor(*currentColor);
    }
    pen.setWidth(penWidth);
    painter.setPen(pen);
    painter.drawPoint(pos);

    updateCanvas(picForeGround);

    lastPoint = pos;
    if(currentTool == "Eraser")
    {
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
                color = new QColor(120, 120, 120, 255);
            }
            QPainter painter(&picBackGround);
            painter.setBrush(*currentBrush);
            painter.setPen(QPen(*color, 1));
            painter.drawPoint(i , j);
        }
    }
    picture = picBackGround.copy();
    update();
}

void DrawModel::drawALine(QPoint lastPos, QPoint currentPos)
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
    updateCanvas(picForeGround);
    if(currentTool == "Eraser")
    {
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
        erasing = false;
    }

}

void DrawModel::userGivenWidthAndHeight(int passedWidth, int passedHeight, bool resizeImage)
{
    width = passedWidth;
    height = passedHeight;
    scaleFactorX = widgetWidth/width;
    scaleFactorY = widgetHeight/height;
    /*
    if(height > width)
    {
        scaleFactor = widgetHeight /height;
    }
    else
    {
        scaleFactor = widgetWidth /width;
    }
    */
    picBackGround = QImage(width, height, QImage::Format_ARGB32);
    if(resizeImage)
    {
        QImage newPicture =  QImage(width, height, QImage::Format_ARGB32);
        newPicture.fill(Qt::transparent);
        QPainter p (&newPicture);
        p.drawImage(0,0,picForeGround);
        drawGrid();
        picForeGround = newPicture.copy();
        updateCanvas(picForeGround);
        getFrameToUpdate();

    }
    else
    {
        width = passedWidth;
        height = passedHeight;
        scaleFactorX = widgetWidth/width;
        scaleFactorY = widgetHeight/height;
        picForeGround = QImage(width, height, QImage::Format_ARGB32);
        picForeGround.fill(Qt::transparent);
        QImage newPicture =  QImage(width, height, QImage::Format_ARGB32);
        newPicture.fill(qRgb(255,255,255));
        QPainter painter(&newPicture);
        painter.setBrush(*currentBrush);
        painter.drawImage(QPoint(0,0), newPicture);
        picture = newPicture.copy();
        drawGrid();
    }
}

void DrawModel::changeTools(std::string tool)
{
    currentTool = tool;
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
    theColor = picForeGround.pixelColor(pos);
    //theColor.setRgba(picForeGround.pixel(pos.x(),pos.y()));
    if(currentTool == "Eyedropper" && theColor == Qt::transparent)
    {
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
    if(drawing == true)
    {
        std::cout << "we not here" << std::endl;
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
    }
    else
    {
        if(currentTool == "Eraser" || currentTool == "Eyedropper")
        {
            QColor transparentColor = eraseColor;
            transparentColor.setAlpha(transparentColor.alpha() + 50);
            pen.setColor(transparentColor);
            painter.setPen(pen);
        }
        else
        {
            QColor transparentColor = *currentColor;
            transparentColor.setAlpha(transparentColor.alpha() / 2);
            pen.setColor(transparentColor);
            painter.setPen(pen);
        }
        painter.drawLine(start, start);
    }

   updateCanvas(realTimeImage);
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

    updateCanvas(picForeGround);

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

       updateCanvas(picForeGround);
       getFrameToUpdate();

    }

}

void DrawModel::redoSlot()
{
    if(redoStack->size() > 0)
    {
        imageHistory->push_back(picForeGround);
        picForeGround = (*redoStack)[redoStack->size() - 1];
        redoStack->pop_back();

        updateCanvas(picForeGround);
        getFrameToUpdate();

    }
}

//CITATION: This algorithm was derived and modified from the following tutorial:
//http://www.williammalone.com/articles/html5-canvas-javascript-paint-bucket-tool/
void DrawModel::boundaryFill(QPoint pos, QColor targetColor)
{
    int t = 0;
    QPainter painter(&picForeGround);
    painter.setBrush(*currentBrush);
    pen.setColor(*currentColor);
    painter.setPen(pen);
    while(pixelStack.size())
    {
        t++;
        std::cout<<t<<std::endl;
        QPoint newPos;
        int x, y, row;
        bool reachLeft, reachRight;
        int originalPenWidth = penWidth;

        newPos = pixelStack[pixelStack.size()-1];
        pixelStack.pop_back();

        x = newPos.x();
        y = newPos.y();

        row = y * picForeGround.width() + x;

        while(y-- >= -1 && (getPixelColor(QPoint(x,y)) == targetColor))//&& (getPixelColor(QPoint(x,y)).alpha() == targetColor.alpha()))
        {
            row -= picForeGround.width();
        }
        row += picForeGround.width();

        reachLeft = false;
        reachRight = false;

        while(y++ < picForeGround.height() - 1  && (getPixelColor(QPoint(x,y)) == targetColor))// && (getPixelColor(QPoint(x,y)).alpha() == targetColor.alpha()))
        {

            penWidth = 1;
            //drawAPoint(QPoint(x,y));

            painter.drawPoint(QPoint(x,y));
            penWidth = originalPenWidth;
            if(x > 0)
            {
                if((getPixelColor(QPoint(x-1,y)) == targetColor))// && (getPixelColor(QPoint(x-1,y)).alpha() == targetColor.alpha()))
                {
                    if(!reachLeft)
                    {
                        pixelStack.push_back(QPoint(x-1,y));
                        reachLeft = true;
                    }
                }
                else if(reachLeft)
                {
                    reachLeft = false;
                }
            }
            if(x < picForeGround.width() - 1)
            {
                if( (getPixelColor(QPoint(x+1,y)) == targetColor))// && (getPixelColor(QPoint(x+1,y)).alpha() == targetColor.alpha()))
                {
                    if(!reachRight)
                    {
                        pixelStack.push_back(QPoint(x+1,y));
                        reachRight = true;
                    }
                }
                else if(reachRight)
                {
                    reachRight = false;
                }
            }
           row += picForeGround.width();
        }
    }

    updateCanvas(picForeGround);
}


void DrawModel::rotateImage(double angle)
{
    //Added to check for rotates when undoing and redoing actions
    if (imageHistory->size()>=50)
    {
        imageHistory->erase(imageHistory->begin());
        imageHistory->push_back(picForeGround);
    }
    else
    {
        imageHistory->push_back(picForeGround);
    }


    QImage image  = QImage(width, height, QImage::Format_ARGB32);
    image.fill(Qt::transparent);
    QPainter p (&image);
    p.translate(width/2, height/2);
    p.rotate(angle);
    p.translate(-width/2, -height/2);
    p.drawImage(0,0,picForeGround);
    picForeGround = image.copy();
    updateCanvas(picForeGround);
    getFrameToUpdate();

}

void DrawModel::saveImage(QString fileName, bool isGif, std::vector<QImage> allFrames, int previewRate){
    if(isGif){
        GifSave saveGif = GifSave();
        QByteArray ba = fileName.toLatin1();

        saveGif.GifBegin(&saveGif.storage, ba.data(),width,height,previewRate);
        if(allFrames.size() <=0){
            allFrames.push_back(picForeGround);
        }
        for(int i = 0; i < allFrames.size(); i++){
            //QImage result = allFrames[i].convertToFormat(QImage::Format_RGB32);

            uint8_t *argbPtr=reinterpret_cast<uint8_t*>(allFrames[i].bits());
            saveGif.GifWriteFrame(&saveGif.storage, argbPtr,width,height,10);
        }

        saveGif.GifEnd(&saveGif.storage);
    }
    else
    {

        picForeGround.save(fileName);
    }
}

void DrawModel::getFrameToUpdate()
{
    emit updateTimelineFrame(picForeGround.copy());//send foreground to mainwindow to replace itself on timeline vector

    emit updatePreviewFrame(picture);
}

void DrawModel::getFrameAndEmit()//emits signal to mainwindow that adds picture to timeline vector
{
    addForegroundToTimeline(picForeGround.copy());//send just the foreground to the timeline vector


    emit addFrameToPreviewTimeline(picture);
}
void DrawModel::addForegroundToTimeline(QImage foreground)
{
    emit addFrameToTimeline(foreground);
}



void DrawModel::openImage(QString fileName)
{
    QImage result = QImage(fileName);
    if(!result.isNull())
    {
        picForeGround = QImage(fileName);
        width = picForeGround.width();
        height = picForeGround.height();
        picBackGround = QImage(width, height, QImage::Format_ARGB32);
        scaleFactorX = widgetWidth/width;
        scaleFactorY = widgetHeight/height;
        /*
        if(height > width)
        {
            scaleFactor = widgetHeight /height;
        }
        else
        {
            scaleFactor = widgetWidth /width;
        }
        */
        drawGrid();
        updateCanvas(picForeGround);
    }
}

void DrawModel::mirrorHorz()
{
    QImage result = picForeGround.mirrored();
    picForeGround = result;
    updateCanvas(picForeGround);
    if (imageHistory->size()>=50)
    {
        imageHistory->erase(imageHistory->begin());
        imageHistory->push_back(picForeGround);
    }
    else
    {
        imageHistory->push_back(picForeGround);
    }
    //if a distinct change occurs cannot redo because this is new history
    redoStack->clear();
    getFrameToUpdate();
}


void DrawModel::mirrorVert()
{
    QImage result = picForeGround.mirrored(true, false);
    picForeGround = result;
    updateCanvas(picForeGround);
    if (imageHistory->size()>=50)
    {
        imageHistory->erase(imageHistory->begin());
        imageHistory->push_back(picForeGround);
    }
    else
    {
        imageHistory->push_back(picForeGround);
    }
    //if a distinct change occurs cannot redo because this is new history
    redoStack->clear();
    getFrameToUpdate();
}

void DrawModel::previewHasStopped(bool notPlaying)
{
    playing = notPlaying;
}


void DrawModel::acceptTransparency(int newTransparency)
{
    currentColor->setAlpha(newTransparency);
}


void DrawModel::acceptChangeOfFrame(QImage newFrame, bool paste)
{
    if(!paste)
    {
        imageHistory->clear();
        redoStack->clear();
    }
    else
    {
        imageHistory->push_back(picForeGround);
    }
    picForeGround = newFrame.copy();
    QPainter painter(&picForeGround);
    painter.setBrush(Qt::transparent);
    pen.setWidth(penWidth);
    pen.setColor(*currentColor);
    painter.setPen(pen);
    updateCanvas(picForeGround);
}
//Creates the .spp file of the current project
void DrawModel::saveSSP(std::vector<QImage> frames, std::string filename, bool isSheet)
{
    std::ofstream output_data;

    if(isSheet) //add conditional for name
    {
        int maxWidth = 1024;
        int biggestImageWidth =0;
        int biggestImageHeight = 0;
        int numRows = 1;
        for(int i = 0; i < frames.size(); i++)
        {
            if(frames[i].width() > biggestImageWidth)
            {
                biggestImageWidth = frames[i].width();
            }

            if(frames[i].height() > biggestImageHeight)
            {
                biggestImageHeight = frames[i].height();
            }

        }
        //max number of images in a row
        int amountInRow = maxWidth / biggestImageWidth;

        //If number of rows is divisible by amount of images in a row then add an additional row for the remainder image
        numRows = frames.size() % amountInRow != 0 ? (frames.size() / amountInRow) + 1 : (frames.size() / amountInRow);

        if(frames.size()  < amountInRow)
        {
            amountInRow = frames.size();
        }

        int imageWidth = amountInRow*biggestImageWidth;

        int imageHeight = numRows * biggestImageHeight;
        QImage compositeImage(imageWidth,imageHeight, QImage::Format_ARGB32);
        compositeImage.fill(Qt::transparent);

        QPainter painter(&compositeImage);
        //painter.setCompositionMode(QPainter::CompositionMode_Clear);


        int count = 0;
        for(int y = 0; y < imageHeight && count < frames.size(); y += biggestImageHeight)
        {
            for (int x = 0; x < imageWidth && count < frames.size(); x += biggestImageWidth)
            {
                painter.drawImage(x,y,frames[count]);
                count++;
                std::cout << count << std::endl;
            }
        }
        QString fileName = QString::fromStdString(filename);
        compositeImage.save(fileName);
    }
    else
    {
        QColor pixelColor;

        //filename += ".ssp";//Creates file of FILENAME w .spp ext
        output_data.open(filename);

        output_data << height <<" " <<width <<"\n";
        output_data << frames.size() <<"\n";

        for(int i=0; i < frames.size(); i++)
        {
            for(int y = 0; y < frames[i].height(); y++)
            {
                for(int x = 0; x < frames[i].width(); x++)
                {
                    pixelColor = frames[i].pixelColor(x,y);
                    output_data << pixelColor.red() <<" " <<pixelColor.green() <<" " <<pixelColor.blue() <<" " <<pixelColor.alpha() <<" ";
                }
                output_data <<"\n";
            }
        }
    }
    QImage result = picBackGround;
    QPainter painter2(&result);
    painter2.drawImage(QPoint(0,0), picForeGround);
    picture = result.copy();
    update();
    updateCanvas(picForeGround);

}

void DrawModel::imageClear(){
    picForeGround.fill(Qt::transparent);

    updateCanvas(picForeGround);
}
void DrawModel::loadSSP(std::string filename, std::vector<QImage> &newFrames)
{
    QColor pixelColor;
    int newHeight;
    int newWidth;
    int frameCount;

    std::cout <<"In load method" <<std::endl;
    std::ifstream in_data;

    in_data.open(filename);

    while(!in_data)
    {
        in_data.close();
        in_data.clear();
    }
    in_data >> newHeight >> newWidth >> frameCount;
    height = newHeight;
    width = newWidth;
    QImage currentFrame(newWidth,newHeight, QImage::Format_ARGB32);
    currentFrame.fill(Qt::transparent);

    std::cout<<height <<" " <<width <<" " <<frameCount <<std::endl;
    scaleFactorX = widgetWidth/width;
    scaleFactorY = widgetHeight/height;
    /*
    if(height > width)
    {
        scaleFactor = widgetHeight /height;
    }
    else
    {
        scaleFactor = widgetWidth /width;
    }
    */
    picBackGround = QImage(width, height, QImage::Format_ARGB32);

    int x = 0;
    int y = 0;
    while(!in_data.eof()&&y!=height)
    {
        int r,g,b,a;
        in_data >> r >>g >>b >>a;
        pixelColor = QColor(r,g,b,a);//make QColor based on that RGBA tuple that was read in

        currentFrame.setPixelColor(x,y, pixelColor);
        x++;
        if(x >= width)
        {
            x = 0;
            y++;
            if(y == height)
            {
                y = 0;

                newFrames.push_back(currentFrame);
                currentFrame = QImage(newWidth, newHeight, QImage::Format_ARGB32);
                currentFrame.fill(Qt::transparent);
            }
        }
    }
    in_data.close();
    in_data.clear();

    picForeGround = newFrames[0];

    QImage newPicture =  QImage(width, height, QImage::Format_ARGB32);
    newPicture.fill(qRgb(255,255,255));
    QPainter painter(&newPicture);
    painter.setBrush(*currentBrush);
    painter.drawImage(QPoint(0,0), newPicture);
    picture = newPicture.copy();
    drawGrid();
    update();
}

void DrawModel::adjustBoardSize(double newWidth, double newHeight)
{
    widgetWidth = newWidth;
    widgetHeight = newHeight;
    userGivenWidthAndHeight(width,height,true);
}
