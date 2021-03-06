#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
// add 'network' to the .pro file and then 'Run qmake' to have access to QNetworkAccessManager


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void dataReadyToRead();
    void dataReadFinished();

private:
    Ui::Widget *ui;

    QNetworkAccessManager * netManager;
    QNetworkReply * netReply;
    QByteArray * mDataBuffer;
};

#endif // WIDGET_H
