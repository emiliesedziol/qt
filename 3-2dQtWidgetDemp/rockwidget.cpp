#include "rockwidget.h"
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

RockWidget::RockWidget(QWidget *parent) : QWidget(parent)
{
//    setWindowTitle("Rock Widge here");
    QLabel * label = new QLabel("Label Text",this);

    QFont label1Font("Times", 20, QFont::Bold);
    QPalette label1Palette;
    label1Palette.setColor(QPalette::Window,Qt::white);
    label1Palette.setColor(QPalette::WindowText,Qt::red);

    QLabel * label1 = new QLabel(this);
    label1->setAutoFillBackground(true);
    label1->setText("my colored label");
    label1->move(50,50);
    label1->setPalette(label1Palette);
    label1->setFont(label1Font);


    /*
     * to change the color of the label font and background the following is needed
     * QPalette label1Palette;
       label1Palette.setColor(QPalette::Window,Qt::white);
       label1Palette.setColor(QPalette::WindowText,Qt::blue);
       label1->setAutoFillBackground(true);
       label1->setPalette(label1Palette);
     */

    QPalette label2Palette;
    label2Palette.setColor(QPalette::Window, Qt::green);
    label2Palette.setColor(QPalette::WindowText, Qt::black);

    QLabel * mLabel2 = new QLabel(this);
    mLabel2->setAutoFillBackground(true);
    mLabel2->setPalette(label2Palette);
    mLabel2->setText("Second label text");
    mLabel2->move(70,170);
    QFont serifFont("Times", 20, QFont::Bold);
    mLabel2->setFont(serifFont);

    QFont buttonFont("Times", 30, QFont::Bold);
    QPushButton * button = new QPushButton(this);
    button->setText("Click this button");
    button->setFont(buttonFont);
    button->move(100,250);
    connect(button, SIGNAL(clicked()),this,SLOT(buttonClicked()));
    /* to get the button to do something
     * in Headers -> rockwidget.h add
     * private slots:
       void buttonClicked();
       rigth click on buttonClicked
       -> refactor
       ->Add Definition in rockwidget.cpp
       which adds void RockWidget::buttonClicked()   below
       add
       QMessageBox::information(this, "Message", "This button was clicked");
       */

}

void RockWidget::buttonClicked()
{
    QMessageBox::information(this, "Message", "This button was clicked");

}

QSize RockWidget::sizeHint() const
{
    return QSize(500,500);

}
