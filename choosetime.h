#ifndef CHOOSETIME_H
#define CHOOSETIME_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class choosetime;
}

class choosetime : public QDialog
{
    Q_OBJECT

public:
    explicit choosetime(QString a, QWidget *parent = nullptr);
    ~choosetime();

private slots:
    void on_appoint1_clicked();
    void on_appoint2_clicked();
    void on_appoint3_clicked();
    void on_apppoint4_clicked();

private:
    Ui::choosetime *ui;


    void checkAndDisableAppointmentButtons();
};

#endif

