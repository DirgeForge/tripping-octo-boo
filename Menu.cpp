#include "Menu.h"
#include "ui_Menu.h"
#include "editmenu.h"
#include "itemdisplay.h"
#include <QToolButton>
#include <QGridLayout>
#include <vector>

//Menu::Menu(int num, GraphicsView *masterView, QWidget *parent) :
Menu::Menu(int num, MenuController * control, QWidget *parent) : control(control),
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    setWindowTitle("Restaurant Menu");
    QString qStr = "Table # " + QString::number(num);
    ui->tableNumDisplay->setText(qStr);
    this->showFullScreen();

    tableNum = num;

    size_t size = control->getSize();
    QGridLayout *layout = new QGridLayout;
    ItemDisplay *add;


    for(size_t i = 0; i <size; ++i)
    {
        add = new ItemDisplay(control->at(i), this);
        layout->addWidget(add->getButton(),i/5,i%5);
    }


    ui->beveragesContents->setLayout(layout);


}

Menu::~Menu()
{
    delete ui;
}

int quantMilk = 1;

void Menu::order(IItem*item)
{
    ui->OrderList->addItem(QString::fromStdString(item->getTitle()));
}


void Menu::on_ClearTable_clicked()
{
   ui->OrderList->clear();
}


void Menu::on_addItem_clicked()
{
    EditMenu * w = new EditMenu(control);
    w->show();
}

void Menu::on_backButton_clicked()
{

    this->close();
}
