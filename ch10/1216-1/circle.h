  class Circle
{
    private:
    int x,y,r;
    public:
    Circle(int x1,int y1,int r1);//传入变量
    void getO(int &cx,int &cy); //获取坐标
    void move(int mvx,int mvy);//移动坐标
    void setR(int mvr);//移动半径
    int getR()//获取半径
    {
        return r;
    }
};
