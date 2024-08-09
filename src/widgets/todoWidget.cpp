#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>

#include "todoWidget.hpp"

TodoWidget::TodoWidget(QWidget *parent) : QWidget(parent) {
  QListWidget *tasksList = new QListWidget(this);
}

TaskWidget::TaskWidget(const int id, QWidget *parent)
    : QWidget(parent), taskId(id) {

  QIcon alertIcon("../src/assets/icons/mdi--progress-alert.svg");
  QIcon inProgessIcon("../src/assets/icons/mdi--progress-helper.svg");
  QIcon checkIcon("../src/assets/icons/mdi--progress-check.svg");
  QIcon clockIcon("../src/assets/icons/mdi--progress-alert.svg");
  QIcon closeIcon("../src/assets/icons/mdi--progress-close.svg");

  QPushButton *statusButton = new QPushButton(inProgessIcon, "", this);
  QLabel *titleLabel = new QLabel("", this);

  QHBoxLayout *taskLayout = new QHBoxLayout(this);
}
