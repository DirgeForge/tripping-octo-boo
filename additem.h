#ifndef ADDITEM_H
#define ADDITEM_H

#include <QWidget>

namespace Ui {
class AddItem;
}

class AddItem : public QWidget
{
    Q_OBJECT

public:
    explicit AddItem(QWidget *parent = 0);
    ~AddItem();

private slots:
    void on_save_changes_clicked();

    void on_Cancel_clicked();

private:
    Ui::AddItem *ui;
};

#endif // ADDITEM_H
