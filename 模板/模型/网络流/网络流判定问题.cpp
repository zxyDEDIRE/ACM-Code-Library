/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
	https://www.luogu.com.cn/problem/P2754
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
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t,tot;
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*n);
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool bfs(int s,int t)
{
	memset(dep+1,0,sizeof(int)*tot);
	queue<int>q;
	dep[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==t)return true;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dep[y]==0&&w>0)
				q.push(y),dep[y]=dep[x]+1;
		}
	}
	return false;
}
int dfs(int x,int flow,int t)
{
	if(x==t)return flow;
	int out=flow;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int w=edge[i].w;
		if(w!=0&&dep[y]==dep[x]+1)
		{
			int tmp=dfs(y,min(out,w),t);
			edge[i].w-=tmp;
			edge[i^1].w+=tmp;
			out-=tmp;
			if(!out)break;
		}
	}
	if(out==flow)dep[x]=0;
	return flow-out;
}
int DINIC(int s,int t)
{
	int ans=0;
	while(bfs(s,t))
		ans+=dfs(s,INF,t);
	return ans;
}
vector<int>v[maxn];
int a[maxn];
int p[maxn];
int h[maxn];
int num;
void solve()
{
	cin>>n>>m>>num;
	for(int i=1;i<=m;i++)
	{
		cin>>h[i];
		int cnt;cin>>cnt;
		while(cnt--){
			int x;cin>>x;
			v[i].push_back(x);
		}
	}
	s=++tot;
	t=++tot;
	init();
	int ans=0;
	for(int i=1;i<=n;i++)
		a[i]=++tot;
	for(int k=1;;k++)
	{
		for(int i=1;i<=n;i++)//还是呆在这一站点
		{
			p[i]=++tot;
			add(a[i],p[i],INF);
			add(p[i],a[i],0);
		}
		for(int i=1;i<=m;i++)
		{
			int len=v[i].size();
			int x=v[i][(k-1)%len];
			int y=v[i][(k)%len];
			if(x==0)x=s;
			else if(x==-1)x=t;
			else x=a[x];

			if(y==0)y=s;
			else if(y==-1)y=t;
			else y=p[y];

			add(x,y,h[i]);
			add(y,x,0);
		}
		ans+=DINIC(s,t);
		if(ans>=num){
			cout<<k<<endl;
			return ;
		}
		if(k>1000){
			cout<<0<<endl;
			return ;
		}
		for(int i=1;i<=n;i++)
			a[i]=p[i];
	}
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
0 1 2
1 2 -1

*/