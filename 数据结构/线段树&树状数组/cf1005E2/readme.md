
> 求数列中位数等于m的区间数

[E2][1]

中位数，可以考虑转化成1/-1序列来处理，小于等于m是1，大于m是-1，于是大家的和如果大于0那就是中位数小于等于m。
（当然，如果大于等于m是1，那么大于0就是中位数大于等于m，不过考虑到树状数组比较擅长维护小的值，就这样设计啦。）
于是问题就转化成：一串1/-1，求其和=0的区间个数。这个问题显然可以用树状数组在nlogn时间里处理出来。

Onlogn写法
``` cpp
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int a[MAXN],b[MAXN];
struct _bit{
    int c[MAXN<<1],n;//n+1(-n->1)
    void init(int _n)
    {
        n = _n;
        for(int i = 1; i <= n; i++)
            c[i] = 0;
    }
    void add(int x)
    {
        for(int i = x; i <= n; i += i&-i)
            c[i]++;
    }
    int sum(int x)
    {
        int res = 0;
        for(int i = x; i > 0; i -= i&-i)
            res += c[i];
        return res;
    }
}bit;

long long solve(int n, int m)
{
    for(int i = 1; i <= n; i++)
        b[i] = (a[i] <= m?1:-1);

    for(int i = 1; i <= n; i++)
        b[i] += b[i-1];

    bit.init(2*n+1);
    bit.add(n+1);
    long long res = 0;
    for(int i = 1; i <= n; i++){
        res += bit.sum(b[i]+n+1);
        bit.add(b[i]+n+1);
    }
    return res;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }

    printf("%lld\n",solve(n,m)-solve(n,m-1));
    return 0;
}

```
这段代码，循环<=少写个等号调了1h QAQ

还有On写法，留作思考。

******
On做法：
我们想处理出和大于等于0的区间。前面的处理方式相同，由于每次加入的新元素不是1就是-1，那么就是说加入1会增加前面前缀和是-1数量的区间，而加入-1会减少前面前缀和为0数量的区间：

``` cpp
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int aa[MAXN];
long long cnt[MAXN<<1];
int n;
long long solve(int m)
{
    memset(cnt,0,sizeof(cnt));
    long long res = 0, ans = 0;
    int sum = 0;
    cnt[n] = 1;
    for(int i = 1; i <= n; i++){
        if(aa[i]<=m){
            sum++;
            res += cnt[sum+n];
        }
        else {//aa[i]>m
            res -= cnt[sum+n];
            sum--;
        }
        cnt[sum+n]++;
        ans += res;
    }
    return ans;
}

int main()
{
    int m;
    scanf("%d%d",&n,&m);
    //int tmp;
    for(int i = 1; i <= n; i++)
        scanf("%d",&aa[i]);
    printf("%I64d\n",solve(m)-solve(m-1));
    return 0;
}

```


*****
一些乱七八糟的联想：
一个数列，求首位相等的区间数。（贪心+2）
一个数列，求右端点比左端点大的区间个数（裸BIT）
一个数列，求和大于等于0的区间个数（前缀和+BIT）

  [1]: http://codeforces.com/contest/1005/problem/E2