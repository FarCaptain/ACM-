题目直接copy
> 单词接龙是一个与我们经常玩的成语接龙相类似的游戏，现在我们已知一组单词，且给定一个开头的字母，要求出以这个字母开头的最长的“龙”（每个单词都最多在“龙”中出现两次），在两个单词相连时，其重合部分合为一部分，例如 beast和astonish，如果接成一条龙则变为beastonish，另外相邻的两部分不能存在包含关系，例如at 和 atide 间不能相连。

***
这道题首先想到字典树，但是一个词最多用两次怎么搞，标签搜索？这怎么做。
建一个图，mx(i,j)代表i串连j串的最小重合长度（为了让长度最长），那么接下来的事情就是在图上进行dfs，注意每个点可以访问两次。回溯还是挺好用的。还有就是string，``+``直接连接太爽了

```cpp
#include <bits/stdc++.h>
using namespace std;
//16:02
string str[21];
int mx[21][21];
int res = -1;
int n;
int get(string a, string b)
{
    int lena = a.length();
    int lenb = b.length();
    string pa,pb;
    int j = 0;
    for(int i = lena-1; i >= 0; i--) {
        pa = a[i]+pa;
        pb = pb+b[j];//好用啊
        if(pa==pb){
            if(j+1==lena||j+1==lenb)return 0;
            return j+1;
        }
        j++;
    }
    return 0;
}

int vis[21];
void dfs(int s,int ans)
{
    //cout << s << endl;
    res = max(res, ans);
    //cout << vis[s] << endl;
    for(int j = 0; j < n; j++){
        if(vis[j]>=2)continue;//读题
        if(mx[s][j]){
            vis[j]++;
            dfs(j,ans+str[j].length()-mx[s][j]);
            vis[j]--;//回溯
        }
    }
    return;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        //getline(cin, str[i]);
        cin >> str[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //if(i!=j)
                mx[i][j] = get(str[i],str[j]);
        }
    }
    char ch;
    cin >> ch;
    for(int i = 0; i < n; i++)if(str[i][0]==ch){
        vis[i]++;
        dfs(i,str[i].length());
        vis[i]--;
    }
    cout << res;
    return 0;
}
```

