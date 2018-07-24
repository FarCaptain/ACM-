## 1001 
> Given an integer n, Chiaki would like to find three positive integers x, y and z such that: n=x+y+z, x∣n, y∣n, z∣n and xyz is maximum

令n = ax = by = cz，易得不定方程 `1/a + 1/b + 1/c = 1`，可知最小值<=3，于是可以得到三组解

``` stylus
1. 3 3 3
2. 2 3 6
3. 2 4 4
```
又由于6的倍数一定是3的倍数，而第一组的乘积比第二组小（代表xyz乘积大），那么讨论1、3组就行。

``` cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int x=-1, y=-1, z=-1;

        if(n%3==0){
            x=y=z=n/3;
        }
        else if(n%2==0&&n%4==0){
            x = n/2; y =n/4, z = y;
        }

        printf("%lld\n",x*1LL*y*z);
    }
    return 0;
}
```

## 1011

时区时间转换。给出时间跟时区，要求转换成UTC+8的时间。
模拟，但是注意读入，注意负数的处理，注意避免浮点精度问题。

``` cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    char s[100];
    while(t--){
        int a, b;
        scanf("%d%d%s",&a,&b,s);
        //cout << s[0] <<endl;
        double tmp;
        sscanf(s,"UTC%lf",&tmp);
        int gap = (int)(tmp*10);
        gap -= 80;
        //cout <<"gap" <<gap<<endl;
        int res = a*60+b;
        res += gap*6;
        if(res<0){
            res += 24*60;
        }
        b = res%60;
        a = (res/60)%24;
        printf("%02d:%02d\n",a,b);
    }
    return 0;
}
```

## 1003

> Chiaki has 3n points p1,p2,…,p3n. It is guaranteed that no three points are collinear.
Chiaki would like to construct n disjoint triangles where each vertex comes from the 3n points.

就是保证给出的3n个点，任意三点不共线，要求组成n个互不相交的三角形。

都说了3点不共线，那么按横坐标排个序，可知每个横坐标下最多两个点，那就随便输出一下就行了。


## 1004 区间不同(*)

> 构造一个n个数的正整数数列，给你m个区间[l,r]，要求区间内任意两个值都不相等。要求构造字典序最小的这样的数列。

贪心+模拟
算法都想到了，但是当时不会实现！

处理出每个点所在区间的最左边界aa_i
然后用一个指针，和一个set

``` cpp
#include <bits/stdc++.h>
using namespace std;
int aa[101010], res[101010];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i++)
            aa[i] = i;
        for(int i = 0; i < m; i++){
            int l, r;
            scanf("%d%d",&l,&r);
            aa[r] = min(aa[r],l);
        }
        for(int i = n-1; i >= 1; i--){
            aa[i] = min(aa[i],aa[i+1]);
        }
        set<int> s;
        for(int i = 1; i <= n; i++)s.insert(i);
        int pl = 1;
        for(int i = 1; i <= n; i++){
            while(pl<aa[i]){
                s.insert(res[pl]);
                pl++;
            }
            res[i] = *s.begin();
            s.erase(res[i]);
        }
        for(int i = 1; i <= n; i++)
            printf("%d%c",res[i],(i==n)?'\n':' ');
    }
    return 0;
}

```
## 1002 最长匹配括号序列(*)

>  Chiaki has n strings s1,s2,…,sn consisting of '(' and ')'. A string
> of this type is said to be balanced:
> + if it is the empty string
> + if A and B are balanced, AB is balanced,
> + if A is balanced, (A) is balanced.
> 
> Chiaki can reorder the strings and then concatenate them get a new
> string t. Let f(t) be the length of the longest balanced subsequence
> (not necessary continuous) of t. Chiaki would like to know the maximum
> value of f(t) for all possible t.

就是说有n个括号串，匹配规则正常，但是可以不连续（子序列），现在把它们按一定顺序拼在一起，问最长匹配是多少。
首先先简单的处理一下每个串的匹配数，自然，我们会剩下左面全是`）`右面全是`（` 的串，统计出左面)的数量`l`右面（的数量`r`，然后接下来就是贪心地排个序，按最优的顺序拼在一起。
贪心的规则见代码。

``` cpp
#include <bits/stdc++.h>
using namespace std;
struct cc{
    int l, r;
}aa[100005];

bool cmp(cc a, cc b)
{
    if(a.l<=a.r&&b.l>b.r) return true;
    if(a.l>a.r&&b.l<=b.r) return false;
    if(a.l>a.r&&b.l>b.r) return a.r > b.r;
    return a.l < b.l;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n, ans = 0;
        scanf("%d",&n);
        char s[100005];
        for(int i = 0; i < n; i++){
            scanf("%s",s);
            int len = strlen(s);
            aa[i].l = 0, aa[i].r = 0;
            for(int j = 0; j < len; j++){
                if(s[j]==')'){
                    if(aa[i].r!=0) ans++, aa[i].r--;
                    else aa[i].l++;
                }
                else {//(
                    aa[i].r++;
                }
            }
        }
        sort(aa,aa+n,cmp);
        int cur = 0;//cur_right
        for(int i = 0; i < n; i++){
            if(aa[i].l>cur)aa[i].l = cur;
            cur -= aa[i].l;
            ans += aa[i].l;
            cur += aa[i].r;
        }
        printf("%d\n",ans*2);
    }
    return 0;
}

```


