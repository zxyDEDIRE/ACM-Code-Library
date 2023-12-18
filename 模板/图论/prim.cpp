#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const ull str_mod=212370440130137957ll;
const ull more=19260817;
const ull prime=233317;
const ull base=131;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct node
{
	int t;int d;
	bool operator < (const node &a) const
	{
		return d>a.d;
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
bitset<maxn>vis;
int n,m;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void prim()
{
	priority_queue<node>q;
	q.push({1,0});
	int ans=0;
	while(!q.empty())
	{
		auto [x,X]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		ans+=X;
		for(int i=head[x];i;i=edge[i].next)
			if(!vis[edge[i].to])
				q.push({edge[i].to,edge[i].w});
	}
	int flag=1;
	for(int i=1;i<=n;i++)
		if(!vis[i])flag=0;
	if(!flag)cout<<"orz"<<endl;
	else cout<<ans<<endl;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	prim();
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
