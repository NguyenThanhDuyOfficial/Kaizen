#include <QHBoxLayout>
#include <QWidget>
#include <qpainter.h>
#include <qpalette.h>

#include "mainWindow.hpp"
#include "widgets/centralWidget.hpp"
#include "widgets/sideBar.hpp"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
  SideBar *sideBar = new SideBar(this);
  CentralWidget *centralWidget = new CentralWidget(this);

  QHBoxLayout *mainWindowLayout = new QHBoxLayout(this);
  mainWindowLayout->setContentsMargins(0, 0, 0, 0);
  mainWindowLayout->setSpacing(1);
  mainWindowLayout->addWidget(sideBar, 1);
  mainWindowLayout->addWidget(centralWidget, 3);
  setLayout(mainWindowLayout);
  setObjectName("mainWindow");
}
