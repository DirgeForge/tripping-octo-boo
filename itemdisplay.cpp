#include "itemdisplay.h"
#include "Menu.h"
#include <string>


ItemDisplay::ItemDisplay(IItem *item, Menu * menu, QWidget *parent) : item(item), QWidget(parent)
{
    itemButton = new QToolButton;
    connect(itemButton, SIGNAL(clicked()),this,SLOT(order()));
    connect(this, SIGNAL(sendOrder(IItem*)), menu, SLOT(order(IItem*)));


    QPixmap pixMap;
    std::string loadtest;
    loadtest = item->getImgPath();



    pixMap.load(QCoreApplication::applicationDirPath() + QString::fromStdString(item->getImgPath()));

    QIcon buttonIcon(pixMap);

    QSize btSize(150,150);
    QSize iconSize(145,115);
    itemButton->setFixedSize(btSize);
    itemButton->setIconSize(iconSize);
    itemButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    itemButton->setIcon(buttonIcon);
    itemButton->setText(QString::fromStdString(item->getTitle()));


}

QToolButton *ItemDisplay::getButton() const
{
    return itemButton;
}

ItemDisplay::~ItemDisplay()
{
    delete itemButton;
}
IItem * ItemDisplay::getItem() const
{
    return item;
}

void ItemDisplay::order()
{
    emit sendOrder(item);
}

