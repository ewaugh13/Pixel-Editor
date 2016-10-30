#ifndef DRAWMODEL_H
#define DRAWMODEL_H

#include <QWidget>
#include <QPixmap>
#include <QPen>
#include <QPainter>
#include <QPaintEvent>
#include <QBrush>
#include <QColor>
#include <iostream>
#include <string>


class DrawModel : public QWidget
{
    Q_OBJECT
public:
    explicit DrawModel(QWidget *parent = 0);

signals:
    void sendEyedropperColor(QColor);
    void sendPreviewImage(QImage);

public slots:
    void userGivenWidthAndHeight(int, int);
    void changePenSize(int);
    void changePenColor(QColor);
    void changeTools(std::string);
    void undoSlot();
    void redoSlot();


protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*)Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent*)Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent*)Q_DECL_OVERRIDE;
    //void resizeEvent(QResizeEvent*)Q_DECL_OVERRIDE;

    //
    void drawAPoint(QPoint);
    void drawALine(QPoint, QPoint); //used for mouse move event to draw pixels
    void drawGrid();
    QColor getPixelColor(QPoint);

private:
    QImage picture;
    QPen pen;
    QPoint lastPoint;
    QBrush* currentBrush;
    QColor* currentColor;
    std::string currentTool;
    QColor eraseColor;

    QImage picForeGround;
    QImage picBackGround;
    std::vector<QImage>* imageHistory;
    std::vector<QImage>* redoStack;

    int width;
    int height;

    int scaleFactorX;
    int scaleFactorY;

    int penWidth;

    bool erasing;

    //used for line tool
    void renderShapes(QPoint, QPoint); //shows line
    void createShapes(QPoint, QPoint); //actually draws line

    //enum Tools{Pen, Eraser, Line, Circle, FillBucket, Ellipse, Rectangle};

    //Tools ourTool;

};

#endif // DRAWMODEL_H
