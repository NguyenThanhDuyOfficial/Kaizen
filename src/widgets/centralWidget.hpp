#ifndef CENTRAL_HPP
#define CENTRAL_HPP

#include <QWidget>

class CentralWidget : public QWidget {
  Q_OBJECT
public:
  CentralWidget(QWidget *parent = nullptr, QStringList *palette = nullptr);

protected:
  void paintEvent(QPaintEvent *pe);
};

#endif // !CENTRAL_HPP
