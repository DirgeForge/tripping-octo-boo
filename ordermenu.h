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
    explicit OrderMenu(QWidget *parent = 0);
    ~OrderMenu();

private:
    Ui::OrderMenu *ui;
};

#endif // OrderMenu_H
