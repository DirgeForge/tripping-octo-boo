#include "restaurantlayout.h"

RestaurantLayout::RestaurantLayout()
{
    tableCount = 0;

    TableButton *table1 = new TableButton(++tableCount,false);
    table1 = new TableButton(++tableCount,false);
    table1->setParent(this);
    table1->setGeometry((12 * screen.width())/64,(3 * screen.height())/64,table1->width(),table1->height());

    TableButton *table2 = new TableButton(++tableCount,false);
    table2->setParent(this);
    table2->setGeometry((21 * screen.width())/64,(3 * screen.height())/64,table2->width(),table2->height());

    TableButton *table3 = new TableButton(++tableCount,false);
    table3->setParent(this);
    table3->setGeometry((12 * screen.width())/64,(11 * screen.height())/64,table3->width(),table3->height());

    TableButton *table4 = new TableButton(++tableCount,false);
    table4->setParent(this);
    table4->setGeometry((21 * screen.width())/64,(11 * screen.height())/64,table4->width(),table4->height());

    TableButton *table5 = new TableButton(++tableCount,false);
    table5->setParent(this);
    table5->setGeometry((21 * screen.width())/64,(19 * screen.height())/64,table5->width(),table5->height());

    TableButton *table6 = new TableButton(++tableCount,false);
    table6->setParent(this);
    table6->setGeometry((12 * screen.width())/64,(23 * screen.height())/64,table6->width(),table6->height());
    table6->rotate();

    TableButton *table7 = new TableButton(++tableCount,false);
    table7->setParent(this);
    table7->setGeometry((21 * screen.width())/64,(27 * screen.height())/64,table7->width(),table7->height());

    // BOOTHS

    TableButton *table8 = new TableButton(++tableCount,true);
    table8->setParent(this);
    table8->setGeometry((30 * screen.width())/64,(3 * screen.height())/64,table8->width(),table8->height());

    TableButton *table9 = new TableButton(++tableCount,true);
    table9->setParent(this);
    table9->setGeometry((30 * screen.width())/64,(screen.height()/128)+ table8->pos().y() + table9->height(),table9->width(),table9->height());

    TableButton *table10 = new TableButton(++tableCount,true);
    table10->setParent(this);
    table10->setGeometry((30 * screen.width())/64,(screen.height()/128)+ table9->pos().y() + table10->height(),table10->width(),table10->height());

    TableButton *table11 = new TableButton(++tableCount,true);
    table11->setParent(this);
    table11->setGeometry((30 * screen.width())/64,(screen.height()/128)+ table10->pos().y() + table11->height(),table11->width(),table11->height());

    // rotate booths

    TableButton *table12 = new TableButton(++tableCount,true);
    table12->setParent(this);
    table12->rotate();
    table12->setGeometry((12 * screen.width())/64,((81 * screen.height())/128),table12->width(),table12->height());

    TableButton *table13 = new TableButton(++tableCount,true);
    table13->setParent(this);
    table13->rotate();
    table13->setGeometry(table12->x()+table13->width()+(screen.height()/128),table12->y(),table13->width(),table13->height());

    TableButton *table14 = new TableButton(++tableCount,true);
    table14->setParent(this);
    table14->rotate();
    table14->setGeometry(table13->x()+table14->width()+(screen.height()/128),table13->y(),table14->width(),table14->height());

    TableButton *table15 = new TableButton(++tableCount,true);
    table15->setParent(this);
    table15->rotate();
    table15->setGeometry(table14->x()+table15->width()+(screen.height()/128),table14->y(),table15->width(),table15->height());

    // tables on the side

    TableButton *table16 = new TableButton(++tableCount,false);
    table16->setParent(this);
    table16->rotate();
    table16->setGeometry((42 * screen.width())/64,(3 * screen.height())/64,table16->width(),table16->height());

    TableButton *table17 = new TableButton(++tableCount,false);
    table17->setParent(this);
    table17->rotate();
    table17->setGeometry(table16->x(),table16->y() + table16->height() + (2 * screen.height())/64,table17->width(),table17->height());

    TableButton *table18 = new TableButton(++tableCount,false);
    table18->setParent(this);
    table18->rotate();
    table18->setGeometry(table17->x(),table17->y() + table17->height() + (2 * screen.height())/64,table18->width(),table18->height());

    TableButton *table19 = new TableButton(++tableCount,false);
    table19->setParent(this);
    table19->rotate();
    table19->setGeometry(table18->x(),table18->y() + table18->height() + (2 * screen.height())/64,table19->width(),table19->height());

    // private members

    editButton = new QPushButton;
    editButton->setParent(this);
    editButton->setGeometry((2*screen.width())/32,((28*screen.height())/32),(3*screen.height())/32,(3*screen.height())/32);
    editButton->setFont(QFont("Old English Text MT",30));
    editButton->setText("Edit");

    rotateButton = new QPushButton;
    rotateButton->setParent(this);
    rotateButton->setGeometry((5*screen.width())/32,((28*screen.height())/32),(3*screen.height())/32,(3*screen.height())/32);

    tableHighlighted = new TableButton();

    employeeButton = new QPushButton;
    employeeButton->setParent(this);
    employeeButton->setGeometry((8*screen.width())/32,((28*screen.height())/32),(3*screen.height())/32,(3*screen.height())/32);
    employeeButton->setFont(QFont("Old English Text MT",19));
    employeeButton->setText("Employee");

    //////////////////////// ON CLICKED FUNCTIONS //////////////////////////////////////

    QObject::connect(table1, SIGNAL(pressed()), this, SLOT(table_pressed()));
    QObject::connect(table2, SIGNAL(pressed()), this, SLOT(table_pressed()));
    QObject::connect(table3, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table4, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table4, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table5, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table6, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table7, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table8, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table9, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table10, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table11, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table12, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table13, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table14, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table15, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table16, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table17, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table18, SIGNAL(pressed()),this,SLOT(table_pressed()));
    QObject::connect(table19, SIGNAL(pressed()),this,SLOT(table_pressed()));

    QObject::connect(editButton, SIGNAL(clicked()), this, SLOT(edit_clicked()));
    QObject::connect(rotateButton, SIGNAL(clicked()),this,SLOT(rotate_clicked()));
    QObject::connect(employeeButton, SIGNAL(clicked()), this, SLOT(employee_clicked()));

    //////////////////////// END OF ON CLICKED FUNCTIONS //////////////////////////////////

    // END
    this->showFullScreen();
}

RestaurantLayout::~RestaurantLayout()
{
    // DESTRUCTOR
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

void RestaurantLayout::table_pressed()
{
    TableButton *currentButton = (TableButton*)sender();
    if (!(tableHighlighted == currentButton)) // highlights table if it wasnt selected before
    {
        tableHighlighted->setStyleSheet("background: transparent");
        currentButton->setStyleSheet("background: red");
        tableHighlighted = currentButton;
    }
}

void RestaurantLayout::rotate_clicked()
{
    tableHighlighted->rotate();
    tableHighlighted->setStyleSheet("background: red");
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

