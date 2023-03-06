 class SavingAccount
{
	private:
		int num; //Î¨Ò»±àºÅ
		double money,rate;
	public:
		SavingAccount(int mm)
		{
			static int n=1;
			money=(double)mm;
			rate=0.05;
			num=n++;
		}
		void display();
		void calculate();
		void changerate(float new_rate);

};
