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

    /*
    int ret = dialog->exec();
    if ( ret == QDialog::Accepted)
    {
        QString position = dialog->getPosition();
        QString os = dialog->getOS();

        qDebug() << " data accepted";
        qDebug() << "position " << position;
        qDebug() << "os " << os;

        ui->infoLabel->setText(position);
        ui->osLabel->setText(os);
    }
    if ( ret == QDialog::Rejected)
    {
        qDebug() << " data rejected";
    }
    */

    // show the dialog non model
    connect(dialog,&InfoDialog::accepted,[=](){
        QString position = dialog->getPosition();
        QString os = dialog->getOS();

        qDebug() << " data accepted";
        qDebug() << "position " << position;
        qDebug() << "os " << os;

        ui->infoLabel->setText(position);
        ui->osLabel->setText(os);
    });
    connect(dialog,&InfoDialog::rejected,[=](){
        qDebug() << " it was rejected";
    });

    dialog->show();
    dialog->raise();
    dialog->activateWindow();
}
