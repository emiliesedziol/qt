#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // in forms -> widget.ui
    // select all buttons and click on the vertical layout
    // then outside of that click and click on the vertical layout
    // somewhat the same below
    // the buttons are stacked together and do not change vertically, horizontally they do expand

    /*
    QVBoxLayout * layout = new QVBoxLayout();
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
