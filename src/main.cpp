#include "log.hpp"
#include <QtCore>
#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <iostream>
#include "minusplus.hpp"
using project_global::logger;
int main(int argc, char **argv) {
  project_global::init_log();
  QApplication app(argc, argv);
  MinusPlus window;
  window.resize(250, 150);
  window.setWindowTitle("YLYDEBUG: Qt5");
  window.setToolTip("A QWidget");
  window.show();
  logger->info("Added a window");
  return app.exec();
}
