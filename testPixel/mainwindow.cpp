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

    QColorDialog* dialog = new QColorDialog();
    dialog->setWindowFlags(Qt::Widget);
    dialog->setOptions(QColorDialog::DontUseNativeDialog | QColorDialog::ShowAlphaChannel);

    auto action = new QWidgetAction(0);
    action->setDefaultWidget(dialog);

    QMenu* menu = new QMenu();
    menu->addAction(action);

    QToolButton* button = new QToolButton();
    button->setMenu( menu );
    button->setPopupMode( QToolButton::InstantPopup );


    //connection between popup window and mainwindow
    QObject::connect(&size, &SizeSelector::setWidthAndHeight, this, &MainWindow::acceptWidthAndHeight);
    QObject::connect(this, &MainWindow::passWidthAndHeight, ui->workspace, &DrawModel::userGivenWidthAndHeight);
    QObject::connect(this, &MainWindow::passColor, ui->workspace, &DrawModel::userGivenColor);

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


void MainWindow::on_colorSelector_clicked()
{
    QColorDialog* dialog = new QColorDialog();
    dialog->show();
    QColor color = QColorDialog::getColor();
    dialog->close();
    QPalette palette;
    palette.setColor(QPalette::Window, color);
    ui->label->setAutoFillBackground(true);
    ui->label->setPalette(palette);
    emit passColor(color);
}
