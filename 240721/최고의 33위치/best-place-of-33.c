#include <stdio.h>
#define MAX 100

int grid[MAX][MAX];

int GetNumOfGold(int row_s, int row_e, int col_s, int col_e)
{
    int num_of_gold = 0;

    for(int row = row_s; row <= row_e; row++)
    {
        for(int col = col_s; col <= col_e; col++)
            num_of_gold += grid[row][col];
    }

    return num_of_gold;
}

int max(int a, int b)
{
    if(a>b) return a;
    else return b;
}

int main() {
    int max_gold = 0;

    int n, i, j;
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < n; col++)
        {
            if((col + 2 >= n) || (row + 2 >= n)) continue;

            int num_of_gold = GetNumOfGold(row, row + 2, col, col + 2);

            max_gold = max(max_gold, num_of_gold);
        }
    }

    printf("%d", max_gold);
}