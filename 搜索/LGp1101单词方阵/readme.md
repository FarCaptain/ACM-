> 给一nXn的字母方阵，内可能蕴含多个“yizhong”单词。单词在方阵中是沿着同一方向连续摆放的。摆放可沿着8个方向的任一方向，同一单词摆放时不再改变方向，单词与单词之间可以交叉,因此有可能共用字母。输出时，将不是单词的字母用“*”代替，以突出显示单词。例如：

![CMmM9O.png](https://s1.ax1x.com/2018/04/21/CMmM9O.png)
	

这道题就是暴搜，但是如果实现思路太过暴力，代码可能会太长写起来很慢。这道题讲讲实现：
想办法用一个函数做所有的事情，用参数控制不同：**除了x,y,还有控制搜索方向和目标字符的参数。**
然后呢，输出结果的部分如果再判一次是不是完整的串就很麻烦，想办法**利用回溯处理，反过来标记结果**。

***
上代码，因为回溯那里判断越界的优先级逻辑出问题WA了一发。

```cpp
#include <bits/stdc++.h>
using namespace std;
char mx[101][101];
char res[101][101];
string str = "yizhong";//0~6
int n;
int dx[8]={-1,1,1,-1,0,0,1,-1};
int dy[8]={-1,1,-1,1,1,-1,0,0};
bool check(int x, int y)
{
    if(x>=n||x<0||y>=n||y<0)return false;
    return true;
}
//bool flag = false;
bool dfs(int x, int y, int ind, int fx)
{
    //backtrack_terminal
    if(ind==7)return true;
    if(!check(x,y))return false;//一定要想好这几个条件的优先级
    if(mx[x][y]!=str[ind])return false;
    //cout << "mx " <<x<<" "<<y<<" = ";
    //cout << mx[x][y] <<endl;
    int nx = x + dx[fx];
    int ny = y + dy[fx];

    bool flag = dfs(nx,ny,ind+1,fx);
    if(flag){//backtrack
        res[x][y] = str[ind];
        return true;
    }

    return false;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mx[i][j];
            res[i][j] = '*';
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mx[i][j]=='y')
            for(int k = 0; k < 8; k++)
                dfs(i,j,0,k);
        }
    }
    for(int i = 0; i < n; i++){
        cout << res[i] <<endl;
    }
    return 0;
}
```