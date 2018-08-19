#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);

    QStandardItem * rootItem = model->invisibleRootItem();

    QStandardItem * africaItem = new QStandardItem("Africa");
    QStandardItem * rwandaItem = new QStandardItem("Rwanda");
    QStandardItem * kigaliItem = new QStandardItem("Kigali");
    QStandardItem * musanzeItem = new QStandardItem("Musanze");
    QStandardItem * ugandaItem = new QStandardItem("Uganda");
    QStandardItem * kampalaItem = new QStandardItem("Kampala");
    QStandardItem * entebbeItem = new QStandardItem("Entebbe");
    QStandardItem * asiaItem = new QStandardItem("Asia");
    QStandardItem * chinaItem = new QStandardItem("China");
    QStandardItem * shanghaiItem = new QStandardItem("Shanghai");
    QStandardItem * beijingItem = new QStandardItem("Beijing");
    QStandardItem * europeItem = new QStandardItem("Europe");
    QStandardItem * franceItem = new QStandardItem("France");
    QStandardItem * parisItem = new QStandardItem("Paris");
    QStandardItem * toulouseItem = new QStandardItem("Toulouse");
    QStandardItem * usItem = new QStandardItem("United States");
    QStandardItem * arizonaItem = new QStandardItem("Arizona");
    QStandardItem * coloradoItem = new QStandardItem("Colorado");
    QStandardItem * denverItem = new QStandardItem("Denver");
    QStandardItem * grandjuctionItem = new QStandardItem("Grand Junction");

    rootItem->appendRow(africaItem);
    africaItem->appendRow(rwandaItem);
    africaItem->appendRow(ugandaItem);

    rwandaItem->appendRow(kigaliItem);
    rwandaItem->appendRow(musanzeItem);
    ugandaItem->appendRow(kampalaItem);
    ugandaItem->appendRow(entebbeItem);

    rootItem->appendRow(asiaItem);
    asiaItem->appendRow(chinaItem);

    chinaItem->appendRow(shanghaiItem);
    chinaItem->appendRow(beijingItem);

    rootItem->appendRow(europeItem);
    europeItem->appendRow(franceItem);
    franceItem->appendRow(parisItem);
    franceItem->appendRow(toulouseItem);

    rootItem->appendRow(usItem);
    usItem->appendRow(arizonaItem);
    usItem->appendRow(coloradoItem);
    coloradoItem->appendRow(denverItem);
    coloradoItem->appendRow(grandjuctionItem);

    ui->treeView->setModel(model);

    ui->treeView->expandAll();

    QItemSelectionModel * selectionModel = ui->treeView->selectionModel();
    connect(selectionModel, SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,
            SLOT(selectionChangedSlot(QItemSelection,QItemSelection)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::selectionChangedSlot(const QItemSelection &oldSelection, const QItemSelection &newSelection)
{
    QModelIndex currentIndex = ui->treeView->selectionModel()->currentIndex();
    QString data = model->data(currentIndex,Qt::DisplayRole).toString();
    qDebug() << "Clicked on " << data;

    int hierarchy = 1;
    QModelIndex seekRoot = currentIndex;
    while ( seekRoot != QModelIndex())
    {
        seekRoot = seekRoot.parent();
        hierarchy++;
    }
    QString dataToShow = QString("%1 level %2").arg(data).arg(QString::number(hierarchy));
    setWindowTitle(dataToShow);
}
