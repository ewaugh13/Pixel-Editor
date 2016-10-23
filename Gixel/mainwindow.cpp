#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    popupSize.show();

    QObject::connect(&popupSize, &SetSpriteSize::setHeightAndWidth, this, &MainWindow::setSpriteHeightAndWidth);
    QObject::connect(&popupSize, &SetSpriteSize::closeApp, this, &MainWindow::cancelSetSize);
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
