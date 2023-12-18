#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll mul(ll a,ll b,ll mod){
	a%=mod;
	b%=mod;
	ll c=(long double)a*b/mod;
	ll ans=a*b-c*mod;
	return (ans%mod+mod)%mod;
}

ll pow_mod(ll x,ll n,ll mod){
	ll res=1;
	while(n){
		if(n&1)res=mul(res,x,mod);
		x=mul(x,x,mod);
		n>>=1;
	}
	return (res+mod)%mod;
}



bool m_r(ll a,ll n){
	ll s=n-1,r=0;
	while((s&1)==0){
		s>>=1;r++;
	}
	ll k=pow_mod(a,s,n);

	if(k==1)return true;
	for(int i=0;i<r;i++,k=k*k%n){
		if(k==n-1)return true;
	}
	return false;
}


bool isprime(ll n){
	if(n==1)return 0;
	ll times=7;
	ll prime[100]={2,3,5,7,11,233,331};
	for(int i=0;i<times;i++){
		if(n==prime[i])return true;
		if(m_r(prime[i],n)==false)return false;
	}
	return true;
}
int main()
{
	while(1){
		ll n;
		cin>>n;
		cout<<isprime(n)<<endl;
	}
	
}