/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
	https://www.luogu.com.cn/problem/P2766
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
int out[maxn];
int dp[maxn];
int in[maxn];
int p[maxn];
int n,m,s,t,tot;
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*tot);
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
void solve()
{
	cin>>n;
	if(n==1){
		cout<<1<<endl<<1<<endl<<1;
		return ;
	}
	for(int i=1;i<=n;i++)
		cin>>p[i],dp[i]=1;

	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			if(p[i]>=p[j])
				dp[i]=max(dp[i],dp[j]+1);
	int len=0;
	for(int i=1;i<=n;i++)
		len=max(len,dp[i]);
	cout<<len<<endl;

	s=1;
	t=2;
	tot=2;
	for(int i=1;i<=n;i++)
	{
		in[i]=++tot;
		out[i]=++tot;
		add(in[i],out[i],1);
		add(out[i],in[i],0);

		if(dp[i]==1)
		{
			add(s,in[i],1);
			add(in[i],s,0);
		}
		

		if(dp[i]==len)
		{
			add(out[i],t,1);
			add(t,out[i],0);
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(p[j]>=p[i]&&dp[j]==dp[i]+1)
			{
				add(out[i],in[j],1);
				add(in[j],out[i],0);
			}
		}
	}
	int ansa=DINIC(s,t);
	cout<<ansa<<endl;

	add(in[1],out[1],INF);
	add(out[1],in[1],0);

	add(s,in[1],INF);
	add(in[1],s,0);

	

	if(dp[n]==len)
	{
		add(in[n],out[n],INF);
		add(out[n],in[n],0);

		add(out[n],t,INF);
		add(t,out[n],0);
	}
	

	int ansb=DINIC(s,t);
	cout<<ansa+ansb<<endl;



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