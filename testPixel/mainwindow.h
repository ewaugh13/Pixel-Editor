#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QtCore>
#include "drawmodel.h"
#include "sizeselector.h"
#include <string>
#include <QColorDialog>
#include <QFileDialog>


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
    void setColorPreviewWindow(QColor);
    void receivePreviewImage(QImage);

signals:
    void passWidthAndHeight(int,int, bool);
    void setPenSize(int);
    void setPenColor(QColor);
    void setToolType(std::string);
    void undoSignal();
    void redoSignal();
    void rotateCanvas(double);
    void exportImage(QString);

private slots:
    void on_penSizeSlider_valueChanged(int value);

    void on_penButton_clicked();

    void on_eraserButton_clicked();

    void on_paintButton_clicked();

    void on_lineButton_clicked();

    void on_ellipseButton_clicked();

    void on_rectangleButton_clicked();

    void on_colorSelectionButton_clicked();

    void on_penSizeSpinBox_valueChanged(int arg1);

    void on_eyedropperButton_clicked();

    void on_undoButton_clicked();

    void on_redoButton_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

private:
    Ui::MainWindow *ui;
    QWidget* central;
    QGridLayout* mainSpace;
    SizeSelector size;
    QColorDialog* colorPicker;
    bool resizeImage;

};

#endif // MAINWINDOW_H
