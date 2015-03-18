#include "ordermenu.h"
#include "ui_messagebox.h"

OrderMenu::OrderMenu(int num, QWidget *parent) : tableNum(num),
    QDialog(parent),
    ui(new Ui::OrderMenu)
{
    ui->setupUi(this);
    QString qStr = QString::number(tableNum);
    ui->displayTableNumber->setText(qStr);
}

OrderMenu::~OrderMenu()
{
    delete ui;
}
