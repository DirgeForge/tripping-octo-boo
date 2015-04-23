#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QTabWidget>
#include <QListWidget>
#include <QListView>
#include <QDesktopWidget>
#include "graphicsview.h"

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(int num,QWidget *parent = 0);
    //explicit Menu(int, GraphicsView*, QWidget *parent = 0);
    ~Menu();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_5_pressed();

    void on_ClearTable_clicked();

    void on_pushButton_6_clicked();

    void on_addItem_clicked();

private:
    Ui::Menu *ui;
    //Viand *Orange;
};

#endif // MENU_H
