#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "setspritesize.h"
#include "spritedatasheet.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void cancelSetSize();
    void setSpriteHeightAndWidth(int,int);
private:
    SetSpriteSize popupSize;
    SpriteDataSheet spriteData;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
