#ifndef TIINGZHEN_H
#define TIINGZHEN_H

#include <QDialog>

namespace Ui {
class tiingzhen;
}

class tiingzhen : public QDialog
{
    Q_OBJECT

public:
    explicit tiingzhen(QString name,QWidget *parent = nullptr);
    ~tiingzhen();
    QString name1;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::tiingzhen *ui;
};

#endif // TIINGZHEN_H
