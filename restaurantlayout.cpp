#include "restaurantlayout.h"

RestaurantLayout::RestaurantLayout()
{
    tableCount = 0;

    QGraphicsScene *scene = new QGraphicsScene(0,0,screen.width(),(26 * screen.height())/32);

    RestTable *table1 = new RestTable(++tableCount,false);
    scene->addItem(table1);
    table1->setPos((12 * screen.width())/64,(3 * screen.height())/64);

    RestTable *table2 = new RestTable(++tableCount,false);
    scene->addItem(table2);
    table2->setPos((21 * screen.width())/64,(3 * screen.height())/64);

    RestTable *table3 = new RestTable(++tableCount,false);
    scene->addItem(table3);
    table3->setPos((12 * screen.width())/64,(11 * screen.height())/64);

    RestTable *table4 = new RestTable(++tableCount,false);
    scene->addItem(table4);
    table4->setPos((21 * screen.width())/64,(11 * screen.height())/64);

    RestTable *table5 = new RestTable(++tableCount,false);
    scene->addItem(table5);
    table5->setPos((21 * screen.width())/64,(19 * screen.height())/64);

    RestTable *table6 = new RestTable(++tableCount,false);
    scene->addItem(table6);
    table6->setPos((12 * screen.width())/64,(23 * screen.height())/64);
    table6->rotate();

    RestTable *table7 = new RestTable(++tableCount,false);
    scene->addItem(table7);
    table7->setPos((21 * screen.width())/64,(27 * screen.height())/64);

    // BOOTHS

    RestTable *table8 = new RestTable(++tableCount,true);
    scene->addItem(table8);
    table8->setPos((30 * screen.width())/64,(3 * screen.height())/64);

    RestTable *table9 = new RestTable(++tableCount,true);
    scene->addItem(table9);
    table9->setPos((30 * screen.width())/64,((8*screen.height())/64)+ table8->pos().y());

    RestTable *table10 = new RestTable(++tableCount,true);
    scene->addItem(table10);
    table10->setPos((30 * screen.width())/64,((8*screen.height())/64)+ table9->pos().y());

    RestTable *table11 = new RestTable(++tableCount,true);
    scene->addItem(table11);
    table11->setPos((30 * screen.width())/64,((8*screen.height())/64)+ table10->pos().y());

//    // rotate booths

    RestTable *table12 = new RestTable(++tableCount,true);
    scene->addItem(table12);
    table12->rotate();
    table12->setPos((12 * screen.width())/64,((81 * screen.height())/128));

    RestTable *table13 = new RestTable(++tableCount,true);
    scene->addItem(table13);
    table13->rotate();
    table13->setPos(table12->x()+((8*screen.height())/64),table12->y());

    RestTable *table14 = new RestTable(++tableCount,true);
    scene->addItem(table14);
    table14->rotate();
    table14->setPos(table13->x()+((8*screen.height())/64),table13->y());

    RestTable *table15 = new RestTable(++tableCount,true);
    scene->addItem(table15);
    table15->rotate();
    table15->setPos(table14->x()+((8*screen.height())/64),table14->y());

//    // tables on the side

    RestTable *table16 = new RestTable(++tableCount,false);
    scene->addItem(table16);
    table16->rotate();
    table16->setPos((42 * screen.width())/64,(3 * screen.height())/64);

    RestTable *table17 = new RestTable(++tableCount,false);
    scene->addItem(table17);
    table17->rotate();
    table17->setPos(table16->x(),table16->y() + (12 * screen.height())/64);

    RestTable *table18 = new RestTable(++tableCount,false);
    scene->addItem(table18);
    table18->rotate();
    table18->setPos(table17->x(),table17->y() + (12 * screen.height())/64);

    RestTable *table19 = new RestTable(++tableCount,false);
    scene->addItem(table19);
    table19->rotate();
    table19->setPos(table18->x(),table18->y() + (12 * screen.height())/64);

    // private members

    view = new QGraphicsView(this);
    view->setGeometry(0,0,screen.width(),(26 * screen.height())/32);
    view->setStyleSheet("background: orange");
    view->setParent(this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->show();
    view->setScene(scene);

    editButton = new QPushButton;
    editButton->setParent(this);
    editButton->setGeometry((2*screen.width())/32,((28*screen.height())/32),(3*screen.height())/32,(3*screen.height())/32);
    editButton->setFont(QFont("Old English Text MT",30));
    editButton->setText("Edit");

    rotateButton = new QPushButton;
    rotateButton->setParent(this);
    rotateButton->setGeometry((5*screen.width())/32,((28*screen.height())/32),(3*screen.height())/32,(3*screen.height())/32);

    tableHighlighted = new RestTable();

    employeeButton = new QPushButton;
    employeeButton->setParent(this);
    employeeButton->setGeometry((8*screen.width())/32,((28*screen.height())/32),(3*screen.height())/32,(3*screen.height())/32);
    employeeButton->setFont(QFont("Old English Text MT",19));
    employeeButton->setText("Employee");

    systemButton = new QPushButton;
    systemButton->setParent(this);
    systemButton->setGeometry((11*screen.width())/32,((28*screen.height())/32),(3*screen.height())/32,(3*screen.height())/32);
    systemButton->setFont(QFont("Old English Text MT",19));
    systemButton->setText("System");

    //////////////////////// ON CLICKED FUNCTIONS //////////////////////////////////////

//    QObject::connect(table1, SIGNAL(pressed()), this, SLOT(table_pressed()));
//    QObject::connect(table2, SIGNAL(pressed()), this, SLOT(table_pressed()));
//    QObject::connect(table3, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table4, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table4, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table5, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table6, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table7, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table8, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table9, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table10, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table11, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table12, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table13, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table14, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table15, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table16, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table17, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table18, SIGNAL(pressed()),this,SLOT(table_pressed()));
//    QObject::connect(table19, SIGNAL(pressed()),this,SLOT(table_pressed()));

    QObject::connect(editButton, SIGNAL(clicked()), this, SLOT(edit_clicked()));
    QObject::connect(rotateButton, SIGNAL(clicked()),this,SLOT(rotate_clicked()));
    QObject::connect(employeeButton, SIGNAL(clicked()), this, SLOT(employee_clicked()));
    QObject::connect(systemButton, SIGNAL(clicked()), this, SLOT(system_clicked()));

    //////////////////////// END OF ON CLICKED FUNCTIONS //////////////////////////////////


    // END
    this->showFullScreen();
}

RestaurantLayout::~RestaurantLayout()
{
    // DESTRUCTOR
}

void RestaurantLayout::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}

void RestaurantLayout::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

}

void RestaurantLayout::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}

void RestaurantLayout::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}

void RestaurantLayout::edit_clicked()
{

}

void RestaurantLayout::employee_clicked()
{
    //QMainWindow *w = new QMainWindow;
    EmployeeMenu *w = new EmployeeMenu;
    w->show();
}

void RestaurantLayout::system_clicked()
{
    SystemMenu *w = new SystemMenu;
    w->show();
}

void RestaurantLayout::table_pressed()
{
//    TableButton *currentButton = (TableButton*)sender();
//    if (!(tableHighlighted == currentButton)) // highlights table if it wasnt selected before
//    {
//        tableHighlighted->setStyleSheet("background: transparent");
//        currentButton->setStyleSheet("background: red");
//        tableHighlighted = currentButton;
//    }
}

void RestaurantLayout::rotate_clicked()
{
    tableHighlighted->rotate();
//    tableHighlighted->setStyleSheet("background: red");
}

void RestaurantLayout::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);

    painter.setBrush(QColor(98,177,109));
    painter.setPen(Qt::NoPen);
    painter.drawRect(0,(26 * screen.height())/32,screen.width(),(33 * screen.height())/32);

    // Rotate Picture
    QPixmap rotate(rotateButton->width(),rotateButton->height());
    rotate.fill(Qt::transparent);
    QPainter painter2(&rotate); 
    QFont font;
    font.setPixelSize(250/11); // number / ratio
    QFontMetrics fm(font);
    painter2.setPen(QPen(QColor(0,0,255)));
    painter2.setFont(font);
    painter2.drawText(QRect((rotateButton->width()/2)-(fm.width(QString("Rotate"))/2),(rotateButton->height()/2)-(fm.height()/2),rotateButton->width(),rotateButton->height()),QString("Rotate"));

    // END
    rotateButton->setIcon(QIcon(rotate));
    rotateButton->setIconSize(QSize(rotateButton->width(),rotateButton->height()));

}

