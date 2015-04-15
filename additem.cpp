#include "additem.h"
#include "ui_additem.h"

AddItem::AddItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddItem)
{
    ui->setupUi(this);
}

AddItem::~AddItem()
{
    delete ui;
}

void AddItem::on_save_changes_clicked()
{
    this->close();
}

void AddItem::on_Cancel_clicked()
{
    this->close();
}
