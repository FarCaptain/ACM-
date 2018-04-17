### 题目

输入包含四个整数x,a,y,b (1<=x,a,y,b<=10^9)，要求 x^a == y^b 是否为 true

****
这题可以取模快速幂，但是太low

直接两边取对数，卡eps，但是要注意，double居然不行，要卡到 long double 的精度（于是比赛就没过

```cpp

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ll x,a,y,b;
        scanf("%lld%lld%lld%lld",&x,&a,&y,&b);
//        if(a>b)swap(a,b),swap(x,y);
//        ll gap = b-a;
//        double tmp = x*1.0/y;
//        double resa = log(x)/log(tmp)*gap;
//        double resb = log(y)/log(tmp)*gap;
//        ll ra = round(resa), rb = round(resb);
        //cout << gap << " " << ra-rb <<endl;
        if(fabs(a*log(x*1.0L)-b*log(y*1.0L)) < eps)printf("Yes\n");//注意这里，用1.0L把x转为long double
        else printf("No\n");
    }
    return 0;
}
/*
4
2 20 4 10
20 20 20 20
20 21 21 20
32768 32768 1048576 24576
*/
```