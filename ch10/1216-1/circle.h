  class Circle
{
    private:
    int x,y,r;
    public:
    Circle(int x1,int y1,int r1);//�������
    void getO(int &cx,int &cy); //��ȡ����
    void move(int mvx,int mvy);//�ƶ�����
    void setR(int mvr);//�ƶ��뾶
    int getR()//��ȡ�뾶
    {
        return r;
    }
};
