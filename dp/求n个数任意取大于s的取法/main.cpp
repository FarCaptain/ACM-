#include <bits/stdc++.h>
using namespace std;
int arr[500];
int dp[500][2005];
int main()
{
    int n, s, t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&s);
        int sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d",&arr[i]);
            sum += arr[i];
        }
        memset(dp,0,sizeof(dp));

        dp[0][0] = 1;
        dp[0][arr[0]] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= sum; j++){
                if(j>=arr[i])
                    dp[i][j] += dp[i-1][j-arr[i]];
                dp[i][j] += dp[i-1][j];
            }
        }
        int ans = 0;
        for(int i = sum; i > s; i--){
            ans += dp[n-1][i];
            //cout <<"dp["<<n<<"-1]["<<i<<"] = "<<dp[n-1][i]<<endl;
        }
        printf("%d\n",ans);
    }
    return 0;
}
