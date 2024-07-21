#include <stdio.h>
#define MAX 1001

int st[MAX];

int DP(int n)
{
	if(st[n] != -1) return st[n];
	else st[n] = DP(n - 2) + DP(n - 3);
	
	return st[n];
}

int main() {
    int n, i;
    
    scanf("%d", &n);
    
    for(i = 0; i <= n; i++)
    {
    	st[i] = -1;
	}
	
	st[1] = 0;
	st[2] = 1;
	st[3] = 1;
	
	printf("%d", DP(n) % 10007);
    
    return 0;
}