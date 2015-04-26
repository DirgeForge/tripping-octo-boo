#include "restaurantmenu.h"

RestaurantMenu::RestaurantMenu()
{
    this->setStyleSheet("background: blue");

    back = new QPushButton;
    back->setParent(this);
    back->setStyleSheet("background: white");
    back->setGeometry(screen.width()/32,screen.height()/32,screen.width()/16,screen.height()/16);
    back->setText("Back");

    printRecipit = new QPushButton;
    printRecipit->setParent(this);
    printRecipit->setStyleSheet("background: white");
    printRecipit->setGeometry(screen.width()/32,(22*screen.height())/32,screen.width()/6,(3*screen.height())/32);
    printRecipit->setText("Print Recipit");

    removeItem = new QPushButton;
    removeItem->setParent(this);
    removeItem->setStyleSheet("background: white");
    removeItem->setGeometry(screen.width()/32,(25*screen.height())/32,screen.width()/6,(3*screen.height())/32);
    removeItem->setText("Remove Item");

    clearTable = new QPushButton;
    clearTable->setParent(this);
    clearTable->setStyleSheet("background: white");
    clearTable->setGeometry(screen.width()/32,(28*screen.height())/32,screen.width()/6,(3*screen.height())/32);
    clearTable->setText("Clear Table");

    tableNumber = new QLabel;
    tableNumber->setParent(this);
    tableNumber->setStyleSheet("background: red");
    tableNumber->setGeometry((4*screen.width())/32,screen.height()/32,screen.width()/16,screen.height()/16);
    tableNumber->setText("Table #11");
    tableNumber->setAlignment(Qt::AlignCenter);

    orderTitle = new QLabel;
    orderTitle->setParent(this);
    orderTitle->setStyleSheet("background:red");
    orderTitle->setGeometry(screen.width()/32,(4*screen.height())/32,screen.width()/6,screen.height()/16);
    orderTitle->setText("Order List");
    orderTitle->setAlignment(Qt::AlignCenter);

    orderList = new QListWidget;
    orderList->setParent(this);
    orderList->setStyleSheet("background: green");
    orderList->setGeometry(screen.width()/32,(6*screen.height())/32,screen.width()/6,screen.height()/2);

    breakfast = new QWidget;
    //breakfast->setParent(this);
    breakfast->setStyleSheet("background: green");

    QScrollArea *breakfastScroll = new QScrollArea(breakfast);
    breakfastScroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //breakfastScroll->setGeometry(0,0,tabMaster->width(),tabMaster->height()*2);

    lunch = new QWidget;
    //lunch->setParent(this);
    lunch->setStyleSheet("background: yellow");

    tabMaster = new QTabWidget;
    tabMaster->setParent(this);
    //tab->setStyleSheet("background: yellow");
    tabMaster->setGeometry((8*screen.width())/32,screen.height()/32,(22*screen.width())/32,(30*screen.height())/32);
    tabMaster->addTab(breakfastScroll,"Breakfast");
    tabMaster->addTab(lunch,"Lunch");

    QPushButton *a = new QPushButton;
    a->setParent(breakfastScroll);
    a->setGeometry(tabMaster->width()/2,tabMaster->height()/2,100,100);
    a->setText("HI");
    a->setStyleSheet("background: orange");

    /////////////////////// BUTTON TRIGGERS ////////////////////////////////////

    QObject::connect(back, SIGNAL(clicked()), this, SLOT(close()));
    //QObject::connect(table2, SIGNAL(pressed()), this, SLOT(table_pressed()));

    //////////////////////// END OF BUTTON TRIGGERS //////////////////////////////

    this->showFullScreen();
}

RestaurantMenu::~RestaurantMenu()
{

}