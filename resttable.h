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


#include<QGraphicsItem>
#include<QGraphicsView>
#include "graphicsview.h"

class RestTable : public QGraphicsItem
{
public:
    static GraphicsView *masterView;
    RestTable();
    RestTable(bool);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;


private:
    static int totalTables;
    int tableID;
    QColor color;
    bool isBooth;
    QPointF prevPoint;
};


#endif // RestTable

