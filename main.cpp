#include <QtWidgets>

#include "resttable.h"
#include "employeemenu.h"
#include "systemmenu.h"
#include "barchair.h"
#include "Menu.h"
#include "editmenu.h"
#include "additem.h"
#include "introwindow.h"

// --- includes for the backend ---
#include "backend/include/menucontroller.h"
#include "backend/include/menumodel.h"
#include "backend/include/iviewable.h"
// --- end includes for the backend ---

#include <math.h>

class GraphicsView : public QGraphicsView, public IViewable
{
// --- control and model variables (these should be private) ---
// pass these pointers to any sub-windows so they can modify the
// model state on event triggers.
// all modifications should be done via control's member functions.
private:
    MenuController * control;
    MenuModel * model;
// --- end variables for control and model ---

public:
    GraphicsView(QGraphicsScene *scene) : QGraphicsView(scene)
    {
        initBackend();
    }

// --- backend-related functions ---
public:
    void initBackend()
    {
        //this->control = new MenuController(model, this);
    }
    void update()
    {
        // get model state via the pointer
    }
    MenuController * getControl()
    {
        return control;
    }
    MenuModel * getModel()
    {
        return model;
    }

// --- end function ---

protected:
    virtual void resizeEvent(QResizeEvent *) Q_DECL_OVERRIDE
    {
    }
};
int screen_width;
int screen_height;

/*
 * Loads the whole restruant layout
 *
 *
 */
void loadRestaurant(QGraphicsScene &scene)
{

    RestTable *tableItem;
    BarChair *chairItem;

    //place tables
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j< 3; j++)
        {
            tableItem = new RestTable;
            tableItem->setPos(700 + (j*200), (.15*screen_height) + (i*120));
            scene.addItem(tableItem);
        }
    }



    //place booths
    for(int i = 0; i < 5; i++)
    {
        tableItem = new RestTable(true);
        tableItem->setPos(800+(130*i) , screen_height - 360);
        tableItem->setRotation(90);
        scene.addItem(tableItem);
    }

    for(int i = 0; i < 4; i++)
    {
        tableItem = new RestTable(true);
        tableItem->setPos( screen_width - 500 , (.15*screen_height) + (130*i));
        scene.addItem(tableItem);
    }

    //add patio tables
    for(int i = 0; i < 3; i++)
    {
        tableItem = new RestTable;
        tableItem->setPos(screen_width-150, (.15 * screen_height + (220 * i)));
        tableItem->setRotation(90);
        scene.addItem(tableItem);
    }

    //create bar

    scene.addRect(200, screen_height-700,75,500,QPen(Qt::black,8),QBrush(QColor(89,102,251)));
    for (int i = 0; i < 7; i++)
    {
        chairItem = new BarChair;
        chairItem->setPos(300, (screen_height-690 + i*70));
        scene.addItem(chairItem);
    }

    // Walls
    scene.addRect(-50,screen_height-185,screen_width-235,35,QPen(QColor(115,115,115)),QBrush(QColor(115,115,115)));
    scene.addRect(screen_width-325,.15*screen_height-20,35,(screen_height-300)-(.15*screen_height-20),QPen(QColor(115,115,115)),QBrush(QColor(115,115,115)));
    scene.addRect(-12,-12,35,screen_height-150,QPen(QColor(115,115,115)),QBrush(QColor(115,115,115)));
    scene.addRect(150,-12,screen_width-430,35,QPen(QColor(115,115,115)),QBrush(QColor(115,115,115)));


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
    screen_width = QApplication::desktop()->width();
    screen_height = QApplication::desktop()->height();

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QGraphicsScene scene(0, 0, screen_width, screen_height);

    loadRestaurant(scene);

    GraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    view.showFullScreen();
    view.fitInView(scene.sceneRect());


    view.setBackgroundBrush(QColor(238, 238, 238));


    view.show();

    IntroWindow *login = new IntroWindow(&view);
    login->show();


    return app.exec();
}
