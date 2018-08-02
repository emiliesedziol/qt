#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*
    1 - String Notation
    connect(ui->pushButtonAA,SIGNAL(clicked()),
            this,SLOT(changeText()));
    */
/*
    2 - Functor Notation : Regular Slots
    connect(ui->pushButtonAA,&QPushButton::clicked,this,&Widget::changeText);
    */

    // 3 - Functor Notation lambdas
    // changetText is not used here
    connect(ui->pushButtonAA,&QPushButton::clicked,[=](){
        ui->labelBB->setText("Lamdba functor notation");
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeText()
{
    qDebug() << "the button was pushed";

    ui->labelBB->setText("The button has been clicked");
}
