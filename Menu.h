#ifndef MENU_H
#define MENU_H

#include "editmenu.h"

#include "receipt.h"

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(int, QWidget *parent = 0);
    ~Form();

private slots:

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::Form *ui;
    int tableNum;
};

#endif // MENU_H
