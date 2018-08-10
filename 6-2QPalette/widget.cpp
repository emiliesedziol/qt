#include "widget.h"
#include "ui_widget.h"
#include <QPalette>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // retrieve color
    QPalette palette = ui->label->palette();
//    ui->label->setAutoFillBackground(true);  // REMEMBER this needs to be set to change background color
    // or in widget.ui the autofillbackground needs to be checked  !!!!

    //modify palette
    palette.setColor(QPalette::Window,Qt::blue);
    palette.setColor(QPalette::WindowText,Qt::red);

    //reset palette to widget
    ui->label->setPalette(palette);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_activeButton_clicked()
{
    QPalette::ColorGroup activeButtonColorGroup = ui->activeButton->palette().currentColorGroup();
    QPalette::ColorGroup disableButtonColorGroup = ui->disableButton->palette().currentColorGroup();

    qDebug() << "active button " << activeButtonColorGroup;
    qDebug() << "disabled button " << disableButtonColorGroup;
}
