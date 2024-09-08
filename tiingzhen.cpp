#include "tiingzhen.h"
#include "ui_tiingzhen.h"
#include"databasemanager.h"
#include<QString>
#include<QMessageBox>
tiingzhen::tiingzhen(QString name,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tiingzhen)
{
    ui->setupUi(this);
    name1=name;
}


tiingzhen::~tiingzhen()
{
    delete ui;
}

void tiingzhen::on_pushButton_2_clicked()
{
    QSqlDatabase db5 = DatabaseManager::instance().getDatabase();
    QSqlQuery query5(db5);


    query5.prepare("UPDATE doctor SET tingzhen = 0, remain1 =0, remain2 =0, remain3 =0, remain4 =0 WHERE name = :Name");
    query5.bindValue(":Name", name1);
    query5.exec();
    QMessageBox::information(this,"成功","该医生已停诊");
}


void tiingzhen::on_pushButton_3_clicked()
{
    QSqlDatabase db5 = DatabaseManager::instance().getDatabase();
    QSqlQuery query5(db5);


    query5.prepare("UPDATE doctor SET tingzhen = 1, remain1 =5, remain2 =5, remain3 =5 ,remain4 =5 WHERE name = :Name");
    query5.bindValue(":Name", name1);
    query5.exec();
     QMessageBox::information(this,"成功","该医生已复诊");
}

