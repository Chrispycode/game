spiel::spiel (QWidget * w):QDialog(w){
  s = new schiff(this, 300, 300);
  s->show();

  e = new enemy(this, 300, 0);
  e->show();

   /*schuss = new geschoss(this, 300, 300);
   schuss->show();*/
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
    if (event->text() == " ") {
        if (s->schuss != NULL)
        {
            s->schuss->hide();
        }
        s->schiessen(this);
    }

}

void spiel::showEvent(QShowEvent *){
   myTimerId = startTimer(10);
}

void spiel::timerEvent(QTimerEvent * event){
   if (event->timerId() == myTimerId){
      s->bewege(richtung);
      if (s->schuss != NULL)
      {
          s->schuss->bewege();
      }
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

enemy::enemy(QWidget * w ,int x , int y): QLabel(w){
   QPixmap p;
   p.load(":images/enemy.png");
   this->setPixmap(p);
   xpos = x;
   ypos = y;
   this->resize (50,50);
   this->move(xpos, ypos);
}

geschoss::geschoss(QWidget * w, int x, int y): QLabel(w) {
    QPixmap p;
    p.load(":images/schuss.png");
    this->setPixmap(p);
    xpos = x;
    ypos = y;
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
void schiff::schiessen(QWidget * w) {
    schuss = new geschoss(w, xpos+12, ypos);
    schuss->show();
}
void geschoss::bewege() {
    ypos = ypos - 5;
    if (ypos < -10)
    {
        this->hide();
    }
    else {
        this->move(xpos, ypos);
    }

}

void schiff::setx(int x) {
   xpos =x;
}
void schiff::sety(int y) {
   ypos =y;
}

void enemy::setx(int x) {
   xpos =x;
}
void enemy::sety(int y) {
   ypos =y;
}
