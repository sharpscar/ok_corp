#include "dbmanager.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

QSqlDatabase DBManager::db = QSqlDatabase();

bool DBManager::connect() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("10.10.20.101");
    db.setDatabaseName("db2");
    db.setUserName("db2");
    db.setPassword("1234");

    if (!db.open()) {
        qDebug() << "Database error: " << db.lastError().text();
        return false;
    }
    return true;
}

QSqlDatabase& DBManager::getDatabase() {
    return db;
}
