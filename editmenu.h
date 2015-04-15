#ifndef EDITMENU_H
#define EDITMENU_H

#include "Menu.h"

#include <QMainWindow>

namespace Ui {
class EditMenu;
}

class EditMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditMenu(QWidget *parent = 0);
    ~EditMenu();

private slots:

    void on_remove_item_pressed();

    void on_save_changes_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::EditMenu *ui;
    QMainWindow *a;
};

#endif // EDITMENU_H
