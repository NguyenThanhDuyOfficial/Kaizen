#include "include/taskCard.hpp"

TaskCard::TaskCard(QWidget *parent)
    : QWidget(parent), mpProjectPushButton(nullptr),
      mpLocationComboBox(nullptr) {
  // Intialize StatusPushButton
  QIcon inprogessIcon("../src/assets/icons/tabler--progress.svg");
  mpStatusPushButton = new QPushButton(inprogessIcon, "", this);

  // Intialize LocationComboBox
  mpLocationComboBox = new QComboBox(this);
  mpLocationComboBox->setCurrentText("In-Basket");

  // Intialize TitleLineEdit
  mpTitleLineEdit = new QLineEdit(this);

  // Intialize TaskCardHBoxLayout
  mpTaskHBoxLayout = new QHBoxLayout(this);
  mpTaskHBoxLayout->addWidget(mpStatusPushButton);
  mpTaskHBoxLayout->addWidget(mpLocationComboBox);
  mpTaskHBoxLayout->addWidget(mpTitleLineEdit);

  setFixedHeight(40);
  setObjectName("taskCard");
}
void TaskCard::paintEvent(QPaintEvent *event) {
  QStyleOption opt;
  opt.initFrom(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

  QWidget::paintEvent(event);
}
