这题大意就是给你一串字符，要求你补充最少的字符，使该串拥有至少两个（最小）循环节。

**是kmp算法很重要的一条应用**，利用next数组。

> 重要性质：最小循环节长度 = len - next [len-1];

```cpp
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 100005;
int nxt[maxn];
char pat[maxn];
int len;
void getNext()
{
    //int len = strlen(pat);
    int ind = 0;
    for(int i = 1; i < len; ){
        if(pat[ind]==pat[i]) {
            nxt[i] = ind+1;//有nxt[i]个相等，恰好也是相等的下一个位置（需要比较的位置
            ind++; i++;
        }
        else {
            if(ind!=0){
                ind = nxt[ind-1];//回溯！
            }
            else {nxt[i] = 0;i++;}
        }
    }
}

int main()
{
    int t;

    scanf("%d",&t);
    while(t--){
        scanf("%s",pat);
        len = strlen(pat);
        getNext();

        //if(nxt[len-1]==len-1){printf("0\n");continue;}//可以证明，相等的前后缀若有交集，则一定是连续相同字符
        int res = len-nxt[len-1];
        if(len%res==0 && len!=res)printf("0\n");
        else {
            printf("%d\n",res-(len%res));
        }
    }
    return 0;
}
```