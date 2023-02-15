> 在 @springhack 的OJ上第一次遇到，暴力dp2333

## 题目描述

一个数字组成的三角形，从顶部出发，在每一结点可以选择向左走或得向右走，一直走到底层，要求找出一条路径，使路径上的值最大。
 
现在要求走到最后mod 100最大(mod 100的意思就是对100取余数，也就是C语言的%100)

## 思路

这道题让我明白，dp不仅可以维护上一个状态的特殊值，还可以维护所有值，进而遍历所有状态。


话不多说上代码（边界搞得很偷懒，摸了）

```cpp
#include <bits/stdc++.h>
using namespace std;
int arr[50][50];
bool dp[50][50][100];//0~99
int main()
{
    int n;
    scanf("%d",&n);
    memset(arr,-1,sizeof(arr));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    dp[1][1][arr[1][1]%100] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            int val = arr[i][j];
            for(int k = 0; k <= 99; k++){
                if(dp[i-1][j][k])dp[i][j][(k+val)%100] = 1;
                if(dp[i-1][j-1][k])dp[i][j][(k+val)%100] = 1;
            }
        }
    }
    int ans = -1;
    for(int j = 1; j <= n; j++){
        for(int k = 99; k >= 0; k--)
        if(dp[n][j][k]){
            ans = max(ans,k); break;
        }
    }

    printf("%d\n",ans);
    return 0;
}

```
