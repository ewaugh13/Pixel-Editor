#ifndef SIZESELECTOR_H
#define SIZESELECTOR_H

#include <QDialog>


namespace Ui {
class SizeSelector;
}

class SizeSelector : public QDialog
{
    Q_OBJECT

public:
    explicit SizeSelector(QWidget *parent = 0);
    ~SizeSelector();
signals:
    void setWidthAndHeight(int,int);


private slots:
    void on_widthSpinBox_valueChanged(int arg1);

    void on_widthSlider_sliderMoved(int position);

    void on_heightSpinBox_valueChanged(int arg1);

    void on_heightSlider_sliderMoved(int position);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::SizeSelector *ui;
};

#endif // SIZESELECTOR_H
