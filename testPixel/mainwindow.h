#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTimer>
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
    void addFrameToTimeline(QImage);
    void addFrameToPreviewTimeline(QImage);
    void updateTimelineFrame(QImage);
    void updatePreviewFrame(QImage);
    void playPreview();
    //void on_pushButton_16_clicked();

signals:
    void passWidthAndHeight(int,int, bool);
    void setPenSize(int);
    void setPenColor(QColor);
    void setToolType(std::string);
    void undoSignal();
    void redoSignal();
    void rotateCanvas(double);
    void exportImage(QString);
    void importImage(QString);
    void addCurrentFrame();
    void playPreviewWindow();

    void vertMirror();
    void horzMirror();

    void previewStopped(bool);
    void changeTransparency(int);
    void changeFrame(QImage);
    void updateFrame();


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

    void on_addFrameButton_clicked();

    void on_playButton_clicked();

    void on_stopButton_clicked();

    void on_fpsSpinBox_valueChanged(int arg1);

    void on_fpsSlider_valueChanged(int value);

    void on_exportButton_clicked();

    void on_resizeButton_clicked();

    void on_rotateClockwiseButton_clicked();

    void on_rotateCounterClockwiseButton_clicked();


    void on_actionExport_triggered();

    void on_actionImport_triggered();

    void on_transparencySpinBox_valueChanged(int arg1);

    void on_transparencySlider_valueChanged(int value);

    void on_frameSlider_valueChanged(int value);

    void on_frameSpinBox_valueChanged(int arg1);

    void on_saveFrameButton_clicked();

    void on_horizontalMirrorButton_clicked();

    void on_verticalMirrorButton_clicked();


private:
    Ui::MainWindow *ui;
    QWidget* central;
    QGridLayout* mainSpace;
    SizeSelector size;
    QColorDialog* colorPicker;
    std::vector<QImage> timelineImages;
    std::vector<QImage> previewImages;
    bool resizeImage;
    int currentFrame;
    int fpsPreview;
    QTimer* playTimer;
    bool previewPlaying;

    void exportPicture();
    void saveSSP();
    void openSSP();
    void importPicture();

};

#endif // MAINWINDOW_H
