#include "previewwindow.h"
#include "ui_previewwindow.h"

previewwindow::previewwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::previewwindow)
{
    playTimer = new QTimer(this);
    fpsPreview = 1000;  //one second
    currentFrame = 0;
    previewPlaying = false;
    width = 0;
    height = 0;
    upgradeSize = false;
    ui->setupUi(this);
    QObject::connect(this, &previewwindow::playPreviewWindow, this, &previewwindow::playPreview);
    QObject::connect(playTimer, &QTimer::timeout, this, &previewwindow::playPreview);

}

previewwindow::~previewwindow()
{
    delete ui;
}

void previewwindow::getImageVector(std::vector<QImage> vec)
{
//    for(int i = 0; i < vec.size(); i ++)
//    {
//        if(vec[i].height() > height)
//        {
//            height = vec[i].height();
//        }
//        if(vec[i].width() > width)
//        {
//            width = vec[i].width();
//        }
//        //imageVector.push_back(vec[i]);

//    }

    imageVector = vec;
}

void previewwindow::playPreview()
{
    if(currentFrame >= imageVector.size())
    {
        currentFrame = 0;
    }

    if(upgradeSize)
    {
        width = 512.0;
        height = 512.0;
    }
    else{
        width = imageVector[currentFrame].width();
        height = imageVector[currentFrame].height();
    }
    ui->label->setPixmap(QPixmap::fromImage(imageVector[currentFrame].scaled(width,height,Qt::KeepAspectRatio)));
    ui->label->setGeometry(306 - width/2,306 - height/2,width,height);
    currentFrame++;


}


void previewwindow::on_playButton_clicked()
{
    if(imageVector.size() > 0)
    {
        currentFrame = 0;
        playTimer->start(fpsPreview);
        previewPlaying = true;
        emit playPreviewWindow();
        //emit previewStopped(true);  //means that preview is currently playing, and doesn't allow preview to update in real time
    }
}

void previewwindow::on_spinBox_valueChanged(int value)
{
    fpsPreview = 1000/value;
    ui->spinBox->setValue(value);

    if(previewPlaying)
    {
        emit on_playButton_clicked();
    }

}

void previewwindow::on_sizeCheckBox_toggled(bool checked)
{
//    if(checked == true)
//    {
//        width = 512;
//        height = 512;
//        if(previewPlaying)
//        {
//            emit on_playButton_clicked();
//        }
//    }
//    if(checked == false)
//    {
//        height = 0;
//        width = 0;
//        for(int i = 0; i < imageVector.size(); i ++)
//        {
//            if(imageVector[i].height() > height)
//            {
//                height = imageVector[i].height();
//            }
//            if(imageVector[i].width() > width)
//            {
//                width = imageVector[i].width();
//            }


//        }
    upgradeSize = checked;
    if(previewPlaying)
    {
        emit on_playButton_clicked();
    }


}
