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
vector<int>v[maxn],G[maxn];
int in[maxn],id[maxn],rk[maxn],cnt[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
		in[x]++;in[y]++;
	}
	iota(id+1, id+1+n, 1);
	sort(id+1,id+1+n,[&](int x,int y){
		return in[x]==in[y]?x<y:in[x]<in[y];
	});
	for(int i=1;i<=n;i++)
		rk[id[i]]=i;
	for(int x=1;x<=n;x++)
		for(auto y:v[x])
			if(rk[y]>rk[x])
				G[x].push_back(y);
	int ans=0;
	for(int x=1;x<=n;x++)
	{
		for(auto y:v[x])
			for(auto z:G[y])
				if(rk[z]>rk[x])
					ans+=cnt[z],cnt[z]++;
		for(auto y:v[x])
			for(auto z:G[y])
				cnt[z]=0;
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