#include "Menu.h"
#include "ui_Menu.h"
#include "editmenu.h"
#include "itemdisplay.h"
#include <QToolButton>
#include <QGridLayout>

//Menu::Menu(int num, GraphicsView *masterView, QWidget *parent) :
Menu::Menu(RestTable * table, MenuController * control, QWidget *parent) : control(control),
    table(table),
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    tableNum = table->getTableID();
    setWindowTitle("Restaurant Menu");
    QString qStr = "Table # " + QString::number(tableNum);
    ui->tableNumDisplay->setText(qStr);
    this->showFullScreen();

    loadMenu();

}

void Menu::loadMenu()
{
    size_t menuSize = control->getSize();
    ItemDisplay *add;


    //amount of items on each tab
    int beveragesSize = 0;
    int appetizersSize = 0;
    int soupsSize = 0;
    int dinnerSize = 0;
    int lunchSize = 0;
    int breakfastSize = 0;
    int dessertsSize = 0;
    int kidsSize = 0;

    for(int i = 0; i < 8; ++i)
    {
        layout.push_back(new QGridLayout());
    }


    for(int i = 0; i < menuSize; ++i)
    {
        switch (control->at(i)->getCategory())
        {
        case FoodItem::BEVERAGES:
            add = new ItemDisplay(control->at(i), this);
            layout.at(FoodItem::BEVERAGES)->addWidget(add->getButton(),
                beveragesSize/4, beveragesSize%4);
            ++breakfastSize;
            break;

        case FoodItem::APPETIZERS:
            add = new ItemDisplay(control->at(i), this);
            layout.at(FoodItem::APPETIZERS)->addWidget(add->getButton(),
                appetizersSize/4, appetizersSize%4);
            ++appetizersSize;
            break;

        case FoodItem::SOUPS:
            add = new ItemDisplay(control->at(i), this);
            layout.at(FoodItem::SOUPS)->addWidget(add->getButton(),
                soupsSize/4, soupsSize%4);
            ++soupsSize;
            break;

        case FoodItem::DINNER:
            add = new ItemDisplay(control->at(i), this);
            layout.at(FoodItem::DINNER)->addWidget(add->getButton(),
                dinnerSize/4, dinnerSize%4);
            ++dinnerSize;
            break;

        case FoodItem::LUNCH:
            add = new ItemDisplay(control->at(i), this);
            layout.at(FoodItem::LUNCH)->addWidget(add->getButton(),
                lunchSize/4, lunchSize%4);
            break;

        case FoodItem::BREAKFAST:
            add = new ItemDisplay(control->at(i), this);
            layout.at(FoodItem::BREAKFAST)->addWidget(add->getButton(),
                breakfastSize/4, breakfastSize%4);
            ++breakfastSize;
            break;

        case FoodItem::DESSERTS:
            add = new ItemDisplay(control->at(i), this);
            layout.at(FoodItem::DESSERTS)->addWidget(add->getButton(),
                dessertsSize/4, dessertsSize%4);
            ++dessertsSize;
            break;

        case FoodItem::KIDS:
            add = new ItemDisplay(control->at(i), this);
            layout.at(FoodItem::KIDS)->addWidget(add->getButton(),
                kidsSize/4, kidsSize%4);
            ++kidsSize;
            break;

        default:
            break;
        }
    }


    ui->beveragesContents->setLayout(layout.at(FoodItem::BEVERAGES));
    ui->appetizersContents->setLayout(layout.at(FoodItem::APPETIZERS));
    ui->soupsContents->setLayout(layout.at(FoodItem::SOUPS));
    ui->dinnerContents->setLayout(layout.at(FoodItem::DINNER));
    ui->lunchContents->setLayout(layout.at(FoodItem::LUNCH));
    ui->breakfastContents->setLayout(layout.at(FoodItem::BREAKFAST));
    ui->dessertsContents->setLayout(layout.at(FoodItem::DESSERTS));
    ui->kidsContents->setLayout(layout.at(FoodItem::KIDS));

}

Menu::~Menu()
{
    delete ui;
}

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
