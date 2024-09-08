#ifndef ZHUCE_H
#define ZHUCE_H

#include <QDialog>

namespace Ui {
class zhuce;
}

class zhuce : public QDialog
{
    Q_OBJECT

public:
    explicit zhuce(QWidget *parent = nullptr);
    ~zhuce();

private slots:
    void on_btnok_clicked();

private:
    Ui::zhuce *ui;
};

#endif // ZHUCE_H
