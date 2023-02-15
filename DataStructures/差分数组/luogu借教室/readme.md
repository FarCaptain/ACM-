>  **题目描述**
	>  n天，第i天有ai间教室可以外借
	>  现在有m个请求，每个请求借vj间教室，从sj天到tj天
	>  外借规则是按照先来后到，一旦借出去不能换。所以有可能m个请求不能全满足
	>  如果全满足，输出0，否则输出-1，并输出第一个不满足的请求j
	>  m,n为1e6，其他的数据1e9

如果考虑用线段树，就是维护区间最小值，每次区间修改，如果最小值小于0，则不满足。
现在考虑差分数组怎么实现。

乍一看，查询是动态的，不能预处理，查询要另外想办法。
仔细一想，这个更改是累加的，但是查询只是一个点，考虑单调性。于是就二分吧，logn次On的查询，也就能接受了。这就是因为差分数组的修改是O1的，才可以这样肆意妄为。

``` cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll aa[1000005],f[1000005];
int le[1000005],ri[1000005], vv[1000005];
int n, m;

bool check(int x)
{
    memset(f,0,(n+3)*sizeof(ll));//borrow num
    for(int i = 1; i <= x; i++){
        f[le[i]] += vv[i];
        f[ri[i]+1] -= vv[i];
    }
    for(int i = 1; i <= n; i++){
        f[i]+=f[i-1];
        //cout << "f"<<i<<"="<<f[i]<<endl;
        if(f[i]>aa[i])return false;
    }
    return true;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++){
        scanf("%lld",&aa[i]);
    }
    for(int i = 1; i <= m; i++){
        scanf("%d%d%d",&vv[i],&le[i],&ri[i]);
    }
    if(check(m))printf("0\n");
    else {
        int l = 1, r = m, mid, ans = 0;
        while(l<=r){
            mid = (l+r)/2;
            if(check(mid))l = mid+1, ans = mid;
            else r = mid-1;
        }
        printf("-1\n%d\n",ans+1);
    }
    return 0;
}

```
