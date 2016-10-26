#ifndef SETSPRITESIZE_H
#define SETSPRITESIZE_H

#include <QDialog>

namespace Ui {
class SetSpriteSize;
}

class SetSpriteSize : public QDialog
{
    Q_OBJECT

public:
    explicit SetSpriteSize(QWidget *parent = 0);
    ~SetSpriteSize();

signals:
    void setHeightAndWidth(int,int);
    void closePopup(int,int);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_heightSpinbox_valueChanged(int arg1);

    void on_widthSpinBox_valueChanged(int arg1);

    void on_heightSlider_sliderMoved(int position);

    void on_widthSlider_sliderMoved(int position);

private:
    Ui::SetSpriteSize *ui;
};

#endif // SETSPRITESIZE_H
