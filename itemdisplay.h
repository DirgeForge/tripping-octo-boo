#ifndef ITEMDISPLAY_H
#define ITEMDISPLAY_H


#include <QObject>
#include <QToolButton>
#include <QLabel>
#include <QCoreApplication>
#include <QFile>
#include "backend/include/fooditem.h"
#include "Menu.h"

class ItemDisplay : public QWidget
{
    Q_OBJECT
public:
    ItemDisplay(IItem* item, Menu *menu, QWidget *parent=0);
    IItem * getItem() const;
    QToolButton *getButton() const;
    ~ItemDisplay();

signals:
    void sendOrder(IItem*);

public slots:
    void order();



private:
    QToolButton *itemButton;
    IItem *item;
    QRect screen {QApplication::desktop()->screenGeometry()};
};

#endif // ITEMDISPLAY_H
