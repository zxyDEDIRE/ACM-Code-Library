#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f;
const int maxn=1e6+7;
int head[maxn],cnt;
bool vis[maxn];
int dis[maxn];
int in[maxn];
int n,m;
struct Edge{
	int to,next,w;
}edge[maxn];
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int spfa(int sa)
{
	queue<int>q;
	q.push(sa);
	vis[sa]=1;
	memset(dis,-INF,sizeof(dis));
	dis[sa]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]<dis[x]+edge[i].w)
			{
				dis[y]=dis[x]+edge[i].w;
				if(!vis[y])
				{
					in[y]++;
					if(in[y]==n)return -1;
					vis[y]=1;
					q.push(y);
				}
			}
		}
	}
}
signed main()
{
	cin>>n>>m;
	
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		add(u-1,v,w);
	}
	for(int i=0;i<n;i++)add(i,i+1,0);
	for(int i=0;i<n;i++)add(i+1,i,-1);
	spfa(0);
	cout<<dis[n];
}
/*
a-b<=c add(b,a,c)
求最短路

a-b>=c add(b,a,c)
求最长路
或add(a,b,-c) 

a-b==c
add(b,a,c)
add(a,b,-c)
*/


