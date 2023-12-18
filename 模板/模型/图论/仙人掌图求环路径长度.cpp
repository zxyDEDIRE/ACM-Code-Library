#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e14+7;
const int maxn=4e6+100;
struct Edge{
	int to,w,next;
}edge[maxn];
int head[maxn],cnt;
int dfn[maxn],low[maxn],indx;
stack<pii>s;
int n,m,ans;
void init()
{
	while(!s.empty())s.pop();
	for(int i=1;i<=n;i++)
	{
		dfn[i]=low[i]=head[i]=0;
	}
	cnt=1;
	indx=0;
	ans=INF;
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++indx;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			s.push({x,edge[i].w});
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x])
			{
				vector<int>g;
				pii v;
				do{
					v=s.top();s.pop();
					g.push_back(v.second);
				}while(v.first!=x);

				sort(g.begin(),g.end());

				if(g.size()==1)ans=min(ans,g[0]);
				else if(g.size()==2)ans=min(ans,g[0]+g[1]);
				else ans=min(ans,min(g[0]+g[1],g[2]));
			}
		}
		else if(dfn[x]>dfn[y]&&i!=(fa^1))
		{
			low[x]=min(low[x],dfn[y]);
			s.push({x,edge[i].w});
		}
	}
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	tarjan(1,0);
	cout<<ans<<endl;
}
signed main(){
	int size(512<<20); // 512M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size)); // YOUR CODE
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	exit(0);
}
