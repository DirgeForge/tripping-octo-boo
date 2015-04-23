#include "employeemenu.h"

EmployeeMenu::EmployeeMenu()
{
    this->setGeometry(100,100,800,800);
    this->setStyleSheet("background-color: rgb(255, 137, 53);");

    QLabel *Title = new QLabel;
    Title->setGeometry(QRect(130,60,188,38));
    Title->setParent(this);
    Title->setStyleSheet("background: transparent");
    Title->setFont(QFont("Old English Text MT",25));
    Title->setText("Pirate's Catch");
    Title->adjustSize();

    QLabel *Date = new QLabel;
    Date->setGeometry(QRect(450,60,341,21));
    Date->setParent(this);
    Date->setStyleSheet("background: transparent");
    Date->setFont(QFont("Old English Text MT",16));
    Date->setText("8:00pm");
    Date->adjustSize();

    QLabel *name = new QLabel;
    name->setGeometry(QRect(150,160,141,41));
    name->setParent(this);
    name->setStyleSheet("background: transparent");
    name->setFont(QFont("Old English Text MT",16));
    name->setText("Total Sales:");
    name->adjustSize();

    QLabel *totalSales = new QLabel;
    totalSales->setGeometry(QRect(110,220,91,31));
    totalSales->setParent(this);
    totalSales->setStyleSheet("background: transparent");
    totalSales->setFont(QFont("Old English Text MT",16));
    totalSales->setText("Total Sales:");
    totalSales->adjustSize();

    QLabel *projectedTip = new QLabel;
    projectedTip->setGeometry(110,250,121,31);
    projectedTip->setParent(this);
    projectedTip->setStyleSheet("background: transparent");
    projectedTip->setFont(QFont("Old English Text MT",16));
    projectedTip->setText("Projected Tip:");
    projectedTip->adjustSize();

    QLabel *money1 = new QLabel;
    money1->setGeometry(320,230,111,16);
    money1->setParent(this);
    money1->setStyleSheet("background: transparent");
    money1->setFont(QFont("Old English Text MT",16));
    money1->setText("$1500");
    money1->adjustSize();

    QLabel *money2 = new QLabel;
    money2->setGeometry(320,250,111,16);
    money2->setParent(this);
    money2->setStyleSheet("background: transparent");
    money2->setFont(QFont("Old English Text MT",16));
    money2->setText("$225");
    money2->adjustSize();

    QLabel *dailySpecials = new QLabel;
    dailySpecials->setGeometry(QRect(400,130,281,201));
    dailySpecials->setParent(this);
    dailySpecials->setStyleSheet("background: blue");
    dailySpecials->setFont(QFont("Old English Text MT",18));
    dailySpecials->setText("Daily Specials");
    dailySpecials->setAlignment(Qt::AlignCenter);

    // BUTTONS

    QPushButton *editOrder = new QPushButton;
    editOrder->setGeometry(80,350,111,161);
    editOrder->setParent(this);
    editOrder->setFont(QFont("",8));
    editOrder->setText("Review/Edit Orders");
    editOrder->setStyleSheet("background: white");

    QPushButton *clockIn = new QPushButton;
    clockIn->setGeometry(210,350,171,71);
    clockIn->setParent(this);
    clockIn->setFont(QFont("",8));
    clockIn->setText("Clock In");
    clockIn->setStyleSheet("background: white");

    QPushButton *startLunch = new QPushButton;
    startLunch->setGeometry(210,440,171,71);
    startLunch->setParent(this);
    startLunch->setFont(QFont("",8));
    startLunch->setText("Start Lunch");
    startLunch->setStyleSheet("background: white");

    QPushButton *clockOut = new QPushButton;
    clockOut->setGeometry(400,350,161,71);
    clockOut->setParent(this);
    clockOut->setFont(QFont("",8));
    clockOut->setText("Clock Out");
    clockOut->setStyleSheet("background: white");

    QPushButton *findLunch = new QPushButton;
    findLunch->setGeometry(400,440,161,71);
    findLunch->setParent(this);
    findLunch->setFont(QFont("",8));
    findLunch->setText("Find Lunch");
    findLunch->setStyleSheet("background: white");

    QPushButton *exit = new QPushButton;
    exit->setGeometry(580,350,111,161);
    exit->setParent(this);
    exit->setFont(QFont("",8));
    exit->setText("Exit to Main Menu");
    exit->setStyleSheet("background: white");
}
EmployeeMenu::~EmployeeMenu()
{

}

