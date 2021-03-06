#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>

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

void Widget::on_chooseDirButton_clicked()
{
    QString filename = QFileDialog::getExistingDirectory(this,"Choose Folder");
    if (filename.isEmpty())
    {
        return;
    }
    ui->lineEdit->setText(filename);
}

void Widget::on_createDirButton_clicked()
{
    QString dirPath = ui->lineEdit->text();
    if (dirPath.isEmpty())
    {
        return;
    }
    QDir dir(dirPath);
    if ( !dir.exists())
    {
      if( dir.mkpath(dirPath) )
      {
          QMessageBox::information(this,"Message","Directory Created");
      }
    }else
    {
        QMessageBox::information(this,"Message","Directory all ready exists");
    }
}

void Widget::on_dirExistButton_clicked()
{
    QString dirPath = ui->lineEdit->text();
    if (dirPath.isEmpty())
    {
        return;
    }
    QDir dir(dirPath);
    if (dir.exists())
    {
        QMessageBox::information(this,"Message","Directory exists");
    }else {
        QMessageBox::information(this,"Message","Directory does not exist");
    }
}


void Widget::on_dirOrFileButton_clicked()
{
    QFileInfo fileInfo(ui->listWidget->currentItem()->text());
    if (fileInfo.isDir())
    {
        QMessageBox::information(this,"Message","This is a Directory");
    }
    else if (fileInfo.isFile())
    {
        QMessageBox::information(this,"Message","This is a file");
    }else
    {
        QMessageBox::information(this,"Message","this is something");
    }
}

void Widget::on_folderContentsButton_clicked()
{
    ui->listWidget->clear();
    QString dirPath = ui->lineEdit->text();
    if( dirPath.isEmpty())
    {
        return;
    }
    QDir dir(dirPath);

    QList<QFileInfo> fileList = dir.entryInfoList();
    for (int i = 0; i < fileList.size();i++)
    {
        QString prefix;
//        if (fileList.at(i).isFile())
//        {
//            prefix = "File: ";
//        }
//        if (fileList.at(i).isDir())
//        {
//            prefix = "Directory: ";
//        }
        ui->listWidget->addItem(prefix + fileList.at(i).absoluteFilePath());
    }
}
