#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_okButton_clicked()
{
    QString userPosition = ui->positionLineEdit->text();
    if (!userPosition.isEmpty())
    {
        position = userPosition;

        if(ui->windowsRadioButton->isChecked())
        {
            oS = "Windows";
        }
        if(ui->macRadioButton->isChecked())
        {
            oS = "Mac";
        }
        if(ui->linuxRadioButton->isChecked())
        {
            oS = "Linux";
        }
    }
    accept();
}

void InfoDialog::on_cancelButton_clicked()
{
    reject();
}

QString InfoDialog::getPosition() const
{
    return position;
}

QString InfoDialog::getOS() const
{
    return oS;
}
