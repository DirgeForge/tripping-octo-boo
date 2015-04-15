#include "editmenu.h"
#include "ui_editmenu.h"

#include "qmessagebox.h"

EditMenu::EditMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditMenu)
{
    ui->setupUi(this);

    a = new QMainWindow;

}

EditMenu::~EditMenu()
{
    delete ui;
}

void EditMenu::on_remove_item_pressed()
{
   QMessageBox::StandardButton reply;
   reply = QMessageBox::question(this,"Remove Item", "Are you sure "
                                 "you want to remove this menu item?", QMessageBox::Yes|QMessageBox::No);

   if (reply == QMessageBox::Yes) this->close();
    //a->show();
}

void EditMenu::on_save_changes_clicked()
{
    this->close();
}

void EditMenu::on_lineEdit_editingFinished()
{
   // fooditem(4)->getName();
}
