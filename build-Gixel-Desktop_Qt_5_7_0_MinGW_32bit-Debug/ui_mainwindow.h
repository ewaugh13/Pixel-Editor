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
    QVBoxLayout *ToolsLayout;
    QPushButton *PenToolButton;
    QPushButton *EraserToolButton;
    QPushButton *EyedropperToolButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *TransformLayout;
    QPushButton *VerticalMirrorButton;
    QPushButton *HorizontalMirrorButton;
    QPushButton *Rotate90Button;
    QPushButton *CutImageButton;
    QPushButton *CopyImageButton;
    QPushButton *PasteImageButton;
    QGraphicsView *graphicsView;
    QPushButton *PreviewSettingsButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(862, 633);
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
        Workspace->setGeometry(QRect(130, 30, 514, 514));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 101, 151));
        ToolsLayout = new QVBoxLayout(verticalLayoutWidget);
        ToolsLayout->setSpacing(6);
        ToolsLayout->setContentsMargins(11, 11, 11, 11);
        ToolsLayout->setObjectName(QStringLiteral("ToolsLayout"));
        ToolsLayout->setContentsMargins(0, 0, 0, 0);
        PenToolButton = new QPushButton(verticalLayoutWidget);
        PenToolButton->setObjectName(QStringLiteral("PenToolButton"));

        ToolsLayout->addWidget(PenToolButton);

        EraserToolButton = new QPushButton(verticalLayoutWidget);
        EraserToolButton->setObjectName(QStringLiteral("EraserToolButton"));

        ToolsLayout->addWidget(EraserToolButton);

        EyedropperToolButton = new QPushButton(verticalLayoutWidget);
        EyedropperToolButton->setObjectName(QStringLiteral("EyedropperToolButton"));

        ToolsLayout->addWidget(EyedropperToolButton);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(660, 30, 160, 181));
        TransformLayout = new QVBoxLayout(verticalLayoutWidget_2);
        TransformLayout->setSpacing(6);
        TransformLayout->setContentsMargins(11, 11, 11, 11);
        TransformLayout->setObjectName(QStringLiteral("TransformLayout"));
        TransformLayout->setContentsMargins(0, 0, 0, 0);
        VerticalMirrorButton = new QPushButton(verticalLayoutWidget_2);
        VerticalMirrorButton->setObjectName(QStringLiteral("VerticalMirrorButton"));

        TransformLayout->addWidget(VerticalMirrorButton);

        HorizontalMirrorButton = new QPushButton(verticalLayoutWidget_2);
        HorizontalMirrorButton->setObjectName(QStringLiteral("HorizontalMirrorButton"));

        TransformLayout->addWidget(HorizontalMirrorButton);

        Rotate90Button = new QPushButton(verticalLayoutWidget_2);
        Rotate90Button->setObjectName(QStringLiteral("Rotate90Button"));

        TransformLayout->addWidget(Rotate90Button);

        CutImageButton = new QPushButton(verticalLayoutWidget_2);
        CutImageButton->setObjectName(QStringLiteral("CutImageButton"));

        TransformLayout->addWidget(CutImageButton);

        CopyImageButton = new QPushButton(verticalLayoutWidget_2);
        CopyImageButton->setObjectName(QStringLiteral("CopyImageButton"));

        TransformLayout->addWidget(CopyImageButton);

        PasteImageButton = new QPushButton(verticalLayoutWidget_2);
        PasteImageButton->setObjectName(QStringLiteral("PasteImageButton"));

        TransformLayout->addWidget(PasteImageButton);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(670, 230, 150, 150));
        PreviewSettingsButton = new QPushButton(centralWidget);
        PreviewSettingsButton->setObjectName(QStringLiteral("PreviewSettingsButton"));
        PreviewSettingsButton->setGeometry(QRect(670, 390, 151, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 862, 21));
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
        PenToolButton->setText(QApplication::translate("MainWindow", "Pen", 0));
        EraserToolButton->setText(QApplication::translate("MainWindow", "Eraser", 0));
        EyedropperToolButton->setText(QApplication::translate("MainWindow", "Eyedropper", 0));
        VerticalMirrorButton->setText(QApplication::translate("MainWindow", "Vert. Mirror", 0));
        HorizontalMirrorButton->setText(QApplication::translate("MainWindow", "Horz. Mirror", 0));
        Rotate90Button->setText(QApplication::translate("MainWindow", "Rotate 90 ", 0));
        CutImageButton->setText(QApplication::translate("MainWindow", "Cut", 0));
        CopyImageButton->setText(QApplication::translate("MainWindow", "Copy", 0));
        PasteImageButton->setText(QApplication::translate("MainWindow", "Paste", 0));
        PreviewSettingsButton->setText(QApplication::translate("MainWindow", "Preview Settings", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
