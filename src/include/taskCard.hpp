#ifndef TASK_CARD_HPP
#define TASK_CARD_HPP

#include <QComboBox>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
#include <QWidget>

class TaskCard : public QWidget {
  Q_OBJECT

  QPushButton *mpStatusPushButton;
  QComboBox *mpLocationComboBox;
  QLineEdit *mpTitleLineEdit;
  QPushButton *mpProjectPushButton;
  QLineEdit *mpCalendarLineEdit;
  QHBoxLayout *mpTaskHBoxLayout;

public:
  TaskCard(QWidget *parent = nullptr);

private:
  void paintEvent(QPaintEvent *event);
};

#endif // !TASK_CARD_HPP
