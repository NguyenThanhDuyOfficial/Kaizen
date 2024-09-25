#include "include/databaseManager.hpp"

DatabaseManager::DatabaseManager(const QString &path) {
  mDatabase = QSqlDatabase::addDatabase("SQLITE");
  mDatabase.setDatabaseName(path);
  if (!mDatabase.open()) {
    qDebug() << "Error: Connect with database failed.";
  } else {
    qDebug() << "Database: connected.";
  }

  createDefaultTable();
}

void DatabaseManager::createDefaultTable() {
  QSqlQuery query("CREATE TABLE IF NOT EXISTS projects ("
                  "projectId INTEGER PRIMARY KEY AUTOINCREMENT,"
                  "title TEXT NOT NULL,"
                  "status TEXT NOT NULL,"
                  "parentProjectId INTEGER,"
                  "FOREIGN KEY (parentProjectId) REFERENCES projects(projectId)"
                  ")");
  if (!query.exec()) {
    qDebug() << "Error:  SQL create default table failed.\n"
             << query.lastError();
  }

  query.prepare("CREATE TABLE IF NOT EXISTS tasks ("
                "taskId INTEGER PRIMARY KEY AUTOINCREMENT,"
                "title TEXT NOT NULL,"
                "status TEXT NOT NULL,"
                "location TEXT NOT NULL,"
                "calendar TEXT,"
                "projectId INTEGER,"
                "FOREIGN KEY(projectId) REFERENCES projects(projectId)"
                ")");
  if (!query.exec()) {
    qDebug() << "Error:  SQL create default table failed.\n"
             << query.lastError();
  }
}
