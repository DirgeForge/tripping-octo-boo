#include "tablebutton.h"

TableButton::TableButton()
{

}

TableButton::TableButton(int tableNumber, bool setBooth)
{
    isBooth = setBooth;
    //++totalTables;
    tableID = tableNumber;
    setCursor(Qt::OpenHandCursor);

    if (isBooth)
    {
        this->setGeometry(0,0,(screen.width()/ratio),(screen.height()/ratio));

        // Painter Startup
        QPixmap table(width(),(height()));
        table.fill(Qt::transparent);
        QPainter painter(&table);
        painter.setRenderHint(QPainter::HighQualityAntialiasing);
        painter.setPen(QPen(Qt::black, 5));
        painter.setBrush(QBrush(QColor(166,45,13)));

        // Draws table
        boothTable = {(1* width())/32 + painter.pen().width(),((5*height())/32) + painter.pen().width(),(width()-(6* width()/32)) - (2 * painter.pen().width()),(height()-((10*height())/32)) - (2 * painter.pen().width())};
        painter.drawRoundedRect(boothTable,10,10);

        // Draws center lines (for refrence)
        //    painter.setPen(QPen(Qt::black, 2));
        //    painter.drawLine((width()/2) - (width()/16),0,(width()/2) - (width()/16),table.height());
        //    painter.drawLine(0,height()/2,width(),height()/2);

        // Draws Table Number
        QFont font;
        font.setBold(true);
        font.setPixelSize(500/ratio); // 500
        QFontMetrics fm(font);
        painter.setPen(QPen(QColor(0,0,255)));
        painter.setFont(font);
        boothText = {((7*width())/16)-(fm.width(QString::number(tableNumber))/2),(height()/2)-(fm.height()/2),width()/2,height()/2};
        painter.drawText(boothText,QString::number(tableNumber));

        // ADDING BOOTH SIDES
        this->setGeometry(0,0,(screen.width()/(ratio2+2)),(screen.height()/ratio2));

        QPixmap booth(width(),(height()));
        booth.fill(Qt::transparent);
        QPainter painter2(&booth);
        painter2.setRenderHint(QPainter::HighQualityAntialiasing);
        painter2.drawPixmap(0,(height()/2) - ((screen.height()/ratio)/2),screen.width()/ratio,screen.height()/ratio,table);

        // Draws Booth Outside Brown
        painter2.setPen(Qt::NoPen);
        painter2.setBrush(QColor(148,89,42));
        topBooth = {0,0,width(),(7*height())/32};
        painter2.drawRoundedRect(topBooth,2,2);
        bottomBooth = {0,(25*height())/32,width(),(8*height())/32};
        painter2.drawRoundedRect(bottomBooth,2,2);
        centerBooth = {(27*width())/32,0,(6*width())/32,height()};
        painter2.drawRoundedRect(centerBooth,2,2);

        // Draws red cushions
        painter2.setBrush(QColor(136,28,31));
        topCushion = {(1*width())/32,(2*height())/32,(24*width())/32,(4*height())/32};
        painter2.drawRoundedRect(topCushion,2,2);
        bottomCushion = {(1*width())/32,(26*height())/32,(24*width())/32,(4*height())/32};
        painter2.drawRoundedRect(bottomCushion,2,2);

        // END
        this->setIcon(QIcon(booth));
        this->setIconSize(QSize(width(),height()));
    }
    else
    {

        this->setGeometry(0,0,(screen.width()/ratio),(screen.height()/ratio));

        // painter Startup
        QPixmap table(width(),height());
        table.fill(Qt::transparent);
        QPainter painter(&table);
        painter.setRenderHint(QPainter::HighQualityAntialiasing);

        // Draw chairs
        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(QColor(0,0,0)));
        leftChair = {width()/32,height()/4,width()/32,height()/2};
        painter.drawRoundedRect(leftChair,2,2); // left
        topChair = {width()/2-(height()/4),height()/16,height()/2,width()/32};
        painter.drawRoundedRect(topChair,2,2); // top
        rightChair = {(30 * width())/32,height()/4,width()/32,height()/2};
        painter.drawRoundedRect(rightChair,2,2); // right
        bottomChair = {width()/2-(height()/4),(29 * height())/32,height()/2,width()/32};
        painter.drawRoundedRect(bottomChair,2,2); // bottom

        //Draws center table
        painter.setPen(QPen(Qt::black, 5));
        painter.setBrush(QBrush(QColor(166,45,13)));
        centerTable = {(3* width())/32 + painter.pen().width(),((5*height())/32) + painter.pen().width(),(width()-(6* width()/32)) - (2 * painter.pen().width()),(height()-((10*height())/32)) - (2 * painter.pen().width())};
        painter.drawRoundedRect(centerTable,10,10 );

        // Draws center lines (for refrence)
        //painter.setPen(QPen(Qt::black, 2));
        //painter.drawLine(width()/2,0,width()/2,table.height());
        //painter.drawLine(0,height()/2,width(),height()/2);
        //image = table;

        // Draws Text
        QFont font;
        font.setBold(true);
        font.setPixelSize(500/ratio); // 500
        QFontMetrics fm(font);
        painter.setPen(QPen(QColor(0,0,255)));
        painter.setFont(font);
        painter.drawText(QRect((width()/2)-(fm.width(QString::number(tableNumber))/2),(height()/2)-(fm.height()/2),width()/2,height()/2),QString::number(tableNumber));

        // END
        this->setIcon(QIcon(table));
        this->setIconSize(QSize(width(),height()));
    }
    this->setStyleSheet("background: transparent");
}

TableButton::~TableButton()
{
    // DESTRUCTOR
}

void TableButton::rotate()
{
    // Switching Width and Height
    int newHeight = width();
    int newWidth = height();
    QPoint pos = this->pos();

    if (isBooth)
    {
        this->setGeometry(pos.x()+(width()/2)-(height()/2),pos.y()+(height()/2)-(width()/2),(screen.height()/ratio),(screen.width()/ratio));

        // Painter Startup
        QPixmap table(width(),(height()));
        table.fill(Qt::transparent);
        QPainter painter(&table);
        painter.setRenderHint(QPainter::HighQualityAntialiasing);
        painter.setPen(QPen(Qt::black, 5));
        painter.setBrush(QBrush(QColor(166,45,13)));

        // Draws table
        boothTable = {boothTable.y(),boothTable.x(),boothTable.height(),boothTable.width()};
        painter.drawRoundedRect(boothTable,10,10);

        // Draws center lines (for refrence)
        //    painter.setPen(QPen(Qt::black, 2));
        //    painter.drawLine((width()/2) - (width()/16),0,(width()/2) - (width()/16),table.height());
        //    painter.drawLine(0,height()/2,width(),height()/2);

        // Draws Table Number
        QFont font;
        font.setBold(true);
        font.setPixelSize(450/ratio); // 500
        QFontMetrics fm(font);
        painter.setPen(QPen(QColor(0,0,255)));
        painter.setFont(font);
        //boothText = {((7*width())/16)-(fm.width(QString::number(tableNumber))/2),(height()/2)-(fm.height()/2),width()/2,height()/2};
        boothText = {(width()/2)-(fm.width(QString::number(tableID))/2),((7*height())/16)-(fm.height()/2),width()/2,height()/2};
        painter.drawText(boothText,QString::number(tableID));

        // INCREASING SIZE OF PIXMAP
        this->setGeometry(x(),y(),newWidth,newHeight);

        QPixmap booth(width(),(height()));
        booth.fill(Qt::transparent);
        QPainter painter2(&booth);
        painter2.setRenderHint(QPainter::HighQualityAntialiasing);
        painter2.drawPixmap((width()/2) - ((screen.height()/ratio)/2),0,screen.height()/ratio,screen.width()/ratio,table);

        // Draws Booth Outside (QColor : Brown)
        painter2.setPen(Qt::NoPen);
        painter2.setBrush(QColor(148,89,42));
        topBooth = {topBooth.y(),topBooth.x(),topBooth.height(),topBooth.width()};
        painter2.drawRoundedRect(topBooth,2,2);
        bottomBooth = {bottomBooth.y(),bottomBooth.x(),bottomBooth.height(),bottomBooth.width()};
        painter2.drawRoundedRect(bottomBooth,2,2);
        centerBooth = {centerBooth.y(),centerBooth.x(),centerBooth.height(),centerBooth.width()};
        painter2.drawRoundedRect(centerBooth,2,2);

        // Draws red cushions
        painter2.setBrush(QColor(136,28,31));
        topCushion = {topCushion.y(),topCushion.x(),topCushion.height(),topCushion.width()};
        painter2.drawRoundedRect(topCushion,2,2);
        bottomCushion = {bottomCushion.y(),bottomCushion.x(),bottomCushion.height(),bottomCushion.width()};
        painter2.drawRoundedRect(bottomCushion,2,2);

        // END
        this->setIcon(QIcon(booth));
        this->setIconSize(QSize(width(),height()));
    }
    else
    {
        this->setGeometry(pos.x()+(width()/2)-(height()/2),pos.y()+(height()/2)-(width()/2),newWidth,newHeight);

        // Painter Startup
        QPixmap table(newWidth,newHeight);
        table.fill(Qt::transparent);
        QPainter painter(&table);
        painter.setRenderHint(QPainter::HighQualityAntialiasing);
        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(QColor(0,0,0)));

        // Draw Chairs
        leftChair = {leftChair.y(),leftChair.x(),leftChair.height(),leftChair.width()};
        painter.drawRoundedRect(leftChair,2,2); // left
        topChair = {topChair.y(),topChair.x(),topChair.height(),topChair.width()};
        painter.drawRoundedRect(topChair,2,2); // top
        rightChair = {rightChair.y(),rightChair.x(),rightChair.height(),rightChair.width()};
        painter.drawRoundedRect(rightChair,2,2); // right
        bottomChair = {bottomChair.y(),bottomChair.x(),bottomChair.height(),bottomChair.width()};
        painter.drawRoundedRect(bottomChair,2,2); // bottom

        // Draw Table
        painter.setPen(QPen(Qt::black, 5));
        painter.setBrush(QBrush(QColor(166,45,13)));
        centerTable = {centerTable.y(),centerTable.x(),centerTable.height(),centerTable.width()};
        painter.drawRoundedRect(centerTable,10,10 );

        // Draws center lines (for refrence)
        //painter.setPen(QPen(Qt::black, 2));
        //painter.drawLine(width()/2,0,width()/2,table.height());
        //painter.drawLine(0,height()/2,width(),height()/2);

        //image = table;

        // Draw Text
        QFont font;
        font.setBold(true);
        font.setPixelSize(450/11); // number / ratio
        QFontMetrics fm(font);
        painter.setPen(QPen(QColor(0,0,255)));
        painter.setFont(font);
        painter.drawText(QRect((width()/2)-(fm.width(QString::number(tableID))/2),(height()/2)-(fm.height()/2),width()/2,height()/2),QString::number(tableID));

        // END
        this->setIcon(QIcon(table));
        this->setIconSize(QSize(width(),height()));
    }
    this->setStyleSheet("background: transparent");
}

void TableButton::mousePressEvent(QMouseEvent *event)
{
    setCursor(Qt::ClosedHandCursor);
    offset = event->pos();
    QPushButton::mousePressEvent(event);
}

void TableButton::mouseMoveEvent(QMouseEvent *event)
{
    if (!isBooth)
       this->move(mapToParent(event->pos() - offset));
    QPushButton::mouseMoveEvent(event);
}

void TableButton::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    setCursor(Qt::OpenHandCursor);
    QPushButton::mouseReleaseEvent(event);
}

void TableButton::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    Menu *w = new Menu(tableID);
    w->show();

}

