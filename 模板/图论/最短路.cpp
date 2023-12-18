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
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w,val;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn];
bitset<maxn>vis;
int n,m,s,t;
void add(int from,int to,int w,int val)
{
	edge[++cnt].w=w;
	edge[cnt].val=val;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij()
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	dis[s]=0;
	vis.reset();
	priority_queue<node>q;
	q.push({s,0});
	while(!q.empty())
	{
		node it=q.top();q.pop();
		int x=it.id;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].w)
			{
				dis[y]=dis[x]+edge[i].w;
				q.push({y,dis[y]});
			}
		}
	}

}
void solve()
{
	while(cin>>n>>m&&n)
	{
		for(int i=1;i<=n;i++)
			head[i]=0;
		cnt=0;
		for(int i=1;i<=m;i++)
		{
			int x,y,w,v=0;
			cin>>x>>y>>w;
			add(x,y,w,v);
			add(y,x,w,v);
		}
		s=1,t=n;
		dij();
		cout<<dis[t]<<endl;
	}
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}