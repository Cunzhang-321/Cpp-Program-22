#include "class.h"
Point::Point(double nx, double ny)
{
    x=nx;y=ny;
}
void Point::SetX(double nx)
{
    x=nx;
}
void Point::SetY(double ny)
{
    y=ny;
}
void Point::SetPoint(double nx, double ny)
{
    x=nx;
    y=ny;
}
void Point::SetPoint(Point &np)
{
    x=np.x;
    y=np.y;
}
// Your code goes here
