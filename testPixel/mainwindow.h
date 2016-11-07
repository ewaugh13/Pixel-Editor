#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTimer>
#include <QMainWindow>
#include <QLayout>
#include <QtCore>
#include "drawmodel.h"
#include "sizeselector.h"
#include "previewwindow.h"
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
    void exportImage(QString, bool, std::vector<QImage>);
    void importImage(QString);
    void addCurrentFrame();
    void playPreviewWindow();
    void previewStopped(bool);

    void sendImageToPreview(std::vector<QImage>);

    void vertMirror();
    void horzMirror();

    void changeTransparency(int);
    void changeFrame(QImage, bool);


    void updateFrame();

    void callSaveSSP(std::vector<QImage>, std::string, bool);
    void callLoadSSP(std::string,std::vector<QImage>&);
    void fillTrans();

    void adjustBoardSize(double,double);


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


    void on_actionSave_triggered();
    void on_actionOpen_triggered();

    void on_maximizePreviewButton_clicked();

    void on_copyButton_clicked();

    void on_pasteButton_clicked();

    void on_cutButton_clicked();

private:
    Ui::MainWindow *ui;
    QWidget* central;
    QGridLayout* mainSpace;
    SizeSelector size;
    previewwindow preview;
    QColorDialog* colorPicker;
    std::vector<QImage> timelineImages;
    std::vector<QImage> previewImages;
    bool resizeImage;
    int currentFrame;
    int fpsPreview;
    QTimer* playTimer;
    bool previewPlaying;
    QImage copyImage;

    void exportPicture();
    void saveSSP();
    void openSSP();
    void importPicture();

protected:
    void resizeEvent(QResizeEvent* event);

};

#endif // MAINWINDOW_H
