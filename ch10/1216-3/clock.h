class myclock
{
    private:
    int hh,mm,ss;
    public:
    //myclock(int h,int m,int s);
    void change(int h1,int m1,int s1);
    void displaytime(); //显示时间
	void readtime(char *a); //从字符串读取时间
	friend void calc(myclock c0,myclock c1,myclock &res);   //计算差值
};
