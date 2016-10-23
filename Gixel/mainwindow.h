#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "setspritesize.h"
#include "spritedatasheet.h"
#include <QPainter>
#include "tool.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Tool* currentTool; //Current working tool in the editor
    Pen pen;//Child of tool

public slots:
    void cancelSetSize();
    void setSpriteHeightAndWidth(int,int);

private slots:
    void on_PenToolButton_clicked();

private:
    SetSpriteSize popupSize;
    SpriteDataSheet spriteData;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
