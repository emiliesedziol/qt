#include "rockwidget.h"
#include <QLabel>

RockWidget::RockWidget(QWidget *parent) : QWidget(parent)
{
//    setWindowTitle("Rock Widge here");
    QLabel * label = new QLabel("Label Text",this);

}
