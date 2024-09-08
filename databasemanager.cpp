#include "databasemanager.h"

DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("mysql");
    db.setUserName("root");
    db.setPassword("Lk619241");

    if (!db.open()) {
        qDebug() << "无法连接到数据库：" << db.lastError().text();
    } else {
        qDebug() << "成功连接到数据库！";
    }}
DatabaseManager::~DatabaseManager() {
    if (db.isOpen())
    {
        db.close();
    }
}
    QSqlDatabase& DatabaseManager::getDatabase()
    {
        return db;
    }

