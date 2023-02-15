题目想累了，码码字。
明天带个键盘来。

差分数组可以很方便的实现区间修改（O1），但是查询的话只能On，如果动态查询不多的话，考虑用预处理应对。

先来一道线段树区间修改的裸题——HDU1556

> 题目就是区间修改+查询

``` cpp
#include <bits/stdc++.h>
using namespace std;
int aa[100005];
int main()
{
    int n;
    while(scanf("%d",&n)&&n){
        memset(aa,0,sizeof(aa));
        int l, r;
        for(int i = 0; i < n; i++){
            scanf("%d%d",&l,&r);
            aa[l] += 1;
            aa[r+1] -= 1;
        }
        for(int i = 1; i <= n; i++){
            aa[i] += aa[i-1];
            printf("%d%c",aa[i],(i==n)?'\n':' ');
        }
    }
    return 0;
}
```
诺，就是这样。