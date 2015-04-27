#include "restaurantmenu.h"

RestaurantMenu::RestaurantMenu()
{
    this->setStyleSheet("background-color: rgb(98,177,109)");

    back = new QPushButton;
    back->setParent(this);
    back->setStyleSheet("background-color: rgb(255, 255, 255);");
    back->setGeometry(screen.width()/32,screen.height()/32,screen.width()/16,screen.height()/16);
    back->setText("Back");

    printRecipit = new QPushButton;
    printRecipit->setParent(this);
    printRecipit->setStyleSheet("background: white");
    printRecipit->setGeometry(screen.width()/32,(22*screen.height())/32,screen.width()/6,(3*screen.height())/32);
    printRecipit->setText("Print Recipit");

    removeItem = new QPushButton;
    removeItem->setParent(this);
    removeItem->setStyleSheet("background: white");
    removeItem->setGeometry(screen.width()/32,(25*screen.height())/32,screen.width()/6,(3*screen.height())/32);
    removeItem->setText("Remove Item");

    clearTable = new QPushButton;
    clearTable->setParent(this);
    clearTable->setStyleSheet("background: white");
    clearTable->setGeometry(screen.width()/32,(28*screen.height())/32,screen.width()/6,(3*screen.height())/32);
    clearTable->setText("Clear Table");

    tableNumber = new QLabel;
    tableNumber->setParent(this);
    tableNumber->setStyleSheet("background: red");
    tableNumber->setGeometry((4*screen.width())/32,screen.height()/32,screen.width()/16,screen.height()/16);
    tableNumber->setText("Table #IDK");
    tableNumber->setAlignment(Qt::AlignCenter);

    orderTitle = new QLabel;
    orderTitle->setParent(this);
    orderTitle->setStyleSheet("background:red");
    orderTitle->setGeometry(screen.width()/32,(4*screen.height())/32,screen.width()/6,screen.height()/16);
    orderTitle->setText("Order List");
    orderTitle->setAlignment(Qt::AlignCenter);

    orderList = new QListWidget;
    orderList->setParent(this);
    orderList->setStyleSheet("background: green");
    orderList->setGeometry(screen.width()/32,(6*screen.height())/32,screen.width()/6,screen.height()/2);

    ////////////////////// END OF ORDER MENU BUTTONS ////////////////////////////////////////////////

    ////////////////////// MENU TABS //////////////////////////////////////////////////////////////

    ////////////// SET UP

    // TAB MASTER
    tabMaster = new QTabWidget;
    tabMaster->setParent(this);
    //tab->setStyleSheet("background: yellow");
    tabMaster->setGeometry((8*screen.width())/32,screen.height()/32,(22*screen.width())/32,(30*screen.height())/32);

    // BREAKFAST TAB
    QWidget *breakfastTab = new QWidget(tabMaster);
    tabMaster->addTab(breakfastTab,"Breakfast");

    // LUNCH TAB
    QWidget *lunchTab = new QWidget(tabMaster);
    tabMaster->addTab(lunchTab,"Lunch");

    // Breakfast Window Set UP
    QGridLayout *layout = new QGridLayout;
    breakfastTab->setLayout(layout);
    QScrollArea *scroll = new QScrollArea;
    scroll->setWidgetResizable(false);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    breakfastTab->layout()->addWidget(scroll);
    QWidget *breakfastWindow = new QWidget;
    breakfastWindow->setGeometry(0,0,tabMaster->width(),screen.height()*2);

    scroll->setWidget(breakfastWindow);

    // Lunch Window Set UP
    QGridLayout *layout2 = new QGridLayout;
    lunchTab->setLayout(layout2);
    QScrollArea *scroll2 = new QScrollArea;
    scroll2->setWidgetResizable(false);
    scroll2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    lunchTab->layout()->addWidget(scroll2);
    QWidget *lunchWindow = new QWidget;
    lunchWindow->setGeometry(0,0,tabMaster->width(),screen.height()*2);
    scroll2->setWidget(lunchWindow);

    ///////////// END OF SET UP

    //////////////BREAKFAST

    // FIRST ROW /////////////////////////////////////////////////////////////////////////////////////////////////////////
    QPushButton *button1 = new QPushButton(breakfastWindow);
    button1->setText("Default Pic");
    //button1->seticon(image-here);
    //button1->setIconSize(QSize(buttonLength,buttonLength));
    button1->setStyleSheet("background: white");
    button1->setGeometry((3*tabMaster->width())/64,(2*tabMaster->height())/32,buttonLength,buttonLength);
    QLabel *label1 = new QLabel(breakfastWindow);
    label1->setGeometry(button1->pos().x(),button1->pos().y()+buttonLength,buttonLength,tabMaster->height()/16);
    label1->setAlignment(Qt::AlignCenter);
    label1->setText("Default Text");

    QPushButton *button2 = new QPushButton(breakfastWindow);
    button2->setText("Default Pic");
    //button1->seticon(image-here);
    //button1->setIconSize(QSize(buttonLength,buttonLength));
    button2->setStyleSheet("background: white");
    button2->setGeometry(button1->pos().x()+buttonLength+((2*tabMaster->width())/32),button1->pos().y(),buttonLength,buttonLength);
    QLabel *label2 = new QLabel(breakfastWindow);
    label2->setGeometry(button2->pos().x(),button2->pos().y()+buttonLength,buttonLength,label1->height());
    label2->setAlignment(Qt::AlignCenter);
    label2->setText("Default Text");

    QPushButton *button3 = new QPushButton(breakfastWindow);
    button3->setText("Default Pic");
    //button1->seticon(image-here);
    //button1->setIconSize(QSize(buttonLength,buttonLength));
    button3->setStyleSheet("background: white");
    button3->setGeometry(button2->pos().x()+buttonLength+((2*tabMaster->width())/32),button1->pos().y(),buttonLength,buttonLength);
    QLabel *label3 = new QLabel(breakfastWindow);
    label3->setGeometry(button3->pos().x(),button3->pos().y()+buttonLength,buttonLength,label1->height());
    label3->setAlignment(Qt::AlignCenter);
    label3->setText("Default Text");

    QPushButton *button4 = new QPushButton(breakfastWindow);
    button4->setText("Default Pic");
    //button1->seticon(image-here);
    //button1->setIconSize(QSize(buttonLength,buttonLength));
    button4->setStyleSheet("background: white");
    button4->setGeometry(button3->pos().x()+buttonLength+((2*tabMaster->width())/32),button1->pos().y(),buttonLength,buttonLength);
    QLabel *label4 = new QLabel(breakfastWindow);
    label4->setGeometry(button4->pos().x(),button4->pos().y()+buttonLength,buttonLength,label1->height());
    label4->setAlignment(Qt::AlignCenter);
    label4->setText("Default Text");

    //SECOND ROW/////////////////////////////////////////////////////////////////////////////////////////////////////////
    QPushButton *button5 = new QPushButton(breakfastWindow);
    button5->setText("Default Pic");
    //button1->seticon(image-here);
    //button1->setIconSize(QSize(buttonLength,buttonLength));
    button5->setStyleSheet("background: white");
    button5->setGeometry(button1->pos().x(),button1->pos().y()+buttonLength+(4*tabMaster->height())/32,buttonLength,buttonLength);
    QLabel *label5 = new QLabel(breakfastWindow);
    label5->setGeometry(button5->pos().x(),button5->pos().y()+buttonLength,buttonLength,label1->height());
    label5->setAlignment(Qt::AlignCenter);
    label5->setText("Default Text");

    QPushButton *button6 = new QPushButton(breakfastWindow);
    button6->setText("Default Pic");
    //button1->seticon(image-here);
    //button1->setIconSize(QSize(buttonLength,buttonLength));
    button6->setStyleSheet("background: white");
    button6->setGeometry(button5->pos().x()+buttonLength+((2*tabMaster->width())/32),button5->pos().y(),buttonLength,buttonLength);
    QLabel *label6 = new QLabel(breakfastWindow);
    label6->setGeometry(button6->pos().x(),button6->pos().y()+buttonLength,buttonLength,label1->height());
    label6->setAlignment(Qt::AlignCenter);
    label6->setText("Default Text");

    QPushButton *button7 = new QPushButton(breakfastWindow);
    button7->setText("Default Pic");
    //button1->seticon(image-here);
    //button1->setIconSize(QSize(buttonLength,buttonLength));
    button7->setStyleSheet("background: white");
    button7->setGeometry(button6->pos().x()+buttonLength+((2*tabMaster->width())/32),button5->pos().y(),buttonLength,buttonLength);
    QLabel *label7 = new QLabel(breakfastWindow);
    label7->setGeometry(button7->pos().x(),button7->pos().y()+buttonLength,buttonLength,label1->height());
    label7->setAlignment(Qt::AlignCenter);
    label7->setText("Default Text");

    QPushButton *button8 = new QPushButton(breakfastWindow);
    button8->setText("Default Pic");
    //button1->seticon(image-here);
    //button1->setIconSize(QSize(buttonLength,buttonLength));
    button8->setStyleSheet("background: white");
    button8->setGeometry(button7->pos().x()+buttonLength+((2*tabMaster->width())/32),button5->pos().y(),buttonLength,buttonLength);
    QLabel *label8 = new QLabel(breakfastWindow);
    label8->setGeometry(button8->pos().x(),button8->pos().y()+buttonLength,buttonLength,label1->height());
    label8->setAlignment(Qt::AlignCenter);
    label8->setText("Default Text");

    //THIRD ROW //////////////////////////////////////////////////////////////////////////////////////////////////////////
    QPushButton *button9 = new QPushButton(breakfastWindow);
    button9->setText("Default Pic");
    //button1->seticon(image-here);
    //button1->setIconSize(QSize(buttonLength,buttonLength));
    button9->setStyleSheet("background: white");
    button9->setGeometry(button5->pos().x(),button5->pos().y()+buttonLength+(4*tabMaster->height())/32,buttonLength,buttonLength);
    QLabel *label9 = new QLabel(breakfastWindow);
    label9->setGeometry(button9->pos().x(),button9->pos().y()+buttonLength,buttonLength,label1->height());
    label9->setAlignment(Qt::AlignCenter);
    label9->setText("Default Text");

    QPushButton *button10 = new QPushButton(breakfastWindow);
    button10->setText("Default Pic");
    //button1->seticon(image-here);
    //button1->setIconSize(QSize(buttonLength,buttonLength));
    button10->setStyleSheet("background: white");
    button10->setGeometry(button9->pos().x()+buttonLength+((2*tabMaster->width())/32),button9->pos().y(),buttonLength,buttonLength);
    QLabel *label10 = new QLabel(breakfastWindow);
    label10->setGeometry(button10->pos().x(),button10->pos().y()+buttonLength,buttonLength,label1->height());
    label10->setAlignment(Qt::AlignCenter);
    label10->setText("Default Text");

    QPushButton *button11 = new QPushButton(breakfastWindow);
    button11->setText("Default Pic");
    //button1->seticon(image-here);
    //button1->setIconSize(QSize(buttonLength,buttonLength));
    button11->setStyleSheet("background: white");
    button11->setGeometry(button10->pos().x()+buttonLength+((2*tabMaster->width())/32),button9->pos().y(),buttonLength,buttonLength);
    QLabel *label11 = new QLabel(breakfastWindow);
    label11->setGeometry(button11->pos().x(),button11->pos().y()+buttonLength,buttonLength,label1->height());
    label11->setAlignment(Qt::AlignCenter);
    label11->setText("Default Text");

    QPushButton *button12 = new QPushButton(breakfastWindow);
    button12->setText("Default Pic");
    //button1->seticon(image-here);
    //button1->setIconSize(QSize(buttonLength,buttonLength));
    button12->setStyleSheet("background: white");
    button12->setGeometry(button11->pos().x()+buttonLength+((2*tabMaster->width())/32),button9->pos().y(),buttonLength,buttonLength);
    QLabel *label12 = new QLabel(breakfastWindow);
    label12->setGeometry(button12->pos().x(),button12->pos().y()+buttonLength,buttonLength,label1->height());
    label12->setAlignment(Qt::AlignCenter);
    label12->setText("Default Text");

    //////////////LUNCH

    // FIRST ROW /////////////////////////////////////////////////////////////////////////////////////////////////////////
    QPushButton *lunchButton1 = new QPushButton(lunchWindow);
    lunchButton1->setText("Default Pic");
    //button1->seticon(image-here);
    //button1->setIconSize(QSize(buttonLength,buttonLength));
    lunchButton1->setStyleSheet("background: white");
    lunchButton1->setGeometry((3*tabMaster->width())/64,(2*tabMaster->height())/32,buttonLength,buttonLength);
    QLabel *lunchLabel1 = new QLabel(lunchWindow);
    lunchLabel1->setGeometry(button1->pos().x(),button1->pos().y()+buttonLength,buttonLength,tabMaster->height()/16);
    lunchLabel1->setAlignment(Qt::AlignCenter);
    lunchLabel1->setText("Default Text");

    QPushButton *lunchButton2 = new QPushButton(lunchWindow);
    lunchButton2->setText("Default Pic");
    //button1->seticon(image-here);
    //button1->setIconSize(QSize(buttonLength,buttonLength));
    lunchButton2->setStyleSheet("background: white");
    lunchButton2->setGeometry(button1->pos().x()+buttonLength+((2*tabMaster->width())/32),button1->pos().y(),buttonLength,buttonLength);
    QLabel *lunchLabel2 = new QLabel(lunchWindow);
    lunchLabel2->setGeometry(button2->pos().x(),button2->pos().y()+buttonLength,buttonLength,label1->height());
    lunchLabel2->setAlignment(Qt::AlignCenter);
    lunchLabel2->setText("Default Text");

    QPushButton *lunchButton3 = new QPushButton(lunchWindow);
    lunchButton3->setText("Default Pic");
    //button1->seticon(image-here);
    //button1->setIconSize(QSize(buttonLength,buttonLength));
    lunchButton3->setStyleSheet("background: white");
    lunchButton3->setGeometry(button2->pos().x()+buttonLength+((2*tabMaster->width())/32),button1->pos().y(),buttonLength,buttonLength);
    QLabel *lunchLabel3 = new QLabel(lunchWindow);
    lunchLabel3->setGeometry(button3->pos().x(),button3->pos().y()+buttonLength,buttonLength,label1->height());
    lunchLabel3->setAlignment(Qt::AlignCenter);
    lunchLabel3->setText("Default Text");

    QPushButton *lunchButton4 = new QPushButton(lunchWindow);
    lunchButton4->setText("Default Pic");
    //button1->seticon(image-here);
    //button1->setIconSize(QSize(buttonLength,buttonLength));
    lunchButton4->setStyleSheet("background: white");
    lunchButton4->setGeometry(button3->pos().x()+buttonLength+((2*tabMaster->width())/32),button1->pos().y(),buttonLength,buttonLength);
    QLabel *lunchLabel4 = new QLabel(lunchWindow);
    lunchLabel4->setGeometry(button4->pos().x(),button4->pos().y()+buttonLength,buttonLength,label1->height());
    lunchLabel4->setAlignment(Qt::AlignCenter);
    lunchLabel4->setText("Default Text");

    //////////////////////// END OF MENU TABS ///////////////////////////////////////////////////

    /////////////////////// BUTTON TRIGGERS ////////////////////////////////////

    QObject::connect(back, SIGNAL(clicked()), this, SLOT(close()));
    //QObject::connect(table2, SIGNAL(pressed()), this, SLOT(table_pressed()));

    //////////////////////// END OF BUTTON TRIGGERS //////////////////////////////



    this->showFullScreen();
}

RestaurantMenu::~RestaurantMenu()
{

}
