题目跟18年天梯赛L1-1有点像，只不过稍微加一点贪心
***
大意是，给你一串座位（字符串表示, ``.``表示空位，``*``表示被占的位置。现在有两波人，要求安排座位，让同一拨人不能相邻坐（a\*a当然可以），问最多可以坐多少人。
***

这道题，把两拨人往坐位里放，每次选择贪心地优先选择当前最多的那一拨人，然后如果不能连续就穿插另一种。如果没了就只能隔一个坐一个。
这个贪心一开始没加，WA了，还有这种题我写起来还是比较卡。码力不够。

```cpp
#include <bits/stdc++.h>
using namespace std;
char str[200005];
int main()
{
    //int pre=-1;//0a,1b,-1*
    int val[2];//a,b
    int len,a,b;
    scanf("%d%d%d",&len,&a,&b);
    val[0] = a; val[1] = b;
    getchar();
    for(int i = 0; i < len; i++){
        scanf("%c",&str[i]);
    }
    int cur = (val[0]>val[1])?0:1;
    bool flag = true;
    for(int i = 0; i < len; i++){
        if(!val[0]&&!val[1])break;
        if(str[i]=='.'){
            if(flag){
                cur = (val[0]>val[1])?0:1;
                flag = false;
                if(val[cur]==0)cur = (cur+1)%2;
                val[cur]--;
            }
            else {
                cur = (cur+1)%2;
                if(val[cur]==0)continue;
                val[cur]--;
            }
        }
        else flag = true;
    }
    int res = a-val[0]+b-val[1];
    printf("%d\n",res);
    return 0;
}
```