#include <QLabel>
#include <QDialog>
#include <QKeyEvent>
#include <QApplication>
//#include <QtGui>

#include "spiel.h"
#include "spiel.cpp"

int main(int argc, char * argv[]){
  QApplication app (argc, argv);
  spiel *QwidgetSpiel = new spiel(0);
  QwidgetSpiel->resize(600,400);
  QwidgetSpiel->setStyleSheet("QDialog {background-image: url(:images/space.jpg) }");
  QwidgetSpiel->show();
  return app.exec();
}
