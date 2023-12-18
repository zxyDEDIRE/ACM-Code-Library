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
vector<int>p;
int n,m,k;
void f()
{
	int t=p.size();
	for(int i=0;i<t;i++)
	{
		int x=p[i];
		v[x].push_back(x+n*2);
		v[x+n*3].push_back(x+n);
		if(i<t-1)
		{
			int y=p[i+1];
			v[x+n*2].push_back(y+n*2);
			v[y+n*3].push_back(x+n*3);
			v[x+n*2].push_back(y+n);
			v[y].push_back(x+n*3);
		}
	}
}
void solve()
{
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}