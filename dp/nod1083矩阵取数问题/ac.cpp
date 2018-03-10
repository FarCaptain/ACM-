#include <bits/stdc++.h>
using namespace std;
int dp[505][505];
//int mx[505][505];
int main()
{
    int n;
    scanf("%d",&n);
    sizeof(dp,0,sizeof(dp));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d",&dp[i][j]);
        }
    }
    //dp[1][1] = mx[1][1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] += max(dp[i-1][j],dp[i][j-1]);
        }
    }
    printf("%d\n",dp[n][n]);
    return 0;
}
