#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Earth");
    ui->comboBox->addItem("Mars");
    ui->comboBox->addItem("Venus");
    ui->comboBox->addItem("Saturn");
    ui->comboBox->addItem("Pluto almost");

    // allow data to be entered into combo box
    // delete data, enter new data and press enter, the new item will be put at the bottom of the list
    ui->comboBox->setEditable(true);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_captureValuesButton_clicked()
{
    qDebug() << "The current selected item is " << ui->comboBox->currentText()
             << " and the index is " << QString::number(ui->comboBox->currentIndex()) ;
}

void Widget::on_setValuesButton_clicked()
{
    ui->comboBox->setCurrentIndex(3);  // sets to saturn
}

void Widget::on_getValuesButton_clicked()
{
    qDebug() << "The combo box currently has " << QString::number(ui->comboBox->count());
    for(int i=0; i < ui->comboBox->count(); i++)
    {
        qDebug() << ui->comboBox->itemText(i);
    }
}
