#ifndef GRAPHICSVIEW
#define GRAPHICSVIEW

#include <QGraphicsView>
#include "backend/include/menucontroller.h"
#include "backend/include/menumodel.h"
#include "backend/include/iviewable.h"

class GraphicsView : public QGraphicsView, public IViewable
{
/* --- control and model variables (these should be private) ---
   pass these pointers to any sub-windows so they can modify the
   model state on event triggers.
   all modifications should be done via control's member functions. */
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
        this->control = new MenuController(model, this);
    }
    void update()
    {
        // get model state via the pointer
    }
    void initMenu()
    {
        this->model = new MenuModel;
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

#endif // GRAPHICSVIEW

