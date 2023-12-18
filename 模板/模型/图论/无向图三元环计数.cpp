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
vector<int>v[maxn];
bitset<maxn>vis;
int in[maxn];
pii p[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		auto &[x,y]=p[i];
		cin>>x>>y;
		in[x]++;in[y]++;
	}
	for(int i=1;i<=m;i++)
	{
		auto [x,y]=p[i];
		if(in[x]<in[y])swap(x,y); // 度数大指向度数小的点
		else if(in[x]==in[y]&&x>y)swap(x,y); // 度数相同，编号小指向编号大的点
		v[x].push_back(y);
	}
	int ans=0;
	for(int x=1;x<=n;x++)
	{
		for(auto y:v[x])vis[y]=1;
		for(auto y:v[x])
			for(auto z:v[y])
				if(vis[z])ans++;
		for(auto y:v[x])vis[y]=0;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}