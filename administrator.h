#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QDialog>

namespace Ui {
class administrator;
}

class administrator : public QDialog
{
    Q_OBJECT

public:
    explicit administrator(QWidget *parent = nullptr);
    ~administrator();
private slots:
    void onTreeViewDoubleClicked(const QModelIndex &index);
private:
    Ui::administrator *ui;
};

#endif
