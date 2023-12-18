/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
	https://ac.nowcoder.com/acm/contest/34649/D
*/
/*
二分图中每个边中至少一个端点在该点集中 的 最小点集

*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int INF=1e9+7;
const int maxn=1e5;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int in[maxn];
int d[maxn];
bitset<maxn>vis;
int n,m,s,t;
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*t);
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int dfs(int x,int flow)
{
	if(x==t)return flow;
	int out=flow;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int w=edge[i].w;
		if(w!=0&&d[y]==d[x]+1)
		{
			int tmp=dfs(y,min(out,w));
			edge[i].w-=tmp;
			edge[i^1].w+=tmp;
			out-=tmp;
			if(!out)break;
		}
	}
	if(out==flow)d[x]=0;
	return flow-out;
}
bool bfs(int s,int t)
{
	memset(d+1,0,sizeof(int)*t);
	queue<int>q;
	d[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==t)return true;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(d[y]==0&&w>0)
			{
				q.push(y);
				d[y]=d[x]+1;
			}
		}
	}
	return false;
}
int DINIC(int s,int t)
{
	int ans=0;
	while(bfs(s,t))
		ans+=dfs(s,INF);
	return ans;
}
void solve()
{
	cin>>n>>m;
	s=n*2+1;
	t=n*2+2;
	init();
	for(int i=1;i<=n;i++)
	{
		add(s,i,1);
		add(i,s,0);


		add(i+n,t,1);
		add(t,i+n,0);
	}
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		add(x,y+n,1);
		add(y+n,x,0);
	}
	cout<<DINIC(s,t)<<endl;

}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}