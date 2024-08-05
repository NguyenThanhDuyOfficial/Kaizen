#include <QGridLayout>
#include <QLabel>
#include <QListWidget>
#include <QPainter>
#include <QPushButton>
#include <QTabWidget>
#include <QWidget>

#include <QLabel>
#include <qboxlayout.h>
#include <qgridlayout.h>
#include <qpushbutton.h>

#include "../utils/resizeFilter.hpp"
#include "../utils/styleManager.hpp"
#include "centralWidget.hpp"

CentralWidget::CentralWidget(QWidget *parent, QStringList *palette)
    : QWidget(parent) {

  QTabWidget *tabWidget = new QTabWidget(this);
  QWidget *test = new QWidget(tabWidget);
  QLabel *testlabel = new QLabel("Hello", test);
  QHBoxLayout *testLayout = new QHBoxLayout(test);
  testLayout->addWidget(testlabel);
  test->setLayout(testLayout);
  test->setObjectName("test");
  QWidget *test2 = new QWidget(tabWidget);
  QLabel *test2label = new QLabel("Hello", test2);
  QHBoxLayout *test2Layout = new QHBoxLayout(test2);
  test2Layout->addWidget(test2label);
  test2->setLayout(test2Layout);
  test->setObjectName("test");
  tabWidget->installEventFilter(new ResizeFilter(tabWidget));
  tabWidget->setContentsMargins(0, 0, 0, 0);
  tabWidget->setTabsClosable(true);
  tabWidget->addTab(test, "test");
  tabWidget->addTab(test2, "2");

  QGridLayout *centralLayout = new QGridLayout(this);
  centralLayout->setContentsMargins(0, 0, 0, 0);
  /*centralLayout->setRowStretch(0, 1);*/
  /*centralLayout->setRowStretch(1, 15);*/
  centralLayout->setSpacing(0);
  centralLayout->addWidget(tabWidget, 1, 0);
  setLayout(centralLayout);
  setObjectName("centralWidget");
}
void CentralWidget::paintEvent(QPaintEvent *pe) {
  QStyleOption o;
  o.initFrom(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
};
