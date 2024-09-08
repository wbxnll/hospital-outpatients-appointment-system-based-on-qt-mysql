#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
class DatabaseManager
{public:

    static DatabaseManager& instance() {
        static DatabaseManager instance;
        return instance;
    }

    QSqlDatabase& getDatabase();


    DatabaseManager();



    ~DatabaseManager();



    QSqlDatabase db;


};

#endif // DATABASEMANAGER_H
