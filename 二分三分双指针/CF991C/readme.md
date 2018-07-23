> 一罐糖n块（1e18)，每天吃k个，然后每天其他人会偷偷吃掉剩下的10%，问你要吃掉至少一半的糖，k至少是多少。
****
一眼二分，但是两个问题：
1. check复杂度？
````
大概 N*(0.9)^k = 1
k = 22*logN，总复杂度再乘上一个 logN, 完全可以接受。

````

2. 10%的浮点精度问题?

```
想什么，整数除法/10就好啦
````

****
代码如下：

````cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
bool check(ll x)
{
    ll tot = n;
    //cout <<"x = "<< x <<" ";
    ll sum = 0;
    while(tot>0){
        if(tot>=x)tot -= x,sum += x;
        else sum+=tot,tot = 0;
        ll tmp = tot/10;
        tot -= tmp;
    }
    //cout << "sum ="<<sum<<endl;
    if(sum>=(n+1)/2)return true;
    return false;
}

int main()
{
    scanf("%I64d",&n);
    ll l = 1, r = n/2+1,ans = n;
    while(l<=r){
        ll mid = (l+r)/2;
        if(check(mid))r = mid-1, ans = mid;
        else l = mid+1;
    }
    printf("%I64d\n",ans);
    return 0;
}
````