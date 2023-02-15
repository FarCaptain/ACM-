今天回来听tls说起这道题。
> 给定n\*n的矩阵，求其任意一个子矩阵，使其内所有数的和最大。
***
n^3的dp，枚举左右列，dp连续行。

注意：前缀和处理得到的，a[r]-a[l] 得到的是`` ( l , r ] ``区间的值。一般在前面塞上一个0，下标从1开始。
```cpp
#include <cstdio>
#include <algorithm>
using namespace std;
//22:00
int mx[105][105];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
        scanf("%d",&mx[i][j]);
        if(i>0)mx[i][j] += mx[i][j-1];
    }
    int ans = 0;
    for(int l= 0; l <= n-1; l++){//枚举列号
        for(int r = l+1; r <= n; r++){
            int tmp = 0;
            for(int i = 1; i <= n; i++){//hang
                tmp += mx[i][r] - mx[i][l];
                if(tmp<0)tmp = 0;
                else ans = max(ans,tmp);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
```
