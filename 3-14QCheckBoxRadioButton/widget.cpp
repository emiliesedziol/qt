#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QButtonGroup * buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->macBox);
    buttonGroup->addButton(ui->windowsBoc);
    buttonGroup->addButton(ui->linuxBox);

    // set so only 1 box can be checked
    buttonGroup->setExclusive(true);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_macBox_toggled(bool checked)
{
    if(checked)
    {
        qDebug() << "Mac box had been checked";
    }else
    {
        qDebug() << "Mac box has not been checked";
    }

}

void Widget::on_coffeBox_toggled(bool checked)
{
    if(checked)
    {
        qDebug() << "Coffee has been selected";
    }
    else {
        qDebug() << "Coffee is no longer selected";
    }
}

void Widget::on_aRadioButton_toggled(bool checked)
{
    if(checked)
    {
        qDebug() << "A has been selected";
    }
    else {
        qDebug() << "A has not been selected";
    }
}

void Widget::on_grabDataButton_clicked()
{
    qDebug()<< endl;
    qDebug() << "inside grab data button";
    if( ui->windowsBoc->isChecked())
    {
        qDebug() << "Windows has been checked";
    }

    if (ui->bRadioButton->isChecked())
    {
        qDebug() << "B has been checked";
    }

    if(ui->teeBox->isChecked())
    {
        qDebug() << "Tee has been checked";
    }
    qDebug() << endl;
}

void Widget::on_setStateButton_clicked()
{
    if (ui->windowsBoc->isChecked())
    {
        ui->windowsBoc->setChecked(false);
    }
    else {
        ui->windowsBoc->setChecked(true);
    }

    if(ui->coffeBox->isChecked())
    {
        ui->coffeBox->setChecked(false);
    }
    else {
        ui->coffeBox->setChecked(true);
    }
}
