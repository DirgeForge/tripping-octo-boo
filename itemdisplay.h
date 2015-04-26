#ifndef ITEMDISPLAY_H
#define ITEMDISPLAY_H


#include <QObject>
#include <QPushButton>
#include <QLabel>
#include "backend/include/fooditem.h"

class ItemDisplay
{
public:
    ItemDisplay(const FoodItem& item);
    QPushButton *getButton() const;
    QLabel *getLabel() const;
    ~ItemDisplay();

private:
    QPushButton *itemButton;
    QLabel *itemLabel;
};

#endif // ITEMDISPLAY_H
