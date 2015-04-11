#ifndef ORDERMENU_H
#define ORDERMENU_H

/*
 * TEMP MENU ORDER UI
 *
 * can be edited to match approved ui or replaced
 * not sure which is easier
 *
 * ui is edited by using the messagebox.ui file
 *
 */

#include <QDialog>

namespace Ui {
class OrderMenu;
}

class OrderMenu : public QDialog
{
    Q_OBJECT

public:
    explicit OrderMenu(int num, QWidget *parent = 0);
    ~OrderMenu();

private:
    int tableNum;
    Ui::OrderMenu *ui;
};

#endif // OrderMenu_H
