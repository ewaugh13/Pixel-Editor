#ifndef DRAWMODEL_H
#define DRAWMODEL_H

#include <vector>
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
    void addFrameToTimeline(QImage);

public slots:
    void userGivenWidthAndHeight(int, int, bool resizeImage);
    void changePenSize(int);
    void changePenColor(QColor);
    void changeTools(std::string);

    void undoSlot();
    void redoSlot();

    void rotateImage(double);
    void saveImage(QString);
    void openImage(QString);
    void getFrameAndEmit();


    void mirrorVert();
    void mirrorHorz();

    void previewHasStopped(bool);



protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*)Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent*)Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent*)Q_DECL_OVERRIDE;
    //void resizeEvent(QResizeEvent*)Q_DECL_OVERRIDE;
    void drawARect(QPoint, QPoint);
    void drawACircle(QPoint, QPoint);

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


    std::vector<QPoint> pixelStack;
    std::vector<QImage>* imageHistory;
    std::vector<QImage>* redoStack;

    int width;
    int height;

    int scaleFactorX;
    int scaleFactorY;

    int penWidth;

    bool erasing;
    bool drawing;

    bool playing;

    //used for line tool
    void renderShapes(QPoint, QPoint); //shows line
    void createShapes(QPoint, QPoint); //actually draws line
    void boundaryFill(QPoint, QColor targetColor);
    //enum Tools{Pen, Eraser, Line, Circle, FillBucket, Ellipse, Rectangle};

    //Tools ourTool;



    void updateCanvas(QImage);
};

#endif // DRAWMODEL_H
