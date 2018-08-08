#include "widget.h"
#include "ui_widget.h"
#include "infodialog.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_provideButton_clicked()
{
    InfoDialog * dialog = new InfoDialog(this);
    int ret = dialog->exec();
    if ( ret == QDialog::Accepted)
    {
        qDebug() << " data accepted";
    }
    if ( ret == QDialog::Rejected)
    {
        qDebug() << " data rejected";
    }
}
