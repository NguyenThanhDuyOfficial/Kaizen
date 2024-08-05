

#include "tabWidget.hpp"

TabWidget::TabWidget(QWidget *parent) : QTabWidget(parent) {}
void TabWidget::setCustomTabBar(QTabBar *tabBar) { setTabBar(tabBar); }
