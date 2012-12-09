#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define BUFFER_SIZE 10000

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
	
	~TreeNode()
	{
		if(left)
			delete left;
		if(right)
			delete right;
	}
	static TreeNode* load()
	{
		char buffer[BUFFER_SIZE];
		cin.getline(buffer,BUFFER_SIZE,'\n');

		TreeNode* root=NULL;
		TreeNode* curNode=NULL;
		queue<TreeNode*> que;

		string str=buffer;
		int n=str.length();
		int cur=1;
		int next=1;
		while(cur<n)
		{
			next=str.find_first_of(",}",cur);
			if(next==str.npos)
				break;

			string item=str.substr(cur,next-cur);
			int val=-1;
			if(item!="#")
			{
				val=atoi(item.c_str());
			}

			cur=next+1;

			if(que.empty())
			{
				if(root==NULL)
				{
					if(val==-1)
					{
						cout<<"Invalid tree string!"<<endl;
						exit(1);
					}
					root=new TreeNode(val);
					que.push(root);
				}
				else
				{
					cout<<"Invalid tree string!"<<endl;
					exit(1);
				}
			}
			else
			{
				if(curNode==NULL)
				{
					curNode=que.front();
					que.pop();
					if(val!=-1)
					{
						TreeNode* nd=new TreeNode(val);
						curNode->left=nd;
						que.push(nd);
					}
				}
				else
				{
					if(val!=-1)
					{
						TreeNode* nd=new TreeNode(val);
						curNode->right=nd;
						que.push(nd);
					}
					curNode=NULL;
				}
			}
		}

		return root;
	}

	void print()
	{
		int level=calLevel();
		visitPrint(0);
	}

private:
	int calLevel()
	{
		int l=0,r=0;
		if(left)
		{
			l=left->calLevel();
		}
		if(right)
		{
			r=right->calLevel();
		}
		return max(r,l)+1;
	}
	
	void visitPrint(int level)
	{
		cout<<val<<endl;
		printNode(level,left);
		printNode(level,right);		
	}

	void printNode(int level, TreeNode* node)
	{
		for(int i=0;i<level;++i)
		{
			cout<<' ';
		}
		cout<<"|-";
		if(node)
		{
			node->visitPrint(level+2);
		}
		else
		{
			cout<<"#"<<endl;
		}
	}
};