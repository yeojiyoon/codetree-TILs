#include <stdio.h>
#define MAX 200

int grid[MAX][MAX];

void makeMatrix(int n, int m)
{
	int i, j;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			scanf("%d", &grid[i][j]);
		}
	}
}

int max(int a, int b)
{
	if(a > b) return a;
	
	return b;
}

int findMaxCase01(int n, int m)
{
	int i, j;
	int sum = 0;
	int max_num = 0;
	
	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < m - 1; j++)
		{	
			sum = grid[i][j] + grid[i+1][j] + grid[i][j+1] + grid[i+1][j+1];
			max_num = max(max_num, sum - grid[i][j]);
			max_num = max(max_num, sum - grid[i+1][j]);
			max_num = max(max_num, sum - grid[i][j+1]);
			max_num = max(max_num, sum - grid[i+1][j+1]); 
		}
	}
	
	return max_num;
}

int findMaxCase02(int n, int m)
{
	int i, j;
	int sum = 0;
	int max_num = 0;
	
	for(i = 0; i < n - 2; i++)
	{
		for(j = 0; j < m; j++)
		{
			sum = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
			max_num = max(max_num, sum);
		}
	}
	
	return max_num;
}

int findMaxCase03(int n, int m)
{
	int i, j;
	int sum = 0;
	int max_num = 0;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m - 2; j++)
		{
			sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
			max_num = max(max_num, sum);
		}
	}
	return max_num;
}

int main()
{
	int n, m;
	int max_num = 0;
	
	scanf("%d %d", &n, &m);
	makeMatrix(n, m);
	
	max_num = max(findMaxCase01(n, m), findMaxCase02(n, m));
	max_num = max(max_num, findMaxCase03(n, m));
	
	printf("%d", max_num);
}