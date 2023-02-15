
### Naive Operations

An interesting application of Segment Tree from 2018 Multi-University Training Contest 2.

The Problem is now a available on HDUOJ-ID6315
Problem Link ：[HDUOJ 6315](http://acm.hdu.edu.cn/showproblem.php?pid=6315)

```cpp
//Σ(1/i)~logn, ai<q, Number of query = Num(query)~q*logn ∴query process~n*logn*logn


#include <bits/stdc++.h>
#define ls rt<<1
#define rs rt<<1|1
using namespace std;
typedef long long ll;
const int MAXN = 100010;
//Segment tree
struct node{
    ll mv;//offsets
    ll lz;//lazy tag(for mv)
    ll val;//value of a/b
    ll bb;//b_i orginal value
}bat[MAXN<<2];
int b[MAXN];
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
    bat[ls].mv-=bat[rt].lz;
    bat[ls].lz+=bat[rt].lz;
	bat[rs].mv-=bat[rt].lz;
    bat[rs].lz+=bat[rt].lz;
    bat[rt].lz = 0;
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
    else if(l==r)return;//leaf node
    if(bat[rt].lz>0) pushdown(rt);//refresh lazy tags

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
    while(scanf("%d%d",&n,&q)!=EOF){//multiple test cases
        for(int i = 1; i <= n; i++)scanf("%d",&b[i]);
        build(1,1,n);
        char op[10];
        int le,ri;
        while(q--){
            scanf("%s%d%d",op,&le,&ri);
            if(op[0]=='a')upd(1,1,n,le,ri);
            else {
                ll res = query(1,1,n,le,ri);
                printf("%lld\n",res);
            }
        }
    }
    return 0;
}

```