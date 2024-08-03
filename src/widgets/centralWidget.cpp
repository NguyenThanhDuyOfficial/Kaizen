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

#include "../utils/styleManager.hpp"
#include "centralWidget.hpp"

CentralWidget::CentralWidget(QWidget *parent, QStringList *palette)
    : QWidget(parent) {

  QWidget *test = new QWidget(this);
  QLabel *testlabel = new QLabel("Hello", test);
  QHBoxLayout *testLayout = new QHBoxLayout(test);
  testLayout->addWidget(testlabel);
  test->setLayout(testLayout);
  test->setObjectName("test");

  QTabWidget *tab = new QTabWidget(this);
  tab->setContentsMargins(0, 0, 0, 0);
  tab->addTab(test, "test");

  QGridLayout *centralLayout = new QGridLayout(this);
  centralLayout->setContentsMargins(0, 0, 0, 0);
  centralLayout->addWidget(tab);
  setLayout(centralLayout);
  setObjectName("centralWidget");
}
void CentralWidget::paintEvent(QPaintEvent *pe) {
  QStyleOption o;
  o.initFrom(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
};
