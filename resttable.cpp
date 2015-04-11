// Test Table for PirateSoft

#include <QtWidgets>
#include "resttable.h"
#include "ordermenu.h"

int RestTable::totalTables(0);

RestTable::RestTable() : color(166, 45, 13)
{
    isBooth = false;
    tableID = ++totalTables;
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

RestTable::RestTable(bool setBooth) : color(166, 45, 13)
{
    isBooth = setBooth;
    tableID = ++totalTables;
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}


QRectF RestTable::boundingRect() const
{
    return QRectF(0, 0, 205, 135);
}
void RestTable::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (isBooth)
    {
        //draws outside border of booth
        painter->setPen(QColor(148,89,42));
        painter->setBrush(QBrush(QColor(148,89,42)));
        painter->drawRect(0,0,175,25);
        painter->drawRect(150,0,25,129);
        painter->drawRect(0,104,175,25);

        //draws booth set
        painter->setPen(QColor(136,28,31));
        painter->setBrush(QColor(136,28,31));
        painter->drawRoundedRect(5,5,160,15,10,10, Qt::RelativeSize);
        painter->drawRoundedRect(5,109,160,15,10,10, Qt::RelativeSize);

        //draws table
        painter->setPen(QPen(Qt::black, 6));
        painter->setBrush(QBrush(color));
        painter->drawRoundedRect(0,30,145,70,15,15, Qt::RelativeSize);
        painter->setPen(QPen(QColor(68,255,0), 2));
        painter->setFont(QFont("Times", 15, QFont::Bold));
        painter->drawText(105,60,QString::number(tableID));
    }
    else
    {
        painter->setPen(QPen(Qt::black, 5));
        painter->setBrush(QBrush(color));
        painter->drawRoundedRect(2,2,150,75,15,15, Qt::RelativeSize);
        painter->setPen(QPen(QColor(68,255,0), 2));
        painter->setFont(QFont("Times", 15, QFont::Bold));
        painter->drawText(40,35,QString::number(tableID));
    }
}

void RestTable::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::ClosedHandCursor);
}

void RestTable::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if  (isBooth)
        return;
    else if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
            .length() < QApplication::startDragDistance()) {
            return;
        }
    setPos(event->scenePos());
}

void RestTable::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::OpenHandCursor);
}
void RestTable::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    OrderMenu *showBox = new OrderMenu(tableID);
    showBox->exec();
}
