#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int INF=10000005;
const int maxn=1e7+10;
const int N=2e4+10;
struct Edge{int to,next,w;}edge[N];
int head[N],_cnt;
int del[N],siz[N],maxson,root,sum;
int dis[N],d[N],cnt;
int ans[N],q[maxn],judge[maxn],ask[maxn];
int n,m;
void add(int from,int to,int w){
	edge[++_cnt].w=w;
	edge[_cnt].to=to;
	edge[_cnt].next=head[from];
	head[from]=_cnt;
}
void getroot(int x,int fa)
{
	siz[x]=1;
	int sx=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==fa||del[y])continue;
		getroot(y,x);
		siz[x]+=siz[y];
		sx=max(sx,siz[y]);
	}
	sx=max(sx,sum-siz[x]);
	if(sx<maxson)maxson=sx,root=x;
}
void getdis(int x,int fa)
{
	dis[++cnt]=d[x];
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==fa||del[y])continue;
		d[y]=d[x]+edge[i].w;
		getdis(y,x);
	}
}
void calc(int x)
{
	judge[0]=1;
	int p=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(del[y])continue;
		cnt=0;
		d[y]=edge[i].w;
		getdis(y,x);
		for(int j=1;j<=cnt;j++)
			for(int k=1;k<=m;k++)
				if(ask[k]>=dis[j])
					ans[k]|=judge[ask[k]-dis[j]];
		for(int j=1;j<=cnt;j++)
			if(dis[j]<INF)
				q[++p]=dis[j],judge[q[p]]=1;
	}
	for(int i=1;i<=p;i++)
		judge[q[i]]=0;
}
void divide(int x)
{
	calc(x);
	del[x]=1;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(del[y])continue;
		maxson=sum=siz[y];
		getroot(y,0);
		divide(root);
	}
}
char ch[maxn];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	for(int i=1;i<=m;i++)
		cin>>ask[i];
	maxson=sum=n;
	getroot(1,0);
	getroot(root,0);
	divide(root);
	for(int i=1;i<=m;i++)
		cout<<(ans[i]?"AYE\n":"NAY\n");
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}