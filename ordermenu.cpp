#include "ordermenu.h"
#include "ui_messagebox.h"

OrderMenu::OrderMenu(int num, QWidget *parent) : tableNum(num),
    QDialog(parent),
    ui(new Ui::OrderMenu)
{
    ui->setupUi(this);
    QString qStr ="Table: " + QString::number(tableNum);
    ui->displayTableNumber->setText(qStr);
    ui->displayTableNumber_2->setText(qStr);
}

OrderMenu::~OrderMenu()
{
    delete ui;
}
