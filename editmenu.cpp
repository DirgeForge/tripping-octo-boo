#include "editmenu.h"
#include "ui_editmenu.h"
#include <iostream>
#include <fstream>

#include "qmessagebox.h"
#include <QFileDialog>
#include <QCoreApplication>


EditMenu::EditMenu(MenuController *control, QWidget *parent) : control(control),
    QMainWindow(parent),
    ui(new Ui::EditMenu)
{
    ui->setupUi(this);
    ui->Title->setText("Add Item");

    a = new QMainWindow;
    item = new FoodItem;

}
EditMenu::EditMenu(MenuController * control, const FoodItem & currentItem, QWidget *parent) :
    control(control),
    QMainWindow(parent),
    ui(new Ui::EditMenu)
{
    ui->setupUi(this);


    a = new QMainWindow;
    item = new FoodItem;
    ui->Title->setText("Edit Item");
    ui->editName->setText(QString::fromStdString(currentItem.getTitle()));
    ui->categories->setCurrentIndex(currentItem.getCategory());
    setImage(QString::fromStdString(currentItem.getImgPath()));

}

EditMenu::~EditMenu()
{
    delete ui;
}

void EditMenu::on_remove_item_pressed()
{
   QMessageBox::StandardButton reply;
   reply = QMessageBox::question(this,"Remove Item", "Are you sure "
                                 "you want to remove this menu item?", QMessageBox::Yes|QMessageBox::No);

   if (reply == QMessageBox::Yes) this->close();
    //a->show();
}

void EditMenu::on_save_changes_clicked()
{
    item->setCategory(ui->categories->currentIndex());
    item->setDesc(ui->editDesc->text().toStdString());
    item->setDiscount(ui->editDiscount->value());
    item->setInSeason(ui->inSeason->isChecked());
    item->setPrice(ui->editPrice->value());
    item->setTitle(ui->editName->text().toStdString());

    control->add(item);
    control->update();

    this->close();
}

void EditMenu::on_lineEdit_editingFinished()
{
   // fooditem(4)->getName();
}

void EditMenu::on_editDescription_clicked()
{

}

void EditMenu::on_UploadNewPicture_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open File"),
                "", tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));
    setImage(imagePath);
}
void EditMenu::setImage(const QString & imagePath)
{
    QImage *imageObject = new QImage();
    imageObject->load(imagePath);
    QPixmap image = QPixmap::fromImage(*imageObject);

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->imgDisplay->setScene(scene);
    ui->imgDisplay->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);

    QString saveName = "/";
    saveName.append(ui->editName->text());
    saveName.append(".jpg");
    imageObject->save(QCoreApplication::applicationDirPath()+ saveName);
    item->setImgPath(saveName.toStdString());

}

void EditMenu::on_remove_item_clicked()
{

}
