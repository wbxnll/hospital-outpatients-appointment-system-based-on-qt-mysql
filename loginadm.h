#ifndef LOGINADM_H
#define LOGINADM_H

#include <QDialog>

namespace Ui {
class loginadm;
}

class loginadm : public QDialog
{
    Q_OBJECT

public:
    explicit loginadm(QWidget *parent = nullptr);
    ~loginadm();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::loginadm *ui;
};

#endif // LOGINADM_H
