#ifndef CLASS_H
#define CLASS_H

class Point
{
public:
    Point(double nx=0.0, double ny=0.0);
    //Point(Point &np);  //该函数为拷贝构造函数，暂时未讲到，本题目不需要实现
    //~Point(); //该函数为析构函数，暂时未讲到，无需实现
    void SetX(double nx);
    void SetY(double ny);
    void SetPoint(double nx, double ny);
    void SetPoint(Point &np);
    double x;
    double y;
};



#endif /* CLASS_H */
