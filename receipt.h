#ifndef RECEIPT_H
#define RECEIPT_H

#include <QWidget>
#include <QDateTime>

namespace Ui {
class Receipt;
}

class Receipt : public QWidget
{
    Q_OBJECT

public:
    explicit Receipt(QWidget *parent = 0, int tableNum = 0);
    ~Receipt();

private slots:
    void on_backButton_clicked();

    void on_subtotal_textChanged(const QString &arg1);

    void on_printButton_clicked();

private:
    Ui::Receipt *ui;
    int tableNum;
};

#endif // RECEIPT_H
