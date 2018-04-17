模板题，不多说
这题用gets会全部WA掉，不知道为啥，尽量避免用吧
```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
char txt[maxn], pat[maxn];
int nxt[maxn];
void getNext()
{
    int len = strlen(pat);
    int ind = 0;
    nxt[0] = 0;
    for(int i = 1; i < len; ){
        if(pat[i]==pat[ind]){
            nxt[i] = ind+1;
            ind++; i++;
        }
        else {
            if(ind!=0){
                ind = nxt[ind-1];
            }
            else {
                nxt[i] = 0;
                i++;
            }
        }
    }
}
//13--40
void kmp()
{
    getNext();
    int lent = strlen(txt), lenp = strlen(pat);
    //cout  << lent <<lenp;
    int i=0, j=0;
    while(true){
        while(i<lent && j<lenp){
            if(txt[i]==pat[j]){
                i++; j++;
            }
            else {
                if(j!=0){
                    j = nxt[j-1];
                }
                else {
                    i++;
                }
            }

        }
        if(j==lenp){
            printf("%d\n",i-lenp+1);
            i = i-lenp+1; j = 0;
        }
        if(i==lent)return;
    }
}

int main()
{
//    gets(txt); gets(pat);
    cin >> txt >> pat;
    kmp();
    int len = strlen(pat);
    for(int i = 0; i < len; i++){
        printf("%d%c",nxt[i],(i==len-1)?'\n':' ');
    }
    return 0;
}
``

