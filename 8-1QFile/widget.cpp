#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
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

void Widget::on_writeButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this,"Save As");
    if( filename.isEmpty())
    {
        return;
    }
    QFile file(filename);
    if ( !file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return;
    }

    QTextStream out(&file);
    out << ui->writeTextEdit->toPlainText() << "\n";

    file.close();
}

void Widget::on_readButton_clicked()
{
    QString fileContent;
    QString filename = QFileDialog::getOpenFileName(this,"Open File");

    if (filename.isEmpty())
    {
        return;
    }

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull())
    {
        fileContent.append(line);
        line = in.readLine();
    }
    file.close();

    ui->writeTextEdit->clear();
    ui->writeTextEdit->setPlainText(fileContent);


}

void Widget::on_selectFileButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Select File");

    if(filename.isEmpty())
    {
        return;
    }
    ui->selectFileLineEdit->setText(filename);
}

void Widget::on_copyButton_clicked()
{
    QString srcFileName = ui->selectFileLineEdit->text();
    QString destFileName = ui->copyLineEdit->text();

    if ( srcFileName.isEmpty() || destFileName.isEmpty())
    {
        return;
    }
    QFile file(srcFileName);
    if (file.copy(destFileName))
    {
        QMessageBox::information(this,"Success","File copy was completed.");
    }else
    {
        QMessageBox::information(this,"Failed","Copy did not happened");
    }
}
