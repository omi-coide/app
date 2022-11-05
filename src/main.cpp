#include "log.hpp"
#include <QtCore/QtCore>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <iostream>
using project_global::logger;
class Cursors : public QWidget {

public:
  Cursors(QWidget *parent = nullptr);
};

Cursors::Cursors(QWidget *parent) : QWidget(parent) {

  auto *frame1 = new QFrame(this);
  frame1->setFrameStyle(QFrame::Box);
  frame1->setCursor(Qt::SizeAllCursor);

  auto *frame2 = new QFrame(this);
  frame2->setFrameStyle(QFrame::Box);
  frame2->setCursor(Qt::WaitCursor);

  auto *frame3 = new QFrame(this);
  frame3->setFrameStyle(QFrame::Box);
  frame3->setCursor(Qt::PointingHandCursor);

  auto *grid = new QGridLayout(this);
  grid->addWidget(frame1, 0, 0);
  grid->addWidget(frame2, 0, 1);
  grid->addWidget(frame3, 0, 2);

  setLayout(grid);
}
int main(int argc, char **argv) {
  project_global::init_log();
  QApplication app(argc, argv);
  Cursors window;
  window.resize(250, 150);
  window.setWindowTitle("YLYDEBUG: Qt5");
  window.setToolTip("A QWidget");
  window.show();
  logger->info("Added a window");
  return app.exec();
}
