#include "widget.h"
#include "ui_widget.h"
#include "customdialog.h"

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

void Widget::on_clickButton_clicked()
{
    CustomDialog * dialog = new CustomDialog(this);

    //set style sheet  - this sets only on the custmdialog.ui
    dialog->setStyleSheet("QPushButton{background-color: yellow; color : green;}");

    dialog->exec();
}
