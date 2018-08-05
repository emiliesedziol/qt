#include "widget.h"
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setupui();
    setFixedSize(400,500);
}

Widget::~Widget()
{

}

void Widget::setupui()
{
    QFont labelFont("Times", 10, QFont::Bold);
    QLabel * mLabel = new QLabel("This is the label", this);
    mLabel->setFont(labelFont);
    mLabel->move(100,25);

    QTextEdit * textEdit = new QTextEdit(this);
    textEdit->move(70,55);

    /*
    //textChange
    connect(textEdit,&QTextEdit::textChanged,[=](){
        qDebug() << "TextChanged";
    });
    */

    // copy, cut paste
    QPushButton * copyButton = new QPushButton("Copy",this);
    copyButton->setMinimumSize(10,25);
    copyButton->move(70,250);
    connect(copyButton,&QPushButton::clicked,[=](){
        textEdit->copy();
    });

    QPushButton * cutButton = new QPushButton("Cut",this);
    cutButton->setMinimumSize(10,25);
    cutButton->move(180,250);
    connect(cutButton,&QPushButton::clicked,[=](){
        textEdit->cut();
    });

    QPushButton * pasteButton = new QPushButton("Paste",this);
    pasteButton->setMinimumSize(10,25);
    pasteButton->move(290,250);
    connect(pasteButton,&QPushButton::clicked,[=](){
        textEdit->paste();
    });

    // undo redo
    QPushButton * undoButton = new QPushButton("Undo", this);
    undoButton->setMinimumSize(10,25);
    undoButton->move(70,300);
    connect(undoButton,&QPushButton::clicked,[=](){
        textEdit->undo();
    });

    QPushButton * redoButton = new QPushButton("Redo", this);
    redoButton->setMinimumSize(10,25);
    redoButton->move(180,300);
    connect(redoButton,&QPushButton::clicked,[=](){
        textEdit->redo();
    });

    // set text and html to the text edit
    QPushButton * plainTextButton = new QPushButton("Plain Text", this);
    plainTextButton->setMinimumSize(100,25);
    plainTextButton->move(70,350);
    connect(plainTextButton,&QPushButton::clicked,[=](){
        textEdit->setPlainText("this text is to be inserted");
    });

    QPushButton * htmlButton = new QPushButton("HTML", this);
    htmlButton->setMinimumSize(10,25);
    htmlButton->move(200,350);
    connect(htmlButton,&QPushButton::clicked,[=](){
        textEdit->setHtml("<h1>Somewhere</h1><p>No where special</p>");
    });

    // grab text and html
    QPushButton * grabTextButton = new QPushButton("Grab Text", this);
    grabTextButton->setMinimumSize(100,25);
    grabTextButton->move(70,400);
    connect(grabTextButton,&QPushButton::clicked,[=](){
        qDebug() << "The plain text inside the text edit is " << textEdit->toPlainText();
    });

    QPushButton * grabHtmlButton = new QPushButton("Grab HTML", this);
    grabHtmlButton->setMinimumSize(100,25);
    grabHtmlButton->move(200,400);
    connect(grabHtmlButton,&QPushButton::clicked,[=](){
        qDebug() << "The plain text inside the text edit for html is " << textEdit->toHtml();
    });
}
