/********************************************************************************
** Form generated from reading UI file 'sizeselector.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIZESELECTOR_H
#define UI_SIZESELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SizeSelector
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *widthSpinBox;
    QSpinBox *heightSpinBox;
    QLabel *titleLabel;
    QSlider *widthSlider;
    QSlider *heightSlider;
    QLabel *widthLabel;
    QLabel *pxWidthLabel;
    QLabel *heightLabel;
    QLabel *pxHeightLabel;

    void setupUi(QDialog *SizeSelector)
    {
        if (SizeSelector->objectName().isEmpty())
            SizeSelector->setObjectName(QStringLiteral("SizeSelector"));
        SizeSelector->resize(600, 380);
        buttonBox = new QDialogButtonBox(SizeSelector);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(230, 320, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widthSpinBox = new QSpinBox(SizeSelector);
        widthSpinBox->setObjectName(QStringLiteral("widthSpinBox"));
        widthSpinBox->setGeometry(QRect(80, 190, 160, 30));
        widthSpinBox->setMinimum(1);
        widthSpinBox->setMaximum(512);
        widthSpinBox->setValue(16);
        widthSpinBox->setDisplayIntegerBase(10);
        heightSpinBox = new QSpinBox(SizeSelector);
        heightSpinBox->setObjectName(QStringLiteral("heightSpinBox"));
        heightSpinBox->setGeometry(QRect(350, 190, 160, 30));
        heightSpinBox->setMinimum(1);
        heightSpinBox->setMaximum(512);
        heightSpinBox->setValue(16);
        titleLabel = new QLabel(SizeSelector);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(140, 30, 320, 120));
        QFont font;
        font.setPointSize(32);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setWordWrap(true);
        widthSlider = new QSlider(SizeSelector);
        widthSlider->setObjectName(QStringLiteral("widthSlider"));
        widthSlider->setGeometry(QRect(80, 240, 160, 22));
        widthSlider->setMinimum(1);
        widthSlider->setMaximum(512);
        widthSlider->setValue(16);
        widthSlider->setOrientation(Qt::Horizontal);
        heightSlider = new QSlider(SizeSelector);
        heightSlider->setObjectName(QStringLiteral("heightSlider"));
        heightSlider->setGeometry(QRect(350, 240, 160, 22));
        heightSlider->setMinimum(1);
        heightSlider->setMaximum(512);
        heightSlider->setValue(16);
        heightSlider->setOrientation(Qt::Horizontal);
        heightSlider->setInvertedAppearance(false);
        heightSlider->setInvertedControls(false);
        widthLabel = new QLabel(SizeSelector);
        widthLabel->setObjectName(QStringLiteral("widthLabel"));
        widthLabel->setGeometry(QRect(30, 190, 47, 30));
        QFont font1;
        font1.setPointSize(12);
        widthLabel->setFont(font1);
        pxWidthLabel = new QLabel(SizeSelector);
        pxWidthLabel->setObjectName(QStringLiteral("pxWidthLabel"));
        pxWidthLabel->setGeometry(QRect(245, 190, 21, 30));
        heightLabel = new QLabel(SizeSelector);
        heightLabel->setObjectName(QStringLiteral("heightLabel"));
        heightLabel->setGeometry(QRect(300, 190, 45, 30));
        heightLabel->setFont(font1);
        pxHeightLabel = new QLabel(SizeSelector);
        pxHeightLabel->setObjectName(QStringLiteral("pxHeightLabel"));
        pxHeightLabel->setGeometry(QRect(515, 190, 20, 30));

        retranslateUi(SizeSelector);
        QObject::connect(buttonBox, SIGNAL(accepted()), SizeSelector, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SizeSelector, SLOT(reject()));

        QMetaObject::connectSlotsByName(SizeSelector);
    } // setupUi

    void retranslateUi(QDialog *SizeSelector)
    {
        SizeSelector->setWindowTitle(QApplication::translate("SizeSelector", "Dialog", 0));
        titleLabel->setText(QApplication::translate("SizeSelector", "Set Sprite Width and Height", 0));
        widthLabel->setText(QApplication::translate("SizeSelector", "Width", 0));
        pxWidthLabel->setText(QApplication::translate("SizeSelector", "px", 0));
        heightLabel->setText(QApplication::translate("SizeSelector", "Height", 0));
        pxHeightLabel->setText(QApplication::translate("SizeSelector", "px", 0));
    } // retranslateUi

};

namespace Ui {
    class SizeSelector: public Ui_SizeSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIZESELECTOR_H
