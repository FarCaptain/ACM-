### 题目
链接：https://www.nowcoder.com/acm/contest/16/A
来源：牛客网

FST是一名可怜的小朋友，他很强，但是经常fst，所以rating一直低迷。
但是重点在于，他非常适合ACM！并在最近的区域赛中获得了不错的成绩。
拿到奖金后FST决定买一台新笔记本，但是FST发现，在价格能承受的范围内，笔记本的内存和速度是不可兼得的。
可是，有一些笔记本是被另外一些“完虐”的，也就是内存和速度都不高于另外某一个笔记本，现在FST想统计一下有多少笔记本被“完虐”。

第一行一个正整数n，
表示笔记本的数量。接下来n行，每行两个正整数Mi，Si表示这款笔记本的内存和速度。
n ≤ 10^5, Mi,Si ≤ 10^9

### 分析
经典题，一维排序，然后第二个维度加入树状数组，由于第一维已经是有序的了，按顺序加，然后通过树状数组维护有多少第二维比它大的。
需要离散化出有序的第一维值的种类。

这道题拓展到三维仍然是可以解决的，可以使用树套树，或者使用CDQ分治解决。

### 代码
```cpp
#include <bits/stdc++.h>
using namespace std;
struct cop{
    int x, y, sum;
}aa[100005];
bool cmpx(cop a, cop b)
{
    return a.x > b.x;
}
bool cmpy(cop a, cop b)
{
    return a.y > b.y;
}

long long bit[100005];
int n;
map<int, int > mp;

long long sum(int i)
{
    long long s = 0;
    while(i>0){
        s += bit[i];
        i -= i&-i;
    }
    return s;
}

void add(int i, int x)
{
    while(i<=n){
        bit[i] += x;
        i += i&-i;
    }
}

int main()
{
    scanf("%d",&n);
    int x, y;
    int ind = 1;
    for(int i = 1; i <= n; i++){
        scanf("%d%d",&aa[i].x,&aa[i].y);
    }

    sort(aa+1,aa+n+1,cmpy);
    for(int i = 1; i <= n; i++){
        if(mp.find(aa[i].y)==mp.end()){
            mp[aa[i].y] = ind++;
        }
    }
    int res = 0;
    sort(aa+1,aa+n+1,cmpx);
    for(int i = 1; i <= n; i++){
        if(sum(mp[aa[i].y]-1))res++;
        add(mp[aa[i].y],1);
    }

    printf("%d\n",res);
    return 0;
}
```
