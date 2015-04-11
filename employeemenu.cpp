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
    return QRectF(0, 0, 300, 100);
}

void EmployeeMenu::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(color));
    painter->drawRoundedRect(EmployeeMenu::boundingRect(), 25, 25, Qt::RelativeSize);
    painter->setPen(QPen(Qt::black, 2));
    painter->setFont(QFont("Times", 20, QFont::Bold));
    painter->drawText(25, 55, "Employee Menu");
}

void EmployeeMenu::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    EmployeeMenu *showBox = new EmployeeMenu();
    showBox->exec();   //Launches the UI
}

EmployeeMenu::~EmployeeMenu()
{
    delete ui;
}
