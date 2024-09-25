

#include "include/todoWidget.hpp"
#include "include/taskCard.hpp"
#include <qlistwidget.h>

TodoWidget::TodoWidget(QWidget *parent) : QWidget(parent) {
  // Intialize header
  mpLocationComboBox = new QComboBox(this);
  mpLocationComboBox->setMinimumHeight(48);
  mpLocationComboBox->setEditable(true);
  mpLocationComboBox->setCurrentText("In-Basket");
  mpLocationComboBox->setFixedHeight(48);

  mpTaskLineEdit = new QLineEdit(this);
  mpTaskLineEdit->setAlignment(Qt::AlignCenter);
  mpTaskLineEdit->setPlaceholderText("Type Task Here...");
  mpTaskLineEdit->setTextMargins(16, 0, 16, 0);
  mpTaskLineEdit->setMinimumHeight(48);

  mpProcessPushButton = new QPushButton(this);
  mpProcessPushButton->setText("Process");
  mpProcessPushButton->setMinimumHeight(48);

  // Intialize tasksListWidget;
  mpTasksListWidget = new QListWidget(this);
  mpTasksListWidget->setSpacing(4);
  for (int i = 0; i < 10; i++) {
    auto taskCard = new TaskCard(this);
    auto item = new QListWidgetItem(mpTasksListWidget);
    item->setSizeHint(taskCard->size());
    mpTasksListWidget->setItemWidget(item, taskCard);
  }

  // Intialize todoLayout;
  mpTodoGridLayout = new QGridLayout(this);
  mpTodoGridLayout->setColumnStretch(0, 1);
  mpTodoGridLayout->setColumnStretch(1, 2);
  mpTodoGridLayout->setColumnStretch(2, 7);
  mpTodoGridLayout->setColumnStretch(3, 1);
  mpTodoGridLayout->setColumnStretch(4, 1);
  mpTodoGridLayout->setRowMinimumHeight(0, 48);
  mpTodoGridLayout->addItem(
      new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum), 0, 0,
      2);
  mpTodoGridLayout->addWidget(mpLocationComboBox, 0, 1);
  mpTodoGridLayout->addWidget(mpTaskLineEdit, 0, 2);
  mpTodoGridLayout->addWidget(mpProcessPushButton, 0, 3);
  mpTodoGridLayout->addItem(
      new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum), 0, 4,
      2);
  mpTodoGridLayout->addWidget(mpTasksListWidget, 1, 1, 1, 3);
}
