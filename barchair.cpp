// Bar chair implementation

#include <QtWidgets>
#include "barchair.h"
#include "Menu.h"

int BarChair::totalChairs(0);

BarChair::BarChair()
{
    chairID = ++totalChairs;
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

BarChair::~BarChair()
{

}

QRectF BarChair::boundingRect() const
{
    return QRectF(0, 0, 80, 60);
}

void BarChair::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);


    painter->setPen(QPen(QBrush(QColor(49,86,144)),4));
    painter->setBrush(QBrush(QColor(110,165,252)));
    painter->drawEllipse(0,0,60,60);
    painter->setPen(Qt::red);
    painter->setFont(QFont("Times",15,QFont::Bold));
    painter->drawText(65,30,QString::number(chairID));
}

void BarChair::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    Form *showBox = new Form(chairID);
    showBox->show();
}
