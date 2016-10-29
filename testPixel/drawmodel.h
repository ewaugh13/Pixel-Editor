#ifndef DRAWMODEL_H
#define DRAWMODEL_H

#include <QWidget>
#include <QPixmap>
#include <QPen>
#include <QPainter>
#include <QPaintEvent>
#include <iostream>

class DrawModel : public QWidget
{
    Q_OBJECT
public:
    explicit DrawModel(QWidget *parent = 0);

signals:

public slots:
    void userGivenWidthAndHeight(int, int);
    void userGivenColor(QColor);

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

private:
    QImage picture;
    QPen pen;
    QPoint lastPoint;
    int width;
    int height;

    int scaleFactorX;
    int scaleFactorY;
    QColor currentColor;

};

#endif // DRAWMODEL_H
