// Test Table for PirateSoft

#include <QtWidgets>
#include "resttable.h"
#include "ordermenu.h"

int RestTable::totalTables(0);

RestTable::RestTable() : color(255, 255, 204)
{
    tableID = ++totalTables;
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}


QRectF RestTable::boundingRect() const
{
    return QRectF(0, 0, 95, 65);
}
void RestTable::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(color));
    painter->drawRoundedRect(0,0,90,60,25,25, Qt::RelativeSize);
    painter->setPen(QPen(Qt::red, 2));
    painter->setFont(QFont("Times", 10, QFont::Bold));
    painter->drawText(40,35,QString::number(tableID));
}

void RestTable::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::ClosedHandCursor);
}

void RestTable::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
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
    OrderMenu *showBox = new OrderMenu();
    showBox->exec();
}
