#include <stdio.h>
#define MAX 50

int memo[MAX];

int Fibbo(int n)
{
    if(memo[n] != -1) return memo[n];
    else if(n <= 2) memo[n] = 1;
    else memo[n] = Fibbo(n - 1) + Fibbo(n - 2);
    
    return memo[n];
}

int main() {
    int n, i;

    scanf("%d", &n);

    for(i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }

    printf("%d", Fibbo(n));

    return 0;
}