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


<<<<<<< HEAD
    //Menu *w = new Menu(5, control);
    RestaurantMenu *w = new RestaurantMenu;
=======
    RestaurantLayout *r = new RestaurantLayout(control);
>>>>>>> origin/master

    IntroWindow *w = new IntroWindow(r);
    w->show();


    return app.exec();
}
