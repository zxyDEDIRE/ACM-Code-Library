/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
	随便搞
	https://www.luogu.com.cn/problem/P4013
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct node{
	int to,next,w,c;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn],flow[maxn],last[maxn];
bitset<maxn>vis;
int n,m,s,t,tot;
void init(){
	memset(head+1,0,sizeof(int)*tot);
	cnt=1;
	tot=0;
}
void add(int from,int to,int w,int c)
{
	edge[++cnt].w=w;
	edge[cnt].c=c;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool spfa(int s,int t)
{
	memset(dis+1,INF,sizeof(int)*tot);
	memset(last+1,-1,sizeof(int)*tot);
	vis.reset();
	queue<int>q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	flow[s]=INF;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			int c=edge[i].c;
			if(w>0&&dis[y]>dis[x]+c)
			{
				dis[y]=dis[x]+c;
				last[y]=i;
				flow[y]=min(flow[x],w);
				if(!vis[y])
					q.push(y),vis[y]=1;
			}
		}
	}
	return last[t]!=-1;
}
int MCMF(int s,int t)
{
	int maxf=0,maxc=0;
	while(spfa(s,t))
	{
		maxf+=flow[t];
		maxc+=flow[t]*dis[t];
		for(int i=t;i!=s;i=edge[last[i]^1].to)
		{
			edge[last[i]].w-=flow[t];
			edge[last[i]^1].w+=flow[t];
		}
	}
	//cout<<maxf<<" "<<maxc<<endl;
	return -maxc;
}
const int N=50;
int out[N][N];
int in[N][N];
int mp[N][N];
void A()
{
	init();
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m+i-1;j++)
		{
			int x;cin>>x;
			mp[i][j]=x;
			out[i][j]=++tot;
			in[i][j]=++tot;
			add(in[i][j],out[i][j],1,-x);
			add(out[i][j],in[i][j],0,x);
			if(i==1)
			{
				add(s,in[i][j],1,0);
				add(in[i][j],s,0,0);
			}
			if(i==n)
			{
				add(out[i][j],t,INF,0);
				add(t,out[i][j],0,0);
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m+i-1;j++)
		{
			add(out[i][j],in[i+1][j],1,0);
			add(in[i+1][j],out[i][j],0,0);

			add(out[i][j],in[i+1][j+1],1,0);
			add(in[i+1][j+1],out[i][j],0,0);
		}
	}
	int ans=0;
	ans=MCMF(s,t);
	cout<<ans<<endl;
}
void B()
{
	init();
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m+i-1;j++)
		{
			int x=mp[i][j];
			out[i][j]=++tot;
			in[i][j]=++tot;
			add(in[i][j],out[i][j],INF,-x);
			add(out[i][j],in[i][j],0,x);
			if(i==1)
			{
				add(s,in[i][j],1,0);
				add(in[i][j],s,0,0);
			}
			if(i==n)
			{
				add(out[i][j],t,INF,0);
				add(t,out[i][j],0,0);
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m+i-1;j++)
		{
			add(out[i][j],in[i+1][j],1,0);
			add(in[i+1][j],out[i][j],0,0);

			add(out[i][j],in[i+1][j+1],1,0);
			add(in[i+1][j+1],out[i][j],0,0);
		}
	}
	int ans=0;
	ans=MCMF(s,t);
	cout<<ans<<endl;
}
void C()
{
	init();
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m+i-1;j++)
		{
			int x=mp[i][j];
			out[i][j]=++tot;
			in[i][j]=++tot;
			add(in[i][j],out[i][j],INF,-x);
			add(out[i][j],in[i][j],0,x);
			if(i==1)
			{
				add(s,in[i][j],1,0);
				add(in[i][j],s,0,0);
			}
			if(i==n)
			{
				add(out[i][j],t,INF,0);
				add(t,out[i][j],0,0);
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m+i-1;j++)
		{
			add(out[i][j],in[i+1][j],INF,0);
			add(in[i+1][j],out[i][j],0,0);

			add(out[i][j],in[i+1][j+1],INF,0);
			add(in[i+1][j+1],out[i][j],0,0);
		}
	}
	int ans=0;
	ans=MCMF(s,t);
	cout<<ans<<endl;
}
void solve()
{
	cin>>m>>n;
	A();
	B();
	C();
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}