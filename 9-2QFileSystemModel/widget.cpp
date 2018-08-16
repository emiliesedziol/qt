#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QString path = "D:/github/Qt/";

    dirModel = new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::Dirs);
    dirModel->setRootPath(path);  // the widget displayed c: and d:
    ui->treeView->setModel(dirModel);

    filesModel = new QFileSystemModel(this);
    filesModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    filesModel->setRootPath(path);
    ui->listView->setModel(filesModel);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_treeView_clicked(const QModelIndex &index)
{
    QString path = dirModel->fileInfo(index).absoluteFilePath();
    // qDebug() << "path " << path;
    ui->listView->setRootIndex(filesModel->setRootPath(path));
}
