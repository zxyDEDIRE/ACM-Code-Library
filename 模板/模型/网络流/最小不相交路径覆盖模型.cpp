/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
	https://www.luogu.com.cn/problem/P2765
	https://www.luogu.com.cn/problem/P2764
	最小路径覆盖问题分为最小不相交路径覆盖（每个顶点只能经过一次）和最小相交路径覆盖（定点可以经过多次）。
	后者做一次floyd传递闭包就变成了前者。而前者需要拆点，将每个点x拆为两个点x1，x2，x1作为二分图的左边点，
	x2作为二分图的右边点，然后建立一个超级源点和超级汇点，跑一遍最大流，最后用顶点数目（最初的）
	n-最大流就是最小路径的数目。（证明：一开始每个点都是独立的为一条路径，总共有n条不相交路径。
	我们每次在二分图里找一条匹配边就相当于把两条路径合成了一条路径，也就相当于路径数减少了1。
	所以找到了几条匹配边，路径数就减少了多少。所以有最小路径覆盖=原图的结点数-新图的最大匹配数。）
链接：https://www.jianshu.com/p/9a37f52c378c
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
vector<int>v[maxn];
bitset<maxn>vis;
int n,m,s,t;
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*(n*2+2));
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
	memset(dep+1,0,sizeof(int)*(n*2+2));
	queue<int>q;
	q.push(s);
	dep[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==t)return true;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(w&&!dep[y])
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
		if(w&&dep[y]==dep[x]+1)
		{
			int tmp=dfs(y,min(out,w),t);
			edge[i].w-=tmp;
			edge[i^1].w+=tmp;
			out-=tmp;
			if(!out)break;
		}
	}
	if(flow==out)dep[x]=0;
	return flow-out;
}
void dfs(int x)
{
	cout<<x<<" ";
	vis[x]=1;
	for(auto y:v[x])
		dfs(y);
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
	cin>>n>>m;
	cnt=1;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		y+=n;
		add(x,y,1);
		add(y,x,0);
	}
	s=n+n+1;
	t=n+n+2;
	for(int i=1;i<=n;i++)
	{
		add(s,i,1);
		add(i,s,0);

		add(i+n,t,1);
		add(t,i+n,0);
	}
	DINIC(s,t);
	for(int x=1;x<=n;x++)
	{
		for(int i=head[x];i;i=edge[i].next)
		{
			if(edge[i].w==0&&edge[i].to-n<=n){
				v[x].push_back(edge[i].to-n);
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
			cout<<endl;
			cnt++;
		}
	}
	cout<<cnt<<endl;
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