#ifndef DATABASE_MANAGER_HPP
#define DATABASE_MANAGER_HPP

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class DatabaseManager {

  QSqlDatabase mDatabase;

public:
  DatabaseManager(const QString &path);

  // Create Task and Project Table;
  void createDefaultTable();
};

#endif // !DATABASE_MANAGER_HPP
