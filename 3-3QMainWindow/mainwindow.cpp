#include "mainwindow.h"
#include "QPushButton"
#include <QMenuBar>
#include <QStatusBar>
#include <QDebug>
#include <QAction>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton * button = new QPushButton("Hello", this);
    setCentralWidget(button);

    //decleare quit action
    QAction * quitAction = new QAction("Quit");
    connect(quitAction, &QAction::triggered, [=](){
        QApplication::quit();
    });

    QMenu * fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");
    menuBar()->addMenu("About");

    // status bar message
    // statusBar()->showMessage("Uploading file ..", 3000);
    // statusBar()->clearMessage();
    statusBar()->showMessage("Main Page");
}

MainWindow::~MainWindow()
{

}

QSize MainWindow::sizeHint() const
{
    return QSize(800,500);

}
