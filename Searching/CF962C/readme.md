题目大意：
给一个2e9的数，你可以删除其中的数字，现在要求删除最少的数字，使得剩余的数字组成一个平方数。

> e.g. 8314 ->2(81)

9位数，还给了两秒，暴力搜索最坏也只有2^10次，dfs暴搜即可。
多写写暴搜身体好。（31ms）

```cpp
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f;
int ans = INF,len;
int bit[11];
void get(int x)
{
    int ind = 0;
    while(x){
        bit[++ind] = x%10;
        x/=10;
    }
    len = ind;
}

void dfs(int pos, int val, int cnt)//cur_pos pre_val pre_cnt
{
    if(pos==0){
        if(val==0)return;
        int x = sqrt(val);
        if(x*x==val){
            ans = min(ans,len-cnt);
        }
        return;
    }
    dfs(pos-1, val, cnt);//do not choose
    //not begin with zero
    if(bit[pos]==0 && val==0) return;

    dfs(pos-1, val*10+bit[pos], cnt+1);//choose pos_val
}


int main()
{
    int n;
    scanf("%d",&n);
    get(n);
    dfs(len,0,0);
    if(ans==INF)printf("-1\n");
    else {
        printf("%d\n",ans);
    }
    return 0;
}
```
