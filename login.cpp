#include "login.h"
#include "ui_login.h"
#include"choosedepartment.h"
#include"QMessageBox"
#include"databasemanager.h"
login::login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);

}

login::~login()
{
    delete ui;
}






void login::on_loginbtn_clicked()
{      QSqlDatabase db2 = DatabaseManager::instance().getDatabase();
    QSqlQuery query2(db2);
    QString s="SELECT idcard,password FROM patient";
    int i=0;
    query2.exec(s);
    while(query2.next()){
        if(ui->idcard->text() == query2.value(0) && ui->password->text() == query2.value(1))
        {
            i++;
        choosedepartment *h=new choosedepartment;
        h->show();
        return;
    }
        qDebug()<<query2.value(0);
     qDebug()<<query2.value(1);
    }
    if(i==0)
    {
        ui->idcard->clear();
        ui->password->clear();
        ui->idcard->setFocus();
        QMessageBox::warning(this,"警告","密码错误");
    }
}

