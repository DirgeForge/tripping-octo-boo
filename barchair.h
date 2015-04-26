#ifndef BARCHAIR_H
#define BARCHAIR_H

/*
 * Creates the image and controls the action
 * of the bar chairs in the restruant.
 *
 * Actual image is created with paint function.
 *
 * should be modified to hold orders ?
 *
 */



#include<QGraphicsItem>
#include "graphicsview.h"

class BarChair : public QGraphicsItem
{
public:
    BarChair();
    ~BarChair();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

private:
    static int totalChairs;
    int chairID;

};

#endif // BARCHAIR_H
