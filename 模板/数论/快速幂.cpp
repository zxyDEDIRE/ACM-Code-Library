#include<bits/stdc++.h>
#define int long long
using ll=long long;
using namespace std;
const int maxn=1e6;
const int mod=1e9+7; 

int fp(int b,int p)
{
	int r=1;b%=mod;
	while(p){
		if(p&1)r=(r*b)%mod;
		p>>=1;
		b=(b*b)%mod;
	}
	return r;
}
ll mull(ll a,ll b){ll qw=0;while(b){if(b&1)qw=(qw+a)%mod;a=(a+a)%mod;b>>=1;}return qw;}

ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}

ll ksm(ll b,ll p,ll mod){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}



signed main(){
	int a,b;
	cin>>a>>b;
	pow(a,b);
	cout<<fp(a,b)<<endl;
}
