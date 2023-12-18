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
ll n,m,k;
ll f(ll n,ll m,ll k)
{
	ll ans=(k-1)%(n-m+1);
	if(k==1) ans=m-1;
	else{
		for(ll i=n-m+2;i<=n;i++){
			ans=(ans+k)%i;
			ll js=i-ans-1;
			js/=k;
			if(n-i-1<js)js=n-i-1;
			if(js>0){
				i+=js;
				ans=ans+k*js;
			}
		}
	}
	return ans+1;
}
void solve()
{
	cin>>n>>m>>k;
	cout<<f(n,m,k)<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}