#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);
#define int long long
using namespace std;
const int mod=1e9+7;
const int maxn=1e6;

bool vis[maxn];
int prime[maxn];
void init()
{
	for(int i=2;i<=maxn;i++)
	{
		if(!vis[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=maxn;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
signed main()
{
	init();
	for(int i=1;i<=11;i++)cout<<prime[i]<<" ";
	cout<<endl;
	// for(int i=1;i<=10000;i++)
	// {
	// 	for(int j=i;j<=10000;j++)
	// 	{
	// 		if(j-i>=3)continue;
	// 		int ans=1;
	// 		for(int k=i;k<=j;k++)
	// 			ans*=prime[k];
	// 		ans++;
	// 		if(ans%prime[j+1]==0){
	// 			cout<<i<<" "<<j<<" "<<ans<<" "<<prime[j+1]<<" "<<ans/prime[j+1]<<endl;
	// 		}
	// 	}
	// }
}
/*
2 3 5 7 11 13 17 19 23 29 31
*/