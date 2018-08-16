#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new QFileSystemModel(this);

    // Qt uses the forward slash '/' in the path
    parentIndex = model->setRootPath("D:/github/Qt");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    int rowCount = model->rowCount(parentIndex);
    qDebug() << "row count: " << QString::number(rowCount);

    for (int i=0; i<rowCount;i++)
    {
        QModelIndex index = model->index(i,0,parentIndex);
        QString data = model->data(index,Qt::DisplayRole).toString();
        // error conversion from QVariant to non-scalar type QString request add '.toString()' to get rid of the error
        qDebug() << "Row " << i << " data " << data;
    }
}
