#include "restaurantmenu.h"

RestaurantMenu::RestaurantMenu()
{
    this->setStyleSheet("background-color: rgb(98,177,109)");

    tabMaster = new QTabWidget;
    tabMaster->setParent(this);
    //tab->setStyleSheet("background: yellow");
    tabMaster->setGeometry((8*screen.width())/32,screen.height()/32,(22*screen.width())/32,(30*screen.height())/32);

    back = new QPushButton;
    back->setParent(this);
    back->setStyleSheet("background-color: rgb(255, 255, 255);");
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

    //breakfast->setParent(this);
    //breakfast->setStyleSheet("background: green");

    //breakfastScroll->setGeometry(0,0,tabMaster->width(),tabMaster->height()*2);

    lunch = new QWidget;
    //lunch->setParent(this);
    //lunch->setStyleSheet("background: yellow");

    QPushButton *a = new QPushButton;
    a->setParent(breakfast);
    a->setGeometry(tabMaster->width()/2,tabMaster->height()/2,100,100);
    a->setText("HI");
    a->setStyleSheet("background: orange");

    QPushButton *b = new QPushButton;
    b->setParent(breakfast);
    b->setGeometry(tabMaster->width()/2,tabMaster->height()-50,100,100);
    b->setText("Low");
    b->setStyleSheet("background: orange");

   // m_ui->scrollArea->setWidgetResizable(true);
    //m_ui->scrollArea->setWidget(pjob);
    QScrollArea *breakfastScroll = new QScrollArea(tabMaster);
    breakfastScroll->setLayout();
    breakfastScroll->setWidgetResizable(true);
    breakfastScroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    breakfast = new QWidget(breakfastScroll);
    breakfast->setGeometry(0,0,tabMaster->width(),tabMaster->height()*2);

    /////////////////////// BUTTON TRIGGERS ////////////////////////////////////

    QObject::connect(back, SIGNAL(clicked()), this, SLOT(close()));
    //QObject::connect(table2, SIGNAL(pressed()), this, SLOT(table_pressed()));

    //////////////////////// END OF BUTTON TRIGGERS //////////////////////////////

    tabMaster->addTab(breakfastScroll,"Breakfast");
    tabMaster->addTab(lunch,"Lunch");

    this->showFullScreen();
}

RestaurantMenu::~RestaurantMenu()
{

}
