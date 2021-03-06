#ifndef EDITMENU_H
#define EDITMENU_H

#include "Menu.h"
#include "backend/include/fooditem.h"
#include "backend/include/fooditem_serialize.h"
#include "backend/include/menucontroller.h"

#include <QMainWindow>

namespace Ui {
class EditMenu;
}

class EditMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditMenu(MenuController *, QWidget *parent = 0);
    explicit EditMenu(MenuController *, const FoodItem&, QWidget *parent = 0);
    ~EditMenu();

private slots:

    void on_remove_item_pressed();

    void on_save_changes_clicked();

    void on_lineEdit_editingFinished();

    void on_editDescription_clicked();

    void on_UploadNewPicture_clicked();

    void on_remove_item_clicked();

private:
    void setImage(const QString &imagePath);
    MenuController * control;
    Ui::EditMenu *ui;
    QMainWindow *a;
    FoodItem *item;
};

#endif // EDITMENU_H
