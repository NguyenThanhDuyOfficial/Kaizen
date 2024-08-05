#ifndef TABWIDGET_HPP
#define TABWIDGET_HPP

#include <QTabWidget>

class TabWidget : public QTabWidget {
  Q_OBJECT
public:
  TabWidget(QWidget *parent = nullptr);
  void setCustomTabBar(QTabBar *tabBar);
};

#endif // !TABWIDGET_HPP
