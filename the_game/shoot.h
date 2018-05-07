#ifndef SHOOT_H
#define SHOOT_H

#include <QImage>
#include <QRect>

class Shoot
{
public:
    Shoot();
    void resetState(int,int);
    void moveTop(int);
    void autoMove();
    void Destroyed();
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
    QRect getRect();
    QImage & getImage();
    bool destroyed;

  private:
    int xdir;
    int ydir;
    QImage image;
    QRect rect;

};

#endif // SHOOT_H
