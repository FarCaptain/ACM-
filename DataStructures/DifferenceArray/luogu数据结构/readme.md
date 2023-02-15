一道很OI的题。
给个网址吧，懒得写题意了。
[传送门][1]
线段树当然可以。
> 其实也就是普通的区间修改+区间查询，查询的是``[L,R] 这个区间中元素T满足 min<=(T∗i % mod)<=max 的 T这样的数的个数``。不过这道题的动态修改只有1000组，然后有1e7组连在一起的查询。
> 于是暴力就行。最后那坨预处理一下就好了。

``` cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ff[100100], sm[100100], ok[100100];
int main()
{
    int opt;
    ll n,mod ,minn, maxx;
    //string str;
    scanf("%lld%lld%lld%lld%lld",&n,&opt,&mod,&minn,&maxx);
    getchar();

    for(int t = 0; t < opt; t++){
        char str[10];
        //getline(cin,str);
        ll l,r,v;
        scanf("%s%lld%lld",str,&l,&r);
        if(str[0]=='A'){
            //int l, r, v;
            //sscanf(str,"A %d %d %d\n",&l,&r,&v);
            scanf("%lld",&v);
            ff[l]+=v; ff[r+1]-=v;
        }
        else if(str[0]=='Q'){
            //int l, r, cnt = 0;
            ll cnt = 0;
            //sscanf(str,"Q %d %d\n",&l,&r);
            for(int i = 1; i <= r; i++){
                sm[i] = sm[i-1] + ff[i];
                if(i>=l&&(sm[i]*i%mod)>=minn&&(sm[i]*i%mod)<=maxx)cnt++;
            }
            printf("%lld\n",cnt);
        }
    }

    for(int i = 1; i <= n; i++){
        //sm[i] = sm[i-1] + ff[i];
        ff[i]+=ff[i-1];
        ok[i] = ok[i-1];
        if((ff[i]*i%mod)>=minn&&(ff[i]*i%mod)<=maxx)ok[i]++;
    }
    int fin,l,r;
    scanf("%d",&fin);
    for(int t = 0; t<fin;t++){
        scanf("%d%d",&l,&r);
        printf("%lld\n",ok[r]-ok[l-1]);
    }
    return 0;
}
```


  [1]: https://www.luogu.org/problemnew/show/P3948