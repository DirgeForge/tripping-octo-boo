#include "Menu.h"
#include "ui_Menu.h"

Form::Form(int num, QWidget *parent) :
    tableNum(num),
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    QString qStr = "Table # " + QString::number(num);
    ui->label->setText(qStr);
}

Form::~Form()
{
    delete ui;
}



void Form::on_pushButton_4_clicked()
{
    EditMenu * w = new EditMenu();
    w->show();

}

void Form::on_pushButton_3_clicked()
{
    AddItem * w = new AddItem();
    w->show();
}

void Form::on_pushButton_clicked()
{
    Receipt * r = new Receipt(0, tableNum);
    r->show();
}
