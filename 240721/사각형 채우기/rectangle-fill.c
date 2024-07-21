#include <stdio.h>
#define MAX 1001

int main(void)
{
	int i, n;
	
	scanf("%d", &n);
	
	int dp[MAX];
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	
	for(i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 3]*1%10007 + dp[i - 2]*2%10007;
	}
	
	printf("%d", dp[n]);
}