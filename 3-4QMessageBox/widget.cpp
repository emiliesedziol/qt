#include "widget.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton * button = new QPushButton(this);
    button->setText("Click it");
    button->move(200,200);
    connect(button,&QPushButton::clicked,[=](){

        /* critical message
        int ret = QMessageBox::critical(this,"Critical title",
                                        "Help",
                                        QMessageBox::Ok | QMessageBox::Cancel);
        */

        // information message
        /*
        int ret = QMessageBox::information(this,"Information",
                                        "What happened, do something",
                                        QMessageBox::Ok | QMessageBox::Cancel);
        */

        // question
        /*
        int ret = QMessageBox::question(this,"Question",
                                        "What do you want",
                                        QMessageBox::Ok | QMessageBox::Cancel);
        */

        // warning
        int ret = QMessageBox::warning(this,"Warning",
                                        "Red alert",
                                        QMessageBox::Ok | QMessageBox::Cancel);


        /* hard way to display a message box
        QMessageBox message;
        message.setMinimumSize(200,300);
        message.setWindowTitle("message title");
        message.setText("some text");
        message.setInformativeText("what do you want to do");
        message.setIcon(QMessageBox::Critical);
        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        message.setDefaultButton(QMessageBox::Cancel);

        int ret = message.exec();
        */

        if ( ret == QMessageBox::Ok)
        {
            qDebug() << "The OK was clicked";
        } else
        {
            qDebug() << "Cancelled was clicked";
        }
    });
}

Widget::~Widget()
{

}
