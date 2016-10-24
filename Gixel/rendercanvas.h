#ifndef RENDERCANVAS_H
#define RENDERCANVAS_H

#include <QWidget>
#include <QImage>
#include <QPoint>
#include <QColor>
#include <QMouseEvent>
#include <Qpainter>

class RenderCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit RenderCanvas(QWidget *parent = 0);

    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);

    bool isModified() const { return modified; }
    QColor getPenColor() const { return penColor; }
    int getPenWidth() const { return penWidth; }

public slots:
   //void setPen(const QPen &pen);
    //void setBrush(const QBrush &brush);
    void clearImage();


protected:
       void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
       void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
       void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
       void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
       void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);

    bool modified;
    bool drawing;
    QImage image;
    QColor penColor;
    QPoint lastPoint;
    int penWidth;

};

#endif // RENDERCANVAS_H
