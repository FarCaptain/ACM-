> n个数，任取三个数（可重复），使其和小于等于k，问总共多少种方案。

排序利用单调性~

首先想到折半枚举，n^2枚举两个数，然后第三个数二分， n^2\*logn
有更优的做法。

n枚举第一个数，然后two pointers搞后两个数，线性。大致上是，头指针在最大的最右端，尾指针在最小的最左端，如果比k-a1小那就左移头指针；大就右移左尾指针；
n^2

大概就这样啦
``` cpp
#include <bits/stdc++.h>
using namespace std;
int aa[100005];
int n, k;
int solve(int val)
{
    val = k-val;
    int l = 0, r = n-1;
    int cnt = 0;
    while(true){
        int res = aa[l]+aa[r];
        if(l>r) break;
        if(res>val)
            r--;
        else {
            //cout << "here"<<endl;
            l++;
            cnt++;
            //cout << cnt <<endl;
        }
    }
    return cnt;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; i++){
        scanf("%d",&aa[i]);
    }
    sort(aa,aa+n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += solve(aa[i]);
    }
    printf("%d\n",sum);
    return 0;
}
/*
5 6
1 3 4 5 2
*/
```
