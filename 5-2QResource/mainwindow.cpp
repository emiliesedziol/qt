#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/minions-png-42180.png");
    ui->label->setPixmap(pix.scaled(300,300));
}

MainWindow::~MainWindow()
{
    delete ui;
}
