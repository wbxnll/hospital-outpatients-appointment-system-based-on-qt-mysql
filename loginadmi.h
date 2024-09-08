#ifndef LOGINADMI_H
#define LOGINADMI_H

#include <QDialog>

namespace Ui {
class loginadmi;
}

class loginadmi : public QDialog
{
    Q_OBJECT

public:
    explicit loginadmi(QWidget *parent = nullptr);
    ~loginadmi();

private:
    Ui::loginadmi *ui;
};

#endif // LOGINADMI_H
