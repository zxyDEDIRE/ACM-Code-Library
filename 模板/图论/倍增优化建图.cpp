/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
namespace Flow{
	struct Edge{
		int to,next,w;
	}edge[maxn];
	int head[maxn],cnt=1;
	int dep[maxn];
	int s,t,tot;
	void init(){
		memset(head+1,0,sizeof(int)*tot);
		cnt=1;
		tot=0;
	}
	void add(int from,int to,int w)
	{
		edge[++cnt].w=w;
		edge[cnt].to=to;
		edge[cnt].next=head[from];
		head[from]=cnt;
	}
	void Add(int u,int v,int w)
	{
		add(u,v,w);
		add(v,u,0);
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
	int DINIC()
	{
		int ans=0;
		while(bfs(s,t))
			ans+=dfs(s,INF,t);
		return ans;
	}
}
vector<pii>v[maxn];
int id[maxn][20];
int f[maxn][20];
int val[maxn];
int dep[maxn];
int n,m;
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;f[x][0]=fa;
	for(int i=1;i<=15;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(auto [y,w]:v[x])
		if(y!=fa)
			val[y]=w,dfs(y,x);
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for (int j = 0, D = dep[x] - dep[y]; D; ++j, D >>= 1)
		if (D & 1) x = f[x][j];
	if(x==y)return x;
	for (int j = 15; ~j; --j)
		if (f[x][j] != f[y][j])
			x = f[x][j], y = f[y][j];
	return f[x][0];
}
int find(int x,int y){
    if(id[x][y])return id[x][y];
    id[x][y]=++Flow::tot;
    if(!y){
    	Flow::Add(id[x][y],Flow::t,val[x]);
    }
    else {
    	Flow::Add(id[x][y],find(x,y-1),INF);
    	Flow::Add(id[x][y],find(f[x][y-1],y-1),INF);
    }
    return id[x][y];
}
void solve()
{
	cin>>n>>m;
	Flow::init();
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}
	Flow::s=1;Flow::t=2;Flow::tot=2;
	int ans=0;
	dfs(1,0);
	while(m--)
	{
		int x,y,a,b;
		cin>>x>>y>>a>>b;a-=b;
		if(a<=0)continue;
		ans+=a;
		int now=++Flow::tot;
		Flow::Add(Flow::s,now,a);
		int lca=LCA(x,y);
		for(int i=14;i>=0;i--)
			if((dep[x]-dep[lca])>>i&1)
			{
				Flow::Add(now,find(x,i),INF);
				x=f[x][i];
			}
		for(int i=14;i>=0;i--)
			if((dep[y]-dep[lca])>>i&1)
			{
				Flow::Add(now,find(y,i),INF);
				y=f[y][i];
			}
	}
	ans-=Flow::DINIC();
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}