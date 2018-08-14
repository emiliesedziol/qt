#include "widget.h"
#include "ui_widget.h"
#include <QColorDialog>
#include <QSettings>
#include <QVariant>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    for (int i=0 ; i < 9; i++)
    {
        colorList.append(Qt::white);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_oneButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[0],this,"Choose Background");
    if (color.isValid())
    {
        colorList[0] = color;  //save color in memory

        QString css = QString("background-color : %1").arg(color.name());  // retreive color
        ui->oneButton->setStyleSheet(css);
    }
}


void Widget::on_twoButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[1],this,"Choose Background");
    if (color.isValid())
    {
        colorList[1] = color;  //save color in memory

        QString css = QString("background-color : %1").arg(color.name());  // retreive color
        ui->twoButton->setStyleSheet(css);
    }
}

void Widget::on_threeButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[2],this,"Choose Background");
    if (color.isValid())
    {
        colorList[2] = color;  //save color in memory

        QString css = QString("background-color : %1").arg(color.name());  // retreive color
        ui->threeButton->setStyleSheet(css);
    }
}

void Widget::on_fourButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[3],this,"Choose Background");
    if (color.isValid())
    {
        colorList[3] = color;  //save color in memory

        QString css = QString("background-color : %1").arg(color.name());  // retreive color
        ui->fourButton->setStyleSheet(css);
    }
}

void Widget::on_fiveButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[4],this,"Choose Background");
    if (color.isValid())
    {
        colorList[4] = color;  //save color in memory

        QString css = QString("background-color : %1").arg(color.name());  // retreive color
        ui->fiveButton->setStyleSheet(css);
    }
}

void Widget::on_sixButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[5],this,"Choose Background");
    if (color.isValid())
    {
        colorList[5] = color;  //save color in memory

        QString css = QString("background-color : %1").arg(color.name());  // retreive color
        ui->sixButton->setStyleSheet(css);
    }
}

void Widget::on_sevenButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[6],this,"Choose Background");
    if (color.isValid())
    {
        colorList[6] = color;  //save color in memory

        QString css = QString("background-color : %1").arg(color.name());  // retreive color
        ui->sevenButton->setStyleSheet(css);
    }
}

void Widget::on_eightButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[7],this,"Choose Background");
    if (color.isValid())
    {
        colorList[7] = color;  //save color in memory

        QString css = QString("background-color : %1").arg(color.name());  // retreive color
        ui->eightButton->setStyleSheet(css);
    }
}

void Widget::on_nineButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[8],this,"Choose Background");
    if (color.isValid())
    {
        colorList[8] = color;  //save color in memory

        QString css = QString("background-color : %1").arg(color.name());  // retreive color
        ui->nineButton->setStyleSheet(css);
    }
}

void Widget::on_saveButton_clicked()
{
    saveColor("oneButton",colorList[0]);
    saveColor("twoButton",colorList[1]);
    saveColor("threeButton",colorList[2]);
    saveColor("fourButton",colorList[3]);
    saveColor("fiveButton",colorList[4]);
    saveColor("sixButton",colorList[5]);
    saveColor("sevenButton",colorList[6]);
    saveColor("eightButton",colorList[7]);
    saveColor("nineButton",colorList[8]);
}

void Widget::on_loadButton_clicked()
{
    setLoadedColor("oneButton",0,ui->oneButton);
    setLoadedColor("twoButton",1,ui->twoButton);
    setLoadedColor("threeButton",2,ui->threeButton);
    setLoadedColor("fourButton",3,ui->fourButton);
    setLoadedColor("fiveButton",4,ui->fiveButton);
    setLoadedColor("sixButton",5,ui->sixButton);
    setLoadedColor("sevenButton",6,ui->sevenButton);
    setLoadedColor("eightButton",7,ui->eightButton);
    setLoadedColor("nineButton",8,ui->nineButton);
}

void Widget::saveColor(QString key, QColor color)
{
    int red = color.red();
    int green = color.green();
    int blue = color.blue();

    QSettings settings("BB", "CC");

    settings.beginGroup("ButtonColor");

    settings.setValue(key + "r", red);
    settings.setValue(key+"g", green);
    settings.setValue(key + "b", blue);

    settings.endGroup();
}

QColor Widget::loadColor(QString key)
{
    int red;
    int green;
    int blue;

    QSettings settings("BB", "CC");

    settings.beginGroup("ButtonColor");

    red = settings.value(key+"r",QVariant(0)).toInt();
    green = settings.value(key+"g",QVariant(0)).toInt();
    blue = settings.value(key+"b",QVariant(0)).toInt();

    settings.endGroup();

    return QColor(red,green,blue);
}

void Widget::setLoadedColor(QString key, int index, QPushButton *button)
{
    QColor color = loadColor(key);
    colorList[index] = color;
    QString css = QString("background-color : %1").arg(color.name());
    button->setStyleSheet(css);
}
