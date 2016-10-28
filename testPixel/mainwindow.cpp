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
