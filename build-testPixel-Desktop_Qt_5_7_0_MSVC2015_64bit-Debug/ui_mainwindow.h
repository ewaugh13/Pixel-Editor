/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "drawmodel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    DrawModel *workspace;
    QGridLayout *gridLayout;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *toolsLayout;
    QPushButton *penButton;
    QPushButton *eraserButton;
    QPushButton *paintButton;
    QPushButton *lineButton;
    QPushButton *ellipseButton;
    QPushButton *rectangleButton;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QPushButton *pushButton_11;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QSlider *penSizeSlider;
    QLabel *label_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QPushButton *colorSelectionButton;
    QLabel *colorPreviewLabel;
    QSpinBox *penSizeSpinBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(879, 580);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        workspace = new DrawModel(centralWidget);
        workspace->setObjectName(QStringLiteral("workspace"));
        workspace->setGeometry(QRect(180, 10, 512, 512));
        workspace->setMinimumSize(QSize(512, 512));
        workspace->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(workspace);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 50, 89, 201));
        toolsLayout = new QVBoxLayout(verticalLayoutWidget);
        toolsLayout->setSpacing(6);
        toolsLayout->setContentsMargins(11, 11, 11, 11);
        toolsLayout->setObjectName(QStringLiteral("toolsLayout"));
        toolsLayout->setContentsMargins(0, 0, 0, 0);
        penButton = new QPushButton(verticalLayoutWidget);
        penButton->setObjectName(QStringLiteral("penButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/pen-9.png"), QSize(), QIcon::Normal, QIcon::Off);
        penButton->setIcon(icon);

        toolsLayout->addWidget(penButton);

        eraserButton = new QPushButton(verticalLayoutWidget);
        eraserButton->setObjectName(QStringLiteral("eraserButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/eraser-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        eraserButton->setIcon(icon1);

        toolsLayout->addWidget(eraserButton);

        paintButton = new QPushButton(verticalLayoutWidget);
        paintButton->setObjectName(QStringLiteral("paintButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/foundation_paint-bucket_simple-black_512x512.png"), QSize(), QIcon::Normal, QIcon::Off);
        paintButton->setIcon(icon2);

        toolsLayout->addWidget(paintButton);

        lineButton = new QPushButton(verticalLayoutWidget);
        lineButton->setObjectName(QStringLiteral("lineButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/1194994615287196054line.svg.hi.png"), QSize(), QIcon::Normal, QIcon::Off);
        lineButton->setIcon(icon3);

        toolsLayout->addWidget(lineButton);

        ellipseButton = new QPushButton(verticalLayoutWidget);
        ellipseButton->setObjectName(QStringLiteral("ellipseButton"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/300px-Ellipse_black.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        ellipseButton->setIcon(icon4);

        toolsLayout->addWidget(ellipseButton);

        rectangleButton = new QPushButton(verticalLayoutWidget);
        rectangleButton->setObjectName(QStringLiteral("rectangleButton"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/shape_square-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        rectangleButton->setIcon(icon5);

        toolsLayout->addWidget(rectangleButton);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 121, 21));
        QFont font;
        font.setPointSize(12);
        font.setUnderline(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(700, 40, 171, 142));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_10 = new QPushButton(gridLayoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        gridLayout_2->addWidget(pushButton_10, 3, 0, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout_2->addWidget(pushButton_9, 1, 0, 1, 1);

        pushButton_11 = new QPushButton(gridLayoutWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        gridLayout_2->addWidget(pushButton_11, 3, 1, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout_2->addWidget(pushButton_8, 2, 0, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_2->addWidget(pushButton_7, 0, 0, 1, 1);

        pushButton_12 = new QPushButton(gridLayoutWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/184524-200.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon6);

        gridLayout_2->addWidget(pushButton_12, 4, 0, 1, 1);

        pushButton_13 = new QPushButton(gridLayoutWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/prefix1/184528-200.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon7);

        gridLayout_2->addWidget(pushButton_13, 4, 1, 1, 1);

        pushButton_14 = new QPushButton(gridLayoutWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        gridLayout_2->addWidget(pushButton_14, 0, 1, 1, 1);

        pushButton_15 = new QPushButton(gridLayoutWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

        gridLayout_2->addWidget(pushButton_15, 1, 1, 1, 1);

        pushButton_16 = new QPushButton(gridLayoutWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

        gridLayout_2->addWidget(pushButton_16, 2, 1, 1, 1);

        penSizeSlider = new QSlider(centralWidget);
        penSizeSlider->setObjectName(QStringLiteral("penSizeSlider"));
        penSizeSlider->setGeometry(QRect(10, 280, 160, 19));
        penSizeSlider->setMinimum(1);
        penSizeSlider->setMaximum(512);
        penSizeSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(45, 260, 61, 16));
        label_2->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(50, 320, 101, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        colorSelectionButton = new QPushButton(verticalLayoutWidget_2);
        colorSelectionButton->setObjectName(QStringLiteral("colorSelectionButton"));

        verticalLayout->addWidget(colorSelectionButton);

        colorPreviewLabel = new QLabel(verticalLayoutWidget_2);
        colorPreviewLabel->setObjectName(QStringLiteral("colorPreviewLabel"));

        verticalLayout->addWidget(colorPreviewLabel);

        penSizeSpinBox = new QSpinBox(centralWidget);
        penSizeSpinBox->setObjectName(QStringLiteral("penSizeSpinBox"));
        penSizeSpinBox->setGeometry(QRect(111, 257, 51, 22));
        penSizeSpinBox->setMinimum(1);
        penSizeSpinBox->setMaximum(512);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 879, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        penButton->setText(QApplication::translate("MainWindow", "Pen", 0));
        eraserButton->setText(QApplication::translate("MainWindow", "Eraser", 0));
        paintButton->setText(QApplication::translate("MainWindow", "Paint Bucket", 0));
        lineButton->setText(QApplication::translate("MainWindow", "Line", 0));
        ellipseButton->setText(QApplication::translate("MainWindow", "Ellipse", 0));
        rectangleButton->setText(QApplication::translate("MainWindow", "Rectangle", 0));
        label->setText(QApplication::translate("MainWindow", "Drawing Tools", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "Vertical Mirror", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "Cut", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "Horizontal Mirror", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "Paste", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "Copy", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "Rotate", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "Rotate", 0));
        pushButton_14->setText(QApplication::translate("MainWindow", "New Frame", 0));
        pushButton_15->setText(QApplication::translate("MainWindow", "Resize", 0));
        pushButton_16->setText(QApplication::translate("MainWindow", "Export", 0));
        label_2->setText(QApplication::translate("MainWindow", "Pen Size", 0));
        colorSelectionButton->setText(QApplication::translate("MainWindow", "Color Selector", 0));
        colorPreviewLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
