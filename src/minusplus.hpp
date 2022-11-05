#ifndef _MINUSPLUSH
#define _MINUSPLUSH
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

class MinusPlus : public QWidget {
  Q_OBJECT
public:
  MinusPlus(QWidget *parent=nullptr);
private slots:
  void OnPlus(void);
  void OnMinus(void);
private:
  QLabel *label;
  int counter;
};

#endif
