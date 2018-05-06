#include "enemy.h"
#include <QObject>
#include <math.h>

Enemy::Enemy(QObject *parent)
    : QObject(parent)

{
    xdir = 0;
    ydir = 1;
    destroyed = false;
	image.load(":images/en1.png");
    rect = image.rect();
    timerd = startTimer(100);
    xt = QTime::currentTime().addSecs(1);
    irot = 1;
}

void Enemy::resetState(int x,int y)
{
	rect.moveTo(x,y);
}
void Enemy::autoMove()
{
	rect.translate(xdir, ydir);


}
void Enemy::Destroyed()
{
    image.load(":images/explo.png");
    destroyed=true;
}
void Enemy::timerEvent(QTimerEvent *event)
{
    n = QTime::currentTime();
    if(xt > n){
	   image.load(":images/en1.png");

    }
    if(xt < n){
		image.load(":images/en2.png");
		xt = QTime::currentTime().addSecs(1);
    }
}

QRect Enemy::getRect(){
  return rect;
}

QImage & Enemy::getImage(){
  return image;
}
void Enemy::moveTop(int top)
{
  rect.moveTop(top);
}
