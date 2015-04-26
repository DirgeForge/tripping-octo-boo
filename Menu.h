#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QTabWidget>
#include <QListWidget>
#include <QStringList>
#include <QListView>
#include <QDesktopWidget>
#include <QVector>
#include "graphicsview.h"

#include "backend/include/menucontroller.h"

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(int, MenuController *, QWidget *parent = 0);
    ~Menu();

public slots:
    void order(IItem *item);

private slots:


    void on_ClearTable_clicked();

    void on_addItem_clicked();

    void on_backButton_clicked();

private:
    MenuController * control;
    Ui::Menu *ui;
    int tableNum;
};

#endif // MENU_H
