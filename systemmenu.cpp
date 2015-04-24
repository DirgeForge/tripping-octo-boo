#include <QtWidgets>
#include "systemmenu.h"
#include "editmenu.h"

SystemMenu::SystemMenu()
{
    this->setStyleSheet("background: orange");

    QLabel *title = new QLabel;
    title->setParent(this);
    title->setGeometry(150,10,221,51);
    title->setFont(QFont("Old English Text MT",26));
    title->setText("Pirate's Catch");

    QLabel *name = new QLabel;
    name->setParent(this);
    name->setGeometry(190,60,161,41);
    name->setFont(QFont("Old English Text MT",12));
    name->setText("Manager's Name");

    QLabel *time = new QLabel;
    time->setParent(this);
    time->setGeometry(20,440,501,21);
    time->setFont(QFont("Old English Text MT",11));
    time->setText("69:69pm");
    time->setAlignment(Qt::AlignCenter);

    // BUTTONS

    QPushButton *power = new QPushButton;
    power->setParent(this);
    power->setGeometry(20,20,91,51);
    power->setFont(QFont("",8));
    power->setText("Power");
    power->setStyleSheet("background: white");
    connect(power, SIGNAL (released()), this, SLOT (power_button()));

    QPushButton *openRest = new QPushButton;
    openRest->setParent(this);
    openRest->setGeometry(30,180,141,71);
    openRest->setFont(QFont("",8));
    openRest->setText("Open Restaurant");
    openRest->setStyleSheet("background: white");

    QPushButton *dailyTotal = new QPushButton;
    dailyTotal->setParent(this);
    dailyTotal->setGeometry(200,180,141,71);
    dailyTotal->setFont(QFont("",8));
    dailyTotal->setText("Daily Total");
    dailyTotal->setStyleSheet("background: white");

    QPushButton *closeRest = new QPushButton;
    closeRest->setParent(this);
    closeRest->setGeometry(370,180,141,71);
    closeRest->setFont(QFont("",8));
    closeRest->setText("Close Restaurant");
    closeRest->setStyleSheet("background: white");

    QPushButton *addItem = new QPushButton;
    addItem->setParent(this);
    addItem->setGeometry(30,270,141,71);
    addItem->setFont(QFont("",8));
    addItem->setText("Add Item to Menu");
    addItem->setStyleSheet("background: white");

    QPushButton *manageEmployees = new QPushButton;
    manageEmployees->setParent(this);
    manageEmployees->setGeometry(200,270,141,71);
    manageEmployees->setFont(QFont("",8));
    manageEmployees->setText("Manage Employees");
    manageEmployees->setStyleSheet("background: white");

    QPushButton *manageInventory = new QPushButton;
    manageInventory->setParent(this);
    manageInventory->setGeometry(370,270,141,71);
    manageInventory->setFont(QFont("",8));
    manageInventory->setText("Manage Inventory");
    manageInventory->setStyleSheet("background: white");

    QPushButton *editOrder = new QPushButton;
    editOrder->setParent(this);
    editOrder->setGeometry(30,360,141,71);
    editOrder->setFont(QFont("",8));
    editOrder->setText("Review/Edit Orders");
    editOrder->setStyleSheet("background: white");

    QPushButton *restartSystem = new QPushButton;
    restartSystem->setParent(this);
    restartSystem->setGeometry(200,360,141,71);
    restartSystem->setFont(QFont("",8));
    restartSystem->setText("Restart System");
    restartSystem->setStyleSheet("background: white");

    QPushButton *exit = new QPushButton;
    exit->setParent(this);
    exit->setGeometry(370,360,141,71);
    exit->setFont(QFont("",8));
    exit->setText("Restart System");
    exit->setStyleSheet("background: white");

    this->showFullScreen();

}

void SystemMenu::power_button()
{
    exit(0);
}

SystemMenu::~SystemMenu()
{

}
