## 题意：
> 有两行数，分别有m,n个，上下某两个数一样，可以连线，但是对于每条连线，必须有另一条线与之交叉（对应的两对数不一样），才能匹配一次。问最大匹配是多少。

***
这道题是一道很经典的动态规划题，跟LCS的想法有点想。
考虑dp( i , j )表示 i, j 位置对应的最大匹配对数（连线条数），可以想到状态转移``` dp[i][j] = max(dp[i-1][j],dp[i][j-1]); ```,若i , j对应的数值不相等的话呢，就分别向前找到一对新的匹配，更新```dp[i][j] = max(dp[i][j],dp[p-1][q-1]+2);```
***
一个细节：当然，可能有三条线（多条）交叉这种情况。转移方程仍然完美。
另一个细节：由于方程都是```i-1```这么更新的，一般做法是下标从1开始，然后0位置留一个“缓冲位”。保证不会访问到无效的内存。

```cpp
#include <cstdio>//cross matches
#include <algorithm>
#include <cstring>
using namespace std;
int a[200],b[200];
int dp[200][200];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n1, n2;
        scanf("%d%d",&n1,&n2);
        for(int i = 1; i <= n1; i++)scanf("%d",&a[i]);
        for(int i = 1; i <= n2; i++)scanf("%d",&b[i]);
        for(int i = 2; i <= n1; i++)
        for(int j = 2; j <= n2; j++){///
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(a[i]!=b[j]){
                int p,q;
                for(p = i-1;p >= 1; p--)
                    if(a[p]==b[j])break;
                for(q = j-1; q >= 1; q--)
                    if(a[i]==b[q])break;
                if(p&&q)
                    dp[i][j] = max(dp[i][j],dp[p-1][q-1]+2);
            }
        }
        printf("%d\n",dp[n1][n2]);
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
```