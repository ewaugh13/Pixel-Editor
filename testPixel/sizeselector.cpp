#include "sizeselector.h"
#include "ui_sizeselector.h"

SizeSelector::SizeSelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SizeSelector)
{
    ui->setupUi(this);
}

SizeSelector::~SizeSelector()
{
    delete ui;
}

void SizeSelector::on_widthSpinBox_valueChanged(int arg1)
{
    ui->widthSlider->setValue(arg1);
}

void SizeSelector::on_widthSlider_sliderMoved(int position)
{
    ui->widthSpinBox->setValue(position);
}

void SizeSelector::on_heightSpinBox_valueChanged(int arg1)
{
    ui->heightSlider->setValue(arg1);
}

void SizeSelector::on_heightSlider_sliderMoved(int position)
{
    ui->heightSpinBox->setValue(position);
}

void SizeSelector::on_buttonBox_accepted()
{
    emit setWidthAndHeight(ui->widthSpinBox->value(), ui->heightSpinBox->value());
    this->close();
}

void SizeSelector::on_buttonBox_rejected()
{
    emit setWidthAndHeight(16, 16);
    this->close();
}
