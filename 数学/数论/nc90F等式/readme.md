### 给n求 x,y
给定n，求1/x + 1/y = 1/n （x<=y）的解数。（x、y、n均为正整数） 
（1<=n<=1e9）

***
这个等式可以变形，两边同时乘 xyn，得到（n-x)(n-y) = n^2
也就是求n^2因子的对数。

Tags：质因数分解；唯一分解定理；
![9q4krt.jpg](https://s1.ax1x.com/2018/03/25/9q4krt.jpg)
n的正因子个数为
![9q4AqP.jpg](https://s1.ax1x.com/2018/03/25/9q4AqP.jpg)

```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,res=1;
        scanf("%d",&n);
        for(int i=2;i*i<=n;i++)if(n%i==0)
        {
            int cnt=0;
            while(n%i==0)n/=i,cnt++;
            res*=2*cnt+1;//n^2质因子数翻倍，这个公式来自唯一分解定理
        }
        if(n>1)res*=3;//最后剩下大质数
        printf("%d\n",(res+1)/2);// n,n 这对因子只算了一次
    }
    return 0;
}
```
还是不太懂…
帖一道相似的题
https://blog.csdn.net/selinafelton/article/details/51893939
