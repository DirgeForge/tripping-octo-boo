#include <QtWidgets>

#include "resttable.h"
#include "ordermenu.h"
#include "employeemenu.h"
#include "systemmenu.h"

#include <math.h>

class GraphicsView : public QGraphicsView
{
public:
    GraphicsView(QGraphicsScene *scene) : QGraphicsView(scene)
    {
    }

protected:
    virtual void resizeEvent(QResizeEvent *) Q_DECL_OVERRIDE
    {
    }
};

void loadRestaurant(QGraphicsScene &scene)
{

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j< 4; j++)
        {
            RestTable *tableItem = new RestTable;
            tableItem->setPos(-100 + (j*170), -80 + (i*120));
            scene.addItem(tableItem);
        }
    }

    EmployeeMenu *employeeIcon = new EmployeeMenu(QColor(52, 183, 14));
    employeeIcon->setPos(400,-300);
    scene.addItem(employeeIcon);

    SystemMenu *systemIcon = new SystemMenu(QColor(252, 183, 214));
    systemIcon->setPos(200, -300);
    scene.addItem(systemIcon);



}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QGraphicsScene scene(-600, -450, 1200, 900);

    loadRestaurant(scene);

    GraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.fitInView(scene.sceneRect());
    view.setBackgroundBrush(QColor(238, 238, 238));

    view.setWindowTitle("Pirate Soft POS UI Prototype");
    view.show();


    return app.exec();
}
