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

// --- includes for the backend ---
#include "backend/include/menucontroller.h"
#include "backend/include/menumodel.h"
#include "backend/include/iviewable.h"
// --- end includes for the backend ---

#include <math.h>




int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    RestaurantLayout *w = new RestaurantLayout;

//    //IntroWindow *w = new IntroWindow;
    w->show();


    return app.exec();
}
