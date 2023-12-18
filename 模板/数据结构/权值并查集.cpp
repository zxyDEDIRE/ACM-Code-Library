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
int f[maxn];
ll w[maxn];
int n,m;
int find(int r){
	if(r==f[r])return r;
	int fa=find(f[r]);
	w[r]+=w[f[r]];
	f[r]=fa;
	return fa;
}
bool merge(int x,int y,int c)
{
	int fa=find(x);
	int fb=find(y);
	if(fa==fb)
	{
		return w[y]-w[x]==c;
	}
	else{
		f[fa]=fb;
		w[fa]=w[y]-w[x]-c;
	}
	return 1;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		f[i]=i,w[i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		//w[x] - w[y] == c？
		if(merge(x,y,c))cout<<i<<" ";
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}