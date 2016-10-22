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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *NewProjectButton;
    QAction *OpenProjectButton;
    QAction *SaveProjectButton;
    QWidget *centralWidget;
    QGraphicsView *Workspace;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *TransformButtonLayout_2;
    QPushButton *RotateButton_2;
    QPushButton *HorzMirrorButton_2;
    QPushButton *VertMirrorButton_2;
    QPushButton *CutButton_2;
    QPushButton *CopyButton_2;
    QPushButton *PasteButton_2;
    QWidget *formLayoutWidget;
    QFormLayout *ToolButtonLayout_2;
    QPushButton *PenButton_2;
    QPushButton *EraserButton_2;
    QPushButton *EyeDropperButton_2;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(717, 573);
        NewProjectButton = new QAction(MainWindow);
        NewProjectButton->setObjectName(QStringLiteral("NewProjectButton"));
        OpenProjectButton = new QAction(MainWindow);
        OpenProjectButton->setObjectName(QStringLiteral("OpenProjectButton"));
        SaveProjectButton = new QAction(MainWindow);
        SaveProjectButton->setObjectName(QStringLiteral("SaveProjectButton"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Workspace = new QGraphicsView(centralWidget);
        Workspace->setObjectName(QStringLiteral("Workspace"));
        Workspace->setGeometry(QRect(120, 10, 400, 400));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(550, 20, 151, 171));
        TransformButtonLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        TransformButtonLayout_2->setSpacing(6);
        TransformButtonLayout_2->setContentsMargins(11, 11, 11, 11);
        TransformButtonLayout_2->setObjectName(QStringLiteral("TransformButtonLayout_2"));
        TransformButtonLayout_2->setContentsMargins(0, 0, 0, 0);
        RotateButton_2 = new QPushButton(verticalLayoutWidget);
        RotateButton_2->setObjectName(QStringLiteral("RotateButton_2"));

        TransformButtonLayout_2->addWidget(RotateButton_2);

        HorzMirrorButton_2 = new QPushButton(verticalLayoutWidget);
        HorzMirrorButton_2->setObjectName(QStringLiteral("HorzMirrorButton_2"));

        TransformButtonLayout_2->addWidget(HorzMirrorButton_2);

        VertMirrorButton_2 = new QPushButton(verticalLayoutWidget);
        VertMirrorButton_2->setObjectName(QStringLiteral("VertMirrorButton_2"));

        TransformButtonLayout_2->addWidget(VertMirrorButton_2);

        CutButton_2 = new QPushButton(verticalLayoutWidget);
        CutButton_2->setObjectName(QStringLiteral("CutButton_2"));

        TransformButtonLayout_2->addWidget(CutButton_2);

        CopyButton_2 = new QPushButton(verticalLayoutWidget);
        CopyButton_2->setObjectName(QStringLiteral("CopyButton_2"));

        TransformButtonLayout_2->addWidget(CopyButton_2);

        PasteButton_2 = new QPushButton(verticalLayoutWidget);
        PasteButton_2->setObjectName(QStringLiteral("PasteButton_2"));

        TransformButtonLayout_2->addWidget(PasteButton_2);

        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 10, 81, 331));
        ToolButtonLayout_2 = new QFormLayout(formLayoutWidget);
        ToolButtonLayout_2->setSpacing(6);
        ToolButtonLayout_2->setContentsMargins(11, 11, 11, 11);
        ToolButtonLayout_2->setObjectName(QStringLiteral("ToolButtonLayout_2"));
        ToolButtonLayout_2->setContentsMargins(0, 0, 0, 0);
        PenButton_2 = new QPushButton(formLayoutWidget);
        PenButton_2->setObjectName(QStringLiteral("PenButton_2"));

        ToolButtonLayout_2->setWidget(0, QFormLayout::LabelRole, PenButton_2);

        EraserButton_2 = new QPushButton(formLayoutWidget);
        EraserButton_2->setObjectName(QStringLiteral("EraserButton_2"));

        ToolButtonLayout_2->setWidget(1, QFormLayout::LabelRole, EraserButton_2);

        EyeDropperButton_2 = new QPushButton(formLayoutWidget);
        EyeDropperButton_2->setObjectName(QStringLiteral("EyeDropperButton_2"));

        ToolButtonLayout_2->setWidget(2, QFormLayout::LabelRole, EyeDropperButton_2);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(550, 220, 150, 150));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 717, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(NewProjectButton);
        menuFile->addAction(OpenProjectButton);
        menuFile->addAction(SaveProjectButton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        NewProjectButton->setText(QApplication::translate("MainWindow", "New Project", 0));
        OpenProjectButton->setText(QApplication::translate("MainWindow", "Open Project", 0));
        SaveProjectButton->setText(QApplication::translate("MainWindow", "Save Project", 0));
        RotateButton_2->setText(QApplication::translate("MainWindow", "Rotate", 0));
        HorzMirrorButton_2->setText(QApplication::translate("MainWindow", "Horizontal Mirror", 0));
        VertMirrorButton_2->setText(QApplication::translate("MainWindow", "Vertical Mirror", 0));
        CutButton_2->setText(QApplication::translate("MainWindow", "Cut", 0));
        CopyButton_2->setText(QApplication::translate("MainWindow", "Copy", 0));
        PasteButton_2->setText(QApplication::translate("MainWindow", "Paste", 0));
        PenButton_2->setText(QApplication::translate("MainWindow", "Pen", 0));
        EraserButton_2->setText(QApplication::translate("MainWindow", "Eraser", 0));
        EyeDropperButton_2->setText(QApplication::translate("MainWindow", "Eyedropper", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
