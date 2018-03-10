#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, r, a;
    scanf("%d%d%d",&l,&r,&a);
    int gap = abs(l-r);
    int res;
    if(gap>=a)res = min(l,r) + a;
    else{
        res = min(l,r)+gap;
        res += (a-gap)/2;
    }
    printf("%d\n",res*2);
    return 0;
}
