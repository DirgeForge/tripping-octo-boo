#include <QtWidgets>

#include "resttable.h"
//#include "employeemenu.h"
#include "systemmenu.h"
#include "barchair.h"
#include "Menu.h"
#include "editmenu.h"
#include "introwindow.h"
#include "graphicsview.h"
#include "restaurantlayout.h"
#include "restaurantmenu.h"

// --- includes for the backend ---
#include "backend/include/menucontroller.h"
#include "backend/include/menumodel.h"
#include "backend/include/iviewable.h"
// --- end includes for the backend ---

#include <math.h>




int main(int argc, char *argv[])
{
    MenuModel * model = new MenuModel;
    MenuController *control = new MenuController(model);

    QApplication app(argc, argv);


    //RestaurantMenu *w = new RestaurantMenu;
    //Menu *w = new Menu(5, control);
    RestaurantLayout *r = new RestaurantLayout(control);

    IntroWindow *w = new IntroWindow(r);
    w->show();


    return app.exec();
}
