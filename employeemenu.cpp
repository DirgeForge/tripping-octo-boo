#include <QtWidgets>
#include "employeemenu.h"
#include "ui_employeemenu.h"

EmployeeMenu::EmployeeMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeMenu)
{
    ui->setupUi(this);
}

EmployeeMenu::EmployeeMenu(QColor color) : color(color)
{

}


QRectF EmployeeMenu::boundingRect() const
{
    return QRectF(0, 0, 155, 105);
}

void EmployeeMenu::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(color));
    painter->drawEllipse(EmployeeMenu::boundingRect());
    painter->setPen(QPen(Qt::black, 2));
    painter->setFont(QFont("Times", 10, QFont::Bold));
    painter->drawText(25, 55, "Employee Menu");
}

void EmployeeMenu::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    EmployeeMenu *showBox = new EmployeeMenu();
    showBox->exec();
}

EmployeeMenu::~EmployeeMenu()
{
    delete ui;
}
