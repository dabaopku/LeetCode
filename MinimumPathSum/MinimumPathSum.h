/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include <vector>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) 
	{
		int row=grid.size();
		if(row==0) return 0;
		int column=grid[0].size();
		if(column==0) return 0;

		vector<int> resRow;
		vector<vector<int> > res;
		for(int i=0;i<=column;++i)
			resRow.push_back(0);
		for(int i=0;i<=row;++i)
			res.push_back(resRow);

		for(int i=row-1;i>=0;--i)
		{
			res[i][column-1]=res[i+1][column-1]+grid[i][column-1];
		}
		for(int i=column-1;i>=0;--i)
		{
			res[row-1][i]=res[row-1][i+1]+grid[row-1][i];
		}

		for(int i=column-2;i>=0;--i)
		{
			for(int j=row-2;j>=0;--j)
			{
				res[j][i]=min(res[j+1][i],res[j][i+1])+grid[j][i];
			}
		}

		return res[0][0];
	}

	void test()
	{
		int m,n;
		cin>>m>>n;
		vector<vector<int> > grid;
		vector<int> row;
		while(m--)
		{
			int c;
			row.clear();
			for(int i=0;i<n;++i)
			{
				cin>>c;
				row.push_back(c);
			}
			grid.push_back(row);
		}
		cout<<minPathSum(grid);
	}
};