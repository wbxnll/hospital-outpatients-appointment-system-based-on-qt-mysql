#include "loginadm.h"
#include "ui_loginadm.h"
#include<QMessageBox>
#include "administrator.h"
loginadm::loginadm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginadm)
{
    ui->setupUi(this);
}

loginadm::~loginadm()
{
    delete ui;
}

void loginadm::on_pushButton_2_clicked()
{
    if(ui->id->text()=="administrator"&& ui->password->text()=="123456")
    {
        administrator* a=new administrator;
        a->show();
    }
}

