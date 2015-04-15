#include "receipt.h"
#include "ui_receipt.h"
#include "qmessagebox.h"

const int TAX = 0.08;

Receipt::Receipt(QWidget *parent, int tableNum) :
    QWidget(parent),
    ui(new Ui::Receipt),
    tableNum(tableNum)
{
    ui->setupUi(this);
    QDateTime time = QDateTime();
    ui->timeDate->setText(time.currentDateTime().toString());
    ui->table->setText(QString::number(tableNum));
}

Receipt::~Receipt()
{
    delete ui;
}

void Receipt::on_backButton_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Receipt Menu", "Quit?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes)
      {
          this->activateWindow();
          close();

      }
}

void Receipt::on_subtotal_textChanged(const QString &arg1)
{
    double subtotal = arg1.toDouble();
    ui->tax->setText(QString::number(subtotal * 0.08, 'f', 2));
    ui->total->setText(QString::number(subtotal * (1.08), 'f', 2));
}

void Receipt::on_printButton_clicked()
{
    QMessageBox::StandardButton printing;
    printing = QMessageBox::information(this, "Print", "Printing...");
    close();
}
