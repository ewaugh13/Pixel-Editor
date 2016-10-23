/********************************************************************************
** Form generated from reading UI file 'setspritesize.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETSPRITESIZE_H
#define UI_SETSPRITESIZE_H

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

class Ui_SetSpriteSize
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *widthSpinBox;
    QSpinBox *heightSpinbox;
    QLabel *spriteHeight;
    QLabel *heightPx;
    QLabel *label;
    QLabel *widthPx;
    QSlider *heightSlider;
    QSlider *widthSlider;
    QLabel *popUpTitle;

    void setupUi(QDialog *SetSpriteSize)
    {
        if (SetSpriteSize->objectName().isEmpty())
            SetSpriteSize->setObjectName(QStringLiteral("SetSpriteSize"));
        SetSpriteSize->resize(500, 300);
        buttonBox = new QDialogButtonBox(SetSpriteSize);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(330, 250, 156, 23));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widthSpinBox = new QSpinBox(SetSpriteSize);
        widthSpinBox->setObjectName(QStringLiteral("widthSpinBox"));
        widthSpinBox->setGeometry(QRect(110, 120, 71, 21));
        widthSpinBox->setMinimum(1);
        widthSpinBox->setMaximum(400);
        widthSpinBox->setValue(32);
        widthSpinBox->setDisplayIntegerBase(10);
        heightSpinbox = new QSpinBox(SetSpriteSize);
        heightSpinbox->setObjectName(QStringLiteral("heightSpinbox"));
        heightSpinbox->setGeometry(QRect(340, 120, 71, 21));
        heightSpinbox->setMinimum(1);
        heightSpinbox->setMaximum(400);
        heightSpinbox->setValue(32);
        spriteHeight = new QLabel(SetSpriteSize);
        spriteHeight->setObjectName(QStringLiteral("spriteHeight"));
        spriteHeight->setGeometry(QRect(270, 120, 61, 21));
        QFont font;
        font.setPointSize(12);
        spriteHeight->setFont(font);
        heightPx = new QLabel(SetSpriteSize);
        heightPx->setObjectName(QStringLiteral("heightPx"));
        heightPx->setGeometry(QRect(420, 120, 21, 16));
        label = new QLabel(SetSpriteSize);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 120, 51, 21));
        label->setFont(font);
        widthPx = new QLabel(SetSpriteSize);
        widthPx->setObjectName(QStringLiteral("widthPx"));
        widthPx->setGeometry(QRect(190, 120, 21, 16));
        heightSlider = new QSlider(SetSpriteSize);
        heightSlider->setObjectName(QStringLiteral("heightSlider"));
        heightSlider->setGeometry(QRect(270, 150, 160, 22));
        heightSlider->setMinimum(1);
        heightSlider->setMaximum(400);
        heightSlider->setValue(32);
        heightSlider->setOrientation(Qt::Horizontal);
        widthSlider = new QSlider(SetSpriteSize);
        widthSlider->setObjectName(QStringLiteral("widthSlider"));
        widthSlider->setGeometry(QRect(60, 150, 160, 22));
        widthSlider->setMinimum(1);
        widthSlider->setMaximum(400);
        widthSlider->setValue(32);
        widthSlider->setOrientation(Qt::Horizontal);
        widthSlider->setTickPosition(QSlider::NoTicks);
        popUpTitle = new QLabel(SetSpriteSize);
        popUpTitle->setObjectName(QStringLiteral("popUpTitle"));
        popUpTitle->setGeometry(QRect(90, 20, 291, 71));
        QFont font1;
        font1.setPointSize(20);
        popUpTitle->setFont(font1);
        popUpTitle->setAlignment(Qt::AlignCenter);
        popUpTitle->setWordWrap(true);

        retranslateUi(SetSpriteSize);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetSpriteSize, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetSpriteSize, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetSpriteSize);
    } // setupUi

    void retranslateUi(QDialog *SetSpriteSize)
    {
        SetSpriteSize->setWindowTitle(QApplication::translate("SetSpriteSize", "Dialog", 0));
        spriteHeight->setText(QApplication::translate("SetSpriteSize", "Height", 0));
        heightPx->setText(QApplication::translate("SetSpriteSize", "px", 0));
        label->setText(QApplication::translate("SetSpriteSize", "Width", 0));
        widthPx->setText(QApplication::translate("SetSpriteSize", "px", 0));
        popUpTitle->setText(QApplication::translate("SetSpriteSize", "Enter the Height and Width of the Sprite", 0));
    } // retranslateUi

};

namespace Ui {
    class SetSpriteSize: public Ui_SetSpriteSize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETSPRITESIZE_H
