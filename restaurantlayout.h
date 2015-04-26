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
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "resttable.h"
#include "employeemenu.h"
#include "systemmenu.h"
#include "backend/include/menucontroller.h"

class RestaurantLayout : public QMainWindow
{
    Q_OBJECT
private slots:
    void table_pressed();
    void edit_clicked();
    void rotate_clicked();
    void employee_clicked();
    void system_clicked();

public:
    RestaurantLayout(MenuController *);
    ~RestaurantLayout();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);


protected:
    void paintEvent(QPaintEvent *event);

private:
    MenuController * control;
    QRect screen {QApplication::desktop()->screenGeometry()};
    int tableCount;
    RestTable *tableHighlighted;
    QPushButton *editButton;
    QPushButton *rotateButton;
    QPushButton *employeeButton;
    QPushButton *systemButton;
    QGraphicsView *view;
    QVector<RestTable*> list;
};

#endif // RESTAURANTLAYOUT_H
