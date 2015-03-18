#ifndef ORDERMENU_H
#define ORDERMENU_H

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
