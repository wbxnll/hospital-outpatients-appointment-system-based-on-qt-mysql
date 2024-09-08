#ifndef DOCTOR_H
#define DOCTOR_H
#include"QString"
#include"QDateTime"
#include"array"
class doctor
{
public:
    doctor(QString name, QString id1, QString gender1, int age1, QString title1, QString department1, QString workday1, QDateTime datetime1[2], QString phonenumber1);
    QString name;
    QString id;
    QString gender;
    int age;
    QString title;
    QString department;
    QString workday;
    QDateTime datetime[2];
    QString phonenumber;
};

#endif // DOCTOR_H
