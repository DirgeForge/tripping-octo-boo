#include <QtWidgets>
#include "systemmenu.h"
#include "ui_systemmenu.h"

SystemMenu::SystemMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SystemMenu)
{
    ui->setupUi(this);
}

SystemMenu::SystemMenu(QColor color) : color(color)
{

}
QRectF SystemMenu::boundingRect() const
{
    return QRectF(0, 0, 155, 105);
}

void SystemMenu::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(color));
    painter->drawEllipse(SystemMenu::boundingRect());
    painter->setPen(QPen(Qt::black, 2));
    painter->setFont(QFont("Times", 10, QFont::Bold));
    painter->drawText(25, 55, "System Menu");
}

void SystemMenu::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    SystemMenu *showBox = new SystemMenu();
    showBox->exec();
}

SystemMenu::~SystemMenu()
{
    delete ui;
}
