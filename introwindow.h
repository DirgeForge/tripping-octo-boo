#ifndef INTROWINDOW_H
#define INTROWINDOW_H

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
#include <QGraphicsView>

#include "restaurantlayout.h"

class IntroWindow : public QMainWindow
{
    Q_OBJECT

private slots:
// click functions
    void number_clicked();
    void backspace_clicked();
    void login_clicked();

public:
    IntroWindow(RestaurantLayout*);
    ~IntroWindow();

protected:
    void paintEvent(QPaintEvent *event);

private:
    RestaurantLayout *restaurantLayout;
    QRect screen {QApplication::desktop()->screenGeometry()};
    int buttonLength;
    int spacing;

    QLabel *date;
    QLabel *time;

    QLabel *numpadEmpty;
    QLabel *numpadError;
    QLabel *digitError;
    QLabel *numpadDisplay;

    QPushButton *one;
    QPushButton *two;
    QPushButton *three;
    QPushButton *four;
    QPushButton *five;
    QPushButton *six;
    QPushButton *seven;
    QPushButton *eight;
    QPushButton *nine;
    QPushButton *backspace;
    QPushButton *zero;
    QPushButton *login;

};

#endif // MAINWINDOW_H
