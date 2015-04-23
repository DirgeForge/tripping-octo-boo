#ifndef RESTAURANTLAYOUT_H
#define RESTAURANTLAYOUT_H

#include <QMainWindow>
#include <QPushButton>
#include <QObject>
#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <QLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QFormLayout>
#include <QPainter>
#include <QDate>
#include <QDateTime>
#include <QMouseEvent>

#include "tablebutton.h"
#include "employeemenu.h"

class RestaurantLayout : public QMainWindow
{
    Q_OBJECT
private slots:
    void table_pressed();
    void edit_clicked();
    void rotate_clicked();
    void employee_clicked();

public:
    RestaurantLayout();
    ~RestaurantLayout();

protected:
    void paintEvent(QPaintEvent *event);

private:
    QRect screen {QApplication::desktop()->screenGeometry()};
    int tableCount;
    TableButton *tableHighlighted;
    QPushButton *editButton;
    QPushButton *rotateButton;
    QPushButton *employeeButton;
};

#endif // RESTAURANTLAYOUT_H
