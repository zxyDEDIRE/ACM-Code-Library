/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
	https://www.luogu.com.cn/problem/P2763
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
int head[maxn],cnt;
int dep[maxn];
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

	// edge[++cnt].w=0;
	// edge[cnt].to=from;
	// edge[cnt].next=head[to];
	// head[to]=cnt;
}
bool bfs(int s,int t)
{
	memset(dep+1,0,sizeof(int)*t);
	queue<int>q;
	q.push(s);
	dep[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==t)return true;
		for(int i=head[x];i;i=edge[i].next)
		{
			int w=edge[i].w;
			int y=edge[i].to;
			if(w&&!dep[y])
				dep[y]=dep[x]+1,q.push(y);
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
		if(w&&dep[y]==dep[x]+1)
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
int a[maxn],b[maxn];
void solve()
{
	cin>>n>>m;
	s=n+m+1;
	t=n+m+2;
	init();
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int w;cin>>w;
		sum+=w;
		add(s,i,w);
		add(i,s,0);
	}
	for(int i=1;i<=m;i++)
	{
		int w;cin>>w;
		add(i+n,t,w);
		add(t,i+n,0);
		for(int j=1;j<=n;j++)
		{
			add(j,i+n,1);
			add(i+n,j,0);
		}
	}
	int ans=DINIC(s,t);
	if(ans!=sum){
		cout<<0<<endl;
		return ;
	}
	cout<<1<<endl;
	for(int x=1;x<=n;x++)
	{
		for(int i=head[x];i;i=edge[i].next)
		{
			if(edge[i].w==0)
				cout<<edge[i].to-n<<" ";
		}
		cout<<endl;
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