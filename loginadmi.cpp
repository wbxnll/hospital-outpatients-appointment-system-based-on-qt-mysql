#include "loginadmi.h"
#include "ui_loginadmi.h"

loginadmi::loginadmi(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::administrator)
{
    ui->setupUi(this);
}

loginadmi::~loginadmi() {
    delete ui;
}
