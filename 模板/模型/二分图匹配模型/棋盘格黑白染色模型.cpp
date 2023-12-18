/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
	https://ac.nowcoder.com/acm/contest/34649/F

	用长度为2宽度为1的牌覆盖棋盘
	将棋盘染成黑白色
	那么牌的一端为黑色，另一端为白色
	那么可以最大二分匹配

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
}
bool bfs(int s,int t)
{
	memset(dep+1,0,sizeof(int)*t);
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
int f(int x,int y){
	return n*(x-1)+y;
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool vis[111][111];
int mp[111][111];
int tot;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		vis[x][y]=1;
	}
	s=n*n+1;
	t=n*n+2;
	init();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(vis[i][j])continue;
			if((i+j)&1)
			{
				add(s,f(i,j),1);
				add(f(i,j),s,0);
				for(int k=0;k<4;k++)
				{
					int x=i+dx[k];
					int y=j+dy[k];
					if(x<1||x>n||y<1||y>n)continue;
					add(f(i,j),f(x,y),1);
					add(f(x,y),f(i,j),0);
				}
			}
			else
			{
				add(f(i,j),t,1);
				add(t,f(i,j),0);
			}
		}
	}
	cout<<DINIC(s,t)<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}