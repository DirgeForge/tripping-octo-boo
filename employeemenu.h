#ifndef EMPLOYEEMENU_H
#define EMPLOYEEMENU_H

/*  Controls UI for employee menu and icon
 *
 *
 *
 * ui is edited by using the employeemenu.ui file
 *
 */

#include <QDialog>
#include <QGraphicsItem>

namespace Ui {
class EmployeeMenu;
}

class EmployeeMenu : public QDialog, public QGraphicsItem
{
    Q_OBJECT

public:
    EmployeeMenu(QColor);
    explicit EmployeeMenu(QWidget *parent = 0);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

    ~EmployeeMenu();

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

private:
    Ui::EmployeeMenu *ui;
    QColor color;
};

#endif // EMPLOYEEMENU_H
