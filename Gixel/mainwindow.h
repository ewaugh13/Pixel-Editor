#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "setspritesize.h"
#include <QPainter>
#include "tool.h"
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include "graphicscene.h"


namespace Ui {
class MainWindow;
}
class GraphicsScene;//<- had "not a type error"; painter not active?
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int userDefinedX, userDefinedY;
    double scaleFactorX, scaleFactorY;

    QTimer updateTimer;
    Tool* currentTool; //Current working tool in the editor
    Pen pen;//Child of tool
    GraphicsScene* scene;//current scene of frame

    QPixmap *pixResultant;
    QPixmap *pixBackground; //pix mapped linked to scene
    QPixmap *pixForeground;

public slots:
    void cancelSetSize(int,int);
    void setSpriteHeightAndWidth(int,int);
    void placePoint(QPointF);

private slots:
    void on_PenToolButton_clicked();
    void workspaceClickCheck();

private:
    SetSpriteSize popupSize;
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
