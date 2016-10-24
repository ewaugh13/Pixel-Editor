#include "rendercanvas.h"
#include <iostream>

RenderCanvas::RenderCanvas(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    modified = false;
    drawing = false;
    penWidth = 1;
    penColor = Qt::blue;


}

bool RenderCanvas::openImage(const QString &fileName){
    QImage loadedImage;
    if(!loadedImage.load(fileName)){
        return false;
    }
    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    modified = false;
    update();
    return true;
}

bool RenderCanvas::saveImage(const QString &fileName, const char *fileFormat){
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());

    if(!visibleImage.save(fileName, fileFormat)){
        return false;
    }
    modified = false;
    return true;
}

void RenderCanvas::setPenColor(const QColor &newColor){
    penColor = newColor;
}

void RenderCanvas::setPenWidth(int newWidth){
    penWidth = newWidth;
}

void RenderCanvas::clearImage(){
    image.fill(qRgba(0,0,0,0));
    modified = true;
    update();
}

void RenderCanvas::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        lastPoint = event->pos();
        drawing = true;
    }
}

void RenderCanvas::mouseMoveEvent(QMouseEvent *event){
    if((event->buttons() & Qt::LeftButton) && drawing){
        drawLineTo(event->pos());

    }
}

void RenderCanvas::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton && drawing){
        drawLineTo(event->pos());
        drawing = false;
    }
}

void RenderCanvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void RenderCanvas::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(penColor, penWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);
    modified = true;

    int rad = (penWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}

void RenderCanvas::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgba(0, 0, 0, 0));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void RenderCanvas::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}




