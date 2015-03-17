#include "ordermenu.h"
#include "ui_messagebox.h"

OrderMenu::OrderMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderMenu)
{
    ui->setupUi(this);
}

OrderMenu::~OrderMenu()
{
    delete ui;
}
