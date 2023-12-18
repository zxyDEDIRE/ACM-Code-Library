/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void Euler(int x)
{
	for(int i=1;i<=tot;i++){
		while(v[x][i]){
			v[x][i]--;
			dfs(i);
			path.push_back(i);
		}		
	}
	// for(int i=head[x];i;i=edge[i].next)
	// {
	// 	if(edge[i].w==0){
	// 		edge[i].w=1;
	// 		dfs(edge[i].to);
	// 	}
	// }
	// path.push_back(x);
}
void solve()
{
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}