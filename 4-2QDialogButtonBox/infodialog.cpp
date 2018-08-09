#include "infodialog.h"
#include "ui_infodialog.h"
#include <QDebug>

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdButton = ui->buttonBox->standardButton(button);

    if(stdButton == QDialogButtonBox::Ok) {
        accept();
        qDebug() << " OK has been pressed";
    }
    if(stdButton == QDialogButtonBox::Yes) {
        qDebug() << " yes has been pressed";
    }
    if(stdButton == QDialogButtonBox::SaveAll) {
        qDebug() << " SaveAll has been pressed";
    }
    if(stdButton == QDialogButtonBox::Open) {
        qDebug() << " open has been pressed";
    }
    if(stdButton == QDialogButtonBox::No) {
        qDebug() << " No has been pressed";
    }
    if(stdButton == QDialogButtonBox::Cancel) {
        reject();
        qDebug() << " cancel has been pressed";
    }
}
