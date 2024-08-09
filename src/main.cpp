#include <QApplication>
#include <QFile>
#include <QMainWindow>
#include <QWidget>

#include "mainWindow.hpp"
#include "utils/dataManager.hpp"
#include "utils/styleManager.hpp"

int main(int argc, char *argv[]) {
  QApplication Kaizen(argc, argv);

  createDataBase();

  MainWindow *mainWindow = new MainWindow(nullptr);
  mainWindow->show();

  QString themeName = "Latte";
  StyleManager::createStyleSheet("../src/css/Kaizen.css",
                                 "../src/css/" + themeName + ".css");
  QFile file("../src/css/" + themeName + ".css");
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug() << "Failed to open stylesheet file";
    return 1;
  }
  QTextStream in(&file);
  QString styleSheet = in.readAll();

  Kaizen.setStyleSheet(styleSheet);

  return Kaizen.exec();
}
