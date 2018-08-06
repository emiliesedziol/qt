#include "widget.h"
#include "ui_widget.h"
#include <QList>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_AddItemButton_clicked()
{
    ui->listWidget->addItem("new Item");
}

void Widget::on_deleteItemButtom_clicked()
{
   ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void Widget::on_selectedItemsButton_clicked()
{
    //list of selected items
    QList<QListWidgetItem *> list = ui->listWidget->selectedItems();

    for (int i=0;i < list.count();i++)
    {
        qDebug() << "selected item " << list.at(i)->text() << ", row number " <<
                  ui->listWidget->row(list.at(i));
    }
}
