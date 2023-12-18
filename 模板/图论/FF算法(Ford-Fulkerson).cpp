/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
bitset<maxn>vis;
int n,m,s,t;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int dfs(int x,int flow)
{
	if(x==t)
		return flow;
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int w=edge[i].w;
		int c;
		if(w>0&&!vis[y]&&(c=dfs(y,min(w,flow)))!=-1)
		{
			edge[i].w-=c;
			edge[i^1].w+=c;
			return c;
		}
	}
	return -1;
}
int FF()
{
	int ans=0,c=0;
	while((c=dfs(s,INF))!=-1)
	{
		vis.reset();
		ans+=c;
	}
	return ans;
}
void solve()
{
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,0);
	}
	cout<<FF()<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}