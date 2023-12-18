#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll INF=1e18+7;
const int N=555;
ll dis[N][N];
ll cnt[N][N];
ll a[N][N];
int n,m;
void solve()
{
	/*
	有向图求最小环的大小 mi
	以及最小环的个数 ans
	*/
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=0,dis[i][j]=INF;
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		a[x][y]=w;
		dis[x][y]=w;
		cnt[x][y]=1;
	}
	ll mi=INF;
	ll ans=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
					cnt[i][j]=cnt[i][k]*cnt[k][j]%mod;
				}
				else if(dis[i][j]==dis[i][k]+dis[k][j])
				{
					cnt[i][j]=(cnt[i][j]+cnt[i][k]*cnt[k][j])%mod;
				}
			}
		for(int i=1;i<k;i++)
		{
			if(a[k][i])
			{
				if(a[k][i]+dis[i][k]<mi){
					mi=a[k][i]+dis[i][k];
					ans=cnt[i][k];
				}
				else if(a[k][i]+dis[i][k]==mi){
					ans=(ans+cnt[i][k])%mod;
				}
			}
		}
	}
	if(mi==INF)ans=mi=-1;
	cout<<mi<<" "<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}