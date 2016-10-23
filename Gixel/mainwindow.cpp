#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    updateTimer.start(10);  //10ms interval

    scene = new GraphicsScene(this);
    pix = new QPixmap(398,398);
    scene->addPixmap(*pix);
    ui->Workspace->setScene(scene);
    currentTool = new Pen();
    currentTool->painter->begin(scene);

    popupSize.show();

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
    this->close();
}

void MainWindow::setSpriteHeightAndWidth(int height, int width)
{

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
    }
}
void MainWindow::on_PenToolButton_clicked()
{
    currentTool = new Pen();
     currentTool->painter->begin(pix);
    std::cout <<"Pen set" <<std::endl;
}
void MainWindow::workspaceClickCheck()
{

}

void MainWindow::placePoint(QPointF incomingPt)
{
    currentTool->painter->drawPoint(incomingPt);
}
