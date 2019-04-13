#include <bits/stdc++.h>
#define rep(op,ed) for(int i=op;i<ed;i++)
using namespace std;
int main()
{
    int n, k;
    char str[2005];
    int nm[26] = {0};
    scanf("%d%d",&n,&k);
    scanf("%s",str);
    rep(0,n){
        nm[str[i]-'a']++;
    }
    int minn = 3000, id;
    rep(0,26){
        minn = min(minn,nm[i]);
        id = i;
    }
    if(nm[id]>k)printf("WRONGANSWER\n");
    else {
        for(int i=0;i<n;i++){
            if(str[i]==id+'a')continue;
            res[i] = id+'a';

        }
    }
    return 0;
}
