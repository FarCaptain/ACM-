#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ff[100100], sm[100100], ok[100100];
int main()
{
    int opt;
    ll n,mod ,minn, maxx;
    //string str;
    scanf("%lld%lld%lld%lld%lld",&n,&opt,&mod,&minn,&maxx);
    getchar();

    for(int t = 0; t < opt; t++){
        char str[1000];
        //getline(cin,str);
        gets(str);
        if(str[0]=='A'){
            int l, r, v;
            sscanf(str,"A %d %d %d\n",&l,&r,&v);
            ff[l]+=v; ff[r+1]-=v;
        }
        else if(str[0]=='Q'){
            int l, r, cnt = 0;
            sscanf(str,"Q %d %d\n",&l,&r);
            for(int i = 1; i <= r; i++){
                sm[i] = sm[i-1] + ff[i];
                if(i>=l&&(sm[i]*i%mod)>=minn&&(sm[i]*i%mod)<=maxx)cnt++;
            }
            printf("%d\n",cnt);
        }
    }

    for(int i = 1; i <= n; i++){
        //sm[i] = sm[i-1] + ff[i];
        ff[i]+=ff[i-1];
        ok[i] = ok[i-1];
        if((ff[i]*i%mod)>=minn&&(ff[i]*i%mod)<=maxx)ok[i]++;
    }
    int fin,l,r;
    scanf("%d",&fin);
    for(int t = 0; t<fin;t++){
        scanf("%d%d",&l,&r);
        printf("%lld\n",ok[r]-ok[l-1]);
    }
    return 0;
}
