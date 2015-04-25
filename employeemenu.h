#ifndef EMPLOYEEMENU_H
#define EMPLOYEEMENU_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

class EmployeeMenu : public QMainWindow
{
    Q_OBJECT

public:
    EmployeeMenu();
    ~EmployeeMenu();

private slots:
    void back_button();
};

#endif // EMPLOYEEMENU_H
