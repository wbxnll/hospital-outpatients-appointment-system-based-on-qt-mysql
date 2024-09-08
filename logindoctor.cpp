#include "logindoctor.h"
#include "ui_logindoctor.h"
#include"databasemanager.h"
#include<QMessageBox>
logindoctor::logindoctor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::logindoctor)
{
    ui->setupUi(this);
}

logindoctor::~logindoctor()
{
    delete ui;
}

void logindoctor::on_pushButton_2_clicked()
{  QSqlDatabase db1 = DatabaseManager::instance().getDatabase();
    QSqlQuery query1(db1);
    QTime timeBegin = QTime::fromString(ui->timebegin->text(), "h:mm AP");
    QTime timeOver = QTime::fromString(ui->timeEdit_2->text(), "h:mm AP");

    QString timeBeginStr = timeBegin.toString("HH:mm:ss");
    QString timeOverStr = timeOver.toString("HH:mm:ss");
    query1.prepare("INSERT INTO doctor(name,  gender,age,title,department,timebegin,timeover,phonenumber,remain1,remain2,remain3,remain4,tingzhen,gongzuori)"
                   " VALUES(:name,  :gender,:age,:title,:department,:timebegin,:timeover,:phonenumber,:remain1,:remain2,:remain3,:remain4,:tingzhen,:gongzuori)");
    query1.bindValue(":name", ui->nameedit->text());
    query1.bindValue(":age", ui->ageedit->text());
    query1.bindValue(":phonenumber", ui->numberedit->text());
    query1.bindValue(":title",ui->titledit->text() );
    query1.bindValue(":gender", ui->gender->currentText());
    query1.bindValue(":department",ui->departmentedit->text() );
  query1.bindValue(":timebegin",timeBeginStr );
  query1.bindValue(":timeover", timeOverStr);
  query1.bindValue(":remain1",5 );
  query1.bindValue(":remain2",5 );
  query1.bindValue(":remain3",5 );
  query1.bindValue(":remain4",5 );
  query1.bindValue(":tingzhen",1 );
  query1.bindValue(":gongzuori",ui->comboBox->currentText().toInt());

    if (!query1.exec()) {
        qDebug() << "插入数据失败：" << query1.lastError().text();
        QMessageBox::warning(this, "注册失败", "注册失败，请稍后再试。");
    } else {
        qDebug() << "注册完成，请关闭注册页面";
        QMessageBox::information(this, "注册成功", "注册成功，请关闭注册页面。");
    }
}

