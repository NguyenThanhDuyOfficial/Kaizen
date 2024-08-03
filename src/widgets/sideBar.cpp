#include <QFile>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPainter>
#include <QPushButton>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVBoxLayout>
#include <QWidget>

#include <QDebug>
#include <qcontainerfwd.h>
#include <qcoreevent.h>
#include <qlogging.h>
#include <qpalette.h>
#include <qpushbutton.h>

#include "../utils/styleManager.hpp"
#include "sideBar.hpp"

SideBar::SideBar(QWidget *parent) : QWidget(parent) {

  QStringList *paletteList = StyleManager::getPalette();
  QWidget *header = new QWidget(this);
  QPushButton *sideButton = new QPushButton(
      StyleManager::changeIconColor(
          "../src/assets/icons/material-symbols--side-navigation.svg", 24, 24,
          paletteList->at(10)),
      "", header);
  sideButton->setIconSize(QSize(24, 24));
  QPushButton *folderButton =
      new QPushButton(StyleManager::changeIconColor(
                          "../src/assets/icons/"
                          "material-symbols--folder-open-outline-rounded.svg",
                          24, 24, paletteList->at(10)),
                      "", header);
  folderButton->setIconSize(QSize(24, 24));
  QPushButton *searchButton =
      new QPushButton(StyleManager::changeIconColor(
                          "../src/assets/icons/material-symbols--search.svg",
                          24, 24, QColor(paletteList->at(10))),
                      "", header);
  searchButton->setIconSize(QSize(24, 24));
  QHBoxLayout *headerLayout = new QHBoxLayout(header);
  headerLayout->setContentsMargins(20, 0, 20, 0);
  headerLayout->addStretch(1);
  headerLayout->addWidget(sideButton, 2);
  headerLayout->addWidget(folderButton, 2);
  headerLayout->addWidget(searchButton, 2);
  headerLayout->addStretch(1);
  header->setLayout(headerLayout);
  header->setObjectName("header");

  QWidget *content = new QWidget(this);
  QPushButton *addTaskButton = new QPushButton("Add Task", content);
  addTaskButton->setMinimumHeight(40);
  QPushButton *createProjectButton = new QPushButton("Create Project", content);
  createProjectButton->setMinimumHeight(40);
  QTreeWidget *listTree = new QTreeWidget(content);
  QPushButton *testButton = new QPushButton("Do Right Now", content);
  QTreeWidgetItem *item = new QTreeWidgetItem(listTree);
  listTree->setItemWidget(item, 1, testButton);
  QGridLayout *contentLayout = new QGridLayout(content);
  contentLayout->setContentsMargins(20, 20, 20, 0);
  contentLayout->setRowStretch(0, 1);
  contentLayout->setRowStretch(1, 18);
  contentLayout->setColumnStretch(0, 4);
  contentLayout->setColumnStretch(1, 4);
  contentLayout->setHorizontalSpacing(10);
  contentLayout->setVerticalSpacing(10);
  contentLayout->addWidget(addTaskButton, 0, 0);
  contentLayout->addWidget(createProjectButton, 0, 1);
  contentLayout->addWidget(listTree, 1, 0, 1, 2);
  content->setLayout(contentLayout);
  content->setObjectName("content");

  QWidget *footer = new QWidget(this);
  QString userName = "Nguyen Thanh Duy";
  QPushButton *userButton = new QPushButton(userName, footer);
  userButton->setMinimumHeight(20);
  QPushButton *helpButton = new QPushButton(
      StyleManager::changeIconColor(
          "../src/assets/icons/material-symbols--help-outline.svg", 24, 24,
          QColor(paletteList->at(10))),
      "", footer);
  helpButton->setIconSize(QSize(24, 24));
  QPushButton *settingButton = new QPushButton(
      StyleManager::changeIconColor("../src/assets/icons/uil--setting.svg", 24,
                                    24, QColor(paletteList->at(10))),
      "", footer);
  settingButton->setIconSize(QSize(24, 24));
  QHBoxLayout *footerLayout = new QHBoxLayout(footer);
  footerLayout->setContentsMargins(20, 0, 20, 0);
  footerLayout->addWidget(userButton, 7);
  footerLayout->addWidget(helpButton, 1);
  footerLayout->addWidget(settingButton, 1);
  footer->setLayout(footerLayout);
  footer->setObjectName("footer");

  QWidget *sideBar = new QWidget(this);
  QVBoxLayout *sideBarLayout = new QVBoxLayout(this);
  sideBarLayout->setContentsMargins(0, 0, 0, 0);
  sideBarLayout->setSpacing(0);
  sideBarLayout->addWidget(header, 1);
  sideBarLayout->addSpacing(1);
  sideBarLayout->addWidget(content, 16);
  sideBarLayout->addWidget(footer, 1);
  setLayout(sideBarLayout);
  setObjectName("sideBar");

  connect(sideButton, &QPushButton::clicked, this, [this]() {
    if (this->isVisible()) {
      this->hide();
    } else {
      this->show();
    }
  });

  delete paletteList;
}
void SideBar::paintEvent(QPaintEvent *pe) {
  QStyleOption o;
  o.initFrom(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
};
