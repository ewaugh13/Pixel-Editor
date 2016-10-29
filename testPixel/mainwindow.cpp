#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //central = new QWidget(this->centralWidget());
    artist = new DrawModel;
    size.show();
    size.raise();
    size.activateWindow();

    //mainSpace = new QGridLayout(ui->workspace);
    //ui->workspace->layout()->addWidget(artist);  //works because widget is also a grid layout
    spriteWidth = 16;
    spriteHeight = 16;

    //mainSpace->setColumnStretch(0,1);
    //mainSpace->setColumnStretch(3,1);
    //mainSpace->addWidget(artist,0,0,1,4);
    //setLayout(mainSpace);

    //connection between popup window and mainwindow
    QObject::connect(&size, &SizeSelector::setWidthAndHeight, this, &MainWindow::acceptWidthAndHeight);
    QObject::connect(this, &MainWindow::passWidthAndHeight, ui->workspace, &DrawModel::userGivenWidthAndHeight);
    QObject::connect(this, &MainWindow::setToolType, ui->workspace, &DrawModel::changeTools);
    QObject::connect(this, &MainWindow::setPenSize, ui->workspace, &DrawModel::changePenSize);
    QObject::connect(this, &MainWindow::setPenColor, ui->workspace, &DrawModel::changePenColor);
    QObject::connect(ui->workspace, &DrawModel::sendEyedropperColor, this, &MainWindow::setColorPreviewWindow);
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
    emit passWidthAndHeight(spriteWidth, spriteHeight);
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

