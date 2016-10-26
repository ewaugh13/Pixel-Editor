#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    userDefinedX = 16;  //Defaults the screen to 16x16 sprite pixels
    userDefinedY = 16;
    scaleFactorX = 512.0/userDefinedX;
    scaleFactorY = 512.0/userDefinedY;

    popupSize.show();   //Calls the custom resolution window
    popupSize.raise();
    popupSize.activateWindow();

    scene = new GraphicsScene(ui);

    pixBackground = new QPixmap(512,512); //Initialize the original pixmap, 512x512
    pixForeground = new QPixmap(512,512);
    pixResultant = new QPixmap(512,512);

    pixResultant->fill(Qt::transparent);

    scene->InitializeWorkspace(pixBackground,scaleFactorX,scaleFactorY);  //Initialize the Workspace as a checkerboard
    scene->InitializeColorspace(pixForeground,scaleFactorX,scaleFactorY);
    //scene->combineForeAndBack(pixResultant,pixBackground,pixForeground); //for some reason doesn't allow to resize if in
    scene->addPixmap(*pixResultant);
    //scene->addPixmap(*pixBackground);
    //scene->addPixmap(*pixForeground);
    ui->Workspace->setScene(scene);

    //currentTool = new Pen();
    //currentTool->painter->begin(scene);

    QObject::connect(&updateTimer, &QTimer::timeout, this, &MainWindow::workspaceClickCheck);//Checks for workspaceClickCheck every 10ms
    QObject::connect(&popupSize, &SetSpriteSize::setHeightAndWidth, this, &MainWindow::setSpriteHeightAndWidth);
    QObject::connect(&popupSize, &SetSpriteSize::closePopup, this, &MainWindow::cancelSetSize);
    QObject::connect(scene, &GraphicsScene::graphicsSceneDrawn, this, &MainWindow::drawChanges);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::cancelSetSize(int height, int width)
{
    this->show();
    setSpriteHeightAndWidth(height, width);
}

void MainWindow::setSpriteHeightAndWidth(int height, int width) //Gets the user defined height and width from the PopUp Window, determines scale factor, and initializes the spriteDataSheet
{
    userDefinedX = width;
    userDefinedY = height;
    scaleFactorX = 512.0/width;
    scaleFactorY = 512.0/height;

    this->show();

    scene->InitializeWorkspace(pixBackground,scaleFactorX,scaleFactorY);  //Reinitialize the workspace based on the new resolution
    scene->InitializeColorspace(pixForeground,scaleFactorX,scaleFactorY);
    //scene->addPixmap(*pixBackground); //Add the new pixmap to the scene so the Workspace updates
    //scene->addPixmap(*pixForeground);
    scene->combineForeAndBack(pixResultant,pixBackground,pixForeground);
    scene->addPixmap(*pixResultant);

}
void MainWindow::on_PenToolButton_clicked()
{
    currentTool = new Pen();
    //currentTool->painter->begin(pix);
    std::cout <<"Pen set" <<std::endl;
}
void MainWindow::workspaceClickCheck()
{

}

void MainWindow::drawChanges()
{
    //currentTool->painter->drawPoint(incomingPt);
    //scene->addPixmap(*pixResultant); //Add the new pixmap to the scene so the Workspace updates
    QRegion region(QRect(0,0,512,512));
    scene->addPixmap(*pixResultant);
    //scene->combineForeAndBack(pixResultant, pixBackground, pixForeground);
}
