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
    // REMOVE GRAPHICSVIEW
    explicit Menu(int, MenuController *, QWidget *parent = 0);
    ~Menu();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_5_pressed();

    void on_ClearTable_clicked();

    void on_pushButton_6_clicked();

    void on_addItem_clicked();

    void on_backButton_clicked();

private:
    Ui::Menu *ui;
    //Viand *Orange;
    int tableNum;
};

#endif // MENU_H
