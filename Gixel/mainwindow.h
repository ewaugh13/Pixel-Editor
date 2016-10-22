#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    Tool currentTool(QPen, QBrush, QColor); //Current working tool in the editor

private slots:
    void on_PenToolButton_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
