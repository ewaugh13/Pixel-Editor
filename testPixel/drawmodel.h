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
#include <fstream>
#include <ostream>
#include "gifsave.h"

class DrawModel : public QWidget
{
    Q_OBJECT
public:
    explicit DrawModel(QWidget *parent = 0);

signals:
    void sendEyedropperColor(QColor);
    void sendPreviewImage(QImage);
    void addFrameToTimeline(QImage);
    void addFrameToPreviewTimeline(QImage);
    void updateTimelineFrame(QImage);
    void updatePreviewFrame(QImage);

public slots:
    void userGivenWidthAndHeight(int, int, bool resizeImage);
    void changePenSize(int);
    void changePenColor(QColor);
    void changeTools(std::string);

    void undoSlot();
    void redoSlot();

    void rotateImage(double);
    void saveImage(QString, bool, std::vector<QImage>);
    void openImage(QString);
    void getFrameAndEmit();

    void previewHasStopped(bool);


    void mirrorVert();
    void mirrorHorz();


    void acceptTransparency(int);

    void acceptChangeOfFrame(QImage, bool);

    void addForegroundToTimeline(QImage);

    void saveSSP(std::vector<QImage> frames, std::string filename);

    void loadSSP(std::string filename, std::vector<QImage> &frames);

    void getFrameToUpdate();

    void imageClear();

    void adjustBoardSize(double,double);


protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*)Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent*)Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent*)Q_DECL_OVERRIDE;
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

    double scaleFactorX;
    double scaleFactorY;

    int penWidth;

    bool erasing;
    bool drawing;

    bool playing;

    //used for line tool
    void renderShapes(QPoint, QPoint); //shows line
    void createShapes(QPoint, QPoint); //actually draws line
    void boundaryFill(QPoint, QColor targetColor);
    void updateCanvas(QImage);

    double widgetWidth;
    double widgetHeight;
};

#endif // DRAWMODEL_H
