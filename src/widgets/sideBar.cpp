#include <QFile>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QPainter>
#include <QPushButton>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVBoxLayout>
#include <QWidget>

#include <QDebug>
#include <qcontainerfwd.h>
#include <qpushbutton.h>
#include <qtreewidget.h>

#include "../utils/styleManager.hpp"
#include "sideBar.hpp"

SideBar::SideBar(QWidget *parent) : QWidget(parent) {
  QStringList *paletteList = StyleManager::getPalette();

  QWidget *fixedSideBar = new QWidget(this);
  QPushButton *sideButton = new QPushButton(
      StyleManager::changeIconColor(
          "../src/assets/icons/material-symbols--side-navigation.svg", 24, 24,
          paletteList->at(10)),
      "", fixedSideBar);
  sideButton->setIconSize(QSize(24, 24));
  QVBoxLayout *fixedLayout = new QVBoxLayout(fixedSideBar);
  fixedLayout->setContentsMargins(0, 0, 0, 0);
  fixedLayout->setSpacing(0);
  fixedLayout->addWidget(sideButton, 1, Qt::AlignCenter);
  fixedLayout->addStretch(15);
  fixedSideBar->setLayout(fixedLayout);
  fixedSideBar->setObjectName("fixedSideBar");

  QWidget *flexibleSideBar = new QWidget(this);
  QWidget *header = new QWidget(flexibleSideBar);
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
  headerLayout->setSpacing(16);
  headerLayout->addWidget(folderButton);
  headerLayout->addWidget(searchButton);
  headerLayout->addStretch();
  header->setLayout(headerLayout);
  header->setObjectName("header");

  QWidget *content = new QWidget(flexibleSideBar);
  QPushButton *addTaskButton = new QPushButton("Add Task", content);
  QPushButton *createProjectButton = new QPushButton("Create Project", content);
  QListWidget *listWidget = new QListWidget(content);
  listWidget->setSpacing(8);
  QStringList locationList = QStringList(
      QStringList() << "Todo" << "Do Right Now" << "Next Action" << "Calendar"
                    << "Project" << "Ticker" << "Reference" << "Wainting For"
                    << "Someday/Maybe");
  qDebug() << locationList.count();
  for (int i = 0; i < locationList.count(); i++) {
    QPushButton *button =
        new QPushButton(locationList.at(i) + " List", listWidget);
    QListWidgetItem *item = new QListWidgetItem(listWidget);
    connect(button, &QPushButton::clicked, this, [button]() {
      QString remove = " List";
      qDebug() << button->text().remove(remove);
    });
    item->setSizeHint(QSize(button->width(), button->height() + 8));

    listWidget->setItemWidget(item, button);
  }

  QGridLayout *contentLayout = new QGridLayout(content);
  contentLayout->setContentsMargins(20, 20, 20, 0);
  contentLayout->setRowStretch(0, 2);
  contentLayout->setRowStretch(1, 14);
  contentLayout->setColumnStretch(0, 4);
  contentLayout->setColumnStretch(1, 4);
  contentLayout->setHorizontalSpacing(10);
  contentLayout->setVerticalSpacing(10);
  contentLayout->addWidget(addTaskButton, 0, 0);
  contentLayout->addWidget(createProjectButton, 0, 1);
  contentLayout->addWidget(listWidget, 1, 0, 1, 2);
  content->setLayout(contentLayout);
  content->setObjectName("content");

  QWidget *footer = new QWidget(flexibleSideBar);
  QString userName = "Nguyen Thanh Duy";
  QPushButton *userButton = new QPushButton(userName, footer);
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
  footerLayout->addWidget(userButton, 6);
  footerLayout->addWidget(helpButton, 1);
  footerLayout->addWidget(settingButton, 1);
  footer->setLayout(footerLayout);
  footer->setObjectName("footer");

  QVBoxLayout *flexibleLayout = new QVBoxLayout(flexibleSideBar);
  flexibleLayout->setContentsMargins(0, 0, 0, 0);
  flexibleLayout->setSpacing(0);
  flexibleLayout->addWidget(header, 1);
  flexibleLayout->addSpacing(2);
  flexibleLayout->addWidget(content, 14);
  flexibleLayout->addWidget(footer, 1);
  flexibleSideBar->setLayout(flexibleLayout);
  flexibleSideBar->setObjectName("flexibleWidget");

  QHBoxLayout *sideBarLayout = new QHBoxLayout(this);
  sideBarLayout->setContentsMargins(0, 0, 0, 0);
  sideBarLayout->setSpacing(0);
  sideBarLayout->addWidget(fixedSideBar, 1);
  sideBarLayout->addSpacing(2);
  sideBarLayout->addWidget(flexibleSideBar, 7);
  setLayout(sideBarLayout);
  setObjectName("sideBar");

  connect(sideButton, &QPushButton::clicked, this,
          [this, sideBarLayout, flexibleSideBar]() {
            QHBoxLayout *parentLayout =
                qobject_cast<QHBoxLayout *>(parentWidget()->layout());
            if (parentLayout->stretch(1) == 3) {
              sideBarLayout->removeWidget(flexibleSideBar);
              parentLayout->setStretch(1, 31);
            } else {
              sideBarLayout->addWidget(flexibleSideBar);
              parentLayout->setStretch(1, 3);
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
