QT       += core gui
QT       +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    administrator.cpp \
    choosedepartment.cpp \
    choosetime.cpp \
    databasemanager.cpp \
    doctor.cpp \
    login.cpp \
    loginadm.cpp \
    logindoctor.cpp \
    main.cpp \
    mainwindow.cpp \
    patient.cpp \
    tiingzhen.cpp \
    zhuce.cpp

HEADERS += \
    administrator.h \
    choosedepartment.h \
    choosetime.h \
    databasemanager.h \
    doctor.h \
    login.h \
    loginadm.h \
    logindoctor.h \
    mainwindow.h \
    patient.h \
    tiingzhen.h \
    zhuce.h

FORMS += \
    administrator.ui \
    choosedepartment.ui \
    choosetime.ui \
    login.ui \
    loginadm.ui \
    logindoctor.ui \
    mainwindow.ui \
    tiingzhen.ui \
    zhuce.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
