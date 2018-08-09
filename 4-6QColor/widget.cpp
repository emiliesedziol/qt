#include "widget.h"
#include "ui_widget.h"
#include <QColor>
#include <QColorDialog>
#include <QDebug>
#include <QFont>
#include <QFontDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_textColorButton_clicked()
{
    QPalette palette = ui->label->palette();
    // current text color
    QColor color = palette.color(QPalette::WindowText);
    QColor pickedColor = QColorDialog::getColor(color, this,"Choose Text Color");
    if(pickedColor.isValid())
    {
        qDebug() << "Color is valid";
        palette.setColor(QPalette::WindowText, pickedColor);
        ui->label->setPalette(palette);
    } else
        {
        // when cancel is clicked
        qDebug() << " Color is not valid";
    }
}

void Widget::on_backgroundButton_clicked()
{
    QPalette palette = ui->label->palette();
    QColor color = palette.color(QPalette::Window);
    QColor pickedColor = QColorDialog::getColor(color, this,"Choose Text Color");
    if(pickedColor.isValid())
    {
        qDebug() << "Color is valid";
        palette.setColor(QPalette::Window, pickedColor);
        ui->label->setPalette(palette);
    } else
        {
        // when cancel is clicked
        qDebug() << " Color is not valid";
    }
}

void Widget::on_fontButton_clicked()
{

    bool ok;
          QFont font = QFontDialog::getFont(
                          &ok, QFont("Helvetica [Cronyx]", 10), this);
          if (ok) {
              // the user clicked OK and font is set to the font the user selected
              ui->label->setFont(font);
          } else {
              // the user canceled the dialog; font is set to the initial
              // value, in this case Helvetica [Cronyx], 10
              QMessageBox::information(this, "Message", "user didn't choose a font");
          }
}
