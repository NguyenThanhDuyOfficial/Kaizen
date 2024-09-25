#ifndef TODO_WIDGET_HPP
#define TODO_WIDGET_HPP

#include <QComboBox>
#include <QGridLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QWidget>

class TodoWidget : public QWidget {
  Q_OBJECT

  QComboBox *mpLocationComboBox;
  QLineEdit *mpTaskLineEdit;
  QPushButton *mpProcessPushButton;
  QListWidget *mpTasksListWidget;
  QGridLayout *mpTodoGridLayout;

public:
  TodoWidget(QWidget *parent);
};

#endif // !TODO_WIDGET_HPP
