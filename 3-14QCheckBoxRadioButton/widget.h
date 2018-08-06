#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_macBox_toggled(bool checked);

    void on_coffeBox_toggled(bool checked);

    void on_aRadioButton_toggled(bool checked);

    void on_grabDataButton_clicked();

    void on_setStateButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
