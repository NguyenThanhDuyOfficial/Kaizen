#ifndef SIDEBAR_HPP
#define SIDEBAR_HPP

#include <QDockWidget>
#include <QWidget>
#include <qdockwidget.h>

class SideBar : public QWidget {
  Q_OBJECT
public:
  SideBar(QWidget *parent = nullptr);

private:
  void paintEvent(QPaintEvent *pe);
};

#endif // !SIDEBAR_HPP
