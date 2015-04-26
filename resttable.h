#ifndef RESTTABLE_H
#define RESTTABLE_H

/*
 * Creates the image and controls the action
 * of the tables and booths in the restruant.
 *
 * Actual image is created with paint function.
 *
 * should be modified to hold orders ?
 *
 */


#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QApplication>
#include <QVector>
#include <QStack>
#include "backend/include/iitem.h"
#include "backend/include/menucontroller.h"

class RestTable : public QGraphicsItem
{
public:
    RestTable();
    RestTable(int tableNumber, bool setBooth, MenuController*);
    void rotate();
    void addItem(IItem*);
    QString sendOrder();
    QVector<IItem*> getOrderList();
    int getTableID() const;

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;


private:
    //static int totalTables;
    QVector<IItem*> orderList;
    QStack<IItem*> unsentOrder;
    MenuController * control;
	QRect screen{ QApplication::desktop()->screenGeometry() };
    int tableID;
    bool isBooth;
    QPointF offset;
	int ratio{ 11 };
	int ratio2{ ratio - 2 };
    QPointF prevPoint;
    bool bHighlighted {false};

	QPixmap image;

	// Normal Table
	QRect leftChair;
	QRect topChair;
	QRect rightChair;
	QRect bottomChair;
	QRect centerTable;

	// Booth
	QRect boothTable;
	QRect boothText;
	QRect topCushion;
	QRect bottomCushion;
	QRect topBooth;
	QRect bottomBooth;
	QRect centerBooth;
};


#endif // RestTable

