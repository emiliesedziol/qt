#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <QColor>
#include <QPushButton>

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_oneButton_clicked();

    void on_twoButton_clicked();

    void on_threeButton_clicked();

    void on_fourButton_clicked();

    void on_fiveButton_clicked();

    void on_sixButton_clicked();

    void on_sevenButton_clicked();

    void on_eightButton_clicked();

    void on_nineButton_clicked();

    void on_saveButton_clicked();

    void on_loadButton_clicked();

private:
    Ui::Widget *ui;
    QList<QColor> colorList;

    void saveColor( QString key, QColor color);
    QColor loadColor(QString key);

    void setLoadedColor( QString key, int index, QPushButton * button);

};

#endif // WIDGET_H
