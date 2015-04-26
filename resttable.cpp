// Test Table for PirateSoft

#include <QtWidgets>
#include "resttable.h"
#include "Menu.h"

// int RestTable::totalTables(0);

RestTable::RestTable()
{
    isBooth = false;
    tableID = 0;
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

RestTable::RestTable(int tableNumber ,bool setBooth)
{
    isBooth = setBooth;
    tableID = tableNumber;
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}


void RestTable::rotate()
{
    if (isBooth)
        this->setTransform(QTransform().translate((screen.width() / (ratio2 + 2))/2, (screen.height() / ratio2)/2).rotate(90).translate(-((screen.width() / (ratio2 + 2))/2), -((screen.height() / ratio2)/2)));
    else
        this->setTransform(QTransform().translate((screen.width() / ratio)/2, (screen.height() / ratio)/2).rotate(90).translate(-((screen.width() / ratio)/2), -((screen.height() / ratio)/2)));

}

QRectF RestTable::boundingRect() const
{
    if (isBooth)
		return QRectF(0, 0, (screen.width() / (ratio2 + 2)), (screen.height() / ratio2));
    else
		return QRectF(0, 0, (screen.width() / ratio), (screen.height() / ratio));
}

void RestTable::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (isBooth)
    {
        QRect size(0, 0, (screen.width() / ratio), (screen.height() / ratio));

        // Painter Startup
        QPixmap temp(size.width(), (size.height()));
        temp.fill(Qt::transparent);
        QPainter painter3(&temp);
        painter3.setRenderHint(QPainter::HighQualityAntialiasing);
        painter3.setPen(QPen(Qt::black, 5));
        painter3.setBrush(QBrush(QColor(166, 45, 13)));

        // Draws table
        boothTable = { (1 * size.width()) / 32 + painter3.pen().width(), ((5 * size.height()) / 32) + painter3.pen().width(), (size.width() - (6 * size.width() / 32)) - (2 * painter3.pen().width()), (size.height() - ((10 * size.height()) / 32)) - (2 * painter3.pen().width()) };
        painter3.drawRoundedRect(boothTable, 10, 10);

        // Draws center lines (for refrence)
        //    painter.setPen(QPen(Qt::black, 2));
        //    painter.drawLine((width()/2) - (width()/16),0,(width()/2) - (width()/16),table.height());
        //    painter.drawLine(0,height()/2,width(),height()/2);

        // Draws Table Number
        QFont font;
        font.setBold(true);
        font.setPixelSize(500 / ratio); // 500
        QFontMetrics fm(font);
        painter3.setPen(QPen(QColor(0, 0, 255)));
        painter3.setFont(font);
        boothText = { ((7 * size.width()) / 16) - (fm.width(QString::number(tableID)) / 2), (size.height() / 2) - (fm.height() / 2), size.width() / 2, size.height() / 2 };
        painter3.drawText(boothText, QString::number(tableID));

        // ADDING BOOTH SIDES
        QRect size2(0, 0, (screen.width() / (ratio2 + 2)), (screen.height() / ratio2));

        QPixmap booth2(size2.width(), (size2.height()));
        booth2.fill(Qt::transparent);
        QPainter painter2(&booth2);
        painter2.setRenderHint(QPainter::HighQualityAntialiasing);
        painter2.drawPixmap(0, (size2.height() / 2) - ((screen.height() / ratio) / 2), screen.width() / ratio, screen.height() / ratio, temp);

        // Draws Booth Outside Brown
        painter2.setPen(Qt::NoPen);
        painter2.setBrush(QColor(148, 89, 42));
        topBooth = { 0, 0, size2.width(), (7 * size2.height()) / 32 };
        painter2.drawRoundedRect(topBooth, 2, 2);
        bottomBooth = { 0, (25 * size2.height()) / 32, size2.width(), (8 * size2.height()) / 32 };
        painter2.drawRoundedRect(bottomBooth, 2, 2);
        centerBooth = { (27 * size2.width()) / 32, 0, (6 * size2.width()) / 32, size2.height() };
        painter2.drawRoundedRect(centerBooth, 2, 2);

        // Draws red cushions
        painter2.setBrush(QColor(136, 28, 31));
        topCushion = { (1 * size2.width()) / 32, (2 * size2.height()) / 32, (24 * size2.width()) / 32, (4 * size2.height()) / 32 };
        painter2.drawRoundedRect(topCushion, 2, 2);
        bottomCushion = { (1 * size2.width()) / 32, (26 * size2.height()) / 32, (24 * size2.width()) / 32, (4 * size2.height()) / 32 };
        painter2.drawRoundedRect(bottomCushion, 2, 2);

        image = booth2;

        //this->setPixmap(image);
        painter->setPen(Qt::NoPen);
        painter->drawPixmap(0,0,size2.width(),size2.height(),image);
    }
    else
    {
        QRect size(0, 0, (screen.width() / ratio), (screen.height() / ratio));

        // painter Startup
        QPixmap table2(size.width(), size.height());
        table2.fill(Qt::transparent);
        QPainter painter2(&table2);
        painter2.setRenderHint(QPainter::HighQualityAntialiasing);

        // Draw chairs
        painter2.setPen(Qt::NoPen);
        painter2.setBrush(QBrush(QColor(0, 0, 0)));
        leftChair = { size.width() / 32, size.height() / 4, size.width() / 32, size.height() / 2 };
        painter2.drawRoundedRect(leftChair, 2, 2); // left
        topChair = { size.width() / 2 - (size.height() / 4), size.height() / 16, size.height() / 2, size.width() / 32 };
        painter2.drawRoundedRect(topChair, 2, 2); // top
        rightChair = { (30 * size.width()) / 32, size.height() / 4, size.width() / 32, size.height() / 2 };
        painter2.drawRoundedRect(rightChair, 2, 2); // right
        bottomChair = { size.width() / 2 - (size.height() / 4), (29 * size.height()) / 32, size.height() / 2, size.width() / 32 };
        painter2.drawRoundedRect(bottomChair, 2, 2); // bottom

        //Draws center table
        painter2.setPen(QPen(Qt::black, 5));
        painter2.setBrush(QBrush(QColor(166, 45, 13)));
        centerTable = { (3 * size.width()) / 32 + painter2.pen().width(), ((5 * size.height()) / 32) + painter2.pen().width(), (size.width() - (6 * size.width() / 32)) - (2 * painter2.pen().width()), (size.height() - ((10 * size.height()) / 32)) - (2 * painter2.pen().width()) };
        painter2.drawRoundedRect(centerTable, 10, 10);

        // Draws center lines (for refrence)
        //painter.setPen(QPen(Qt::black, 2));
        //painter.drawLine(width()/2,0,width()/2,table.height());
        //painter.drawLine(0,height()/2,width(),height()/2);
        //image = table;

        // Draws Text
        QFont font;
        font.setBold(true);
        font.setPixelSize(500 / ratio); // 500
        QFontMetrics fm(font);
        painter2.setPen(QPen(QColor(0, 0, 255)));
        painter2.setFont(font);
        painter2.drawText(QRect((size.width() / 2) - (fm.width(QString::number(tableID)) / 2), (size.height() / 2) - (fm.height() / 2), size.width() / 2, size.height() / 2), QString::number(tableID));

        image = table2;

        painter->setPen(Qt::NoPen);
        painter->drawPixmap(0,0,size.width(),size.height(),image);
    }
}

void RestTable::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ClosedHandCursor);
    offset = event->pos();
    bHighlighted = true;
}

void RestTable::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if  (!isBooth)       //does nothing if the object is a booth since they unmoveable
    {
        //Collision Detection on tables, if the table is touching another object movement stops until
        //the whole object is clear of the colliding object.

        QList<QGraphicsItem *> list = collidingItems();
        if(!list.isEmpty())
        {
            setPos(event->screenPos() - offset);
            list.clear();
            list = collidingItems();
            if(list.isEmpty())
            {
                prevPoint = event->screenPos() - offset;
                return;
            }
            else
            {
                setPos(prevPoint);
                return;
            }
        }
        setPos(event->scenePos() - offset);
        prevPoint = event->scenePos() - offset;
    }



}

void RestTable::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::OpenHandCursor);
}
void RestTable::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);

    //Menu *showBox = new Menu(tableID, masterView);
    RestaurantMenu *showBox = new RestaurantMenu;
    showBox->show();
}
