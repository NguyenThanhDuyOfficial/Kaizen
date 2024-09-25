#include <QApplication>
#include <QFile>

#include "include/databaseManager.hpp"
#include "include/mainWindow.hpp"

int main(int argc, char *argv[]) {
  QApplication kaizen(argc, argv);

  DatabaseManager db("../src/database/kaizen.db");

  auto *mainWindow = new MainWindow(nullptr);
  mainWindow->show();
  QFile file("../src/style.css");
  file.open(QFile::ReadOnly);

  QString styleSheet = QLatin1String(file.readAll());

  qApp->setStyleSheet(styleSheet);

  return kaizen.exec();
}
