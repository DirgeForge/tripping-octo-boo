#include "Menu.h"
#include "ui_Menu.h"
#include "editmenu.h"

Menu::Menu(int num, GraphicsView *masterView, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    setWindowTitle("Restaurant Menu");
    QString qStr = "Table # " + QString::number(num);
    ui->tableNumDisplay->setText(qStr);
    //ui->foodCategories->setStyleSheet("QTabBar::tab {height: 200px, width: 200px; }");
    //ui->foodCategories->tabBar()->setStyleSheet("background: blue");
    //ui->OrderList->setW

     masterView->initMenu();



    this->show();
}

Menu::~Menu()
{
    delete ui;
}

int quantMilk = 1;
void Menu::on_pushButton_clicked()
{

   QString milk = "Milk";// x " + QString::number(quantMilk);

   ui->OrderList->addItem(milk);

}

void Menu::on_pushButton_5_pressed()
{
    ui->OrderList->addItem("Orange Juice");
    //Viand *currentButton = (Viand *)sender();
    //ui->listWidget->addItem(currentButton->getFoodName());
}

void Menu::on_ClearTable_clicked()
{
   ui->OrderList->clear();
}


//Back Button
void Menu::on_pushButton_6_clicked()
{
    this->close();
}

//    QVBoxLayout *layout = new QVBoxLayout(this);
//    //while(!clearTable)
//    for (int i = 0; i < 40; i++)
//    {
//        QLabel *foodItem = new QLabel("Hello............");
//        layout->addWidget(foodItem);

//    }

//    ui->scrollContents->setLayout(layout);
//    //ui->ClearTable->;




void Menu::on_addItem_clicked()
{
    EditMenu * w = new EditMenu();
    w->show();
}
