#include <stdio.h>
#define MAX 100

int grid[MAX][MAX];

void makeMatrix(int n)
{
	int i, j;
	
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }
}

int findHappyRow(int n, int m)
{
    int i, j;
    int ch, b, sum = 0; //ch: 연속된 수 개수, b: 직전 숫자, sum: 행복한 수열 총계

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if(j == 0) {
                b = grid[i][j];
                ch = 1;
            }

            else if(grid[i][j] != b)
            {
                b = grid[i][j];
                ch = 1;
            }
            
			else ch++;
            
            if(ch == m)
            {
            	sum++;
            	break;
			}
        }
    }
    return sum;
}

int findHappyCol(int n, int m)
{
    int i, j;
    int ch, b, sum = 0; //ch: 연속된 수 개수, b: 직전 숫자, sum: 행복한 수열 총계

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if(j == 0) 
			{
                b = grid[j][i];
                ch = 1;
            }
            
            else if(grid[j][i] != b)
            {
                b = grid[j][i];
                ch = 1;
            }
            
            else ch++;
             
			if(ch == m)
            {
               	sum++;
               	break;
			}
        }
        
    }
    return sum;
}

int main() {
    int n, m;
    int sum = 0;

    scanf("%d %d", &n, &m);
    makeMatrix(n);

    sum += findHappyRow(n, m);
    sum += findHappyCol(n, m);

    printf("%d", sum);

    return 0;
}