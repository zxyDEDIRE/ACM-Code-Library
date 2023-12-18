#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<ll,ll>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct Node{
	ll id,dis;
	bool operator<(const Node&a)const{
		return a.dis<dis;
	}
};
vector<pii>v[maxn];
bitset<maxn>vis;
ll dis[maxn];
ll p[maxn];
ll n,l,r;
void add(int x,int y,ll w){
	v[x].push_back({y,w});
}
void dij(int s)
{
	for(int i=0;i<p[1];i++)
		dis[i]=LLONG_MAX;
	priority_queue<Node>q;
	q.push({s,0});
	dis[s]=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto [y,w]:v[x])
		{
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				q.push({y,dis[y]});
			}
		}
	}
}
void solve()
{
	cin>>n>>l>>r;l--;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	for(int i=0;i<p[1];i++)
		for(int j=2;j<=n;j++)
			add(i,(i+p[j])%p[1],p[j]);
	dij(0);
	ll ans=0;
	for(int i=0;i<p[1];i++)
	{
		ll R=(r-dis[i])/p[1]+1;
		ll L=(l-dis[i])/p[1]+1;
		if(r<dis[i])R=0;
		if(l<dis[i])L=0;
		ans+=R-L;
	}
	cout<<ans<<endl;
}
/*
in：
2 5 10
3 5
out:
5
*/
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}
