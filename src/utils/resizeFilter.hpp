#ifndef RESIZEFILTER_HPP
#define RESIZEFILTER_HPP

#include <QEvent>
#include <QTabWidget>

class ResizeFilter : public QObject {
  QTabWidget *target;

public:
  ResizeFilter(QTabWidget *target = nullptr);
  bool eventFilter(QObject *object, QEvent *event);
};
#endif // !RESIZEFILTER_HPP
