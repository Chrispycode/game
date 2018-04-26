spiel::spiel (QWidget * w):QDialog(w){
   s = new schiff(this, 300, 300);
   schuss = new geschoss(this, 300, 300);
   s->show();
   schuss->show();
}

void spiel::keyPressEvent(QKeyEvent *event){
    if (event->text() == "a")
        richtung = 4;
    if (event->text() == "d")
    richtung = 6;
    if (event->text() == "w")
     richtung = 8;
    if (event->text() == "s")
        richtung = 2;
}
 
void spiel::showEvent(QShowEvent *){
   myTimerId = startTimer(10);
}
 
void spiel::timerEvent(QTimerEvent * event){
   if (event->timerId() == myTimerId){
      s->bewege(richtung);
      schuss->bewege();
   }
   else{
      QWidget::timerEvent(event);
   }
}

void spiel::hideEvent(QHideEvent * ){
   killTimer(myTimerId);
   myTimerId = 0;
}

schiff::schiff(QWidget * w ,int x , int y): QLabel(w){
   QPixmap p;
   p.load(":images/schiff.gif");
   this->setPixmap(p);
   xpos = x;
   ypos = y;
   this->resize (40,40);
   this->move(xpos, ypos);
}
geschoss::geschoss(QWidget * w, int x, int y): QLabel(w) {
    QPixmap p;
    p.load(":images/schuss.gif");
    this->setPixmap(p);
    xpos = x;
    ypos = y;
    this->resize(14, 20);
    this->move(xpos, ypos);
}

void schiff::bewege(int richtung){
   switch(richtung){
      case 4: xpos= xpos -1;
      break;
      case 6: xpos = xpos +1;
      break;
      case 2: ypos = ypos +1;
      break;
      case 8: ypos = ypos -1;
      break;
   }
   if (xpos <0 ) xpos = 0;
   if (xpos >560) xpos = 560;
   if (ypos <0) ypos = 0;
   if (ypos >360) ypos = 360;
   this->move (xpos, ypos);
}
void geschoss::bewege() {
    ypos = ypos - 1;
    this->move(xpos, ypos);
}
void schiff::setx(int x) {
   xpos =x;
}
void schiff::sety(int y) {
   ypos =y;
}

