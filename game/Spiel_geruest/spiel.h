#include <QLabel>
#include <QPixmap>

class schiff : public QLabel {
   private:
   int xpos;
   int ypos;
   int richtung;
   public:
      void setx(int);
      void sety(int);
      void bewege(int);
      schiff(QWidget * w = 0);
};

class spiel : public QDialog  {
   private:
       int richtung;
       int myTimerId;
       schiff * s;
   public: 
      spiel (QWidget * );
      void  keyPressEvent(QKeyEvent *event);
      void  showEvent(QShowEvent * event);
      void  timerEvent(QTimerEvent * event);
      void  hideEvent(QHideEvent * event );
};
   
   
