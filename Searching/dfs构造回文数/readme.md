### 写一道题想到的，要求从小到大输出回文数

```cpp
vector<int> res;
int rr;
void dfs(int pos, int len)
{
    double id = (len+1)*1.0/2;
    if(len>10)return;
    if(pos>id){
        rr = 0;
        for(int i = 1; i <= len; i++)
        {
            rr = rr*10+res[i];
        }
        printf("%d\n",rr);
        return;
    }
    for(int i = 0; i < 10; i++){
        if(pos==1&&i==0)continue;
        res[pos] = i;
        //cout << pos <<" " <<  id <<endl;
        res[id*2-pos] = i;
        dfs(pos+1,len);
    }
    dfs(1,len+1);
}
```
两维就好。