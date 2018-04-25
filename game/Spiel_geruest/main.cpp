#include <QLabel>
#include <QDialog>
#include <QKeyEvent>
#include <QApplication>
//#include <QtGui>

#include "spiel.h"
#include "spiel.cpp"

int main(int argc, char * argv[]){
QApplication app (argc, argv);
spiel *s = new spiel(0);
s->resize(600,400);
s->show();
return app.exec();
}

  

