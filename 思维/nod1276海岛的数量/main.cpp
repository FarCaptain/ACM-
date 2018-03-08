#include <bits/stdc++.h>
using namespace std;
struct node{
    int v, id;
    bool operator < (node &tmp){return v < tmp.v;}
};
node arr[50005], que[50005];
int ans[50005];
bool vis[50005];//false
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i].v);
        arr[i].id = i;
    }
    for(int j = 0; j < q; j++){
        scanf("%d",&que[j].v);
        que[j].id = j;
    }
    sort(arr,arr+n); sort(que,que+q);
    int i = 0, cnt = 1;
    for(int j = 0; j < q; j++){
        for(;arr[i].v<=que[j].v&&i<n;i++){
            int ind = arr[i].id;
            //edging
            if(ind==0){
                if(vis[1])
                    cnt--;
            }
            else if(ind==n-1){
                if(vis[n-2])
                    cnt--;
            }
            else {//mid
                if(vis[ind-1]&&vis[ind+1]) cnt--;
                else if(!vis[ind-1]&&(!vis[ind+1])) cnt++;
            }
            vis[ind] = true;
        }
        ans[que[j].id] = cnt;
        //cout << "wtf";
    }
    //cout << q;
    for(int j = 0; j < q; j++){
        printf("%d\n",ans[j]);
    }
    return 0;
}
