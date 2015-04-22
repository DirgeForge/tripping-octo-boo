#ifndef SYSTEMICON_H
#define SYSTEMICON_H

/*  Controls UI for system menu and icon
 *
 *
 *
 * ui is edited by using the systemmenu.ui file
 *
 */


#include <QGraphicsItem>
#include <QDialog>
#include <QDateTime>

namespace Ui {
class SystemMenu;
}

class SystemMenu : public QDialog, public QGraphicsItem
{
    Q_OBJECT

public:
    SystemMenu(QColor);
    explicit SystemMenu(QWidget *parent = 0);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

    ~SystemMenu();

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void on_power_clicked();

    void on_pushButton_clicked();

private:
    Ui::SystemMenu *ui;
    QColor color;
};


#endif // SYSTEMICON_H
