#include<bits/stdc++.h>
#define int long long
#define ios ios::sync_with_stdio(false);
using namespace std;
const int mod=1e9+7;
const int maxn=1e6+7;

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

signed main(){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
}
