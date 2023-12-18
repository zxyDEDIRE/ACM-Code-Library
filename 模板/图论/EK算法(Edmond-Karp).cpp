/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct Edge{
	int to,next;ll w;
}edge[maxn];
int head[maxn],cnt;
ll flow[maxn],last[maxn];
int n,m,s,t;
void add(int from,int to,ll w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int bfs()
{
	memset(last+1,-1,sizeof(int)*n);
	queue<int>q;
	q.push(s);
	flow[s]=INF;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==t)
			break;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			ll w=edge[i].w;
			if(w>0&&last[y]==-1)
			{
				last[y]=i;
				flow[y]=min(flow[x],w);
				q.push(y);
			}
		}
	}
	return last[t]!=-1;
}
ll EK()
{
	ll ans=0;
	while(bfs())
	{
		ans+=flow[t];
		for(int i=t;i!=s;i=edge[last[i]^1].to)
		{
			edge[last[i]].w-=flow[t];
			edge[last[i]^1].w+=flow[t];
		}
	}
	return ans;
}
void solve()
{
	cin>>n>>m>>s>>t;
	cnt=1;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,0);
	}
	cout<<EK()<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}