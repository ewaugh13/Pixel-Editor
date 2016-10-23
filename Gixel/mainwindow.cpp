#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene* scene = new QGraphicsScene(this);
    QPixmap *pix = new QPixmap(398,398);
    scene->addPixmap(*pix);
    ui->Workspace->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PenToolButton_clicked()
{
    currentTool = new Pen();

    std::cout <<"Pen set" <<std::endl;
}

