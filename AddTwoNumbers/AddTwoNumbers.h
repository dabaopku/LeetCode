/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain 
a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *res=NULL;
		ListNode *cur=res;

		int a=0,b=0,c=0,s=0;
		while(true)
		{
			if(!l1 && !l2)
			{
				if(c)
				{
					cur->next=new ListNode(c);
				}
				return res;
			}

			if(l1)
			{
				a=l1->val;
				l1=l1->next;
			}
			else
			{
				a=0;
			}

			if(l2)
			{
				b=l2->val;
				l2=l2->next;
			}
			else
			{
				b=0;
			}

			s=a+b+c;
			c=s/10;
			s=s%10;
			if(!res)
			{
				res=new ListNode(s);
				cur=res;
			}
			else
			{
				cur->next=new ListNode(s);
				cur=cur->next;
			}
		}
	}

	void test()
	{
		ListNode *l1=NULL, *l2=NULL, *cur;
		int num1,num2,val;
		
		cin>>num1;
		while(num1--)
		{
			cin>>val;
			ListNode *nd=new ListNode(val);
			if(!l1)
				l1=cur=nd;
			else
				cur=cur->next=nd;
		}
		
		cin>>num2;
		while(num2--)
		{
			cin>>val;
			ListNode *nd=new ListNode(val);
			if(!l2)
				l2=cur=nd;
			else
				cur=cur->next=nd;
		}

		ListNode *res=addTwoNumbers(l1,l2);

		while(res)
		{
			cout<<res->val;
			res=res->next;
		}
	}
};
