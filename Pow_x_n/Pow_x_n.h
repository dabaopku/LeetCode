/*
Implement pow(x, n).
*/

class Solution {
public:

#define eps 1e-10

	double pow(double x, int n)
	{
		if(n==0) return 1;
		if(abs(x)<eps) return 0;
		bool neg=false;
		if(n<0)
		{
			n=-n;
			neg=true;
		}

		double factor=x,res=1;
		while(n)
		{
			if(n%2)
				res*=factor;
			n/=2;
			factor*=factor;
		}
		if(neg)
		{
			if(fabs(res)<eps)
			{
				bool s=res>0;
				res=(s?1:-1)*eps;
			}
			return 1/res;
		}
		else
			return res;
	}

	void test()
	{
		cout<<pow(-1.213,-8);
	}
};