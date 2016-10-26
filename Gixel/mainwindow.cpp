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
    scaleFactorX = 512/userDefinedX;
    scaleFactorY = 512/userDefinedY;

    popupSize.show();   //Calls the custom resolution window
    popupSize.raise();
    popupSize.activateWindow();

    scene = new GraphicsScene(ui);

    pix = new QPixmap(512,512); //Initialize the original pixmap, 512x512
    pix->fill(Qt::gray);

    scene->InitializeWorkspace(pix,scaleFactorX,scaleFactorY);  //Initialize the Workspace as a checkerboard
    scene->addPixmap(*pix);
    ui->Workspace->setScene(scene);

    //currentTool = new Pen();
    //currentTool->painter->begin(scene);

    QObject::connect(&updateTimer, &QTimer::timeout, this, &MainWindow::workspaceClickCheck);//Checks for workspaceClickCheck every 10ms
    QObject::connect(&popupSize, &SetSpriteSize::setHeightAndWidth, this, &MainWindow::setSpriteHeightAndWidth);
    QObject::connect(&popupSize, &SetSpriteSize::closeApp, this, &MainWindow::cancelSetSize);
    QObject::connect(scene, &GraphicsScene::graphicsSceneClicked, this, &MainWindow::placePoint);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::cancelSetSize()
{
    //this->close();
}

void MainWindow::setSpriteHeightAndWidth(int height, int width) //Gets the user defined height and width from the PopUp Window, determines scale factor, and initializes the spriteDataSheet
{
    userDefinedX = width;
    userDefinedY = height;
    scaleFactorX = 512/width;
    scaleFactorY = 512/height;

    /*
    spriteData.totalData.resize(width);
    for(int i =0; i< width; i++)
    {
        spriteData.totalData[i].resize(height);
    }
    for(int i = 0; i < width; i++)
    {
        for(int j=0; j < height; j++)
        {
            std::tuple<int,int,int,int> newData(0,0,0,0);
            spriteData.totalData[i][j] =  newData;
            //std::cout << "RGBA value at " << i << "," << j << " is " << std::get<0>(spriteData.totalData[i][j])
            //          << "," << std::get<1>(spriteData.totalData[i][j])<< "," << std::get<2>(spriteData.totalData[i][j]) << "," << std::get<3>(spriteData.totalData[i][j]) << std::endl;
        }
    }*/
    this->show();

    scene->InitializeWorkspace(pix,scaleFactorX,scaleFactorY);  //Reinitialize the workspace based on the new resolution
    scene->addPixmap(*pix); //Add the new pixmap to the scene so the Workspace updates
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

void MainWindow::placePoint(QPointF incomingPt)
{
    //currentTool->painter->drawPoint(incomingPt);
}
