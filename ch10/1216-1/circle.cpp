#include "circle.h"
 Circle::Circle(int x1,int y1,int r1)
{
    x=x1;y=y1;r=r1;
}
void Circle::getO(int &cx,int &cy)
{
    cx=x;cy=y;
}
void Circle::move(int mvx,int mvy)
{
    x=x+mvx;y=y+mvy;
}
void Circle::setR(int newR)
{
    r=newR;
}
