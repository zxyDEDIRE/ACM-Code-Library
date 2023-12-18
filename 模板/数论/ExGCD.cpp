#include<bits/stdc++.h>
#define int long long
#define ios ios::sync_with_stdio(false);
using namespace std;
const int mod=1e9+7;
const int maxn=1e6+7;

int exgcd(int a,int b,int& x,int& y)
{
	if(b==0)return x=1,y=0,a;
	int d=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return d;
}


signed main(){
	
}
