/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

#include <map>
#include <string>
using namespace std;

class Solution {
public:
	int numDecodings(string s)
	{
		int n=s.length();
		if(n==0)
			return 0;

		count.clear();
		count[n]=1;
		if(s[n-1]=='0')
			count[n-1]=0;
		else
			count[n-1]=1;
		for(int i=n-2;i>=0;--i)
		{
			char cur=s[i]-'0';
			char next=s[i+1]-'0';
			if(cur==0)
			{
				count[i]=0;
			}
			else if(cur==1)
			{
				count[i]=count[i+1]+count[i+2];
			}
			else if(cur==2)
			{
				if(next<=6)
					count[i]=count[i+1]+count[i+2];
				else
					count[i]=count[i+1];
			}
			else
			{
				count[i]=count[i+1];
			}
		}
		return count[0];
	}
	void test()
	{
		string s;
		cin>>s;
		cout<<numDecodings(s);
	}
private:
	map<int,int> count;
};