#include <QEvent>
#include <QTabWidget>

#include "resizeFilter.hpp"
ResizeFilter::ResizeFilter(QTabWidget *target)
    : QObject(target), target(target) {}

bool ResizeFilter::eventFilter(QObject *object, QEvent *event) {
  if (event->type() == QEvent::Resize) {
    target->setStyleSheet(QString("QTabBar::tab { height: %1px; } ")
                              .arg((target->size().height() / 16) - 16));
  }
  return false;
}
