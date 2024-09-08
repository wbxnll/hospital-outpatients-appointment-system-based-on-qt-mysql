#include "zhuce.h"
#include "ui_zhuce.h"
#include"databasemanager.h"
#include<QMessageBox>
zhuce::zhuce(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::zhuce)
{
    ui->setupUi(this);

}

zhuce::~zhuce()
{
    delete ui;
}

void zhuce::on_btnok_clicked()
{  QSqlDatabase db1 = DatabaseManager::instance().getDatabase();
QSqlQuery query1(db1);


QString idcard = ui->idcardedit->text();
query1.prepare("SELECT COUNT(*) FROM patient WHERE idcard = :idcard");
query1.bindValue(":idcard", idcard);

if (!query1.exec()) {
    qDebug() << "查询ID卡失败：" << query1.lastError().text();
    QMessageBox::warning(this, "错误", "无法验证身份证号，请稍后再试。");
    return;
}

query1.next();
int count = query1.value(0).toInt();

if (count > 0) {

    QMessageBox::warning(this, "注册失败", "该身份证号已被注册。");
    return;
}


query1.prepare("INSERT INTO patient(name, idcard, age, phonenumber, symptom, gender, password)"
               " VALUES(:name, :idcard, :age, :phonenumber, :symptom, :gender, :password)");
query1.bindValue(":name", ui->nameedit->text());
query1.bindValue(":idcard", idcard);
query1.bindValue(":age", ui->ageedit->text());
query1.bindValue(":phonenumber", ui->phonenumberedit->text());
query1.bindValue(":symptom", ui->symptomedit->text());
query1.bindValue(":gender", ui->genderbox->currentText());
query1.bindValue(":password", ui->passwordedit->text());

if (!query1.exec()) {
    qDebug() << "插入数据失败：" << query1.lastError().text();
    QMessageBox::warning(this, "注册失败", "注册失败，请稍后再试。");
} else {
    qDebug() << "注册完成，请关闭注册页面";
    QMessageBox::information(this, "注册成功", "注册成功，请关闭注册页面。");
}
}
