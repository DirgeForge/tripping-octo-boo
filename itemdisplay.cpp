#include "itemdisplay.h"

#include <string>
#include <QApplication>

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

    QSize btSize(screen.width()/6,screen.width()/6);
    QSize iconSize(screen.width()/6 - 5,screen.width()/6 - 30);
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

