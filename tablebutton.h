#ifndef TABLEBUTTON_H
#define TABLEBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QtWidgets>
#include <QPainter>
#include <QMainWindow>

#include <QGraphicsItem>
#include<QGraphicsView>
#include "graphicsview.h"

#include "Menu.h"

//class TableButton : public QPushButton
class TableButton : public QPushButton
{
public:
    TableButton();
    TableButton(int tableNumber, bool setBooth);
    ~TableButton();

    void rotate();
    int getTableID() const;

    // QMouseEvent
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

protected:
    //void paintEvent(QPaintEvent *event);

private:
    //static int totalTables;
    QRect screen {QApplication::desktop()->screenGeometry()};
    int tableID;
    bool isBooth;
    QPoint offset;
    int ratio {11};
    int ratio2 {ratio-2};
    QRect size;

    // Normal Table
    QPixmap table;
    QRect leftChair;
    QRect topChair;
    QRect rightChair;
    QRect bottomChair;
    QRect centerTable;

    // Booth
    QPixmap booth;
    QRect boothTable;
    QRect boothText;
    QRect topCushion;
    QRect bottomCushion;
    QRect topBooth;
    QRect bottomBooth;
    QRect centerBooth;

};

#endif // TABLEBUTTON_H
