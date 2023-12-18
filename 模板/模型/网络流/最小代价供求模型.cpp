/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
	https://www.luogu.com.cn/problem/P4016
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct Edge{
	int to,next,w,c;
}edge[maxn];
int head[maxn],cnt=1;
int dis[maxn],flow[maxn],last[maxn];
bitset<maxn>vis;
int p[maxn];
int n,m,s,t;
void init()
{
	cnt=1;
	memset(head+1,0,sizeof(int)*t);
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
	memset(dis+1,INF,sizeof(int)*t);
	memset(last+1,-1,sizeof(int)*t);
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
			if(w&&dis[y]>dis[x]+c)
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
void MCMF(int s,int t)
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
	cout<<maxc<<endl;
	//cout<<maxf<<endl;
}
void solve()
{
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],sum+=p[i];
	sum/=n;
	s=n+1;
	t=n+2;
	init();
	for(int i=1;i<=n;i++)
	{
		if(p[i]>sum)
		{
			add(s,i,p[i]-sum,0);
			add(i,s,0,0);
		}
		if(p[i]<sum)
		{
			add(i,t,sum-p[i],0);
			add(t,i,0,0);
		}

		for(int j=1;j<=n;j++)
		{
			if(p[i]>sum&&p[j]<sum)
			{
				int x=i,y=j;
				if(x>y)swap(x,y);
				int c=min(y-x,n+x-y);
				add(i,j,INF,c);
				add(j,i,0,-c);
			}
		}
	}
	MCMF(s,t);
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
/*
17 9 14 16 4
5  -3 2 4  -8
*/