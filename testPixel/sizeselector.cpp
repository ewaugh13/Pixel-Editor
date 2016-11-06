#include "sizeselector.h"
#include "ui_sizeselector.h"

SizeSelector::SizeSelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SizeSelector)
{
    ui->setupUi(this);
    squareRatio =false;
    sixteenBy9Ratio = false;
    fourByThreeRatio = false;
}

SizeSelector::~SizeSelector()
{
    delete ui;
}

void SizeSelector::on_widthSpinBox_valueChanged(int arg1)
{
    ui->widthSlider->setValue(arg1);
    if(squareRatio)
    {
        ui->heightSpinBox->setValue(ui->widthSpinBox->value());
        ui->heightSlider->setValue(ui->widthSlider->value());
    }
    else if(sixteenBy9Ratio)
    {
        int newHeight = ui->widthSpinBox->value() * 9 / 16;
        ui->heightSpinBox->setValue(newHeight);
        ui->heightSlider->setValue(newHeight);
    }
    else if(fourByThreeRatio)
    {
        int newHeight = ui->widthSpinBox->value() * 3 / 4;
        ui->heightSpinBox->setValue(newHeight);
        ui->heightSlider->setValue(newHeight);
    }
}

void SizeSelector::on_widthSlider_valueChanged(int position)
{
    ui->widthSpinBox->setValue(position);
    if(squareRatio)
    {
        ui->heightSpinBox->setValue(ui->widthSpinBox->value());
        ui->heightSlider->setValue(ui->widthSlider->value());
    }
    else if(sixteenBy9Ratio)
    {
        int newHeight = ui->widthSpinBox->value() * 9 / 16;
        ui->heightSpinBox->setValue(newHeight);
        ui->heightSlider->setValue(newHeight);
    }
    else if(fourByThreeRatio)
    {
        int newHeight = ui->widthSpinBox->value() * 3 / 4;
        ui->heightSpinBox->setValue(newHeight);
        ui->heightSlider->setValue(newHeight);
    }
}

void SizeSelector::on_heightSpinBox_valueChanged(int arg1)
{
    ui->heightSlider->setValue(arg1);
    if(squareRatio)
    {
        ui->widthSlider->setValue(ui->heightSlider->value());
        ui->widthSpinBox->setValue(ui->heightSpinBox->value());
    }
    else if(sixteenBy9Ratio)
    {
        int newWidth = ui->heightSpinBox->value() * 16 / 9;
        ui->widthSlider->setValue(newWidth);
        ui->widthSpinBox->setValue(newWidth);
    }
    else if(fourByThreeRatio)
    {
        int newWidth = ui->heightSpinBox->value() * 4 / 3;
        ui->widthSlider->setValue(newWidth);
        ui->widthSpinBox->setValue(newWidth);
    }
}

void SizeSelector::on_heightSlider_valueChanged(int position)
{
    ui->heightSpinBox->setValue(position);
    if(squareRatio)
    {
        ui->widthSlider->setValue(ui->heightSlider->value());
        ui->widthSpinBox->setValue(ui->heightSpinBox->value());
    }
    else if(sixteenBy9Ratio)
    {
        int newWidth = ui->heightSpinBox->value() * 16 / 9;
        ui->widthSlider->setValue(newWidth);
        ui->widthSpinBox->setValue(newWidth);
    }
    else if(fourByThreeRatio)
    {
        int newWidth = ui->heightSpinBox->value() * 4 / 3;
        ui->widthSlider->setValue(newWidth);
        ui->widthSpinBox->setValue(newWidth);
    }
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

void SizeSelector::on_squareAspectCheckBox_clicked(bool checked)
{
    squareRatio = checked;
    if(squareRatio)
    {
        sixteenBy9Ratio = false;
        fourByThreeRatio = false;
        ui->sixteenByNineRatioCheckBox->setChecked(false);
        ui->fourByNineRatioCheckBox->setChecked(false);
        ui->heightSpinBox->setValue(ui->widthSpinBox->value());
        ui->heightSlider->setValue(ui->widthSlider->value());
    }
}

void SizeSelector::on_sixteenByNineRatioCheckBox_clicked(bool checked)
{
    sixteenBy9Ratio = checked;
    if(sixteenBy9Ratio)
    {
        squareRatio = false;
        fourByThreeRatio = false;
        ui->squareAspectCheckBox->setChecked(false);
        ui->fourByNineRatioCheckBox->setChecked(false);
        int newHeight = ui->widthSpinBox->value() * 9 / 16;
        ui->heightSpinBox->setValue(newHeight);
        ui->heightSlider->setValue(newHeight);
    }
}

void SizeSelector::on_fourByNineRatioCheckBox_clicked(bool checked) //mistakes were made, should be 4 by 3
{
    fourByThreeRatio = checked;
    if(fourByThreeRatio)
    {
        squareRatio = false;
        sixteenBy9Ratio = false;
        ui->squareAspectCheckBox->setChecked(false);
        ui->sixteenByNineRatioCheckBox->setChecked(false);
        int newHeight = ui->widthSpinBox->value() * 3 / 4;
        ui->heightSpinBox->setValue(newHeight);
        ui->heightSlider->setValue(newHeight);
    }
}



