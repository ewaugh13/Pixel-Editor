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


void MainWindow::on_penSizeSpinBox_valueChanged(int arg1)
{
    ui->penSizeSlider->setValue(arg1);
    ui->penSizeSlider->setSliderPosition(arg1);
    emit setPenSize(arg1);
}
void MainWindow::setColorPreviewWindow(QColor newColor)
{
    QPalette palette;
    palette.setColor(QPalette::Window,newColor);
    ui->colorPreviewLabel->setAutoFillBackground(true);
    ui->colorPreviewLabel->setPalette(palette);
}

void MainWindow::receivePreviewImage(QImage preview)
{
    ui->previewLabel->setPixmap(QPixmap::fromImage(preview.scaled(128,128)));

}

void MainWindow::on_undoButton_clicked()
{
    emit undoSignal();
}

void MainWindow::on_redoButton_clicked()
{
    emit redoSignal();
}
void MainWindow::on_pushButton_12_clicked()
{
    emit rotateCanvas(-90.0);
}

void MainWindow::on_pushButton_13_clicked()
{
    emit rotateCanvas(90.0);
}

void MainWindow::on_pushButton_15_clicked()
{
    size.show();
    size.raise();
    size.activateWindow();
    resizeImage = true;
}

void MainWindow::on_pushButton_16_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "",
                               tr("Images (*.png *.jpg)"));

    emit exportImage(fileName);
}
