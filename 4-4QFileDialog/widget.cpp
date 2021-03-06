#include "widget.h"
#include "ui_widget.h"
#include <qfiledialog.h>
#include <QDebug>

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

void Widget::on_pushButton_clicked()
{
    //
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                 "/home/jana/untitled.png",
                                 tr("Images (*.png *.xpm *.jpg)"));
    qDebug() << "file name saved " << fileName;


    /*
     * select a list of files
     *
    QStringList files = QFileDialog::getOpenFileNames(
                              this,
                              "Select one or more files to open",
                              getenv("HIFI_DIR"),
                              "Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)");
    qDebug() << "files selected " << files;
   /* returns
    Starting D:\github\Qt\build-4-4QFileDialog-Desktop_Qt_5_10_1_MinGW_32bit-Debug\debug\4-4QFileDialog.exe...
    files selected  ("C:/src/hifi/hifi-master/interface/src/AboutUtil.cpp",
        "C:/src/hifi/hifi-master/interface/src/AndroidHelper.cpp")
    in the window to select files, the following will allow a different file type to be looked for
     "Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)"
    QStringList files = QFileDialog::getOpenFileNames(
                              this,
                              "Select one or more files to open",
                              getenv("HIFI_DIR"),
                              "Images (*.png *.xpm *.jpg *cpp)");
    */


    // get and existing file
    /*
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      getenv("HIFI_DIR"),
                                                      tr("Images (*.png *.xpm *.jpg *.cpp)"));
    qDebug() << fileName << " was selected";
    */

    /* get and existing directory
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                      getenv("HIFI_DIR"),
                                                      QFileDialog::ShowDirsOnly
                                                      | QFileDialog::DontResolveSymlinks);
    // note "/home" opens the default Qt directory, if an environmental variable is setup getenv can be used
    // haven't found how to change the direcotory to something else

    qDebug() << "The direclty is " << dir;
    */
}
