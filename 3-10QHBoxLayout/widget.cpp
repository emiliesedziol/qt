#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // in forms -> widget.ui
    // select all buttons and click on the horizontal layout
    // then outside of that click and click on the horizontal layout
    // this produces the same effect as below
/*
    QHBoxLayout * layout = new QHBoxLayout();
    layout->addWidget(ui->oneButton);
    layout->addWidget(ui->twoButton);
    layout->addWidget(ui->threeButton);
    layout->addWidget(ui->fourButton);
    layout->addWidget(ui->fiveButton);

    setLayout(layout);
    */
}

Widget::~Widget()
{
    delete ui;
}
