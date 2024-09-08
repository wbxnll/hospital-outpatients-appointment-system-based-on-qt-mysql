#include "doctor.h"

doctor::doctor(QString name1,QString id1, QString gender1,int age1,QString title1,QString department1,QString workday1,QDateTime datetime1[2],QString phonenumber1)
    :name(name1),id(id1),gender(gender1),age(age1),title(title1),department(department1),workday(workday1),datetime{datetime1[0],datetime1[1]},phonenumber(phonenumber1)
{}
