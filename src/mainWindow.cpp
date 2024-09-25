

#include "include/mainWindow.hpp"
#include "include/todoWidget.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  auto *mpTodoWidget = new TodoWidget(this);
  setCentralWidget(mpTodoWidget);
}
