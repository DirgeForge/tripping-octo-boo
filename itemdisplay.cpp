#include "itemdisplay.h"

ItemDisplay::ItemDisplay(const FoodItem & item)
{
    itemButton = new QPushButton;
    itemLabel = new QLabel;

    QPixmap pixMap(QString::fromStdString(item.getImgPath()));
    QIcon buttonIcon(pixMap);

    QSize btSize(150,150);
    QSize iconSize(145,145);
    itemButton->setFixedSize(btSize);
    itemButton->setIconSize(iconSize);
    itemButton->setIcon(buttonIcon);




}

QPushButton *ItemDisplay::getButton() const
{
    return itemButton;
}
QLabel *ItemDisplay::getLabel() const
{
    return itemLabel;
}

ItemDisplay::~ItemDisplay()
{
    delete itemButton;
    delete itemLabel;
}

