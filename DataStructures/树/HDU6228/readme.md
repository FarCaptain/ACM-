[题目][1]

对于每一条边，能够成为k种染色的公共边，当且仅当这条边两端点为根的子树大小大于等于k。dfs统计一下= =

```cpp
#include <bits/stdc++.h>
using namespace std;
vector<int> vec[200003];
struct _edg{
    int u,v;
}edg[200003];

bool used[200003];
int sz[200003];
void dfs(int s)
{
    //cout << "s"<<s <<endl;
    sz[s] = 1;
    used[s] = true;
    if(vec[s].empty()){
        return;
    }
    //else sz[s] = 1;
    for(int i = 0; i < vec[s].size(); i++)if(!used[vec[s][i]]){
        dfs(vec[s][i]);
        sz[s]+=sz[vec[s][i]];
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n, k;
        scanf("%d%d",&n,&k);
        int _u,_v;
        for(int i = 1; i <= n; i++)vec[i].clear();
        memset(used,0,sizeof(used));

        for(int i = 0; i < n-1; i++){
            scanf("%d%d",&_u,&_v);
            if(_u>_v)swap(_u,_v);
            vec[_u].push_back(_v);
            //vec[_v].push_back(_u);
            edg[i].u = _u;
            edg[i].v = _v;
        }
        dfs(1);
        int cnt = 0;
        for(int i = 0; i < n-1; i++){
            if(n-sz[edg[i].v]>=k&&(sz[edg[i].v]>=k))cnt++;
            //cout <<"h"<<sz[1]-sz[edg[i].u]+1<<" "<<sz[edg[i].v]<<endl;
        }
        //cout << sz[1]<<endl;
        printf("%d\n",cnt);
    }
    return 0;
}
```


  [1]: http://acm.hdu.edu.cn/showproblem.php?pid=6228