#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //central = new QWidget(this->centralWidget());
    size.show();
    size.raise();
    size.activateWindow();

    spriteWidth = 16;
    spriteHeight = 16;
    resizeImage = false;
    QPalette palette;
    palette.setColor(QPalette::Window,QColor(255,255,255,255));
    ui->colorPreviewLabel->setAutoFillBackground(true);
    ui->colorPreviewLabel->setPalette(palette);


    playTimer = new QTimer(this);
    fpsPreview = 1000;  //one second
    previewPlaying = false;

    //connection between popup window and mainwindow
    QObject::connect(&size, &SizeSelector::setWidthAndHeight, this, &MainWindow::acceptWidthAndHeight);
    QObject::connect(this, &MainWindow::passWidthAndHeight, ui->workspace, &DrawModel::userGivenWidthAndHeight);
    QObject::connect(this, &MainWindow::setToolType, ui->workspace, &DrawModel::changeTools);
    QObject::connect(this, &MainWindow::setPenSize, ui->workspace, &DrawModel::changePenSize);
    QObject::connect(this, &MainWindow::setPenColor, ui->workspace, &DrawModel::changePenColor);
    QObject::connect(ui->workspace, &DrawModel::sendEyedropperColor, this, &MainWindow::setColorPreviewWindow);
    QObject::connect(ui->workspace, &DrawModel::sendPreviewImage, this, &MainWindow::receivePreviewImage);
    QObject::connect(this, &MainWindow::undoSignal, ui->workspace, &DrawModel::undoSlot);
    QObject::connect(this, &MainWindow::redoSignal, ui->workspace, &DrawModel::redoSlot);\

    QObject::connect(this, &MainWindow::rotateCanvas, ui->workspace, &DrawModel::rotateImage);
    QObject::connect(this, &MainWindow::exportImage, ui->workspace, &DrawModel::saveImage);
    QObject::connect(this, &MainWindow::importImage, ui->workspace, &DrawModel::openImage);
    QObject::connect(this, &MainWindow::vertMirror, ui->workspace, &DrawModel::mirrorVert);
    QObject::connect(this, &MainWindow::horzMirror, ui->workspace, &DrawModel::mirrorHorz);


    QObject::connect(playTimer, &QTimer::timeout, this, &MainWindow::playPreview);
    // for use of adding frames and playing frames
    QObject::connect(this, &MainWindow::addCurrentFrame, ui->workspace, &DrawModel::getFrameAndEmit);
    QObject::connect(ui->workspace, &DrawModel::addFrameToTimeline, this, &MainWindow::addFrameToTimeline);
    QObject::connect(this, &MainWindow::playPreviewWindow, this, &MainWindow::playPreview);


    QObject::connect(this, &MainWindow::previewStopped, ui->workspace, &DrawModel::previewHasStopped);

    //send signal for new transparency of pixel color
    QObject::connect(this, &MainWindow::changeTransparency, ui->workspace, &DrawModel::acceptTransparency);
    //change workspace image
    QObject::connect(this, &MainWindow::changeFrame, ui->workspace, &DrawModel::acceptChangeOfFrame);

    //Add current working frame to the previewVector
    QObject::connect(ui->workspace,&DrawModel::addFrameToPreviewTimeline,this,&MainWindow::addFrameToPreviewTimeline);
    //Retrieve the current frame from DrawModel and give to MainWindow so it can update itself in the timelineVector and previewVector
    QObject::connect(this, &MainWindow::updateFrame, ui->workspace, &DrawModel::getFrameToUpdate);
    //Gets the foreground to UPDATE the timeline Vector
    QObject::connect(ui->workspace,&DrawModel::updateTimelineFrame,this,&MainWindow::updateTimelineFrame);
    //Gets the composite image to UPDATE the preview Vector
    QObject::connect(ui->workspace,&DrawModel::updatePreviewFrame,this,&MainWindow::updatePreviewFrame);

    QObject::connect(this,&MainWindow::sendImageToPreview,&preview,&previewwindow::getImageVector);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::acceptWidthAndHeight(int width, int height)
{
    spriteWidth = width;
    spriteHeight = height;
    this->show();
    emit passWidthAndHeight(spriteWidth, spriteHeight, resizeImage);
    resizeImage = false;
}

void MainWindow::on_penSizeSlider_valueChanged(int value)
{
    ui->penSizeSpinBox->setValue(value);
    emit setPenSize(value);
}

void MainWindow::on_penButton_clicked()
{
    emit setToolType("Pen");
}

void MainWindow::on_eraserButton_clicked()
{
    emit setToolType("Eraser");
}

void MainWindow::on_paintButton_clicked()
{
    emit setToolType("FillBucket");
}

void MainWindow::on_lineButton_clicked()
{
    emit setToolType("Line");
}

void MainWindow::on_ellipseButton_clicked()
{
    emit setToolType("Ellipse");
}

void MainWindow::on_rectangleButton_clicked()
{
    emit setToolType("Rectangle");
}
void MainWindow::on_eyedropperButton_clicked()
{
    emit setToolType("Eyedropper");
}
void MainWindow::on_colorSelectionButton_clicked()
{
    colorPicker = new QColorDialog();
    QColor  color = colorPicker->getColor();
    colorPicker->close();
    QPalette palette;
    palette.setColor(QPalette::Window,color);
    ui->colorPreviewLabel->setAutoFillBackground(true);
    ui->colorPreviewLabel->setPalette(palette);
    emit setPenColor(color);
    delete colorPicker;
}

//set pen size of the tool
void MainWindow::on_penSizeSpinBox_valueChanged(int arg1)
{
    ui->penSizeSlider->setValue(arg1);
    ui->penSizeSlider->setSliderPosition(arg1);
    emit setPenSize(arg1);
}
//set color of preview color palette
void MainWindow::setColorPreviewWindow(QColor newColor)
{
    QPalette palette;
    palette.setColor(QPalette::Window,newColor);
    ui->colorPreviewLabel->setAutoFillBackground(true);
    ui->colorPreviewLabel->setPalette(palette);
}
//slot that takes image given from draw model
void MainWindow::receivePreviewImage(QImage preview)
{
    ui->previewLabel->setPixmap(QPixmap::fromImage(preview.scaled(128,128)));

}
//undo last distinct change made to canvas, up to three
void MainWindow::on_undoButton_clicked()
{
    emit undoSignal();
}
//send signal to redo most recent undo change
void MainWindow::on_redoButton_clicked()
{
    emit redoSignal();
}

//requests current frame from draw model
void MainWindow::on_addFrameButton_clicked()
{
    emit addCurrentFrame();

}
//adds frame to timeline of preview at current state
void MainWindow::addFrameToTimeline(QImage frame)
{
    timelineImages.push_back(frame);
    ui->frameSlider->setMaximum(timelineImages.size()-1);
    ui->frameSpinBox->setMaximum(timelineImages.size()-1);
    ui->frameSlider->setValue(timelineImages.size()-1);
    ui->frameSpinBox->setValue(timelineImages.size()-1);
}
void MainWindow::addFrameToPreviewTimeline(QImage frame)
{
    previewImages.push_back(frame);
    ui->previewLabel->setPixmap(QPixmap::fromImage(frame.scaled(128,128)));
}

//Start preview of frames of current working sprite
void MainWindow::playPreview()
{
    if(currentFrame == previewImages.size())
    {
        currentFrame = 0;
    }
    ui->previewLabel->setPixmap(QPixmap::fromImage(previewImages[currentFrame].scaled(128,128)));
    currentFrame++;

}
//Starts playback of frame previews at the set fps
void MainWindow::on_playButton_clicked()
{
    if(previewImages.size() > 0)
    {
        currentFrame = 0;
        playTimer->start(fpsPreview);
        previewPlaying = true;
        emit playPreviewWindow();
        emit previewStopped(true);  //means that preview is currently playing, and doesn't allow preview to update in real time
    }

}
//Stop preview playback and put to last frame in timeline
void MainWindow::on_stopButton_clicked()
{
    playTimer->stop();
    currentFrame = previewImages.size() - 1;
    previewPlaying = false;
    //ui->previewLabel->setPixmap(QPixmap::fromImage(timelineImages[currentFrame].scaled(128,128)));
    emit previewStopped(false); //returns preview to active image preview
}
//Changes Fps of preview playback and restarts preview
void MainWindow::on_fpsSpinBox_valueChanged(int arg1)
{
    fpsPreview = 1000/arg1;
    ui->fpsSlider->setValue(arg1);
    if(previewPlaying)
    {
        emit on_playButton_clicked();
    }
}
//Changes Fps of preview playback
void MainWindow::on_fpsSlider_valueChanged(int value)
{
    fpsPreview = 1000/value;
    ui->fpsSpinBox->setValue(value);
    if(previewPlaying)
    {
        emit on_playButton_clicked();
    }
}
//Update the current frame in the timeline vector
void MainWindow::updateTimelineFrame(QImage frame)
{
    if(timelineImages.size() > 0){
    timelineImages[ui->frameSlider->value()] = frame.copy();
    }
}
//Update the current frame in the preview vector
void MainWindow::updatePreviewFrame(QImage frame)
{

    if(previewImages.size() > 0)
    {
    previewImages[ui->frameSlider->value()] = frame.copy();
    }

}



void MainWindow::on_exportButton_clicked()
{
    exportPicture();

}

void MainWindow::on_resizeButton_clicked()
{

    size.show();
    size.raise();
    size.activateWindow();
    resizeImage = true;

}


void MainWindow::on_rotateClockwiseButton_clicked()
{
    emit rotateCanvas(90.0);
}

void MainWindow::on_rotateCounterClockwiseButton_clicked()
{
    emit rotateCanvas(-90.0);
}


void MainWindow::on_actionExport_triggered()
{
    exportPicture();
}

void MainWindow::exportPicture(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "",
                               tr("Images (*.png *.jpg)"));
    if(fileName != NULL){
        emit exportImage(fileName);
    }
}

void MainWindow::importPicture(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Picture"), "", tr("Images (*.png *.jpg)"));
    if(fileName != NULL){
        emit importImage(fileName);
    }
}








void MainWindow::on_actionImport_triggered()
{
    importPicture();
}

void MainWindow::on_transparencySpinBox_valueChanged(int arg1)
{
    ui->transparencySlider->setValue(arg1);
    emit changeTransparency(arg1);
}

void MainWindow::on_transparencySlider_valueChanged(int value)
{
    ui->transparencySpinBox->setValue(value);
    emit changeTransparency(value);

}

void MainWindow::on_horizontalMirrorButton_clicked()
{
    emit horzMirror();
}

void MainWindow::on_verticalMirrorButton_clicked()
{
    emit vertMirror();
}

void MainWindow::on_frameSlider_valueChanged(int value)
{
    ui->frameSpinBox->setValue(value);
    emit changeFrame(timelineImages[value], false);
}

void MainWindow::on_frameSpinBox_valueChanged(int arg1)
{
    ui->frameSlider->setValue(arg1);
    emit changeFrame(timelineImages[arg1], false);
}

void MainWindow::on_saveFrameButton_clicked()
{
    emit updateFrame();
}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_maximizePreviewButton_clicked()
{
    preview.show();
    //preview.raise();
    //preview.activateWindow();
    emit sendImageToPreview(previewImages);


}

void MainWindow::on_copyButton_clicked()
{
    if(!(timelineImages.size() == 0))
    {
        copyImage = timelineImages[ui->frameSlider->value()];
    }
}

void MainWindow::on_pasteButton_clicked()
{
    if(!(timelineImages.size() == 0))
    {
        //timelineImages[ui->frameSlider->value()] = copyImage;
        //previewImages[ui->frameSlider->value()] = copyImage;
        bool paste = true;

        emit changeFrame(copyImage, true);

    }

}
