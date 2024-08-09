#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include "dataManager.hpp"

int createDataBase() {
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("../src/data/Kaizen.db");
  if (!db.open()) {
    qDebug() << "Error: Database Error - " << db.lastError();
  }
  createTable();
  return 0;
}
int createTable() {
  QSqlQuery query("CREATE TABLE IF NOT EXISTS tasks ( "
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "title TEXT NOT NULL, "
                  "status TEXT NOT NULL DEFAULT 'in progress', "
                  "location TEXT NOT NULL DEFAULT 'Do Right Now', "
                  "description TEXT NULL,"
                  "date TEXT NULL,"
                  "projectId INTEGER NULL, "
                  "FOREIGN KEY (projectId) REFERENCES projects(id), "
                  "CHECK (status IN ('in progress', 'completed', 'cancelled', "
                  "'critical', 'scheduled'))"
                  "CHECK (location IN ('Do Right Now', 'Next Action', "
                  "'Calendar', 'Waiting'))"
                  ")");
  if (!query.exec()) {
    qDebug() << "Error: SQL Error - " << query.lastError();
    return -1;
  }

  query.prepare("CREATE TABLE IF NOT EXISTS projects ( "
                "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                "title TEXT NOT NULL, "
                "status TEXT NOT NULL DEFAULT 'in progress',"
                "parentId INTEGER NULL, "
                "FOREIGN KEY (parentId) REFERENCES projects(id), "
                "CHECK (status IN ('in progress', 'completed', 'cancelled', "
                "'critical', 'scheduled'))"
                ")");
  if (!query.exec()) {
    qDebug() << "Error: SQL Error - " << query.lastError();
    return -1;
  }

  qDebug() << "Create Table Successfully.";
  return 0;
}
