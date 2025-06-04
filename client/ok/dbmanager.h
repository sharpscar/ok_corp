#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>

class DBManager {
public:
    static bool connect();
    static QSqlDatabase& getDatabase();

private:
    static QSqlDatabase db;
};

#endif // DBMANAGER_H