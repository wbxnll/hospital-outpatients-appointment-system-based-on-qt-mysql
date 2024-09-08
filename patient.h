#ifndef PATIENT_H
#define PATIENT_H
#include"QString"
#include"QDateTime"
class patient
{
public:
    patient(QString name1,QString idcard1,QString gender1,int age1,QDateTime datetime1,QString phonenumber1,QString symptom1);
    QString name;
    QString idcard;
    QString gender;
    int age;
    QDateTime datetime;
    QString phonenumber;
    QString symptom;

};

#endif // PATIENT_H
