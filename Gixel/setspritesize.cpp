#include "setspritesize.h"
#include "ui_setspritesize.h"

SetSpriteSize::SetSpriteSize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetSpriteSize)
{
    ui->setupUi(this);
}

SetSpriteSize::~SetSpriteSize()
{
    delete ui;
}

void SetSpriteSize::on_buttonBox_accepted()
{
    emit setHeightAndWidth(ui->heightSpinbox->value(), ui->widthSpinBox->value());
    this->close();
}

void SetSpriteSize::on_buttonBox_rejected()
{
    emit closePopup(ui->heightSpinbox->value(), ui->widthSpinBox->value());
    this->close();
}

void SetSpriteSize::on_heightSpinbox_valueChanged(int arg1)
{
    ui->heightSlider->setValue(arg1);
}

void SetSpriteSize::on_widthSpinBox_valueChanged(int arg1)
{
    ui->widthSlider->setValue(arg1);
}

void SetSpriteSize::on_heightSlider_sliderMoved(int position)
{
    ui->heightSpinbox->setValue(position);
}

void SetSpriteSize::on_widthSlider_sliderMoved(int position)
{
    ui->widthSpinBox->setValue(position);
}
