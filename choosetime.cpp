
#include "choosetime.h"
#include "ui_choosetime.h"
#include "databasemanager.h"
#include <QMessageBox>
#include <QTime>
#include <QSqlError>

choosetime::choosetime(QString a, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::choosetime)
{
    ui->setupUi(this);
    ui->name->setText(a);
    QSqlDatabase db4 = DatabaseManager::instance().getDatabase();
    QSqlQuery query4(db4);

    query4.exec("SELECT * FROM doctor ");
    while (query4.next())
    {
        if (query4.value(0) == a)
        {
            ui->age->setText(query4.value(3).toString());
            ui->title->setText(query4.value(4).toString());
            ui->department->setText(query4.value(5).toString());
            ui->phonenumber->setText(query4.value(8).toString());
            ui->gender->setText(query4.value(2).toString());

            int remain1 = query4.value(9).toInt();
            int remain2 = query4.value(10).toInt();
            int remain3 = query4.value(11).toInt();
            int remain4 = query4.value(12).toInt();

            ui->remain1->setText(QString::number(remain1));
            ui->remain2->setText(QString::number(remain2));
            ui->remain3->setText(QString::number(remain3));
            ui->remain4->setText(QString::number(remain4));

            int tingzhen = query4.value(13).toInt();
            if (tingzhen == 1) {
                ui->tingzhen->setText("该医生正常出诊");
            } else {
                ui->tingzhen->setText("该医生已停诊");
                ui->remain1->setText("0");
                ui->remain2->setText("0");
                ui->remain3->setText("0");
                ui->remain4->setText("0");
            }

                QTime startTime = query4.value(6).toTime();
            QTime endTime = query4.value(7).toTime();
            int totalMinutes = startTime.secsTo(endTime) / 60;
            int segmentMinutes = totalMinutes / 4;

            QTime segment1End = startTime.addSecs(segmentMinutes * 60);
            QTime segment2End = segment1End.addSecs(segmentMinutes * 60);
            QTime segment3End = segment2End.addSecs(segmentMinutes * 60);
            QTime segment4End = endTime;

            ui->time1->setText(startTime.toString("HH:mm") + " - " + segment1End.toString("HH:mm"));
            ui->time2->setText(segment1End.toString("HH:mm") + " - " + segment2End.toString("HH:mm"));
            ui->time3->setText(segment2End.toString("HH:mm") + " - " + segment3End.toString("HH:mm"));
            ui->time4->setText(segment3End.toString("HH:mm") + " - " + segment4End.toString("HH:mm"));


            checkAndDisableAppointmentButtons();
        }
    }
}

choosetime::~choosetime()
{
    delete ui;
}

void choosetime::checkAndDisableAppointmentButtons()
{

    if (ui->remain1->text().toInt() <= 0) {
        ui->appoint1->setEnabled(false);
    }
    if (ui->remain2->text().toInt() <= 0) {
        ui->appoint2->setEnabled(false);
    }
    if (ui->remain3->text().toInt() <= 0) {
        ui->appoint3->setEnabled(false);
    }
    if (ui->remain4->text().toInt() <= 0) {
        ui->apppoint4->setEnabled(false);
    }
}

void choosetime::on_appoint1_clicked()
{
    QString name = ui->name->text();
    QSqlDatabase db5 = DatabaseManager::instance().getDatabase();
    QSqlQuery query5(db5);

    int remain1 = ui->remain1->text().toInt();
    if (remain1 <= 0) {
        QMessageBox::warning(this, "预约失败", "预约名额已满，无法继续预约。");
        ui->appoint1->setEnabled(false);
        return;
    }

    query5.prepare("UPDATE doctor SET remain1 = remain1 - 1 WHERE name = :Name");
    query5.bindValue(":Name", name);

    if (query5.exec()) {
        QMessageBox::information(this, "预约成功", "预约成功，请在时间段内前来就诊");

        query5.prepare("SELECT remain1 FROM doctor WHERE name = :Name");
        query5.bindValue(":Name", name);
        if (query5.exec() && query5.next()) {
            QString remain = query5.value(0).toString();
            ui->remain1->setText(remain);
            if (remain.toInt() <= 0) {
                ui->appoint1->setEnabled(false);
            }
        } else {
            qDebug() << "Error fetching updated remain1 value:" << query5.lastError().text();
        }
    } else {
        qDebug() << "Update error:" << query5.lastError().text();
        QMessageBox::critical(this, "预约失败", "更新数据库失败，请稍后再试。");
    }
}

void choosetime::on_appoint2_clicked()
{
    QString name = ui->name->text();
    QSqlDatabase db5 = DatabaseManager::instance().getDatabase();
    QSqlQuery query5(db5);

    int remain2 = ui->remain2->text().toInt();
    if (remain2 <= 0) {
        QMessageBox::warning(this, "预约失败", "预约名额已满，无法继续预约。");
        ui->appoint2->setEnabled(false);
        return;
    }

    query5.prepare("UPDATE doctor SET remain2 = remain2 - 1 WHERE name = :Name");
    query5.bindValue(":Name", name);

    if (query5.exec()) {
        QMessageBox::information(this, "预约成功", "预约成功，请在时间段内前来就诊");

        query5.prepare("SELECT remain2 FROM doctor WHERE name = :Name");
        query5.bindValue(":Name", name);
        if (query5.exec() && query5.next()) {
            QString remain = query5.value(0).toString();
            ui->remain2->setText(remain);
            if (remain.toInt() <= 0) {
                ui->appoint2->setEnabled(false);
            }
        } else {
            qDebug() << "Error fetching updated remain2 value:" << query5.lastError().text();
        }
    } else {
        qDebug() << "Update error:" << query5.lastError().text();
        QMessageBox::critical(this, "预约失败", "更新数据库失败，请稍后再试。");
    }
}

void choosetime::on_appoint3_clicked()
{
    QString name = ui->name->text();
    QSqlDatabase db5 = DatabaseManager::instance().getDatabase();
    QSqlQuery query5(db5);

    int remain3 = ui->remain3->text().toInt();
    if (remain3 <= 0) {
        QMessageBox::warning(this, "预约失败", "预约名额已满，无法继续预约。");
        ui->appoint3->setEnabled(false);
        return;
    }

    query5.prepare("UPDATE doctor SET remain3 = remain3 - 1 WHERE name = :Name");
    query5.bindValue(":Name", name);

    if (query5.exec()) {
        QMessageBox::information(this, "预约成功", "预约成功，请在时间段内前来就诊");

        query5.prepare("SELECT remain3 FROM doctor WHERE name = :Name");
        query5.bindValue(":Name", name);
        if (query5.exec() && query5.next()) {
            QString remain = query5.value(0).toString();
            ui->remain3->setText(remain);
            if (remain.toInt() <= 0) {
                ui->appoint3->setEnabled(false);
            }
        } else {
            qDebug() << "Error fetching updated remain3 value:" << query5.lastError().text();
        }
    } else {
        qDebug() << "Update error:" << query5.lastError().text();
        QMessageBox::critical(this, "预约失败", "更新数据库失败，请稍后再试。");
    }
}

void choosetime::on_apppoint4_clicked()
{
    QString name = ui->name->text();
    QSqlDatabase db5 = DatabaseManager::instance().getDatabase();
    QSqlQuery query5(db5);

    int remain4 = ui->remain4->text().toInt();
    if (remain4 <= 0) {
        QMessageBox::warning(this, "预约失败", "预约名额已满，无法继续预约。");
        ui->apppoint4->setEnabled(false);
        return;
    }

    query5.prepare("UPDATE doctor SET remain4 = remain4 - 1 WHERE name = :Name");
    query5.bindValue(":Name", name);

    if (query5.exec()) {
        QMessageBox::information(this, "预约成功", "预约成功，请在时间段内前来就诊");

        query5.prepare("SELECT remain4 FROM doctor WHERE name = :Name");
        query5.bindValue(":Name", name);
        if (query5.exec() && query5.next()) {
            QString remain = query5.value(0).toString();
            ui->remain4->setText(remain);
            if (remain.toInt() <= 0) {
                ui->apppoint4->setEnabled(false);
            }
        } else {
            qDebug() << "Error fetching updated remain4 value:" << query5.lastError().text();
        }
    } else {
        qDebug() << "Update error:" << query5.lastError().text();
        QMessageBox::critical(this, "预约失败", "更新数据库失败，请稍后再试。");
    }
}

