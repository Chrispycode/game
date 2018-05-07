#include "plane.h"

Plane::Plane(){

	image.load(":images/plane3.gif");
    rect = image.rect();
    resetState();
  }
void Plane::moveLeft(int left){
if (rect.left() >= 2)
rect.moveTo(left, rect.top());
}

void Plane::moveRight(int right){
if (rect.right() <= 580)

  rect.moveTo(right, rect.top());

}

void Plane::resetState(){

rect.moveTo(275, 350);

}

QRect Plane::getRect(){

return rect;

}

QImage & Plane::getImage(){

return image;

}
