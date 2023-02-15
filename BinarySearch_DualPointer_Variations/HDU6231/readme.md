[题目][1]

17年CCPC哈尔滨站B

直接二分第M大的“区间第K大值”，check做法如下。
check（x）：
处理出数组中所有大于等于x的值的位置，于是枚举左端点，就可以二分出大于x的值多于k个的区间的个数，这一步O(nlogn)，于是这些区间的第k大值就是大于等于x的。
然后用这些区间的数量>=m二分一下，复杂度Onlognlogn

````cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+7;
int aa[N], tmp[N], pos[N];
int n, k;
ll m;

bool check(int x)
{
    //cout << "check:"<<x<<endl;
    ll res=0;
    memset(pos,0,sizeof(pos));
    int ind = 0;
    for(int i = 0; i < n; i++){
        if(aa[i]>=x)pos[ind++] = i;
    }
    for(int s = 0; s < n; s++){
        int l = 0, r = ind-1,mid,ans=ind;
        while(l<=r){
            mid = (l+r)/2;
            if(pos[mid]>=s)r = mid-1, ans=mid;
            else l = mid+1;
        }
        //ans+k
        if(ans+k-1>=ind)continue;
        res +=  n-pos[ans+k-1];
        //cout << "s"<<s<<" "<<ind-(ans+k-1)+1<<endl;
    }

    //cout << "res=" << res << endl;
    if(res>=m)return true;
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%lld",&n,&k,&m);
        for(int i = 0; i < n; i++){
            scanf("%d",&aa[i]);
            tmp[i] = aa[i];
        }
        sort(tmp,tmp+n);///
        int l = 0, r = n-1, mid, ans;
        while(l<=r){
            mid = (l+r)/2;
            if(check(tmp[mid]))l = mid+1, ans = mid;
            else r = mid-1;
            //cout << tmp[mid]<<" ";
        }
        //cout <<endl;
        //if(check(1))cout << "skr";
        printf("%d\n",tmp[ans]);
    }
    return 0;
}

```

  [1]: http://acm.hdu.edu.cn/showproblem.php?pid=6231