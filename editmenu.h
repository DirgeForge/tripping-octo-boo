#ifndef EDITMENU_H
#define EDITMENU_H

#include "Menu.h"

#include <QMainWindow>

// ---- includes for the backend ----
#include "backend/include/menucontroller.h"
#include "backend/include/menumodel.h"
// ---- end backend includes ----

namespace Ui {
class EditMenu;
}

class EditMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditMenu(QWidget *parent = 0);
    EditMenu(MenuModel * model, MenuController * controller, QWidget *parent = 0);  // this *shouldn't* crap out
    ~EditMenu();

private slots:

    void on_remove_item_pressed();

    void on_save_changes_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::EditMenu *ui;
    QMainWindow *a;

    // model/controller pointers
    MenuController * menu;
    MenuModel * model;
};

#endif // EDITMENU_H
