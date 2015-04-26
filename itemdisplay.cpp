#include "itemdisplay.h"
#include <string>

ItemDisplay::ItemDisplay(IItem *item)
{
    itemButton = new QPushButton;
    itemLabel = new QLabel;

    QPixmap pixMap;
    std::string loadtest;
    loadtest = item->getImgPath();

    pixMap.load(QCoreApplication::applicationDirPath() + QString::fromStdString(item->getImgPath()));

    QIcon buttonIcon(pixMap);

    QSize btSize(150,150);
    QSize iconSize(145,145);
    itemButton->setFixedSize(btSize);
    itemButton->setIconSize(iconSize);
    itemButton->setIcon(buttonIcon);

/*
    QString test = "test-";
    test.append(QString::fromStdString(item->getImgPath()));
    itemButton->setText(test);
*/
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

