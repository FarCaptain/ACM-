double 的精度肯定不够，（只有6、7位的样子） 
于是想到a*(10^n),用快速幂可以解决，但是会爆longlong  
**于是,a/b的小数部分==a%b/b小数部分！**  

所以只要快速幂里mod b 就可以！  
所以，计算 a\*(10^(n-1))(mod b) ，（因为要小数部分才会一样）快速幂解决   
好题。

暴力版本：
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    typedef long long ll;
    ll a,b,n;

    while(scanf("%lld%lld%lld",&a,&b,&n)!=EOF){
        for(ll i = 1; i <= n-1; i++){
            a = (a%b*10)%b;
        }

        printf("%d\n",(a%b)*10/b);
    }
    return 0;
}
```

快速幂常规操作

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll qmod(ll a, ll b, ll mod)
{
	ll res = 1ll;
	while(b){
		if(b&1) res = res*a%mod;
		b>>=1, a = a*a%mod;
	}
	return res;
}

int main(void)
{
	 ll a, b, n;
    while(~scanf("%lld%lld%lld",&a,&b,&n)){
        printf("%lld\n",a%b*qmod(10,n-1,b)%b*10/b);
    }
    return 0;
}
```
