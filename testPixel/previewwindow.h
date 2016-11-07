#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QDialog>
#include <QLayout>
#include <QtCore>
#include <iostream>
namespace Ui {
class previewwindow;
}

class previewwindow : public QDialog
{
    Q_OBJECT
public slots:
    void getImageVector(std::vector<QImage>);
public:
    explicit previewwindow(QWidget *parent = 0);
    ~previewwindow();

private slots:
    void on_playButton_clicked();
    void playPreview();
    void on_spinBox_valueChanged(int arg1);

    void on_sizeCheckBox_toggled(bool checked);

signals:
    void playPreviewWindow();


private:
    Ui::previewwindow *ui;
    int fpsPreview;
    std::vector<QImage> imageVector;
    int currentFrame;
    QTimer* playTimer;
    bool previewPlaying;

    double width;
    double height;

    bool upgradeSize;

    double scaleFactor;

};

#endif // PREVIEWWINDOW_H
