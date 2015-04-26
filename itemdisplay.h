#ifndef ITEMDISPLAY_H
#define ITEMDISPLAY_H


#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QCoreApplication>
#include <QFile>
#include "backend/include/fooditem.h"

class ItemDisplay
{
public:
    ItemDisplay(IItem* item);
    QPushButton *getButton() const;
    QLabel *getLabel() const;
    ~ItemDisplay();

private:
    QPushButton *itemButton;
    QLabel *itemLabel;
};

#endif // ITEMDISPLAY_H
