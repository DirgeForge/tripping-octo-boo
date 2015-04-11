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


/*
 * Loads the whole restruant layout
 *
 *
 */
void loadRestaurant(QGraphicsScene &scene)
{
    int screen_width = QApplication::desktop()->width();
    int screen_height = QApplication::desktop()->height();
    RestTable *tableItem;

    //place tables
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j< 4; j++)
        {
            tableItem = new RestTable;
            tableItem->setPos(100 + (j*170), 80 + (i*120));
            scene.addItem(tableItem);
        }
    }

    //place booths
    for(int i = 0; i < 6; i++)
    {
        tableItem = new RestTable(true);
        tableItem->setPos(700+(130*i) , screen_height - 360);
        tableItem->setRotation(90);
        scene.addItem(tableItem);
    }

    //menu bar at bottom
    scene.addRect(-50,screen_height-150,screen_width+100,200,QPen(QColor(98,177,109)),QBrush(QColor(98,177,109)));



    //place icons
    EmployeeMenu *employeeIcon = new EmployeeMenu(QColor(86,195,51));
    employeeIcon->setPos(550,screen_height-125);
    scene.addItem(employeeIcon);

    SystemMenu *systemIcon = new SystemMenu(QColor(86,195,51));
    systemIcon->setPos(200,screen_height-125);
    scene.addItem(systemIcon);



}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    int screen_width = QApplication::desktop()->width();
    int screen_height = QApplication::desktop()->height();

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QGraphicsScene scene(0, 0, screen_width, screen_height);

    loadRestaurant(scene);

    GraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //view.showFullScreen();
    //view.fitInView(scene.sceneRect());
    view.setBackgroundBrush(QColor(238, 238, 238));


    view.show();


    return app.exec();
}
