#include <cstdio>
#include <vector>
#include <ctype.h>
using namespace std;
//我这辈子见过最美的模拟
vector<int> Ans[200010];
int p,cnt,n=1;

int main(){
	for(char ch=getchar();isdigit(ch);ch=getchar(),n++)
		if(ch=='1'){
			if(!p){printf("-1\n");return 0;}
			Ans[p--].push_back(n);
		}else if(p==cnt) Ans[p=++cnt].push_back(n);
		else Ans[++p].push_back(n);
	if(p<cnt){printf("-1\n");return 0;}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i){
		printf("%d ",Ans[i].size());
		for(int j=0;j<Ans[i].size();++j)
			printf("%d ",Ans[i][j]);
		printf("\n");
	}
	return 0;
}