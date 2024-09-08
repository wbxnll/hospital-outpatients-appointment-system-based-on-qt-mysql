#ifndef LOGINDOCTOR_H
#define LOGINDOCTOR_H

#include <QDialog>

namespace Ui {
class logindoctor;
}

class logindoctor : public QDialog
{
    Q_OBJECT

public:
    explicit logindoctor(QWidget *parent = nullptr);
    ~logindoctor();
    int numbe;

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::logindoctor *ui;
};

#endif // LOGINDOCTOR_H
