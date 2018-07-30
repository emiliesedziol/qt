#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // initialize
    srand (time(NULL));

    // randomnumber
    randomNumber = rand() % 10 + 1;
    qDebug() << "Random number generated " << QString::number(randomNumber);

    ui->startOverButton->setDisabled(true);

    ui->messageLabel->setText("");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_guessButton_clicked()
{
    guessNumber = ui->spinBox->value();
    qDebug() << " spinBox number " << QString::number(guessNumber);

    if (guessNumber == randomNumber)
    {
        ui->messageLabel->setText("correct guess");
        // disable guess button
        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);
    } else {
        if (randomNumber < guessNumber)
        {
            ui->messageLabel->setText("number is lower");
        }
        if (randomNumber > guessNumber)
        {
            ui->messageLabel->setText("number is higher");
        }
    }
}

void Widget::on_startOverButton_clicked()
{
    ui->guessButton->setDisabled(false);

    ui->startOverButton->setDisabled(true);

    ui->spinBox->setValue(1);

    randomNumber = rand() % 10 + 1;
    qDebug() << "Random number generated " << QString::number(randomNumber);

    ui->messageLabel->setText("");
}
