#include "widget.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QFont labelFont("Times", 20, QFont::Bold);
    QFont editFont("Times", 16, QFont::Bold);

    // First Name
    QLabel * firstNameLabel = new QLabel("First Name",this);
    firstNameLabel->setMinimumSize(70,50);
    firstNameLabel->setFont(labelFont);
    firstNameLabel->move(10,10);

    QLineEdit * firstNameLineEdit = new QLineEdit(this);
    firstNameLineEdit->setMinimumSize(200,50);
    firstNameLineEdit->setFont(editFont);
    firstNameLineEdit->move(200,10);

    // last name
    QLabel * lastNameLabel = new QLabel("Last Name",this);
    lastNameLabel->setMinimumSize(70,50);
    lastNameLabel->setFont(labelFont);
    lastNameLabel->move(10,80);

    QLineEdit * lastNameLineEdit = new QLineEdit(this);
    lastNameLineEdit->setMinimumSize(200,50);
    lastNameLineEdit->setFont(editFont);
    lastNameLineEdit->move(200,80);

    // city
    // First Name
    QLabel * cityLabel = new QLabel("City",this);
    cityLabel->setMinimumSize(70,50);
    cityLabel->setFont(labelFont);
    cityLabel->move(10,150);

    QLineEdit * cityLineEdit = new QLineEdit(this);
    cityLineEdit->setMinimumSize(200,50);
    cityLineEdit->setFont(editFont);
    cityLineEdit->move(200,150);

    QFont buttonFont("Times", 24, QFont::Bold);
    QPushButton * button = new QPushButton("Grab Data", this);
    button->setFont(buttonFont);
    button->move(200,220);

    connect(button,&QPushButton::clicked,[=](){
       QString firstName = firstNameLineEdit->text();
       QString lastName = lastNameLineEdit->text();
       QString city = cityLineEdit->text();

       if(!firstName.isEmpty() && !lastName.isEmpty()&& !city.isEmpty()) {
           qDebug() << "First Name " << firstName;
           qDebug() << "Last Name " << lastName;
           qDebug() << "City " << city;
       }
       else {
           if(firstName.isEmpty()) {
               qDebug() << "Enter a first name";
           }
           if(lastName.isEmpty()) {
               qDebug() << "Enter a last name";
           }
           if(city.isEmpty()) {
               qDebug() << "Enter a city";
           }
       }
    });

    // respond to signals from qlineedit

    /*
    //cursor position changed
    connect(firstNameLineEdit,&QLineEdit::cursorPositionChanged,[=](){
        qDebug() << "The current cursor position is " << firstNameLineEdit->cursorPosition();
    });
    */

    /*
    // editting finished -> emitted when the user clicks enter or when the line looses focus
    connect(firstNameLineEdit,&QLineEdit::editingFinished,[=](){
        qDebug() << "editing finished ";
    });
    */

    /*
    // enter key is pressed
    connect(firstNameLineEdit,&QLineEdit::returnPressed,[=](){
        qDebug() << "return key pressed";
    });
    */

    /*
    // selection change -> highlight characters that have been entered
    connect(firstNameLineEdit,&QLineEdit::selectionChanged,[=](){
        qDebug() << "selection changed";
    });
    */

    /*
    //text changed
    connect(firstNameLineEdit,&QLineEdit::textChanged,[=](){
        qDebug() << "text changed " << firstNameLineEdit->text();
    });
    */

    // text edited
    connect(firstNameLineEdit,&QLineEdit::textEdited,[=](){
        qDebug() << "The current cursor position is " << firstNameLineEdit->text();
    });

    // change text in QlineEdit programmatically
    // place holder text
    lastNameLineEdit->setText("Say your last name");

    // this is a lighter color font compared to setText
    firstNameLineEdit->setPlaceholderText("Enter a first name");


}

Widget::~Widget()
{

}
