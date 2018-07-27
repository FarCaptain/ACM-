毒瘤场，英语阅读场

A. n 个 字母，要取k个组成一个火箭（什么鬼），规则是字典顺序递增而且相邻两个字母字典序相差必须大于1，取a的字典序为1，z为26，然后要求最小的火箭的值是多少？

这道题光荣的fst了，感觉自己的能力真的很差啊。这种“快速确定题意->确定解法->快速写出没有bug的代码“的能力啊。pat跟cf都暴露很多啊，总得来说就是码力不行啊。
fst的原因就是k=1的时候我的退出条件是延迟的，于是就多加了一个。

``` cpp
#include <bits/stdc++.h>
using namespace std;
int aa[60];
int main()
{
    string str;
    int n, k;
    cin >> n >> k;
    cin >> str;
    int len = str.length();
    for(int i = 0; i < n; i++){
        aa[i] = str[i]-'a'+1;
    }
    sort(aa,aa+n);
//    for(int i = 0; i < n; i++){
//        printf("%c",aa[i]+'a'-1);
//    }
    int sum = aa[0];
    int cnt = 1;
    int pre = 0;
    for(int i = 1; i < n; i++){
        if(cnt==k)break;
        if(aa[i]-aa[pre]<=1)continue;
        else {
            sum+=aa[i];
            cnt++;
            pre = i;
        }
    }
    if(cnt<k){printf("-1\n");return 0;}
    printf("%d\n",sum);
    return 0;
}

```
B 随便二分

C. 推公式啊
这题就是说有n个星球，其中1号是地球，n号是火星，然后就先从地球出发，在2号着陆，再从2出发……最后在地球着陆。然后烧油……给个链接你自己看吧。
[1011C][1]
这题倒着模拟一遍啊，然后就有公式了。注意什么时候不能飞的条件啊，这题不错啊，暴露了我的数学水平，想了好久，听说顺序还可以打乱呢

``` cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double a[1005],b[1005];

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i = 0; i <n; i++){
        scanf("%lf",&a[i]);
        if(a[i]==1){
            printf("-1\n");
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        scanf("%lf",&b[i]);
        if(b[i]==1){
            printf("-1\n");
            return 0;
        }
    }

    double tmp = m;
    double res = m;
    res += res/(a[0]-1);
    //cout << res <<endl;
    for(int i = n-1; i > 0; i--){
        res += res/(b[i]-1);
        //cout << res << endl;
        res += res/(a[i]-1);
        //cout << res << endl;
    }
    res += res/(b[0]-1);
    //m+=res;
    //cout << res-m <<endl;
    //cout << a[0] <<" " <<res <<endl;
    printf("%.10f",res-m);
    return 0;
}
```

D.交互题，二分

E. 这题有点意思。数论
[传送][2]
贝祖定理是可以推广的n个数上的，就是说 `Σxi*ai = gcd(ai)`有解，而且等式右面一定是gcd的倍数，然后考虑同余意义(modk)下的这个方程，如果解有负数就偏移k直到为正就好了。

``` cpp
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    while(b){
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}
int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    int tmp, mo;
    scanf("%d",&tmp);
    mo = tmp;
    for(int i = 1; i < n; i++){
        scanf("%d",&tmp);
        mo = gcd(mo, tmp);
    }
    set<int> ans;
    long long res = mo;
    for(int i = 0; i<k; i++)
    {
        //cout << res <<endl;
        ans.insert(res%k);
        res%=k;
        res+=mo*1LL;
    }
    int sz = ans.size();
    printf("%d\n",sz);
    int cnt = 0;
    for(set<int>::iterator it = ans.begin(); it != ans.end(); ++it){
        ++cnt;
        printf("%d%c",*it,(cnt==sz)?'\n':' ');
    }
    return 0;
}

```

F不想看啊



  [1]: http://codeforces.com/contest/1011/problem/C
  [2]: http://codeforces.com/contest/1011/problem/E