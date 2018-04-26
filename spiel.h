#include <QLabel>
#include <QPixmap>
//Klassen definition für Schuss
class geschoss : public QLabel {
    private:
        int xpos;
        int ypos;
    public:
        void bewege();
        //custom constructor für die position des schussses anhand der schiff koordinaten
        geschoss(QWidget * w, int x, int y);
};
class schiff : public QLabel {
   private:
   int xpos;
   int ypos;
   int richtung;
   public:
      void setx(int);
      void sety(int);
      void bewege(int);
      schiff(QWidget * w = 0,int x = 300, int y = 300);
};

class spiel : public QDialog  {
   private:
       int richtung;
       int myTimerId;
       schiff * s;
       geschoss * schuss;
   public: 
      spiel (QWidget * );
      void  keyPressEvent(QKeyEvent *event);
      void  showEvent(QShowEvent * event);
      void  timerEvent(QTimerEvent * event);
      void  hideEvent(QHideEvent * event );
};
   
   
