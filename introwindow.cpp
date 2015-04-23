#include "introwindow.h"

IntroWindow::IntroWindow()
{
    this->setStyleSheet("background:rgb(98,177,109);");

    //////////////////////// INTRO WORD ////////////////////////////////////

    QLabel *Intro = new QLabel;
    Intro->setParent(this);
    Intro->setText("Welcome to");
    // text size need to become generic
    Intro->setFont(QFont("Old English Text MT" , screen.height()/15)); // 80
    // label covers all of the text
    Intro->adjustSize();
    Intro->setGeometry(((screen.center().x())-((Intro->width())/2)),((2*(((screen.center().y())/16)))-((Intro->height())/2)),Intro->width(),Intro->height());
    Intro->setScaledContents(true);

    QLabel *Intro2 = new QLabel;
    Intro2->setParent(this);
    Intro2->setText("Pirate's Catch");
    // text size need to become generic
    Intro2->setFont(QFont("Old English Text MT" , screen.height()/15)); // 90
    // label covers all of the text
    Intro2->adjustSize();
    Intro2->setGeometry(((screen.center().x())-((Intro2->width())/2)),((6*(((screen.center().y())/16)))-((Intro2->height())/2)),Intro2->width(),Intro2->height());
    Intro2->setScaledContents(true);

    QLabel *Intro3 = new QLabel;
    Intro3->setParent(this);
    Intro3->setText("Seafood Restuarant and Bar");
    // text size need to become generic
    Intro3->setFont(QFont("Old English Text MT" , screen.height()/50)); // 26
    // label covers all of the text
    Intro3->adjustSize();
    Intro3->setGeometry(((screen.center().x())-((Intro3->width())/2)),((10*(((screen.center().y())/16)))-((Intro3->height())/2)),Intro3->width(),Intro3->height());
    Intro3->setScaledContents(true);

    ////////////////////////// END OF INTRO WORD /////////////////////////

    ////////////////////////// QLABELS //////////////////////////////////

    // NUMPAD WHITE BOX
    numpadDisplay = new QLabel;
    numpadDisplay->setParent(this);

    // for debugging
    numpadDisplay->setStyleSheet("background: white");

    numpadDisplay->setFont(QFont("Old English Text MT" , screen.height()/35)); //45
    // set width and height of box
    numpadDisplay->setGeometry(0,0,screen.center().x()/3,screen.center().y()/10);
    numpadDisplay->setGeometry(((screen.center().x())-((numpadDisplay->width())/2)),(((screen.center().y())-((numpadDisplay->height())/2))-(screen.height()/12)),numpadDisplay->width(),numpadDisplay->height());


    // NUMPAD EMPTY MESSAGE
    numpadEmpty = new QLabel;
    numpadEmpty->setParent(this);

    numpadEmpty->setFont(QFont("Old English Text MT", screen.height()/60));
    numpadEmpty->setText("Enter Employee Number");
    numpadEmpty->setStyleSheet("background: transparent");
    numpadEmpty->adjustSize();
    numpadEmpty->setGeometry(((screen.center().x())-((numpadEmpty->width())/2)),(((screen.center().y())-((numpadEmpty->height())/2))-(screen.height()/12)),numpadEmpty->width(),numpadEmpty->height());

    // NUMPAD ERROR MESSAGE
    numpadError = new QLabel;
    numpadError->setParent(this);

    numpadError->setFont(QFont("Old English Text MT", screen.height()/64));
    numpadError->setText("No Match");
    numpadError->setStyleSheet("background: transparent; color: red");
    numpadError->adjustSize();
    numpadError->setGeometry(numpadDisplay->pos().x() + (29*(numpadDisplay->width()/32)),numpadDisplay->pos().y() + (numpadDisplay->height()/3),numpadError->width(),numpadError->height());
    numpadError->setVisible(false);

    // NUMPAD DIGIT ERROR MESSAGE
    digitError = new QLabel;
    digitError->setParent(this);

    digitError->setFont(QFont("Old English Text MT", screen.height()/64));
    digitError->setText("Must be\n 8-digit");
    digitError->setStyleSheet("background: transparent; color: red");
    //numpadError->adjustSize();
    digitError->setGeometry(numpadDisplay->pos().x() + (30*(numpadDisplay->width()/32)),numpadDisplay->pos().y(),numpadError->width(),numpadError->height()*2);
    digitError->setWordWrap(true);
    digitError->setVisible(false);

    ////////////////////////////// END OF LABELS //////////////////////////////////////

    /////////////////////// #5 BUTTON (ALPHA BUTTON)  //////////////////////////////
    // if 5 is moved the numpad follows with it

    five = new QPushButton;
    five->setParent(this);
    five->setText("5");
    five->setStyleSheet("background: transparent"); // button is drawn by QPainter

    buttonLength = (screen.width()/24);

    // Login and Backspace text size
    int loginButton_size = (buttonLength/4);

    // All number buttons text size
    QFont font("Old English Text MT",buttonLength/2);
    five->setFont(font);


    // button is squared and is sized by (comp screen horizontal length / 16)
    five->setGeometry(0,0,buttonLength,buttonLength);
    // button is slighty adjust to make it centered, just position is changed
    five->setGeometry(((screen.center().x())-((five->width())/2)),(((screen.center().y())-((five->height())/2))+(screen.height()/6)),buttonLength,buttonLength);

    /////////////////////// END of #5 BUTTON (ALPHA BUTTON) ////////////////////

    spacing = (screen.width()/54);

    /////////////////////// Buttons on SIDE/TOP of #5 (#2,#4,#6,#8,#0) ////////////////////

    two = new QPushButton;
    two->setParent(this);
    two->setText("2");
    two->setFont(font);
    two->setStyleSheet("background: transparent");
    two->setGeometry(five->x(),(five->y()-(spacing+buttonLength)),buttonLength,buttonLength);


    four = new QPushButton;
    four->setParent(this);
    four->setText("4");
    four->setFont(font);
    four->setStyleSheet("background: transparent");
    four->setGeometry((five->x()-(spacing+buttonLength)),five->y(),buttonLength,buttonLength);


    six = new QPushButton;
    six->setParent(this);
    six->setText("6");
    six->setFont(font);
    six->setStyleSheet("background: transparent");
    six->setGeometry((five->x()+(spacing+buttonLength)),five->y(),buttonLength,buttonLength);


    eight = new QPushButton;
    eight->setParent(this);
    eight->setText("8");
    eight->setFont(font);
    eight->setStyleSheet("background: transparent");
    eight->setGeometry(five->x(),(five->y()+(spacing+buttonLength)),buttonLength,buttonLength);

    zero = new QPushButton;
    zero->setParent(this);
    zero->setText("0");
    zero->setFont(font);
    zero->setStyleSheet("background: transparent");
    zero->setGeometry(five->x(),(five->y()+(2*(spacing+buttonLength))),buttonLength,buttonLength);

    //////////////////////// END of SIDE/TOP of 5 ////////////////////////

    //////////////////////// OTHER BUTTONS (#1,#3,#7,#9,backspace,login) ////////////////

    three = new QPushButton;
    three->setParent(this);
    three->setText("3");
    three->setFont(font);
    three->setStyleSheet("background: transparent");
    three->setGeometry((five->x()+(spacing+buttonLength)),(five->y()-(spacing+buttonLength)),buttonLength,buttonLength);

    one = new QPushButton;
    one->setParent(this);
    one->setText("1");
    one->setFont(font);
    one->setStyleSheet("background: transparent");
    one->setGeometry((five->x()-(spacing+buttonLength)),(five->y()-(spacing+buttonLength)),buttonLength,buttonLength);

    seven = new QPushButton;
    seven->setParent(this);
    seven->setText("7");
    seven->setFont(font);
    seven->setStyleSheet("background: transparent");
    seven->setGeometry((five->x()-(spacing+buttonLength)),(five->y()+(spacing+buttonLength)),buttonLength,buttonLength);

    nine = new QPushButton;
    nine->setParent(this);
    nine->setText("9");
    nine->setFont(font);
    nine->setStyleSheet("background: transparent");
    nine->setGeometry((five->x()+(spacing+buttonLength)),(five->y()+(spacing+buttonLength)),buttonLength,buttonLength);

    backspace = new QPushButton;
    backspace->setParent(this);
    backspace->setText("x");
    backspace->setFont(QFont("Old English Text MT", loginButton_size));
    backspace->setStyleSheet("background: transparent");
    backspace->setGeometry((five->x()-(spacing+buttonLength)),(five->y()+(2*(spacing+buttonLength))),buttonLength,buttonLength);

    login = new QPushButton;
    login->setParent(this);
    login->setText("Login");
    login->setFont(QFont("Old English Text MT", loginButton_size));
    login->setStyleSheet("background: transparent");
    login->setGeometry((five->x()+(spacing+buttonLength)),(five->y()+(2*(spacing+buttonLength))),buttonLength,buttonLength);

    ///////////////////////// END of OTHER BUTTONS /////////////////////////////////////

    //////////////////////// ON CLICKED FUNCTIONS //////////////////////////////////////

    QObject::connect(one, SIGNAL(clicked()), this, SLOT(number_clicked()));
    QObject::connect(two, SIGNAL(clicked()), this, SLOT(number_clicked()));
    QObject::connect(three, SIGNAL(clicked()),this,SLOT(number_clicked()));
    QObject::connect(four, SIGNAL(clicked()),this,SLOT(number_clicked()));
    QObject::connect(five, SIGNAL(clicked()),this,SLOT(number_clicked()));
    QObject::connect(six, SIGNAL(clicked()),this,SLOT(number_clicked()));
    QObject::connect(seven, SIGNAL(clicked()),this,SLOT(number_clicked()));
    QObject::connect(eight, SIGNAL(clicked()),this,SLOT(number_clicked()));
    QObject::connect(nine, SIGNAL(clicked()),this,SLOT(number_clicked()));
    QObject::connect(backspace, SIGNAL(clicked()),this,SLOT(backspace_clicked()));
    QObject::connect(zero, SIGNAL(clicked()),this,SLOT(number_clicked()));
    QObject::connect(login, SIGNAL(clicked()),this,SLOT(login_clicked()));

    //////////////////////// END OF ON CLICKED FUNCTIONS //////////////////////////////////

    ////////////////////////  TradeMark //////////////////////////////////////////////

    QLabel *pos = new QLabel;
    pos->setParent(this);

    pos->setText("POS by PirateSoft");
    pos->setFont(QFont("Times New Roman", screen.height()/40));
    pos->adjustSize();
    pos->setGeometry(screen.width()/64,63*(screen.height()/64),pos->width(),pos->height());

    //////////////////////// END Of TradeMark //////////////////////////////////////////

    //////////////////////////  TIME & DATE ////////////////////////////////////

    // Date
    date = new QLabel;
    date->setParent(this);

    QDate currentDate = QDate::currentDate(); // gets current date
    int year = currentDate.year();
    year = year % 2000;
    date->setText(QString::number(currentDate.month()) + "/" + QString::number(currentDate.day()) + "/" + QString::number(year));
    date->setFont(QFont("Old English Text MT" , screen.height()/32));
    date->setStyleSheet("background: transparent");
    date->adjustSize();
    date->setGeometry(screen.width()/16,screen.height()/16,date->width(),date->height());

    // Time
    time = new QLabel;
    time->setParent(this);

    QTime currentTime = QTime::currentTime(); // gets current date
    QString hour;
    QString postfix;

    if (currentTime.hour() < 12)
    {
        postfix = "AM";
        int i = currentTime.hour();
        if (i > 9)
            hour = QString::number(i);
        else
            hour = "0" + QString::number(i);
    }
    else
    {
        postfix = "PM";
        int i = currentTime.hour();
        i -= 12;
        if (i > 9)
            hour = QString::number(i);
        else
            hour = "0" + QString::number(i);
    }

    time->setText(hour + ":" + QString::number(currentTime.minute())
                  + " " + postfix);
    time->setFont(QFont("New Times Roman" , screen.height()/40));
    time->setStyleSheet("background: transparent");
    time->adjustSize();
    time->setGeometry(9*(screen.width()/128),3*(screen.height()/16),date->width(),date->height());
    /////////////////////////// END OF TIME & DATE

    this->showFullScreen();
}

IntroWindow::~IntroWindow()
{

}

void IntroWindow::number_clicked()
{
    if (!(numpadDisplay->text().size() >= 8))
    {
        if (numpadDisplay->text().size() == 0)
            numpadEmpty->setVisible(false);

        if (digitError->isVisible())
            digitError->setVisible(false);

        QPushButton *currentButton = (QPushButton *)sender();
        numpadDisplay->setText(numpadDisplay->text() + currentButton->text());
    }

}

void IntroWindow::backspace_clicked()
{
    if (numpadDisplay->text().size() != 0)
    {
        if (numpadError->isVisible())
            numpadError->setVisible(false);

        if (digitError->isVisible())
            digitError->setVisible(false);

        QString newText = numpadDisplay->text();
        newText.chop(1);
        numpadDisplay->setText(newText);

        if (numpadDisplay->text().size() == 0)
            numpadEmpty->setVisible(true);
    }
}

void IntroWindow::login_clicked()
{
    if (numpadDisplay->text().size() == 8)
    {
        if (numpadDisplay->text() == "11111111")
        {
            RestaurantLayout *w = new RestaurantLayout;
            //QMainWindow *w = new QMainWindow;
            w->setWindowTitle("Next Window");
            w->show();
        }
        else
        {
            numpadError->setVisible(true);
        }
    }
    else if (!(numpadDisplay->text() == 0))
    {
        digitError->setVisible(true);
    }
}

void IntroWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);

    // Draws Green border of the display
    painter.setBrush(QBrush(QColor(74,168,44)));
    QPen pen;
    pen.setWidth(5);
    painter.setPen(pen);
    QRect displayGreen(0,0,(8*(screen.width()/32)),(3*(screen.height()/32)));
    painter.drawRoundRect(((screen.center().x())-((displayGreen.width())/2)),(((screen.center().y())-((displayGreen.height())/2))-(screen.height()/12)),displayGreen.width(),displayGreen.height(),10,40);

    // Draws Green border of numpad
    QRect numpadGreen(0,0,(3 * one->width()) + (3 * spacing),(4 * one->height()) + (4 * spacing));
    painter.drawRoundRect(one->pos().x() - (spacing/2),one->pos().y() - (spacing/2),numpadGreen.width(),numpadGreen.height(),15,10);

    // Draws white numpad display
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(QColor(255,255,255)));
    QRect Display(0,0,(7*(screen.center().x()/16)),(2*(screen.center().y()/16)));
    painter.drawRoundRect(((screen.center().x())-((Display.width())/2)),(((screen.center().y())-((Display.height())/2))-(screen.height()/12)),Display.width(),Display.height(),10,40);

    ///////////////////////// Draws all the numpad buttons ///////////////////////////////
    QPixmap pixmap(buttonLength,buttonLength);
    pixmap.fill(Qt::transparent);

    QPainter painter2(&pixmap);
    painter2.setRenderHint(QPainter::HighQualityAntialiasing);
    painter2.setPen(Qt::NoPen);
    painter2.setBrush(QBrush(QColor(255,255,255)));
    painter2.drawRoundRect(0,0,pixmap.width(),pixmap.height(),15,15);
    QPen pen2;
    pen2.setWidth(5);
    painter2.setPen(pen2);
    painter2.drawEllipse((pixmap.width()/16),(pixmap.height()/16),buttonLength - (pixmap.width()/8),buttonLength - (pixmap.height()/8));

    painter.setBrush(QBrush(QColor(0,0,0)));

    // Login Button
    QPen pen3;
    pen3.setWidth(6);
    painter.setPen(pen3);
    painter.setBrush(QBrush(QColor(108,246,65)));
    painter.drawRoundRect(login->pos().x(),login->pos().y(),buttonLength,buttonLength,15,15);

    // Backspace Button
    QPixmap pixmapBackspace(buttonLength,buttonLength);
    pixmapBackspace.fill(Qt::transparent);

    QPainter painterBackspace(&pixmapBackspace);
    painterBackspace.setRenderHint(QPainter::HighQualityAntialiasing);
    painterBackspace.setPen(Qt::NoPen);
    painterBackspace.setBrush(QBrush(QColor(255,255,255)));
    painterBackspace.drawRoundRect(0,0,pixmap.width(),pixmap.height(),15,15);
    QPen pen4;
    pen4.setWidth(5);
    painterBackspace.setPen(pen4);
    QPolygon polygon;
    polygon << QPoint(pixmapBackspace.width()/8,pixmapBackspace.height()/2) << QPoint(pixmapBackspace.width()/3,pixmapBackspace.height()/4)
            << QPoint(7*(pixmapBackspace.width()/8),pixmapBackspace.height()/4) << QPoint(7*(pixmapBackspace.width()/8),3*(pixmapBackspace.height()/4))
            << QPoint(pixmapBackspace.width()/3,3*(pixmapBackspace.height()/4));
    painterBackspace.setBrush(QBrush(QColor(255,0,0)));
    painterBackspace.drawPolygon(polygon);

    // location of number drawings
    painter.drawPixmap(one->pos().x(),one->pos().y(),buttonLength,buttonLength,pixmap);
    painter.drawPixmap(two->pos().x(),two->pos().y(),buttonLength,buttonLength,pixmap);
    painter.drawPixmap(three->pos().x(),three->pos().y(),buttonLength,buttonLength,pixmap);
    painter.drawPixmap(four->pos().x(),four->pos().y(),buttonLength,buttonLength,pixmap);
    painter.drawPixmap(five->pos().x(),five->pos().y(),buttonLength,buttonLength,pixmap);
    painter.drawPixmap(six->pos().x(),six->pos().y(),buttonLength,buttonLength,pixmap);
    painter.drawPixmap(seven->pos().x(),seven->pos().y(),buttonLength,buttonLength,pixmap);
    painter.drawPixmap(eight->pos().x(),eight->pos().y(),buttonLength,buttonLength,pixmap);
    painter.drawPixmap(nine->pos().x(),nine->pos().y(),buttonLength,buttonLength,pixmap);
    painter.drawPixmap(zero->pos().x(),zero->pos().y(),buttonLength,buttonLength,pixmap);
    painter.drawPixmap(backspace->pos().x(),backspace->pos().y(),buttonLength,buttonLength,pixmapBackspace);

    //////////////////////////// End of numpad buttons ////////////////////////////////////////

    painter.setBrush(QBrush(QColor(108,246,65)));
    painter.setPen(Qt::NoPen);
    painter.drawRoundRect((date->pos().x()) - (screen.width()/64),(date->pos().y()) - (screen.height()/64),date->width() + (2*(screen.width()/64)),date->height() + (2*(screen.height()/64)),15,15);
    painter.drawRoundRect((time->pos().x()) - (screen.width()/128),(time->pos().y()) - (screen.height()/128),time->width() + (2*(screen.width()/128)),time->height() + (2*(screen.height()/128)),15,15);

}
