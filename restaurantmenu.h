#ifndef RESTAURANTMENU_H
#define RESTAURANTMENU_H

#include <QMainWindow>
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QListWidget>
#include <QDesktopWidget>
#include <QTabWidget>
#include <QWidget>
#include <QScrollArea>
#include <QPalette>

class RestaurantMenu : public QMainWindow
{
    Q_OBJECT
private slots:

public:
    RestaurantMenu();
    ~RestaurantMenu();
private:
    QRect screen {QApplication::desktop()->screenGeometry()};
    QPushButton *back;
    QPushButton *clearTable;
    QPushButton *printRecipit;
    QPushButton *removeItem;
    QPushButton *order;

    QTabWidget *tabMaster;
    QWidget *breakfast;
    QWidget *lunch;

    QLabel *tableNumber;
    QLabel *orderTitle;
    QListWidget *orderList;
};

#endif // RESTAURANTMENU_H
