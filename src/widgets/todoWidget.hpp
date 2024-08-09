#ifndef TODOTAB_HPP
#define TODOTAB_HPP

#include <QWidget>

class TodoWidget : public QWidget {
  Q_OBJECT
public:
  TodoWidget(QWidget *parent = nullptr);
};

class TaskWidget : public QWidget {
  Q_OBJECT
public:
  TaskWidget(const int id, QWidget *parent);

private:
  const int taskId;
};

#endif // TODOTAB_HPP
