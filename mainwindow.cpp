#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"login.h"
#include"databasemanager.h"
#include"QMessageBox"
#include"loginadm.h"
#include"logindoctor.h"
#include<zhuce.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = DatabaseManager::instance().getDatabase();
    QSqlQuery query(db);





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_patient_clicked()
{
    login*log=new login;
    log->show();
}


void MainWindow::on_patientenroll_clicked()
{
    zhuce*zhu=new zhuce;
    zhu->show();
}

void MainWindow::on_adminastrator_clicked()
{
    loginadm*adm=new loginadm(this);
    adm->show();

}


void MainWindow::on_doctor_clicked()
{
    logindoctor* c=new logindoctor;
    c->show();
}

