spiel::spiel (QWidget * w):QDialog(w){
   s = new schiff(this);
   s->show();
}

void spiel::keyPressEvent(QKeyEvent *event){
 if ( event->text() =="a")
    richtung =4;
 if (event->text() == "d")
    richtung = 6;
}
 
void spiel::showEvent(QShowEvent *){
   myTimerId = startTimer(10);
}
 
void spiel::timerEvent(QTimerEvent * event){
   if (event->timerId() == myTimerId){
      s->bewege(richtung);
   }
   else{
      QWidget::timerEvent(event);
   }
}

void spiel::hideEvent(QHideEvent * ){
   killTimer(myTimerId);
   myTimerId = 0;
}

schiff::schiff(QWidget * w ): QLabel(w){
   QPixmap p;
   p.load(":images/schiff.gif");
   this->setPixmap(p);
   xpos = 300;
   ypos = 300;
   this->resize (40,40);
   this->move(xpos, ypos);
}

void schiff::bewege(int richtung){
   switch(richtung){
      case 4: xpos= xpos -1;
      break;
      case 6: xpos = xpos +1;
      break;
   }
   if (xpos <0 ) xpos = 0;
   if (xpos >560) xpos = 560;
   this->move (xpos, ypos);
}
void schiff::setx(int x) {
   xpos =x;
}
void schiff::sety(int y) {
   ypos =y;
}

