[sauoj1068][1]

对于一个字符串，如果要求任意一个长度为 k 的子串都是回文的，那么考虑下面几种情况：
1. 如果 k 是偶数，那么字符串的每个字母都是一样的。因为对称轴在两个字母中间，两个相邻的子串对称轴中间间隔一个字母，这样对称下去就会扩展到整个串。
2. 如果 k 是奇数（1除外），那么要么每个字母都是一样的，要么整个串是两个字母交替“abab..”/"baba..."。因为对称轴是在字母上的，两个相邻的对称轴就是两个相邻的字母，所以两个相邻的字母可以不同，但是每隔一个字母都必须相同。
3. 如果 k == 1，那么任何串都行。
4. 如果 k == n，那么任意回文串都行。所以最少操作次数的回文串是定下任意一半，然后调整另外一半使两者对称。

参考标程如下：

``` cpp
#include <bits/stdc++.h>
using namespace std;
char ss[1000005];
int main()
{
//    freopen("hacker.in","r",stdin);
//    freopen("hacker.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        memset(ss,0,sizeof(ss));
        scanf("%s",ss);
        if(k==1){
            printf("0\n");
            continue;
        }
        if(k==n){
            int md=n/2,res=0;
            for(int i=0;i<md;++i){
                if(ss[i]!=ss[n-1-i])res++;
            }
            printf("%d\n",res);
            continue;
        }
        int acnt=0,bcnt=0,as=0,bs=0;
        for(int i=0;i<n;i++){
            if(ss[i]=='a')acnt++;
            else bcnt++;
            if(i&1){
                if(ss[i]!='b')as++;
                else bs++;
            }
            else {
                if(ss[i]!='a')as++;
                else bs++;
            }
        }
        int res = min(acnt,bcnt);
        if((k&1)&&k>2){
            res = min(res,min(as,bs));
        }
        printf("%d\n",res);
    }
    return 0;
}
```


  [1]: http://202.199.27.176/problem.php?id=1068