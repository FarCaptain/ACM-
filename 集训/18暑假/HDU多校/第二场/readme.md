## 1007 Naive Operations
[HDU 6316 ][1]
原来这才是数据结构。
首先，分析完题目，思路是有的，就是维护一个初始值是bi的数列，然后每次更新就相当于在区间上-1。于是每次更新完统计区间上0的个数就加进另一棵树，哪里是0就加到哪个点上，然后再把那个点置回bi就行了……
然鹅这样复杂度是多少呢，好像取决于点的更新。
而且这样维护两棵树又要取下标，怎么写啊。

1. 复杂度计算：其实复杂度就取决于总共的 a/b 的值是多少，有多少就要进行几次单点的更新。
显然ai < q，那么总次数可以写成 `Σq/bi`，这个东西的分母根据**调和级数部分和**是趋近于logn的，那么更新的复杂度有 q\*logn，每次更新的复杂度又是logn级别的那么总复杂度 nlognlogn 

2. 虽然两棵树也可行，但是写起来很难啊不会啊。考虑用一棵树维护*偏移量* （决定什么时候+1）的最小值，还有*每个节点上的值*，每次更新时，在搜到区间最小值为0的区间，就一直dfs下去直到找到为0的点，然后在这个点上直接做更新，仔细想想，这样不会比轮询最小值要慢的。

``` cpp
#include <bits/stdc++.h>
#define ls rt<<1
#define rs rt<<1|1
using namespace std;
typedef long long ll;
struct node{
    ll mv;//偏移量
    ll lz;//这个lazy是给mv打的
    ll val;//真实值
    ll bb;
}bat[100010<<2];
int b[100010];
int n,q;
void pushup(int rt)
{
    bat[rt].mv = min(bat[ls].mv, bat[rs].mv);
    bat[rt].val = bat[ls].val + bat[rs].val;
}

void build(int rt, int l, int r)
{
    int mid = (l+r)>>1;
    bat[rt].lz = bat[rt].val = 0;
    if(l==r){
        bat[rt].mv = bat[rt].bb = b[l];
        return;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(rt);
}

void pushdown(int rt)
{
    //if(bat[rt].lz){
        bat[ls].mv-=bat[rt].lz;
        bat[ls].lz+=bat[rt].lz;

        bat[rs].mv-=bat[rt].lz;
        bat[rs].lz+=bat[rt].lz;
        bat[rt].lz = 0;
    //}
}

void upd(int rt, int l, int r, int ql, int qr)
{
    //if(l>r)return;
    int mid = (l+r)>>1;
    if(bat[rt].mv>1&&ql<=l&&r<=qr){
        bat[rt].mv--;
        bat[rt].lz += 1;
        return;
    }
    if(bat[rt].mv==1&&l==r){
        bat[rt].val++;
        bat[rt].mv = bat[rt].bb;
        bat[rt].lz = 0;
        return;
    }
    else if(l==r)return;//叶子
    if(bat[rt].lz>0) pushdown(rt);

    if(ql<=mid)upd(ls,l,mid,ql,qr);
    if(qr>mid)upd(rs,mid+1,r,ql,qr);
    pushup(rt);
}

ll query(int rt, int l, int r, int ql, int qr)
{
    //if(l>r)return 0;
    int mid = (l+r)>>1;
    if(ql<=l&&r<=qr){
        return bat[rt].val;
    }

    //pushdown(rt);
    ll v1=0, v2=0;
    if(ql<=mid)v1 = query(ls,l,mid,ql,qr);
    if(qr>mid)v2 = query(rs,mid+1,r,ql,qr);
    return v1+v2;
}

int main()
{
    while(scanf("%d%d",&n,&q)!=EOF){
        for(int i = 1; i <= n; i++)scanf("%d",&b[i]);
        build(1,1,n);
        char op[10];
        int le,ri;
        while(q--){
            scanf("%s%d%d",op,&le,&ri);
            if(op[0]=='a')upd(1,1,n,le,ri);
            else {
                long long res = query(1,1,n,le,ri);
                printf("%lld\n",res);
            }
        }
    }
    return 0;
}
```
调了挺长时间的，注意一个细节：
这棵线段树在upd的时候回一直向下dfs，所以要在每个叶子结点上写递归出口。


  [1]: http://hdu.hustoj.com/showproblem.php?pid=6315