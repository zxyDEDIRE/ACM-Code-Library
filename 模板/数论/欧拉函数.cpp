#include<bits/stdc++.h>
#define int long long
#define ios ios::sync_with_stdio(false);
using namespace std;
const int mod=1e9+7;
const int maxn=1e6+7;
int prime[maxn],phi[maxn];
bool vis[maxn];
int n;
void doit(int N)
{
	for(int i=2;i<=N;i++){
		if(!vis[i])prime[++prime[0]]=i,phi[i]=i-1;
		for(int j=1;j<=prime[0]&&prime[j]*i<=N;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
int PHI(int x)
{
	//O(sqrt(x)
	int ans=x;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
		{
			while(x%i==0)x/=i;
			ans=ans*(i-1)/i;
		}
	if(x>1)ans=ans*(x-1)/x;
	return ans;
}
signed main(){
	int n;cin>>n;
	doit(n);
	cout<<phi[n];
}
