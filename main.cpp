#include <QtWidgets>



#include "resttable.h"
#include "ordermenu.h"

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

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QGraphicsScene scene(-400, -300, 800, 600);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j< 4; j++)
        {
            RestTable *tableItem = new RestTable;
            tableItem->setPos(-100 + (j*110), -20 + (i*80));
            scene.addItem(tableItem);
        }
    }

    GraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setBackgroundBrush(QColor(238, 238, 238));
    view.setWindowTitle("Drag and Drop Robot");
     view.show();


    return app.exec();
}
