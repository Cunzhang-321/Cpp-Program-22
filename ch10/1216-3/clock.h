class myclock
{
    private:
    int hh,mm,ss;
    public:
    //myclock(int h,int m,int s);
    void change(int h1,int m1,int s1);
    void displaytime(); //��ʾʱ��
	void readtime(char *a); //���ַ�����ȡʱ��
	friend void calc(myclock c0,myclock c1,myclock &res);   //�����ֵ
};
