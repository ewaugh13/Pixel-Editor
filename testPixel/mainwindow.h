#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QtCore>
#include "drawmodel.h"
#include "sizeselector.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int spriteWidth;
    int spriteHeight;
public slots:
    void acceptWidthAndHeight(int,int);

signals:
    void passWidthAndHeight(int,int);

private:
    Ui::MainWindow *ui;
    QWidget* central;
    QGridLayout* mainSpace;
    SizeSelector size;
    DrawModel* artist;

};

#endif // MAINWINDOW_H